#include "SupportMetod.h"

string SupportMetod::getCurrentTime() {
    time_t timeBox;
    struct tm *date;
    char tmpTime [15];

    time( &timeBox );
    date = localtime( &timeBox);
    strftime( tmpTime, sizeof(tmpTime), "%Y-%m-%d", date );

    return tmpTime;
}

int SupportMetod::convertStringToInt(string digit)
{
    int digitInt;
    istringstream iss(digit);
    iss >> digitInt;

    return digitInt;
}

int SupportMetod::splitDate(string date, int start, int stop){

    string newDate = "";
    for(int i = start; i < stop; i++){
            newDate += date[i];
    }
    return convertStringToInt(newDate);
}

string SupportMetod::convertUserDateToDateWithNoMinusSign(string date){
    string newDate;
    for(int i = 0; i < date.length(); i++){
        if (date[i] != '-')
            newDate += date[i];
    }
    return newDate;
}

string SupportMetod::convertIntToString(int digit) {
    ostringstream ss;
    ss << digit;
    string str = ss.str();
    return str;
}

bool SupportMetod::sortDateIncome ( Income lhs,  Income rhs){
    return lhs.getDate() < rhs.getDate();
}

bool SupportMetod::sortDateExpense ( Expense lhs, Expense rhs){
    return lhs.getDate() < rhs.getDate();
}
string SupportMetod::getCurrentDateWithLastDayOfMonth(){
    int currentMonth = 0;
    int currentYear = 0;
    int amountDaysInCurrentMonth =0;
    string date;
    string tmpCurrentMonth = "";
    string tmpCurrentYear = "";
    string tmpLastDayInCurrentMonth = "";

    date = getCurrentTime();
    date = convertUserDateToDateWithNoMinusSign(date);

    for (int i=0; i<date.length(); i++ ){
        if(i <= 3)
            tmpCurrentYear += date[i];
        else if (i > 3 && i <=5)
            tmpCurrentMonth += date[i];
    }
    currentMonth = convertStringToInt(tmpCurrentMonth);
    currentYear = convertStringToInt(tmpCurrentYear);
    amountDaysInCurrentMonth = howManyDaysInMonth(currentMonth, currentYear);
    tmpLastDayInCurrentMonth = convertIntToString(amountDaysInCurrentMonth);
    string fullDate = tmpCurrentYear + tmpCurrentMonth + tmpLastDayInCurrentMonth;

    return fullDate;
}

string SupportMetod::getCurrentDateWithFirstDayOfMonth(){

    string date;
    string currentMonth = "";
    string currentYear = "";
    string firstCurrentDay = "01";

    date = getCurrentTime();
    date = convertUserDateToDateWithNoMinusSign(date);

    for (int i=0; i<date.length(); i++ ){
        if(i <= 3)
            currentYear += date[i];
        else if (i > 3 && i <=5)
            currentMonth += date[i];
    }

    string fullDate = currentYear + currentMonth + firstCurrentDay;

    return fullDate;
}

string SupportMetod::getPreviouseMonthWithLastDayOfMonth(){
    int currentMonth = 0;
    int currentYear = 0;
    int amountDaysInCurrentMonth =0;
    string date;
    string tmpCurrentMonth = "";
    string tmpCurrentYear = "";
    string tmpLastDayInCurrentMonth = "";

    date = getCurrentTime();
    date = convertUserDateToDateWithNoMinusSign(date);

    for (int i=0; i<date.length(); i++ ){
        if(i <= 3)
            tmpCurrentYear += date[i];
        else if (i > 3 && i <=5)
            tmpCurrentMonth += date[i];
    }
    currentMonth = convertStringToInt(tmpCurrentMonth)-1;
    if(currentMonth == 0)
        currentMonth = 12;
    currentYear = convertStringToInt(tmpCurrentYear);
    if(currentMonth == 12)
        currentYear -= 1;
    amountDaysInCurrentMonth = howManyDaysInMonth(currentMonth, currentYear);
    tmpLastDayInCurrentMonth = convertIntToString(amountDaysInCurrentMonth);
    tmpCurrentYear = convertIntToString(currentYear);
    if(currentMonth < 10)
        tmpCurrentMonth = "0" + convertIntToString(currentMonth);
    else
        tmpCurrentMonth = convertIntToString(currentMonth);

    string fullDate = tmpCurrentYear + tmpCurrentMonth + tmpLastDayInCurrentMonth;
    return fullDate;
}

string SupportMetod::getPreviouseMonthWithFirstDayOfMonth(){

    int currentMonth = 0;
    int currentYear = 0;
    string date;
    string tmpCurrentMonth = "";
    string tmpCurrentYear = "";
    string firstCurrentDay = "01";

    date = getCurrentTime();
    date = convertUserDateToDateWithNoMinusSign(date);

    for (int i=0; i<date.length(); i++ ){
        if(i <= 3)
            tmpCurrentYear += date[i];
        else if (i > 3 && i <=5)
            tmpCurrentMonth += date[i];
    }
    currentMonth = convertStringToInt(tmpCurrentMonth)-1;
    if(currentMonth == 0)
        currentMonth = 12;
    currentYear = convertStringToInt(tmpCurrentYear);
    if(currentMonth == 12)
        currentYear -= 1;

    tmpCurrentYear = convertIntToString(currentYear);
    tmpCurrentMonth = convertIntToString(currentMonth);

    string fullDate = tmpCurrentYear + tmpCurrentMonth + firstCurrentDay;

    return fullDate;
}

bool SupportMetod::checkLastDayFromUserInputDay(string userDate){
    int fromDate = 20000101;
    int toDate = 0;
    int tmpUserDate;

    toDate = convertStringToInt(getCurrentDateWithLastDayOfMonth());
    tmpUserDate = convertStringToInt(userDate);

    if(tmpUserDate >= fromDate && tmpUserDate <= toDate)
        return true;
    else
        return false;
}
int SupportMetod::howManyDaysInMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear)
            return 29;
        else
            return 28;
    } else
        return 31;
}


