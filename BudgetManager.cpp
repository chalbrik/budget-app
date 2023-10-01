#include "BudgetManager.h"

void BudgetManager::addIncome() {
    char chooseOption;

    int currentDate = 0;

    cout << "1 - Would you like to add Income with today's date?" << endl;
    cout << "2 - Would you like to add Income with different date?" << endl;

    chooseOption = HelpMethods::getCharacter();

    if(chooseOption == '1') {
        currentDate = getCurrentDate();

        cout << currentDate << endl;
        system("pause");

    } else if(chooseOption == '2') {

    }

}

// private

int BudgetManager::getCurrentDate() {
    string currentYear = "";
    string currentMonth = "";
    string currentDay = "";
    string currentStrDate = "";
    int currentIntDate = 0;

    time_t currentTime;
    time(&currentTime);
    tm *tmLocal = localtime(&currentTime);

    currentYear = HelpMethods::convertIntToString(tmLocal->tm_year + 1900);
    currentMonth = HelpMethods::convertIntToString(tmLocal->tm_mon + 1);
    currentDay = HelpMethods::convertIntToString(tmLocal->tm_mday);

    if(currentMonth.size() == 1) {
        currentMonth = "0" + currentMonth;
    }

    if(currentDay.size() == 1) {
        currentDay =  "0" + currentDay;
    }

    currentStrDate = currentYear + currentMonth + currentDay;
    currentIntDate = HelpMethods::convertStringToInt(currentStrDate);

    return currentIntDate;

}
