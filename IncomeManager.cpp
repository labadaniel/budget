#include "IncomeManager.h"

void IncomeManager::addIncome(){
    char answer;

    cout << "Podaj przychod: " << endl << endl;

    cout << "1. Z data dzisiejsza" << endl;
    cout << "2. Z inna data" << endl;

    cin >> answer;

    switch(answer){
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

int IncomeManager::getIncomeId() {
    if (incomes.empty())
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

void IncomeManager::inputDataWithTodayDate(){
    double amount;
    string item;
    string date;
    date = SupportMetod::getCurrentTime();
    date = SupportMetod::convertUserDateToDateWithNoMinusSign(date);

    income.setDate(SupportMetod::convertStringToInt(date));
    income.setIncomeId(getIncomeId());
    income.setUserId(ID_LOGGED_IN_USER);
    cout << "Podaj wartosc przychodu: ";
    cin >> amount;
    income.setAmount(amount);

    cout << "Podaj rodzaj wplaty: ";
    cin >> item;
    income.setItem(item);

    incomes.push_back(income);
}

void IncomeManager::inputDataWithUserDate(){
    double amount;
    string item;

    cout << "Podaj date (rrrr-mm-dd) pod ktora wpisac wplate: ";
    cin >> date;

        if(checkFormatUserDate() && checkCorrectDate()){
            date = SupportMetod::convertUserDateToDateWithNoMinusSign(date);
            if(checkLastDayFromUserInputDay(date)){
                cout << "Podaj wartosc przychodu: ";
                cin >> amount;
                cout << "Podaj rodzaj wplaty: ";
                cin >> item;

                income.setDate(SupportMetod::convertStringToInt(date));
                income.setIncomeId(getIncomeId());
                income.setUserId(ID_LOGGED_IN_USER);
                income.setAmount(amount);
                income.setItem(item);
                incomes.push_back(income);
            }
            else{
                cout << "Podano date wykraczajaca poza biezacy miesiac." << endl;
                system("pause");
            }
        }
        else {
            cout << "Podano niepoprawna date!" << endl;
            system("pause");
        }
}



void IncomeManager::showUserIncomes(){
    for(int i = 0; i<incomes.size(); i++){
        cout << "data: " << incomes[i].getDate() << endl;
        cout << "id wplaty: " << incomes[i].getIncomeId() << endl;
        cout << "id uzytkownika: " << incomes[i].getUserId() << endl;
        cout << "wartosc: " << incomes[i].getAmount() << endl;
        cout << "rodzaj wplaty: " << incomes[i].getItem() << endl;
    }
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

bool IncomeManager::checkFormatUserDate(){
    char sign = '-';
    if(date.length() == 10)
        if(date[4] == sign && date[7] == sign)
            return 1;
}

int IncomeManager::howManyDaysInMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear)
            return 29;
        else
            return 28;
    } else
        return 31;
}


bool IncomeManager::checkLastDayFromUserInputDay(string userDate){
    int fromDate = 20000101;
    int toLastDateCurrentMonth = 0;
    int tmpUserDate;

    toLastDateCurrentMonth = SupportMetod::convertStringToInt(getCurrentDateWithLastDayOfMonth());
    tmpUserDate = SupportMetod::convertStringToInt(userDate);

    if(tmpUserDate >= fromDate && tmpUserDate <= toLastDateCurrentMonth)
        return true;
    else
        return false;
}

string IncomeManager::getCurrentDateWithLastDayOfMonth(){
    int currentMonth = 0;
    int currentYear = 0;
    int amountDaysInCurrentMonth =0;
    string date;
    string tmpCurrentMonth = "";
    string tmpCurrentYear = "";
    string tmpLastDayInCurrentMonth = "";

    date = SupportMetod::getCurrentTime();
    date = SupportMetod::convertUserDateToDateWithNoMinusSign(date);

    for (int i=0; i<date.length(); i++ ){
        if(i <= 3)
            tmpCurrentYear += date[i];
        else if (i > 3 && i <=5)
            tmpCurrentMonth += date[i];
    }
    currentMonth = SupportMetod::convertStringToInt(tmpCurrentMonth);
    currentYear = SupportMetod::convertStringToInt(tmpCurrentYear);
    amountDaysInCurrentMonth = howManyDaysInMonth(currentMonth, currentYear);
    tmpLastDayInCurrentMonth = SupportMetod::convertIntToString(amountDaysInCurrentMonth);
    string fullDate = tmpCurrentYear + tmpCurrentMonth + tmpLastDayInCurrentMonth;

    return fullDate;
}



