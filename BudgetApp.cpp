#include "BudgetApp.h"
#include "HelpMethods.h"


void BudgetApp::displayMainMenu() {
    cout << ">>> BUDGET APP <<<" << endl << endl;

    cout << "1 - Registration" << endl;
    cout << "2 - Log in" << endl;
    cout << "3 - Close application" << endl;

    cout << endl << "Option: ";

    chosenOptionFromMainMenu = HelpMethods::getCharacter();

}

void BudgetApp::displayUsersMenu() {
    userManager.displayUsersMenu();
}

bool BudgetApp::checkIfUserIsLogged() {
    return userManager.checkIfUserIsLogged();
}

char BudgetApp::getChosenOptionFromMainMenu() {
    return chosenOptionFromMainMenu;
}

char BudgetApp::getChosenOptionFromUsersMenu() {
    return userManager.getChosenOptionFromUsersMenu();
}

void BudgetApp::userRegistration() {
    userManager.userRegistration();

}

void BudgetApp::userLogIn() {
    userManager.userLogIn();
    if(userManager.checkIfUserIsLogged()) {
        budgetManager = new BudgetManager("Incomes.xml", "Expenses.xml", userManager.getLoggedUsersId());
    }
}

void BudgetApp::addIncome() {
    budgetManager->addIncome();
}

void BudgetApp::addExpense() {
    budgetManager->addExpense();
}

void BudgetApp::displayBalance()
{
    budgetManager->displayBalanceMenu();
}

void BudgetApp::changeUsersPassword()
{
    userManager.changeUsersPassword();
}

void BudgetApp::userLogOut() {
    userManager.userLogOut();
}

