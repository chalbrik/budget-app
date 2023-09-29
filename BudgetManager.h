#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "TransactionFile.h"
#include "Transactions.h"


using namespace std;

class BudgetManager{

    TransactionFile incomeFile;
    vector <Transactions> incomes;

    TransactionFile expensesFile;
    vector <Transactions> expenses;

public:

    BudgetManager();
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodBalance();


};











#endif
