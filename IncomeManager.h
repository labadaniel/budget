#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>

#include "SupportMetod.h"
#include "Income.h"


using namespace std;

class IncomeManager
{
    vector <Income> incomes;
    string date;
    int incomeId;
    Income income;
    const int ID_LOGGED_IN_USER;
    int getIncomeId();
    void inputDataWithTodayDate();
    void inputDataWithUserDate();
    bool checkCorrectDate();
    bool checkFormatUserDate();
    int howManyDaysInMonth(int month, int year);
    bool checkLastDayFromUserInputDay (string userDate);
    string getCurrentDateWithLastDayOfMonth();

public:
    IncomeManager(int idLoggedUser):ID_LOGGED_IN_USER(idLoggedUser){
        incomeId = 0;
    };
    void addIncome();
    void showUserIncomes();

};


#endif
