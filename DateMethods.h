#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <ctime>
#include "HelpMethods.h"
#include "Enums.h"

using namespace std;

class DateMethods {


public:

    int getDate(MonthTag monthTag, DayTag dayTag);
    int getFirstDayOfCurrentMonthDate();
    int getSpecificDateFromUser();
    bool checkIfADateFitInRequiredPeriod(string date);

};








#endif
