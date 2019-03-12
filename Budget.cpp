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

    string inputUserDateFrom = dateManager.getFirstUserDate();
    string inputUserDateTo = dateManager.getSecondUserDate();

    checkBalance(inputUserDateFrom, inputUserDateTo);
}

void Budget::checkBalance(string fromDate, string toDate){

    incomeManager -> showUserBalance(fromDate, toDate);
    expenseManager -> showUserBalance(fromDate, toDate);

    double balance = incomeManager -> getSumOfIncomes() - expenseManager -> getSumOfExpenses();

    cout << endl << endl << "Bilans wynosi: " << balance << "zl. " << endl << endl;
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

void Budget::showUserBalanceFromCurrentMonth(){

    string fromDate = dateManager.getFirstDateCurrentMonth();
    string toDate = dateManager.getSecondDateCurrentMonth();

    checkBalance(fromDate, toDate);
}

void Budget::showUserBalanceFromPreviouseMonth(){

    string fromDate = dateManager.getFirstDatePreviouseMonth();
    string toDate = dateManager.getSecondDatePreviouseMonth();

    checkBalance(fromDate, toDate);
}
