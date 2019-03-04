#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"


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
    void showUserIncomes();
    void addExpense();
    void showUserExpenses();
};


#endif
