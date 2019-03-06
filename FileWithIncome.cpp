#include "FileWithIncome.h"
#include "SupportMetod.h"

void FileWithIncome::addIncomeToFile(Income income) {
    CMarkup fileXml;

    fileXml.Load(fileWithIncome);


    while(fileXml.FindElem("income"))
        fileXml.OutOfElem();

    fileXml.AddElem("income");
    fileXml.IntoElem();
    fileXml.AddElem("incomeId", income.getIncomeId());
    fileXml.AddElem("userId", income.getUserId());
    fileXml.AddElem("date", income.getDate());
    fileXml.AddElem("item", income.getItem());
    fileXml.AddElem("amount", SupportMetod::convertDoubleToString(income.getAmount()));
    fileXml.Save(fileWithIncome);
    cout << income.getAmount();
    system("pause");
}

vector <Income> FileWithIncome::loadIncomeFromFile(int ID_LOGGED_IN_USER) {
    vector <Income> incomes;
    Income income;
    CMarkup xml;

    xml.Load(fileWithIncome);

    while (xml.FindElem("income")) {
        xml.IntoElem();
        xml.FindElem("incomeId");
        income.setIncomeId( atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("userId");
        income.setUserId( atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("date");
        income.setDate( atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("item");
        income.setItem(xml.GetData());
        xml.FindElem("amount");
        income.setAmount( xml.GetData());
        incomeId++;
        if (income.getUserId() == ID_LOGGED_IN_USER)
            incomes.push_back(income);
        xml.OutOfElem();
    }
    return incomes;
}

int FileWithIncome::getIncomeId(){
    return incomeId;
}
