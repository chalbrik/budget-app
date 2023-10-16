#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include "UserManager.h"
#include "TransactionFile.h"
#include "MonthlyExpensesManager.h"
#include "Transactions.h"
#include "DateMethods.h"
#include "BalanceManager.h"
#include "HelpMethods.h"
#include "Enums.h"


using namespace std;

class BudgetManager {

    const int LOGGED_USER_ID;

    TransactionTag transactionTag;
    MonthTag monthTag;

    TransactionFile incomeFile;
    vector <Transactions> incomes;

    TransactionFile expensesFile;
    vector <Transactions> expenses;

    TransactionFile currentMonthFinancesFile;
    vector <Transactions> currentMonthFinances;

    DateMethods dateMethods;
    BalanceManager balanceManager;
    MonthlyExpensesManager monthlyExpensesManager;

    void addTransaction(vector <Transactions> &transactions, TransactionFile transactionFile);
    int addTransactionsDate();
    string addTransactionsCategory();
    double addTransactionsAmount();

    string getTransactionType();

    void setTransactionTag(TransactionTag newTag);
    void setMonthTag(MonthTag newTag);




public:

    BudgetManager(int loggedUserId, string incomesFileName, string expensesFileName, string currentMonthFinancesFileName) : LOGGED_USER_ID(loggedUserId),
        incomeFile(incomesFileName),
        expensesFile(expensesFileName),
        currentMonthFinancesFile(currentMonthFinancesFileName) {

        incomeFile.loadOperationFromFile(incomes, LOGGED_USER_ID, "INCOME");

        expensesFile.loadOperationFromFile(expenses, LOGGED_USER_ID, "EXPENSE");

        currentMonthFinancesFile.loadOperationFromFile(currentMonthFinances, LOGGED_USER_ID, "CURRENT_MONTH_EXPENSES_FILE");

    };

    void addIncome();
    void addExpense();

    void displayBalanceMenu();

    void diplayCurrentMonthExpensesPlan();





};



#endif
