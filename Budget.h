#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"


using namespace std;

class Budget
{
    UserManager userManager;
    IncomeManager *incomeManager;

public:
    Budget(){
        incomeManager = NULL;
    }
    ~Budget(){
        delete incomeManager;
        incomeManager = NULL;
    }
    void showAllUser();
    void signInUser();
    void logInUser();
    void changeLoggedUserPassword();
    void addIncome();
    void showUserIncomes();
};


#endif
