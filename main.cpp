#include <iostream>
#include "Budget.h"


using namespace std;

int main()
{
    Budget budget;

    budget.showAllUser();
    budget.logInUser();
    budget.addIncome();




    budget.showUserIncomesCurrentMonth();


    return 0;
}
