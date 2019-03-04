#include "ExpenseManager.h"

void ExpenseManager::addExpense(){
    char answer;

    cout << endl << "Podaj wydatek: " << endl << endl;

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


void ExpenseManager::inputDataWithTodayDate(){
    double amount;
    string item;
    string date;
    date = SupportMetod::getCurrentTime();
    date = SupportMetod::convertUserDateToDateWithNoMinusSign(date);

    expense.setDate(SupportMetod::convertStringToInt(date));
    expense.setExpenseId(fileWithExpense.getExpenseId());
    expense.setUserId(ID_LOGGED_IN_USER);
    cout << "Podaj wartosc wydatku: ";
    cin >> amount;
    expense.setAmount(amount);

    cout << "Podaj rodzaj wydatku: ";
    cin >> item;
    expense.setItem(item);

    expenses.push_back(expense);

    fileWithExpense.addExpenseToFile(expense);

}

void ExpenseManager::inputDataWithUserDate(){
    double amount;
    string item;

    cout << "Podaj date (rrrr-mm-dd) pod ktora wpisac wplate: ";
    cin >> date;

        if(checkFormatUserDate() && checkCorrectDate()){
            date = SupportMetod::convertUserDateToDateWithNoMinusSign(date);
            if(checkLastDayFromUserInputDay(date)){
                cout << "Podaj wartosc wydatku: ";
                cin >> amount;
                cout << "Podaj rodzaj wydatku: ";
                cin >> item;

                expense.setDate(SupportMetod::convertStringToInt(date));
                expense.setExpenseId(fileWithExpense.getExpenseId());
                expense.setUserId(ID_LOGGED_IN_USER);
                expense.setAmount(amount);
                expense.setItem(item);
                expenses.push_back(expense);
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



void ExpenseManager::showUserExpenses(){
    for(int i = 0; i<expenses.size(); i++){
        cout << "data: " << expenses[i].getDate() << endl;
        cout << "id wyplaty: " << expenses[i].getExpenseId() << endl;
        cout << "id uzytkownika: " << expenses[i].getUserId() << endl;
        cout << "wartosc: " << expenses[i].getAmount() << endl;
        cout << "rodzaj wyplaty: " << expenses[i].getItem() << endl;
    }
}

bool ExpenseManager::checkCorrectDate() {

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

bool ExpenseManager::checkFormatUserDate(){
    char sign = '-';
    if(date.length() == 10)
        if(date[4] == sign && date[7] == sign)
            return 1;
}

int ExpenseManager::howManyDaysInMonth(int month, int year) {
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


bool ExpenseManager::checkLastDayFromUserInputDay(string userDate){
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

string ExpenseManager::getCurrentDateWithLastDayOfMonth(){
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




