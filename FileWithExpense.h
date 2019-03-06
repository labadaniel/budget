#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H
#include <iostream>
#include <vector>

#include "Markup.h"
#include "Expense.h"

using namespace std;

class FileWithExpense {

    string fileWithExpense;
    int expenseId;

public:

    FileWithExpense(){
        fileWithExpense = "Expenses.xml";
        expenseId = 1;
    };
    int getExpenseId();
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpenseFromFile(int ID_LOGGED_IN_USER);
};

#endif

