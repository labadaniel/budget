#include "IncomeManager.h"

void IncomeManager::addIncome(){
    char answer;

    cout << endl << "Podaj przychod: " << endl << endl;

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


void IncomeManager::inputDataWithTodayDate(){
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
                income.setIncomeId(fileWithIncome.getIncomeId());
                income.setUserId(ID_LOGGED_IN_USER);
                income.setAmount(amount);
                income.setItem(item);
                incomes.push_back(income);
                fileWithIncome.addIncomeToFile(income);
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


void IncomeManager::showUserIncomesCurrentMonth(){

    sort(incomes.begin(), incomes.end(), sortDate);
    cout << endl << "-----PRZYCHODY - MIESIAC BIEZACY-----" << endl << endl;
    for(int i = 0; i<incomes.size(); i++){
        if(incomes[i].getDate() <= SupportMetod::convertStringToInt(getCurrentDateWithLastDayOfMonth()) &&
        incomes[i].getDate() >= SupportMetod::convertStringToInt(getCurrentDateWithFirstDayOfMonth())){
            cout << incomes[i].getDate() << " " << incomes[i].getAmount() << "zl " << incomes[i].getItem() << endl;
        }
    }
}

void IncomeManager::showUserIncomesPreviouseMonth(){

    sort(incomes.begin(), incomes.end(), sortDate);
    cout << endl << "-----PRZYCHODY - MIESIAC POPRZEDNI-----" << endl << endl;
    for(int i = 0; i<incomes.size(); i++){
        if(incomes[i].getDate() <= SupportMetod::convertStringToInt(getPreviouseMonthWithLastDayOfMonth()) &&
        incomes[i].getDate() >= SupportMetod::convertStringToInt(getPreviouseMonthWithFirstDayOfMonth())){
            cout << incomes[i].getDate() << " " << incomes[i].getAmount() << "zl " << incomes[i].getItem() << endl;
        }
    }
}

bool IncomeManager::sortDate ( Income lhs,  Income rhs){
    return lhs.getDate() < rhs.getDate();
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
    int toDate = 0;
    int tmpUserDate;

    toDate = SupportMetod::convertStringToInt(getCurrentDateWithLastDayOfMonth());
    tmpUserDate = SupportMetod::convertStringToInt(userDate);

    if(tmpUserDate >= fromDate && tmpUserDate <= toDate)
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

string IncomeManager::getCurrentDateWithFirstDayOfMonth(){

    string date;
    string currentMonth = "";
    string currentYear = "";
    string firstCurrentDay = "01";

    date = SupportMetod::getCurrentTime();
    date = SupportMetod::convertUserDateToDateWithNoMinusSign(date);

    for (int i=0; i<date.length(); i++ ){
        if(i <= 3)
            currentYear += date[i];
        else if (i > 3 && i <=5)
            currentMonth += date[i];
    }

    string fullDate = currentYear + currentMonth + firstCurrentDay;

    return fullDate;
}

string IncomeManager::getPreviouseMonthWithLastDayOfMonth(){
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
    currentMonth = SupportMetod::convertStringToInt(tmpCurrentMonth)-1;
    if(currentMonth == 0)
        currentMonth = 12;
    currentYear = SupportMetod::convertStringToInt(tmpCurrentYear);
    if(currentMonth == 12)
        currentYear -= 1;
    amountDaysInCurrentMonth = howManyDaysInMonth(currentMonth, currentYear);
    tmpLastDayInCurrentMonth = SupportMetod::convertIntToString(amountDaysInCurrentMonth);
    tmpCurrentYear = SupportMetod::convertIntToString(currentYear);
    if(currentMonth < 10)
        tmpCurrentMonth = "0" + SupportMetod::convertIntToString(currentMonth);
    else
        tmpCurrentMonth = SupportMetod::convertIntToString(currentMonth);

    string fullDate = tmpCurrentYear + tmpCurrentMonth + tmpLastDayInCurrentMonth;
    return fullDate;
}

string IncomeManager::getPreviouseMonthWithFirstDayOfMonth(){

    int currentMonth = 0;
    int currentYear = 0;
    string date;
    string tmpCurrentMonth = "";
    string tmpCurrentYear = "";
    string firstCurrentDay = "01";

    date = SupportMetod::getCurrentTime();
    date = SupportMetod::convertUserDateToDateWithNoMinusSign(date);

    for (int i=0; i<date.length(); i++ ){
        if(i <= 3)
            tmpCurrentYear += date[i];
        else if (i > 3 && i <=5)
            tmpCurrentMonth += date[i];
    }
    currentMonth = SupportMetod::convertStringToInt(tmpCurrentMonth)-1;
    if(currentMonth == 0)
        currentMonth = 12;
    currentYear = SupportMetod::convertStringToInt(tmpCurrentYear);
    if(currentMonth == 12)
        currentYear -= 1;

    tmpCurrentYear = SupportMetod::convertIntToString(currentYear);
    tmpCurrentMonth = SupportMetod::convertIntToString(currentMonth);



    string fullDate = tmpCurrentYear + tmpCurrentMonth + firstCurrentDay;

    return fullDate;
}



