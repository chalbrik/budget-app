#include <iostream>
#include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("Users.txt");

    budgetApp.userRegistration();

    return 0;
}
