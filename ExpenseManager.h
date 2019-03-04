#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>

#include "SupportMetod.h"
#include "Expense.h"
#include "FileWithExpense.h"


using namespace std;

class ExpenseManager
{
    vector <Expense> expenses;
    FileWithExpense fileWithExpense;
    string date;

    Expense expense;
    const int ID_LOGGED_IN_USER;
    void inputDataWithTodayDate();
    void inputDataWithUserDate();
    bool checkCorrectDate();
    bool checkFormatUserDate();
    int howManyDaysInMonth(int month, int year);
    bool checkLastDayFromUserInputDay (string userDate);
    string getCurrentDateWithLastDayOfMonth();

public:
    ExpenseManager(int idLoggedUser):ID_LOGGED_IN_USER(idLoggedUser){
        expenses = fileWithExpense.loadExpenseFromFile(ID_LOGGED_IN_USER);
    };
    void addExpense();
    void showUserExpenses();

};


#endif

