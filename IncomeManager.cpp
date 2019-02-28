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

    income.setDate(SupportMetod::getCurrentTime());
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

    string date;
    double amount;
    string item;

    cout << "Podaj date (rrrr-mm-dd) pod ktora wpisac wplate: ";
    cin >> date;
    if(checkFormatUserDate(date)){
        cout << "Podaj wartosc przychodu: ";
        cin >> amount;
        cout << "Podaj rodzaj wplaty: ";
        cin >> item;

        income.setDate(date);
        income.setIncomeId(getIncomeId());
        income.setUserId(ID_LOGGED_IN_USER);
        income.setAmount(amount);
        income.setItem(item);

        incomes.push_back(income);
    }
    else
        cout << "Podano niepoprawna date!" << endl;
        system("pause");
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

bool IncomeManager::checkFormatUserDate(string date){
    string year, month, day;
    char sign = '-';
    if(date.length() == 10)
        if((date[4] && date[7]) == sign)
            return 1;
    return 0;
}



