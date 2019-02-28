#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    string date;
    string item;
    double amount;

public:
    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};
#endif
