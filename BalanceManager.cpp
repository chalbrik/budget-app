#include "BalanceManager.h"


void BalanceManager::displayBalanceMenu(vector <Transactions> incomes, vector <Transactions> expenses) {
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
        displayCurrentMonthBalance(incomes, expenses);
        break;
    case '2':
        displayPreviousMonthBalance(incomes, expenses);
        break;
    case '3':
        displaySpecificPeriodBalance(incomes, expenses);
        break;
    }
}

void BalanceManager::displayCurrentMonthBalance(vector <Transactions> &incomes, vector <Transactions> &expenses) {

    int firstDayOfCurrentMonthDate = 0;
    int currentDate = 0;

    currentDate = dateManager.getDate("CURRENT", "TODAY");

    firstDayOfCurrentMonthDate = dateManager.getDate("CURRENT", "FIRST");

    displayBalance(firstDayOfCurrentMonthDate, currentDate, incomes, expenses);

}

void BalanceManager::displayPreviousMonthBalance(vector <Transactions> &incomes, vector <Transactions> &expenses) {

    int firstDayOfPreviousMonthDate = 0;
    int lastDayOfPreviousMonthDate = 0;

    firstDayOfPreviousMonthDate = dateManager.getDate("PREVIOUS", "FIRST");
    lastDayOfPreviousMonthDate = dateManager.getDate("PREVIOUS", "LAST");

    displayBalance(firstDayOfPreviousMonthDate, lastDayOfPreviousMonthDate, incomes, expenses);

}

void BalanceManager::displaySpecificPeriodBalance(vector <Transactions> &incomes, vector <Transactions> &expenses) {

    int dateBeginning = 0;
    int dateEnd = 0;

    cout << endl << "Insert beginning of desired balance period." << endl;
    dateBeginning = dateManager.getSpecificDateFromUser();
    cout << endl << "Insert end of desired balance period." << endl;
    dateEnd = dateManager.getSpecificDateFromUser();

    displayBalance(dateBeginning, dateEnd, incomes, expenses);

}


void BalanceManager::displayBalance(int beginingDate, int endDate, vector <Transactions> &incomes, vector <Transactions> &expenses) {

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

void BalanceManager::showTransactionsFromOldestToLatest(vector <Transactions> transactions) {

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

double BalanceManager::showSumOfTransactions(vector <Transactions> transactions) {
    double sumOfAmount = 0;

    for(vector <Transactions>::iterator itr = transactions.begin(); itr != transactions.end(); itr++) {
        sumOfAmount = sumOfAmount + itr->getAmount();
    }

    return sumOfAmount;
}

vector <Transactions> BalanceManager::filterTransactions(vector <Transactions> transactions, int beginingDate, int endDate) {
    vector <Transactions> filteredTransactions;

    for(vector <Transactions>::iterator itr = transactions.begin(); itr != transactions.end(); itr++) {

        if(itr->getDate() >= beginingDate && itr->getDate() <= endDate) {
            filteredTransactions.push_back(*itr);
        }
    }

    return filteredTransactions;
}

bool BalanceManager::compareDates(Transactions t1, Transactions t2) {
    return (t1.getDate() < t2.getDate());
}
