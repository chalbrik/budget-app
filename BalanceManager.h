#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Transactions.h"
#include "DateMethods.h"
#include "HelpMethods.h"

using namespace std;

class BalanceManager {

    //vector <Transactions> transactions;

    DateMethods dateMethods;

    void displayCurrentMonthBalance(vector <Transactions> &incomes, vector <Transactions> &expenses);
    void displayPreviousMonthBalance(vector <Transactions> &incomes, vector <Transactions> &expenses);
    void displaySpecificPeriodBalance(vector <Transactions> &incomes, vector <Transactions> &expenses);

    void displayBalance(int beginingDate, int endDate, vector <Transactions> &incomes, vector <Transactions> &expenses);
    void showTransactionsFromOldestToLatest(vector <Transactions> transactions);
    double showSumOfTransactions(vector <Transactions> transactions);
    vector <Transactions> filterTransactions(vector <Transactions> transactions, int beginingDate, int endDate);

    static bool compareDates(Transactions t1, Transactions t2);

public:

    BalanceManager(){};

    void displayBalanceMenu(vector <Transactions> incomes, vector <Transactions> expenses);

};






#endif
