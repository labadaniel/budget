#ifndef INCOME_H
#define INCOME_H
#include <iostream>



using namespace std;

class Income
{
    int incomeId;
    int userId;
    int date;
    string item;
    double amount;

public:
    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);
};
#endif
