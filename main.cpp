#include <iostream>
#include "Budget.h"


using namespace std;

int main() {
    Budget budget;
    while(1) {
        if(budget.isUserLogedIn()) {
            char option = budget.userManu();

            switch(option) {
            case '1':
                budget.addIncome();
                break;
            case '2':
                budget.addExpense();
                break;
            case '3':
                budget.showUserIncomesCurrentMonth();
                budget.showUserExpensesCurrentMonth();
                budget.checkBalance();
                break;
            case '4':
                budget.showUserIncomesPreviouseMonth();
                budget.showUserExpensesPreviouseMonth();
                budget.checkBalance();
                break;
            case '5':
                budget.showUserIncomesFromUserPeriod();
                budget.checkBalance();
                break;
            case '6':
                budget.changeLoggedUserPassword();
                break;
            case '7':
                budget.logOutUser();
                break;
            default:
                cout<< endl << "Wybrales zla opcje. Sprobuj ponownie." << endl<< endl;
                system("pause");
                break;
            }
        } else {
            char option = budget.mainManu();

            switch(option) {
            case '1':
                budget.signInUser();
                break;
            case '2':
                budget.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout<< endl << "Wybrales zla opcje. Sprobuj ponownie." << endl<< endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
