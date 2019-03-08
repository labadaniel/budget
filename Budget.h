#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "SupportMetod.h"


using namespace std;

class Budget
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;


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
    void showAllUser();
    void signInUser();
    void logInUser();
    void changeLoggedUserPassword();
    void addIncome();
    void showUserBalanceCurrentMonth();
    void showUserBalancePreviouseMonth();
    void addExpense();
    void showUserBalanceFromUserPeriod();
    void checkBalance();
    char mainMenu();
    char userMenu();
    bool isUserLogedIn();
    void logOutUser();
};


#endif
