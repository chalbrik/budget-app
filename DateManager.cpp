#include "DateManager.h"


int DateManager::getDate(string monthTag, string dayTag) {
    string year = "";
    string month = "";
    string day = "";
    string strDate = "";
    int intDate = 0;

    time_t currentTime;
    time(&currentTime);
    tm *tmLocal = localtime(&currentTime);

    if(monthTag == "CURRENT") {
        year = HelpMethods::convertIntToString(tmLocal->tm_year + 1900);
        month = HelpMethods::convertIntToString(tmLocal->tm_mon + 1);
    } else if (monthTag == "PREVIOUS" && dayTag == "FIRST") {

        tmLocal->tm_mon -= 1;

        if(tmLocal->tm_mon == 0) {
            tmLocal->tm_mon = 12;
            tmLocal->tm_year -= 1;
        }
        year = HelpMethods::convertIntToString(tmLocal->tm_year + 1900);
        month = HelpMethods::convertIntToString(tmLocal->tm_mon + 1);
    }

    if(monthTag == "CURRENT" && dayTag == "TODAY") {
        day = HelpMethods::convertIntToString(tmLocal->tm_mday);
    } else if((monthTag == "CURRENT" || monthTag == "PREVIOUS") && dayTag == "FIRST") {
        day = "01";
    } else if(monthTag == "PREVIOUS" && dayTag == "LAST") {

        if(tmLocal->tm_mon == 0) {
            tmLocal->tm_mon = 12;
            tmLocal->tm_year -= 1;
        }

        tmLocal->tm_mday = 0;

        mktime(tmLocal);

        year = HelpMethods::convertIntToString(tmLocal->tm_year + 1900);
        month =  month = HelpMethods::convertIntToString(tmLocal->tm_mon + 1);
        day = HelpMethods::convertIntToString(tmLocal->tm_mday);
    }

    if(month.size() == 1) {
        month = "0" + month;
    }

    if(day.size() == 1) {
        day =  "0" + day;
    }

    strDate = year + month + day;
    intDate = HelpMethods::convertStringToInt(strDate);

    return intDate;

}

int DateManager::getFirstDayOfCurrentMonthDate() {
    string currentYear = "";
    string currentMonth = "";
    string firstDayOfCurrentMonth = "";
    string firstDayOfCurrentMonthStrDate = "";
    int firstDayOfCurrentMonthIntDate = 0;

    time_t currentTime;
    time(&currentTime);
    tm *tmLocal = localtime(&currentTime);

    currentYear = HelpMethods::convertIntToString(tmLocal->tm_year + 1900);
    currentMonth = HelpMethods::convertIntToString(tmLocal->tm_mon + 1);
    firstDayOfCurrentMonth = "01";

    if(currentMonth.size() == 1) {
        currentMonth = "0" + currentMonth;
    }

    firstDayOfCurrentMonthStrDate = currentYear + currentMonth + firstDayOfCurrentMonth;

    firstDayOfCurrentMonthIntDate = HelpMethods::convertStringToInt(firstDayOfCurrentMonthStrDate);

    return firstDayOfCurrentMonthIntDate;
}

int DateManager::getSpecificDateFromUser() {
    string strDateOfATransactionFromUser = "";
    int dateOfATransactionFromUser = 0;

    do {
        cout << endl << "Type date(YYYY-MM-DD):";

        strDateOfATransactionFromUser = HelpMethods::readLine();

    } while (checkIfADateFitInRequiredPeriod(strDateOfATransactionFromUser));

    for(size_t i = 0; i < strDateOfATransactionFromUser.size(); i++) {
        if(strDateOfATransactionFromUser[i] == '-') {
            strDateOfATransactionFromUser.erase(i, 1);
        }
    }

    dateOfATransactionFromUser = HelpMethods::convertStringToInt(strDateOfATransactionFromUser);

    return dateOfATransactionFromUser;
}

bool DateManager::checkIfADateFitInRequiredPeriod(string date) {
    string extract = "";
    int indexOfHyphen = 0;
    int lenghtOfDateAfterHyphen = 0;
    int year = 0;
    int month = 0;
    int day = 0;
    int caseCounter = 0;

    time_t currentTime;
    time(&currentTime);
    tm *tmLocal = localtime(&currentTime);

    while(date.size() > 0) {
        indexOfHyphen = date.find('-');

        if(indexOfHyphen > 0) {
            extract = date.substr(0, indexOfHyphen);
            caseCounter++;
            lenghtOfDateAfterHyphen = date.size() - extract.size();
            date = date.substr(indexOfHyphen + 1, lenghtOfDateAfterHyphen - 1);
        } else {
            caseCounter++;
            extract = date;
            date.erase();
        }

        switch(caseCounter) {
        case 1:
            year = HelpMethods::convertStringToInt(extract);
            break;
        case 2:
            month = HelpMethods::convertStringToInt(extract);
            break;
        case 3:
            day = HelpMethods::convertStringToInt(extract);
            break;
        }
    }

    if( (year > 2000 && year < tmLocal->tm_year + 1900) || (year == tmLocal->tm_year + 1900 && month < tmLocal->tm_mon + 1) || (month == tmLocal->tm_mon + 1 && day <= tmLocal->tm_mday) ) {
        return false;
    } else {
        cout << "Given date does not fit in between 2000-01-01 and present day period. Try again." << endl;
        system("pause");
        return true;
    }
}
