#include <iostream>
#include "BudgetApp.h"

using namespace std;

int main() {
    BudgetApp budgetApp("Users.xml", "Incomes.xml", "Expenses.xml", "CurrentMonthExpenses.xml");

    while(true) {

        if(budgetApp.checkIfUserIsLogged() == 0) {
            system("cls");
            budgetApp.displayMainMenu();
            switch(budgetApp.getChosenOptionFromMainMenu()) {

            case '1':
                system("cls");
                budgetApp.userRegistration();
                break;

            case '2':
                system("cls");
                budgetApp.userLogIn();
                break;

            case '3':
                exit(0);
                break;
            }
        } else {
            system("cls");
            budgetApp.displayUsersMenu();

            switch(budgetApp.getChosenOptionFromUsersMenu()) {

            case '1':
                system("cls");
                budgetApp.addIncome();
                break;

            case '2':
                system("cls");
                budgetApp.addExpense();
                break;

            case '3':
                system("cls");
                budgetApp.displayBalance();
                break;

            case '4':
                budgetApp.diplayCurrentMonthExpensesPlan();
                break;

            case '5':
                budgetApp.changeUsersPassword();
                break;

            case '6':
                budgetApp.userLogOut();
                break;
            }
        }
    }

    return 0;
}

