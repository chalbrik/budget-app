#include <iostream>
#include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("Users.xml");

    budgetApp.userRegistration();

    return 0;
}
