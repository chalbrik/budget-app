#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include <bits/stdc++.h>
#include "UserManager.h"
#include "TransactionFile.h"
#include "Transactions.h"
#include "HelpMethods.h"


using namespace std;

class BudgetManager {

    const int LOGGED_USER_ID;

    TransactionFile incomeFile;
    vector <Transactions> incomes;

    TransactionFile expensesFile;
    vector <Transactions> expenses;

    void addTransaction(string transactionName, string transactionTag, vector <Transactions> transactions, TransactionFile transactionFile);
    int addTransactionsDate(string transactionType);
    string addTransactionsCategory(string transactionTag);
    double addTransactionsAmount(string transactionName);

    int getDate(string monthTag, string dayTag);
    int getFirstDayOfCurrentMonthDate();
    int getSpecificDateFromUser();
    bool checkIfADateFitInRequiredPeriod(string date);


    void displayBalance(int beginingDate, int endDate);
    void showTransactionsFromOldestToLatest(vector <Transactions> transactions);
    double showSumOfTransactions(vector <Transactions> transactions);
    vector <Transactions> filterTransactions(vector <Transactions> transactions, int beginingDate, int endDate);


public:

    BudgetManager(int loggedUserId, string incomesFileName, string expensesFileName) : LOGGED_USER_ID(loggedUserId), incomeFile(incomesFileName), expensesFile(expensesFileName){

        incomeFile.loadOperationFromFile(incomes, LOGGED_USER_ID, "INCOME");

        expensesFile.loadOperationFromFile(expenses, LOGGED_USER_ID, "EXPENSE");
    };
    void addIncome();
    void addExpense();

    void displayBalanceMenu();

    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodBalance();



};



#endif
