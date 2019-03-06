#include "Expense.h"
#include "SupportMetod.h"

    int Expense::getExpenseId(){
        return expenseId;
    }
    int Expense::getUserId(){
        return userId;
    }
    int Expense::getDate(){
        return date;
    }
    string Expense::getItem(){
        return item;
    }
    double Expense::getAmount(){
        return amount;
    }

    void Expense::setExpenseId(int newExpenseId){
        expenseId = newExpenseId;
    }
    void Expense::setUserId(int newUserId){
        userId = newUserId;
    }
    void Expense::setDate(int newDate){
        date = newDate;
    }
    void Expense::setItem(string newItem){
        item = newItem;
    }
    void Expense::setAmount(string newAmount){
        amount = SupportMetod::checkIfComma(newAmount);
    }
