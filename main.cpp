#include <iostream>
#include "Budget.h"


using namespace std;

int main()
{
    Budget budget;

    budget.showAllUser();
    budget.logInUser();
    budget.addIncome();


    budget.showUserIncomes();



    return 0;
}
