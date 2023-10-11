#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Transactions.h"

using namespace std;

class BalanceManager {

    //vector <Transactions> transactions;

    static bool compareDates(Transactions t1, Transactions t2);

    public:

    void displayBalance(int beginingDate, int endDate, vector <Transactions> incomes, vector <Transactions> expenses);
    void showTransactionsFromOldestToLatest(vector <Transactions> transactions);
    double showSumOfTransactions(vector <Transactions> transactions);
    vector <Transactions> filterTransactions(vector <Transactions> transactions, int beginingDate, int endDate);

};






#endif
