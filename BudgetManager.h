#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include "UserManager.h"
#include "TransactionFile.h"
#include "Transactions.h"
#include "HelpMethods.h"


using namespace std;

class BudgetManager{

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
    int getSpecificDateFromUser();
    bool checkIfADateFitInRequiredPeriod(string date);


public:

    BudgetManager(string incomesFileName, string expensesFileName, int loggedUserId) : incomeFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId) {

    incomeFile.loadOperationFromFile(incomes);

    expensesFile.loadOperationFromFile(expenses);
    };
    void addIncome();
    void addExpense();

    void displayBalance();

    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodBalance();


};











#endif
