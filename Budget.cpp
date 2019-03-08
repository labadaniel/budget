#include "Budget.h"

void Budget::showAllUser(){
    userManager.showAllUser();
}

void Budget::signInUser(){
    userManager.signInUser();
}

void Budget::logInUser(){
    userManager.logInUser();
    if(userManager.isUserLoggedIn())
        incomeManager = new IncomeManager(userManager.getLoggedInUserId());
        expenseManager = new ExpenseManager(userManager.getLoggedInUserId());
}

void Budget::changeLoggedUserPassword(){
    userManager.changeLoggedUserPassword();
}

void Budget::addIncome(){
    incomeManager -> addIncome();
}

void Budget::addExpense(){
    expenseManager -> addExpense();
}

void Budget::showUserBalanceFromUserPeriod(){
    string inputUserDateFrom;
    string inputUserDateTo;

    cout << "Podaj od jakiej daty pokazac przychody (rrrr-mm-dd): ";
    cin >> inputUserDateFrom;

    inputUserDateFrom = SupportMetod::convertUserDateToDateWithNoMinusSign(inputUserDateFrom);

    cout << "Podaj do jakiej daty pokazac przychody (rrrr-mm-dd): ";
    cin >> inputUserDateTo;

    inputUserDateTo = SupportMetod::convertUserDateToDateWithNoMinusSign(inputUserDateTo);

    cout << inputUserDateFrom << " " << inputUserDateTo;
    incomeManager -> showUserBalance(inputUserDateFrom, inputUserDateTo);
    expenseManager -> showUserBalance(inputUserDateFrom, inputUserDateTo);
    checkBalance();
}

void Budget::checkBalance(){
    cout << endl << endl << "Bilans wynosi: " << incomeManager -> getSumOfIncomes() - expenseManager -> getSumOfExpenses() << "zl. " << endl << endl;
    system ("pause");
}

char Budget::mainMenu()
{
    char option;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> option;

    return option;
}

char Budget::userMenu(){
    char option;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> option;

    return option;
}

bool Budget::isUserLogedIn(){

    if(userManager.isUserLoggedIn())
        return true;
    else
        return false;
}

void Budget::logOutUser(){

    userManager.logOutUser();
    delete incomeManager;
    delete expenseManager;

    incomeManager = NULL;
    expenseManager = NULL;
}

void Budget::showUserBalanceCurrentMonth(){
    string originDate = SupportMetod::convertUserDateToDateWithNoMinusSign(SupportMetod::getCurrentTime()); //20190307
    string month = "";
    string year = "";
    string lastDay = "";

    for (int i = 0; i < 6; i++ ){
        if (i < 4)
            year += originDate[i];
        else if (i >= 4 && i < 6)
            month += originDate[i];
    }
    string firstDay = "01";
    string fromDate = year + month + firstDay;

    int toLastDay = SupportMetod::howManyDaysInMonth(SupportMetod::convertStringToInt(month), SupportMetod::convertStringToInt(year));

    lastDay = SupportMetod::convertIntToString(toLastDay);

    string toDate = year + month + lastDay;

    incomeManager -> showUserBalance(fromDate, toDate);
    expenseManager -> showUserBalance(fromDate, toDate);
    checkBalance();
}

void Budget::showUserBalancePreviouseMonth(){
    string originDate = SupportMetod::convertUserDateToDateWithNoMinusSign(SupportMetod::getCurrentTime()); //20190307
    string month = "";
    string year = "";
    string lastDay = "";
    int intMonth;
    int intYear;

    for (int i = 0; i < 6; i++ ){
        if (i < 4)
            year += originDate[i];
        else if (i >= 4 && i < 6)
            month += originDate[i];
    }
    intMonth = SupportMetod::convertStringToInt(month)-1;
    intYear = SupportMetod::convertStringToInt(year)-1;

    if (intMonth == 0){
        intMonth = 12;
        month = SupportMetod::convertIntToString(intMonth);
        year = SupportMetod::convertIntToString(intYear);
    }
    else if (intMonth < 10 && intMonth > 0)
        month = "0" + SupportMetod::convertIntToString(intMonth);
    else
        month = SupportMetod::convertIntToString(intMonth);

    string firstDay = "01";
    string fromDate = year + month + firstDay;

    int toLastDay = SupportMetod::howManyDaysInMonth(SupportMetod::convertStringToInt(month), SupportMetod::convertStringToInt(year));

    lastDay = SupportMetod::convertIntToString(toLastDay);

    string toDate = year + month + lastDay;
    incomeManager -> showUserBalance(fromDate, toDate);
    expenseManager -> showUserBalance(fromDate, toDate);
    checkBalance();
}


