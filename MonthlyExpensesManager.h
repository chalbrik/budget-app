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

    const int NUMBER_OF_DAYS_IN_WEEK;
    const int NUMBER_OF_WEEKS_IN_MONTH;

    DateMethods dateMethods;
    BalanceManager balanceManagerMethods;

    int paycheckDay;
    int daysLeftToNextPaycheck;
    double currentMonthSavings;
    double sumOfCurrentMonthExpenses;

    double getCurrentMonthIncome(vector <Transactions> incomes);
    double getSumOfCurrentMonthExpenses(vector <Transactions> expenses);
    double askForCurrentMonthSavings();

    int getPaycheckDayFromUser();
    int calculateHowManyDaysToNextPaycheck();


public:
    MonthlyExpensesManager(int numberOfDaysInWeek = 7, int numberOfWeeksInMonth = 4) : NUMBER_OF_DAYS_IN_WEEK(numberOfDaysInWeek), NUMBER_OF_WEEKS_IN_MONTH(numberOfWeeksInMonth) {};

    void diplayCurrentMonthExpensesPlan(vector <Transactions> incomes, vector <Transactions> expenses);


};


#endif
