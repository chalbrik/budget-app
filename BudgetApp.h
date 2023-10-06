#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetApp {

    UserManager userManager;
    BudgetManager* budgetManager;

    char chosenOptionFromMainMenu;

public:

    BudgetApp(string userFileName) : userManager(userFileName) {
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

    void changeUsersPassword();
    void userLogOut();

};

#endif
