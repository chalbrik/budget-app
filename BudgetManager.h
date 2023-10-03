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

    int addTransactionsDate(string transactionType);
    string addTransactionsCategory();
    double addTransactionsAmount();

    int getCurrentDate();
    int getSpecificDateFromUser();
    bool checkIfADateFitInRequiredPeriod(string date);


public:

    BudgetManager(string incomesFileName, string expensesFileName, int loggedUserId) : incomeFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId) {};
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodBalance();


};











#endif
