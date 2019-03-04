#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <algorithm>

#include "SupportMetod.h"
#include "Income.h"
#include "FileWithIncome.h"


using namespace std;

class IncomeManager
{
    vector <Income> incomes;
    FileWithIncome fileWithIncome;
    string date;

    Income income;
    const int ID_LOGGED_IN_USER;
    void inputDataWithTodayDate();
    void inputDataWithUserDate();
    bool checkCorrectDate();
    bool checkFormatUserDate();
    int howManyDaysInMonth(int month, int year);
    bool checkLastDayFromUserInputDay (string userDate);
    string getCurrentDateWithLastDayOfMonth();
    string getCurrentDateWithFirstDayOfMonth();
    static bool sortDate (Income lhs, Income rhs);

public:
    IncomeManager(int idLoggedUser):ID_LOGGED_IN_USER(idLoggedUser){
        incomes = fileWithIncome.loadIncomeFromFile(ID_LOGGED_IN_USER);
    };
    void addIncome();
    void showUserIncomesCurrentMonth();

};


#endif
