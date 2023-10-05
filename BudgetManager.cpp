#include "BudgetManager.h"

void BudgetManager::addIncome() {

    addTransaction("Income", "INCOME", incomes, incomeFile);
}

void BudgetManager::addExpense() {

    addTransaction("Expense", "EXPENSE", expenses, expensesFile);
}

void BudgetManager::displayBalanceMenu() {
    char chooseOption;

    system("cls");

    cout << "DISPLAY BALANCE ACCOUNT" << endl << endl;
    cout << "1 - Display current month balance" << endl;
    cout << "2 - Display previous month balance" << endl;
    cout << "3 - Choose period to display balance" << endl;

    chooseOption = HelpMethods::getCharacter();

    switch(chooseOption) {
    case '1':
        displayCurrentMonthBalance();
        break;
    case '2':
        //displayPreviousMonthBalance();
        break;
    case '3':
        //displaySpecificPeriodBalance();
        break;
    }


}

void BudgetManager::displayCurrentMonthBalance() {

    int firstDayOfCurrentMonthDate = 0;
    int currentDate = 0;

    currentDate = getCurrentDate();

    firstDayOfCurrentMonthDate = getFirstDayOfCurrentMonthDate();

    cout << firstDayOfCurrentMonthDate << endl;
    system("pause");

    displayBalance(firstDayOfCurrentMonthDate, currentDate);

}


// private

void BudgetManager::addTransaction(string transactionName, string transactionTag, vector <Transactions> transactions, TransactionFile transactionFile) {
    Transactions transaction;

    int transactionId = 0;
    int dateOfATransaction = 0;
    string item = "";
    double amount = 0;

    dateOfATransaction = addTransactionsDate(transactionName);
    item = addTransactionsCategory(transactionTag);
    amount = addTransactionsAmount();

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

string BudgetManager::addTransactionsCategory(string transactionTag) {

    char chooseOption;
    string item = "";

    cout << "Pick category of your transaction." << endl;

    if(transactionTag == "INCOME") {
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
        case '3':
            item = "Repayment";
            break;
        }

    } else if(transactionTag == "EXPENSE") {

        cout << "1 - Food" << endl;
        cout << "2 - Transportation" << endl;
        cout << "3 - Rent" << endl;

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

double BudgetManager::addTransactionsAmount() {
    string strAmount = "";
    double amount = 0;

    cout << "What is an amount of your transaction?" << endl;

    strAmount = HelpMethods::readLine();
    HelpMethods::changeCommaToDot(strAmount);
    amount = HelpMethods::convertStringToDouble(strAmount);

    return amount;

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

void BudgetManager::displayBalance(int beginingDate, int endDate) {

    vector <Transactions> filteredIncomes;
    vector <Transactions> filteredExpenses;

    double sumOfIncomes = 0;
    double sumOfExpenses = 0;
    double incomeExpensesDifference = 0;

    filteredIncomes = filterTransactions(incomes, beginingDate, endDate);
    showTransactionsFromOldestToLatest(filteredIncomes, beginingDate, endDate);
    sumOfIncomes = showSumOfTransactions(filteredIncomes);
    cout << "Total incomes amount: " << sumOfIncomes << " pln" << endl << endl;

    filteredExpenses = filterTransactions(expenses, beginingDate, endDate);
    showTransactionsFromOldestToLatest(filteredExpenses, beginingDate, endDate);
    sumOfExpenses = showSumOfTransactions(filteredExpenses);
    cout << "Total expenses amount: " << sumOfExpenses << " pln" << endl << endl;

    incomeExpensesDifference = sumOfIncomes - sumOfExpenses;

    incomeExpensesDifference >= 0 ?  cout << "You have " << incomeExpensesDifference << " pln savings on your account." << endl : cout << "You have " << incomeExpensesDifference << " pln debt on your account." << endl;

    system("pause");
}

void BudgetManager::showTransactionsFromOldestToLatest(vector <Transactions> transactions, int beginingDate, int endDate) {

    sort(transactions.begin(), transactions.end());

    for(vector <Transactions>::iterator itr = transactions.begin(); itr != transactions.end(); itr++) {
        cout << "Income ID: " << itr->getTransactionId() << endl;
        cout << "User ID: " << itr->getUserId() << endl;
        cout << "Date: " << itr->getDate() << endl;
        cout << "Category: " << itr->getItem() << endl;
        cout << "Amount: " << itr->getAmount() << endl;
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




