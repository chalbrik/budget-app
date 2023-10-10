#include "BudgetManager.h"

void BudgetManager::addIncome() {

    addTransaction("income", "INCOME", incomes, incomeFile);
}

void BudgetManager::addExpense() {

    addTransaction("expense", "EXPENSE", expenses, expensesFile);
}

void BudgetManager::displayBalanceMenu() {
    char chooseOption;

    system("cls");

    cout << ">>> DISPLAY BALANCE ACCOUNT <<<" << endl << endl;
    cout << "1 - Display current month balance" << endl;
    cout << "2 - Display previous month balance" << endl;
    cout << "3 - Choose period to display balance" << endl;

    cout << endl << "Option: ";

    chooseOption = HelpMethods::getCharacter();

    switch(chooseOption) {
    case '1':
        displayCurrentMonthBalance();
        break;
    case '2':
        displayPreviousMonthBalance();
        break;
    case '3':
        displaySpecificPeriodBalance();
        break;
    }
}

void BudgetManager::displayCurrentMonthBalance() {

    int firstDayOfCurrentMonthDate = 0;
    int currentDate = 0;

    currentDate = getDate("CURRENT", "TODAY");

    firstDayOfCurrentMonthDate = getDate("CURRENT", "FIRST");

    displayBalance(firstDayOfCurrentMonthDate, currentDate);

}

void BudgetManager::displayPreviousMonthBalance() {

    int firstDayOfPreviousMonthDate = 0;
    int lastDayOfPreviousMonthDate = 0;

    firstDayOfPreviousMonthDate = getDate("PREVIOUS", "FIRST");
    lastDayOfPreviousMonthDate = getDate("PREVIOUS", "LAST");

    displayBalance(firstDayOfPreviousMonthDate, lastDayOfPreviousMonthDate);

}

void BudgetManager::displaySpecificPeriodBalance() {

    int dateBeginning = 0;
    int dateEnd = 0;

    cout << endl << "Insert beginning of desired balance period." << endl;
    dateBeginning = getSpecificDateFromUser();
    cout << endl << "Insert end of desired balance period." << endl;
    dateEnd = getSpecificDateFromUser();

    displayBalance(dateBeginning, dateEnd);

}


// private

void BudgetManager::addTransaction(string transactionName, string transactionTag, vector <Transactions> transactions, TransactionFile transactionFile) {
    Transactions transaction;

    int dateOfATransaction = 0;
    string item = "";
    double amount = 0;

    cout << ">>> ADD " << transactionTag << " <<<" << endl << endl;

    dateOfATransaction = addTransactionsDate(transactionName);
    item = addTransactionsCategory(transactionTag);
    amount = addTransactionsAmount(transactionName);

    transaction.setUserId(LOGGED_USER_ID);

    transactions.size() == 0 ? transaction.setTransactionId(1) : transaction.setTransactionId(transactions.back().getTransactionId() + 1); //setting transactionsId
    transaction.setDate(dateOfATransaction);
    transaction.setItem(item);
    transaction.setAmount(amount);

    transactions.push_back(transaction);

    transactionFile.addOperationToFile(transactionTag, transaction);
}

int BudgetManager::addTransactionsDate(string transactionType) {
    char chooseOption;

    int dateOfATransaction = 0;

    cout << "1 - Would you like to add " + transactionType + " with today's date?" << endl;
    cout << "2 - Would you like to add " + transactionType + " with different date?" << endl;

    cout << endl << "Option: ";

    chooseOption = HelpMethods::getCharacter();

    switch(chooseOption) {
    case '1':
        dateOfATransaction = getDate("CURRENT", "TODAY");
        break;
    case '2':
        dateOfATransaction = getSpecificDateFromUser();
        break;
    }
    return dateOfATransaction;
}

string BudgetManager::addTransactionsCategory(string transactionTag) {

    char chooseOption;
    string item = "";

    system("cls");
    cout << "Pick category of your transaction." << endl << endl;

    if(transactionTag == "INCOME") {
        cout << "1 - salary" << endl;
        cout << "2 - sale" << endl;
        cout << "3 - repayment" << endl;

        cout << endl << "Option: ";

        chooseOption = HelpMethods::getCharacter();

        switch(chooseOption) {
        case '1':
            item = "Salary";
            break;
        case '2':
            item = "Sale";
            break;
        case '3':
            item = "Repayment";
            break;
        }

    } else if(transactionTag == "EXPENSE") {

        cout << "1 - Food" << endl;
        cout << "2 - Transportation" << endl;
        cout << "3 - Rent" << endl;

        cout << endl << "Option: ";

        chooseOption = HelpMethods::getCharacter();

        switch(chooseOption) {
        case '1':
            item = "Food";
            break;
        case '2':
            item = "Transportation";
            break;
        case '3':
            item = "Rent";
            break;
        }
    }

    return item;
}

double BudgetManager::addTransactionsAmount(string transactionName) {
    string strAmount = "";
    double amount = 0;

    do {
        system("cls");

        cout << "What is an amount of your " << transactionName << "?" << endl;
        cout << endl << "Type amount: ";

        strAmount = HelpMethods::readLine();
        strAmount = HelpMethods::changeCommaToDot(strAmount);

        if(!HelpMethods::checkIfNumber(strAmount)) {
            cout << endl << "This is not a number. Try again." << endl << endl;
            system("pause");
        }

    } while(!HelpMethods::checkIfNumber(strAmount));

    amount = HelpMethods::convertStringToDouble(strAmount);

    return amount;

}

int BudgetManager::getDate(string monthTag, string dayTag) {
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

int BudgetManager::getFirstDayOfCurrentMonthDate() {
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

int BudgetManager::getSpecificDateFromUser() {
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

void BudgetManager::displayBalance(int beginingDate, int endDate) {

    vector <Transactions> filteredIncomes;
    vector <Transactions> filteredExpenses;

    double sumOfIncomes = 0;
    double sumOfExpenses = 0;
    double incomeExpensesDifference = 0;

    system("cls");

    cout << ">>> LIST OF INCOMES <<<" << endl << endl;

    filteredIncomes = filterTransactions(incomes, beginingDate, endDate);
    showTransactionsFromOldestToLatest(filteredIncomes);
    sumOfIncomes = showSumOfTransactions(filteredIncomes);
    cout << "Total incomes amount: " << sumOfIncomes << " pln" << endl << endl;

    cout << ">>> LIST OF EXPENSES <<<" << endl << endl;

    filteredExpenses = filterTransactions(expenses, beginingDate, endDate);
    showTransactionsFromOldestToLatest(filteredExpenses);
    sumOfExpenses = showSumOfTransactions(filteredExpenses);
    cout << "Total expenses amount: " << sumOfExpenses << " pln" << endl << endl;

    incomeExpensesDifference = sumOfIncomes - sumOfExpenses;

    cout << ">>> SUMMARY <<<" << endl << endl;

    incomeExpensesDifference >= 0 ?  cout << "You have " << incomeExpensesDifference << " pln savings on your account." << endl << endl : cout << "You have " << incomeExpensesDifference << " pln debt on your account." << endl << endl;

    system("pause");
}

void BudgetManager::showTransactionsFromOldestToLatest(vector <Transactions> transactions) {

    sort(transactions.begin(), transactions.end(), compareDates);

    for(vector <Transactions>::iterator itr = transactions.begin(); itr != transactions.end(); itr++) {
        cout << "Transacion ID: " << itr->getTransactionId() << endl;
        cout << "User ID: " << itr->getUserId() << endl;
        cout << "Date: " << itr->getDate() << endl;
        cout << "Category: " << itr->getItem() << endl;
        cout << "Amount: " << itr->getAmount() << " pln" << endl;
        cout << endl;
    }
}

double BudgetManager::showSumOfTransactions(vector <Transactions> transactions) {
    double sumOfAmount = 0;

    for(vector <Transactions>::iterator itr = transactions.begin(); itr != transactions.end(); itr++) {
        sumOfAmount = sumOfAmount + itr->getAmount();
    }

    return sumOfAmount;
}

vector <Transactions> BudgetManager::filterTransactions(vector <Transactions> transactions, int beginingDate, int endDate) {
    vector <Transactions> filteredTransactions;

    for(vector <Transactions>::iterator itr = transactions.begin(); itr != transactions.end(); itr++) {

        if(itr->getDate() >= beginingDate && itr->getDate() <= endDate) {
            filteredTransactions.push_back(*itr);
        }
    }

    return filteredTransactions;
}

bool BudgetManager::compareDates(Transactions t1, Transactions t2)
{
    return (t1.getDate() < t2.getDate());
}




