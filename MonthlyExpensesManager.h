#ifndef MONTHLYEXPENSESMANAGER_H
#define MONTHLYEXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include "DateMethods.h"
#include "BalanceManager.h"
#include "HelpMethods.h"
#include "Transactions.h"
#include "Enums.h"

using namespace std;


class MonthlyExpensesManager {

    DateMethods dateMethods;

    int paycheckDay;
    int daysLeftToNextPaycheck;
    double currentMonthSavings;

    double getCurrentMonthIncome(vector <Transactions> incomes);

    int getPaycheckDayFromUser();
    int calculateHowManyDaysToNextPaycheck();


public:

    void diplayCurrentMonthExpensesPlan(vector <Transactions> incomes);


};


#endif
