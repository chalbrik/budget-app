#include "BudgetManager.h"

void BudgetManager::addIncome() {

    char chooseOption;

    int dateOfATransaction = 0;
    string item = "";
    string strAmount = "";
    double amount = 0;


    dateOfATransaction = addTransactionsDate("income");

    cout << "Pick category of your transaction." << endl;

    cout << "1 - salary" << endl;
    cout << "2 - sale" << endl;
    cout << "3 - repayment" << endl;

    chooseOption = HelpMethods::getCharacter();

    switch(chooseOption) {
    case '1':
        item = "Salary";
        break;
    case '2':
        item = "Sale";
        break;
    case 3:
        item = "Repayment";
        break;
    }

    cout << "What is an amount of your transaction?" << endl;

    strAmount = HelpMethods::readLine();
    HelpMethods::changeCommaToDot(strAmount);
    amount = HelpMethods::convertStringToDouble(strAmount);







    //dodaj obiekt transaction do vektora i przypisz incomeId
    //dodaj obiekt transaction do vektora i przypisz userId
    //dodaj obiekt transaction do vektora i przypisz date
    //dodaj obiekt transaction do vektora i przypisz item
    //dodaj obiekt transaction do vektora i przypisz amount





}

// private

int BudgetManager::addTransactionsDate(string transactionType) {
    char chooseOption;

    int dateOfATransaction = 0;

    cout << "1 - Would you like to add " + transactionType + " with today's date?" << endl;
    cout << "2 - Would you like to add " + transactionType + " with different date?" << endl;

    chooseOption = HelpMethods::getCharacter();

    switch(chooseOption) {
    case '1':
        dateOfATransaction = getCurrentDate();
        break;
    case '2':
        dateOfATransaction = getSpecificDateFromUser();
        break;
    }
}

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

int BudgetManager::getSpecificDateFromUser() {
    string strDateOfATransactionFromUser = "";
    int dateOfATransactionFromUser = 0;

    do {
        cout << "Type date of the transaction(YYYY-MM-DD):";

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

bool BudgetManager::checkIfADateFitInRequiredPeriod(string date) {
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
