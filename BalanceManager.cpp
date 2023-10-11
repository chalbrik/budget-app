#include "BalanceManager.h"


void BalanceManager::displayBalance(int beginingDate, int endDate, vector <Transactions> incomes, vector <Transactions> expenses) {

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
