#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "SupportMetod.h"
#include "DateManager.h"

using namespace std;

class Budget
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    DateManager dateManager;

    void checkBalance(string fromDate, string toDate);

public:
    Budget(){
        incomeManager = NULL;
        expenseManager = NULL;
    }
    ~Budget(){
        delete incomeManager;
        delete expenseManager;
        incomeManager = NULL;
        expenseManager = NULL;
    }
    bool isUserLogedIn();
    char userMenu();
    void addIncome();
    void addExpense();
    void showUserBalanceFromCurrentMonth();
    void showUserBalanceFromPreviouseMonth();
    void showUserBalanceFromUserPeriod();
    void changeLoggedUserPassword();
    void logOutUser();
    char mainMenu();
    void signInUser();
    void logInUser();
    void showAllUser();
};

#endif
