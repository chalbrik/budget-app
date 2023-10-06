#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class BudgetApp {

    UserManager userManager;

public:

    BudgetApp(string userFileName) : userManager(userFileName) {};

    void userRegistration();
    void userLogIn();

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodBalance();

    void changePassword();
    void LogOut();

};

#endif
