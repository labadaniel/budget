#include "DateManager.h"

string DateManager::getFirstDateCurrentMonth(){
    string originDate = SupportMetod::convertUserDateToDateWithNoMinusSign(SupportMetod::getCurrentTime()); //20190307
    string month = "";
    string year = "";
    string lastDay = "";

    for (int i = 0; i < 6; i++ ){
        if (i < 4)
            year += originDate[i];
        else if (i >= 4 && i < 6)
            month += originDate[i];
    }
    string firstDay = "01";
    string fromDate = year + month + firstDay;

    return fromDate;
}

string DateManager::getSecondDateCurrentMonth(){
    string originDate = SupportMetod::convertUserDateToDateWithNoMinusSign(SupportMetod::getCurrentTime()); //20190307
    string month = "";
    string year = "";
    string lastDay = "";

    for (int i = 0; i < 6; i++ ){
        if (i < 4)
            year += originDate[i];
        else if (i >= 4 && i < 6)
            month += originDate[i];
    }
    int toLastDay = SupportMetod::howManyDaysInMonth(SupportMetod::convertStringToInt(month), SupportMetod::convertStringToInt(year));

    lastDay = SupportMetod::convertIntToString(toLastDay);

    string toDate = year + month + lastDay;

    return toDate;
}

string DateManager::getFirstUserDate(){

    string inputUserDate;
    cout << "Podaj od jakiej daty pokazac przychody (rrrr-mm-dd): ";
    cin >> inputUserDate;

    inputUserDate = SupportMetod::convertUserDateToDateWithNoMinusSign(inputUserDate);

    return inputUserDate;
}

string DateManager::getSecondUserDate(){

    string inputUserDate;
    cout << "Podaj do jakiej daty pokazac przychody (rrrr-mm-dd): ";
    cin >> inputUserDate;

    inputUserDate = SupportMetod::convertUserDateToDateWithNoMinusSign(inputUserDate);

    return inputUserDate;
}

string DateManager::getFirstDatePreviouseMonth(){
    string originDate = SupportMetod::convertUserDateToDateWithNoMinusSign(SupportMetod::getCurrentTime()); //20190307
    string month = "";
    string year = "";
    int intMonth;
    int intYear;

    for (int i = 0; i < 6; i++ ){
        if (i < 4)
            year += originDate[i];
        else if (i >= 4 && i < 6)
            month += originDate[i];
    }
    intMonth = SupportMetod::convertStringToInt(month)-1;
    intYear = SupportMetod::convertStringToInt(year)-1;

    if (intMonth == 0){
        intMonth = 12;
        month = SupportMetod::convertIntToString(intMonth);
        year = SupportMetod::convertIntToString(intYear);
    }
    else if (intMonth < 10 && intMonth > 0)
        month = "0" + SupportMetod::convertIntToString(intMonth);
    else
        month = SupportMetod::convertIntToString(intMonth);

    string firstDay = "01";
    string fromDate = year + month + firstDay;

    return fromDate;
}

string DateManager::getSecondDatePreviouseMonth(){
    string originDate = SupportMetod::convertUserDateToDateWithNoMinusSign(SupportMetod::getCurrentTime()); //20190307
    string month = "";
    string year = "";
    int intMonth;
    int intYear;

    for (int i = 0; i < 6; i++ ){
        if (i < 4)
            year += originDate[i];
        else if (i >= 4 && i < 6)
            month += originDate[i];
    }
    intMonth = SupportMetod::convertStringToInt(month)-1;
    intYear = SupportMetod::convertStringToInt(year)-1;

    if (intMonth == 0){
        intMonth = 12;
        month = SupportMetod::convertIntToString(intMonth);
        year = SupportMetod::convertIntToString(intYear);
    }
    else if (intMonth < 10 && intMonth > 0)
        month = "0" + SupportMetod::convertIntToString(intMonth);
    else
        month = SupportMetod::convertIntToString(intMonth);

    int toLastDay = SupportMetod::howManyDaysInMonth(SupportMetod::convertStringToInt(month), SupportMetod::convertStringToInt(year));

    string lastDay = SupportMetod::convertIntToString(toLastDay);

    string toDate = year + month + lastDay;

    return toDate;
}
