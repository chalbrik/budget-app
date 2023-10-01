#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include "TransactionFile.h"
#include "Transactions.h"
#include "HelpMethods.h"


using namespace std;

class BudgetManager{

    TransactionFile incomeFile;
    vector <Transactions> incomes;

    TransactionFile expensesFile;
    vector <Transactions> expenses;

    int getCurrentDate();


public:

    BudgetManager(string incomesFileName, string expensesFileName) : incomeFile(incomesFileName), expensesFile(expensesFileName) {};
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodBalance();


};











#endif
