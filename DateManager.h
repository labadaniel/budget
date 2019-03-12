#ifndef DATEMANAGER_H
#define DATEMANAGER_H
#include <iostream>
#include "SupportMetod.h"

using namespace std;

class DateManager{

public:
    string getFirstDateCurrentMonth();
    string getSecondDateCurrentMonth();
    string getFirstDatePreviouseMonth();
    string getSecondDatePreviouseMonth();
    string getFirstUserDate();
    string getSecondUserDate();
};

#endif // DATEMANAGER_H
