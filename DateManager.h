#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>
#include "HelpMethods.h"

using namespace std;

class DateManager {


public:

    int getDate(string monthTag, string dayTag);
    int getFirstDayOfCurrentMonthDate();
    int getSpecificDateFromUser();
    bool checkIfADateFitInRequiredPeriod(string date);

};








#endif
