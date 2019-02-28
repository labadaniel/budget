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
