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

void Budget::showUserIncomesCurrentMonth(){
    incomeManager -> showUserIncomesCurrentMonth();
}

void Budget::showUserIncomesPreviouseMonth(){
    incomeManager -> showUserIncomesPreviouseMonth();
}

void Budget::addExpense(){
    expenseManager -> addExpense();
}

void Budget::showUserExpensesCurrentMonth(){
    expenseManager -> showUserExpensesCurrentMonth();
}

void Budget::showUserExpensesPreviouseMonth(){
    expenseManager -> showUserExpensesPreviouseMonth();
}

void Budget::showUserIncomesFromUserPeriod(){
    string inputUserDateFrom;
    string inputUserDateTo;

    cout << "Podaj od jakiej daty pokazac przychody (rrrr-mm-dd): ";
    cin >> inputUserDateFrom;

    cout << "Podaj do jakiej daty pokazac przychody (rrrr-mm-dd): ";
    cin >> inputUserDateTo;

    incomeManager -> showUserIncomesFromUserPeriod(inputUserDateFrom, inputUserDateTo);
    expenseManager -> showUserExpensesFromUserPeriod(inputUserDateFrom, inputUserDateTo);
}

void Budget::checkBalance(){
    cout << endl << endl << "Bilans wynosi: " << incomeManager -> getSumOfIncomes() - expenseManager -> getSumOfExpenses() << "zl. " << endl << endl;
    system ("pause");
}

char Budget::mainManu()
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

char Budget::userManu(){
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
