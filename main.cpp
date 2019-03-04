#include <iostream>
#include "Budget.h"


using namespace std;

int main()
{
    Budget budget;

    budget.showAllUser();
    budget.logInUser();





    budget.showUserIncomesCurrentMonth();
    budget.showUserExpensesCurrentMonth();
    budget.checkBalance();

    //budget.showUserIncomesPreviouseMonth();


    return 0;
}
