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
    string amount;
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
    string amount;
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
                fileWithExpense.addExpenseToFile(expense);
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

bool ExpenseManager::checkLastDayFromUserInputDay(string userDate){
    int fromDate = 20000101;
    int toLastDateCurrentMonth = 0;
    int tmpUserDate;

    toLastDateCurrentMonth = SupportMetod::convertStringToInt(SupportMetod::getCurrentDateWithLastDayOfMonth());
    tmpUserDate = SupportMetod::convertStringToInt(userDate);

    if(tmpUserDate >= fromDate && tmpUserDate <= toLastDateCurrentMonth)
        return true;
    else
        return false;
}

void ExpenseManager::showUserBalance(string fromDate, string toDate){

    sumOfExpenses = 0;
    sort(expenses.begin(), expenses.end(), SupportMetod::sortDateExpense);
    cout << endl << "----- WYDATKI -----" << endl << endl;
    for(int i = 0; i<expenses.size(); i++){
        if(expenses[i].getDate() <= SupportMetod::convertStringToInt(toDate) &&
        expenses[i].getDate() >= SupportMetod::convertStringToInt(fromDate)){
            cout << SupportMetod::convertDateToDateWithMinusSign(expenses[i].getDate()) << " " << expenses[i].getAmount() << "zl " << expenses[i].getItem() << endl;
            sumOfExpenses += expenses[i].getAmount();
        }
    }cout << endl << "Suma wydatkow wynosi: " << sumOfExpenses << "zl " << endl;
}

double ExpenseManager::getSumOfExpenses(){
    return sumOfExpenses;
}
