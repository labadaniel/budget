#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H
#include <iostream>
#include <vector>

#include "Markup.h"
#include "Income.h"


using namespace std;

class FileWithIncome {

    string fileWithIncome;
    int incomeId;

public:

    FileWithIncome(){
        fileWithIncome = "Incomes.xml";
        incomeId = 1;
    };
    int getIncomeId();
    void addIncomeToFile(Income income);
    vector <Income> loadIncomeFromFile(int ID_LOGGED_IN_USER);
};

#endif
