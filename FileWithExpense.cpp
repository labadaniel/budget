#include "FileWithExpense.h"
#include "SupportMetod.h"


void FileWithExpense::addExpenseToFile(Expense expense) {
    CMarkup fileXml;

    fileXml.Load(fileWithExpense);


    while(fileXml.FindElem("expense"))
        fileXml.OutOfElem();

    fileXml.AddElem("expense");
    fileXml.IntoElem();
    fileXml.AddElem("expenseId", expense.getExpenseId());
    fileXml.AddElem("userId", expense.getUserId());
    fileXml.AddElem("date", expense.getDate());
    fileXml.AddElem("item", expense.getItem());
    fileXml.AddElem("amount", SupportMetod::convertDoubleToString(expense.getAmount()));
    fileXml.Save(fileWithExpense);
}

vector <Expense> FileWithExpense::loadExpenseFromFile(int ID_LOGGED_IN_USER) {
    vector <Expense> expenses;
    Expense expense;
    CMarkup xml;

    xml.Load(fileWithExpense);

    while (xml.FindElem("expense")) {
        xml.IntoElem();
        xml.FindElem("expenseId");
        expense.setExpenseId( atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("userId");
        expense.setUserId( atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("date");
        expense.setDate( atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("item");
        expense.setItem(xml.GetData());
        xml.FindElem("amount");
        expense.setAmount(xml.GetData());
        expenseId++;
        if (expense.getUserId() == ID_LOGGED_IN_USER)
            expenses.push_back(expense);
        xml.OutOfElem();
    }
    return expenses;
}

int FileWithExpense::getExpenseId(){
    return expenseId;
}

