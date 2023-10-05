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
    double addTransactionsAmount();

    int getCurrentDate();
    int getFirstDayOfCurrentMonthDate();
    int getSpecificDateFromUser();
    bool checkIfADateFitInRequiredPeriod(string date);


    void displayBalance(int beginingDate, int endDate);
    void showTransactionsFromOldestToLatest(vector <Transactions> transactions, int beginingDate, int endDate);
    double showSumOfTransactions(vector <Transactions> transactions); //tutaj trzrba bedzie przekazac zmieniony wektor
    vector <Transactions> filterTransactions(vector <Transactions> transactions, int beginingDate, int endDate);






public:

    BudgetManager(string incomesFileName, string expensesFileName, int loggedUserId) : incomeFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId) {

        incomeFile.loadOperationFromFile(incomes, LOGGED_USER_ID);

        expensesFile.loadOperationFromFile(expenses, LOGGED_USER_ID);
    };
    void addIncome();
    void addExpense();

    void displayBalanceMenu();

    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodBalance();



};



#endif
