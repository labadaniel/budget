#ifndef SUPPORTMETOD_H
#define SUPPORTMETOD_H
#include <iostream>
#include <time.h>

#include <sstream>

using namespace std;


class SupportMetod
{

public:
    static string getCurrentTime();
    static int convertStringToInt(string digit);
    static int splitDate(string date, int start, int length);
    static string convertUserDateToDateWithNoMinusSign(string date);
    static string convertIntToString(int digit);
};




#endif
