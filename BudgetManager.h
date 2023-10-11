#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include "UserManager.h"
#include "TransactionFile.h"
#include "Transactions.h"
#include "DateManager.h"
#include "BalanceManager.h"
#include "HelpMethods.h"


using namespace std;

class BudgetManager {

    const int LOGGED_USER_ID;

    TransactionFile incomeFile;
    vector <Transactions> incomes;

    TransactionFile expensesFile;
    vector <Transactions> expenses;

    TransactionFile currentMonthExpensesFile;
    vector <Transactions> currentMonthExpenses;

    double currentMonthSavings;

    DateManager dateManager;
    BalanceManager balanceManager;

    void addTransaction(string transactionName, string transactionTag, vector <Transactions> transactions, TransactionFile transactionFile);
    int addTransactionsDate(string transactionType);
    string addTransactionsCategory(string transactionTag);
    double addTransactionsAmount(string transactionName);

    double getCurrentMonthIncome();


public:

    BudgetManager(int loggedUserId, string incomesFileName, string expensesFileName, string currentMonthExpensesFileName) : LOGGED_USER_ID(loggedUserId), incomeFile(incomesFileName), expensesFile(expensesFileName), currentMonthExpensesFile(currentMonthExpensesFileName) {

        incomeFile.loadOperationFromFile(incomes, LOGGED_USER_ID, "INCOME");

        expensesFile.loadOperationFromFile(expenses, LOGGED_USER_ID, "EXPENSE");

        currentMonthExpensesFile.loadOperationFromFile(currentMonthExpenses, LOGGED_USER_ID, "CURRENT_MONTH_EXPENSES_FILE");

    };
    void addIncome();
    void addExpense();

    void displayBalanceMenu();

    void diplayCurrentMonthExpensesPlan();



};



#endif
