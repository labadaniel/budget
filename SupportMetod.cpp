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
 //2018-02-05
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

