#include "Budget.h"

void Budget::showAllUser(){
    userManager.showAllUser();
}

void Budget::signInUser(){
    userManager.signInUser();
}

void Budget::logInUser(){
    userManager.logInUser();
    if(userManager.isUserLoggedIn())
        incomeManager = new IncomeManager(userManager.getLoggedInUserId());
        expenseManager = new ExpenseManager(userManager.getLoggedInUserId());
}

void Budget::changeLoggedUserPassword(){
    userManager.changeLoggedUserPassword();
}

void Budget::addIncome(){
    incomeManager -> addIncome();
}

void Budget::showUserIncomesCurrentMonth(){
    incomeManager -> showUserIncomesCurrentMonth();
}

void Budget::showUserIncomesPreviouseMonth(){
    incomeManager -> showUserIncomesPreviouseMonth();
}

void Budget::addExpense(){
    expenseManager -> addExpense();
}

void Budget::showUserExpensesCurrentMonth(){
    expenseManager -> showUserExpensesCurrentMonth();
}

void Budget::showUserExpensesPreviouseMonth(){
    expenseManager -> showUserExpensesPreviouseMonth();
}
