#include "IncomeManager.h"

void IncomeManager::addIncome() {
    char answer;

    cout << endl << "Podaj przychod: " << endl << endl;

    cout << "1. Z data dzisiejsza" << endl;
    cout << "2. Z inna data" << endl;

    cin >> answer;

    switch(answer) {
    case '1':
        inputDataWithTodayDate();
        break;
    case '2':
        inputDataWithUserDate();
        break;
    default:
        cout << "Wybierz wlasciwa opcje!";
        Sleep(2000);
    }
}


void IncomeManager::inputDataWithTodayDate() {
    double amount;
    string item;
    string date;
    date = SupportMetod::getCurrentTime();
    date = SupportMetod::convertUserDateToDateWithNoMinusSign(date);

    income.setDate(SupportMetod::convertStringToInt(date));
    income.setIncomeId(fileWithIncome.getIncomeId());
    income.setUserId(ID_LOGGED_IN_USER);
    cout << "Podaj wartosc przychodu: ";
    cin >> amount;
    income.setAmount(amount);

    cout << "Podaj rodzaj wplaty: ";
    cin >> item;
    income.setItem(item);

    incomes.push_back(income);

    fileWithIncome.addIncomeToFile(income);

}

void IncomeManager::inputDataWithUserDate() {
    double amount;
    string item;

    cout << "Podaj date (rrrr-mm-dd) pod ktora wpisac wplate: ";
    cin >> date;

    if(checkFormatUserDate() && checkCorrectDate()) {
        date = SupportMetod::convertUserDateToDateWithNoMinusSign(date);
        if(SupportMetod::checkLastDayFromUserInputDay(date)) {
            cout << "Podaj wartosc przychodu: ";
            cin >> amount;
            cout << "Podaj rodzaj wplaty: ";
            cin >> item;

            income.setDate(SupportMetod::convertStringToInt(date));
            income.setIncomeId(fileWithIncome.getIncomeId());
            income.setUserId(ID_LOGGED_IN_USER);
            income.setAmount(amount);
            income.setItem(item);
            incomes.push_back(income);
            fileWithIncome.addIncomeToFile(income);
        } else {
            cout << "Podano date wykraczajaca poza biezacy miesiac." << endl;
            system("pause");
        }
    } else {
        cout << "Podano niepoprawna date!" << endl;
        system("pause");
    }
}


void IncomeManager::showUserIncomesCurrentMonth() {

    sumOfIncomes = 0;
    sort(incomes.begin(), incomes.end(), SupportMetod::sortDateIncome);
    cout << endl << "-----PRZYCHODY - MIESIAC BIEZACY-----" << endl << endl;
    for(int i = 0; i<incomes.size(); i++) {
        if(incomes[i].getDate() <= SupportMetod::convertStringToInt(SupportMetod::getCurrentDateWithLastDayOfMonth()) &&
                incomes[i].getDate() >= SupportMetod::convertStringToInt(SupportMetod::getCurrentDateWithFirstDayOfMonth())) {
            cout << SupportMetod::convertDateToDateWithMinusSign(incomes[i].getDate()) << " " << incomes[i].getAmount() << "zl " << incomes[i].getItem() << endl;
            sumOfIncomes += incomes[i].getAmount();
        }

    }
    cout << endl << "Suma przychodow wynosi: " << sumOfIncomes << "zl " << endl;

}

void IncomeManager::showUserIncomesPreviouseMonth() {

    sumOfIncomes = 0;
    sort(incomes.begin(), incomes.end(), SupportMetod::sortDateIncome);
    cout << endl << "-----PRZYCHODY - MIESIAC POPRZEDNI-----" << endl << endl;
    for(int i = 0; i<incomes.size(); i++) {
        if(incomes[i].getDate() <= SupportMetod::convertStringToInt(SupportMetod::getPreviouseMonthWithLastDayOfMonth()) &&
                incomes[i].getDate() >= SupportMetod::convertStringToInt(SupportMetod::getPreviouseMonthWithFirstDayOfMonth())) {
            cout << SupportMetod::convertDateToDateWithMinusSign(incomes[i].getDate()) << " " << incomes[i].getAmount() << "zl " << incomes[i].getItem() << endl;
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    cout << endl << "Suma przychodow wynosi: " << sumOfIncomes << "zl " << endl;
}

bool IncomeManager::checkCorrectDate() {

    int year, month, day;
    year = SupportMetod::splitDate(date, 0, 4);
    month = SupportMetod::splitDate(date, 5, 7);
    day = SupportMetod::splitDate(date, 8, 10);

    if(day > 31)
        return false;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day <=30)
        return true;
    else if (month == 2) {
        bool isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
        if (isLeapYear && day <=29)
            return true;
        else if(day <=28)
            return true;
        else
            return false;
    } else
        return true;
}

bool IncomeManager::checkFormatUserDate() {
    char sign = '-';
    if(date.length() == 10)
        if(date[4] == sign && date[7] == sign)
            return 1;
}

int IncomeManager::getSumOfIncomes() {
    return sumOfIncomes;
}

void IncomeManager::showUserIncomesFromUserPeriod(string inputUserDateFrom, string inputUserDateTo) {

    sumOfIncomes = 0;
    sort(incomes.begin(), incomes.end(), SupportMetod::sortDateIncome);
    cout << endl << "-----PRZYCHODY - WYBRANY OKRES-----" << endl << endl;
    for(int i = 0; i<incomes.size(); i++) {
        if(incomes[i].getDate() <= SupportMetod::convertStringToInt(SupportMetod::convertUserDateToDateWithNoMinusSign(inputUserDateTo)) &&
        incomes[i].getDate() >= SupportMetod::convertStringToInt(SupportMetod::convertUserDateToDateWithNoMinusSign(inputUserDateFrom))) {
            cout << SupportMetod::convertDateToDateWithMinusSign(incomes[i].getDate()) << " " << incomes[i].getAmount() << "zl " << incomes[i].getItem() << endl;
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    cout << endl << "Suma przychodow wynosi: " << sumOfIncomes << "zl " << endl;

}













