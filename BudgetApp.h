#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetApp {

    UserManager userManager;
    BudgetManager* budgetManager;

    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
    const string CURRENT_MONTH_FINANCES;

    char chosenOptionFromMainMenu;

public:

    BudgetApp(string userFileName, string incomesFileName, string expensesFileName, string currentMonthFinancesFileName) : userManager(userFileName),
        INCOMES_FILE_NAME(incomesFileName),
        EXPENSES_FILE_NAME(expensesFileName),
        CURRENT_MONTH_FINANCES(currentMonthFinancesFileName) {
        chosenOptionFromMainMenu = 0;
        budgetManager = NULL;
    };

    ~BudgetApp() {
        delete budgetManager;
        budgetManager = NULL;
    }

    void displayMainMenu();
    void displayUsersMenu();
    bool checkIfUserIsLogged();
    char getChosenOptionFromMainMenu();
    char getChosenOptionFromUsersMenu();

    void userRegistration();
    void userLogIn();

    void addIncome();
    void addExpense();

    void displayBalance();

    void diplayCurrentMonthExpensesPlan();

    void changeUsersPassword();
    void userLogOut();

};

#endif
