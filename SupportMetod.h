#ifndef SUPPORTMETOD_H
#define SUPPORTMETOD_H
#include <iostream>
#include <time.h>
#include <sstream>

#include "Income.h"
#include "Expense.h"
#include "IncomeManager.h"

using namespace std;


class SupportMetod
{
public:
    static string getCurrentTime();
    static int convertStringToInt(string digit);
    static double convertStringToDouble(string digit);
    static int splitDate(string date, int start, int length);
    static string convertUserDateToDateWithNoMinusSign(string date);
    static string convertDateToDateWithMinusSign(int date);
    static string convertIntToString(int digit);
    static string convertDoubleToString(double digit);
    static string getCurrentDateWithLastDayOfMonth();
    static string getCurrentDateWithFirstDayOfMonth();
    static bool sortDateIncome (Income lhs, Income rhs);
    static bool sortDateExpense (Expense lhs, Expense rhs);
    static bool checkLastDayFromUserInputDay (string userDate);
    static int howManyDaysInMonth(int month, int year);
    static double checkIfComma (string amount);
};




#endif
