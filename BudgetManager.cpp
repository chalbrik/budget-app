#include "BudgetManager.h"

void BudgetManager::addIncome() {

    addTransaction("income", "INCOME", incomes, incomeFile);
}

void BudgetManager::addExpense() {

    addTransaction("expense", "EXPENSE", expenses, expensesFile);
}

void BudgetManager::displayBalanceMenu() {
    char chooseOption;

    system("cls");

    cout << ">>> DISPLAY BALANCE ACCOUNT <<<" << endl << endl;
    cout << "1 - Display current month balance" << endl;
    cout << "2 - Display previous month balance" << endl;
    cout << "3 - Choose period to display balance" << endl;

    cout << endl << "Option: ";

    chooseOption = HelpMethods::getCharacter();

    switch(chooseOption) {
    case '1':
        displayCurrentMonthBalance();
        break;
    case '2':
        displayPreviousMonthBalance();
        break;
    case '3':
        displaySpecificPeriodBalance();
        break;
    }
}

void BudgetManager::displayCurrentMonthBalance() {

    int firstDayOfCurrentMonthDate = 0;
    int currentDate = 0;

    currentDate = dateManager.getDate("CURRENT", "TODAY");

    firstDayOfCurrentMonthDate = dateManager.getDate("CURRENT", "FIRST");

    balanceManager.displayBalance(firstDayOfCurrentMonthDate, currentDate, incomes, expenses);

}

void BudgetManager::displayPreviousMonthBalance() {

    int firstDayOfPreviousMonthDate = 0;
    int lastDayOfPreviousMonthDate = 0;

    firstDayOfPreviousMonthDate = dateManager.getDate("PREVIOUS", "FIRST");
    lastDayOfPreviousMonthDate = dateManager.getDate("PREVIOUS", "LAST");

    balanceManager.displayBalance(firstDayOfPreviousMonthDate, lastDayOfPreviousMonthDate, incomes, expenses);

}

void BudgetManager::displaySpecificPeriodBalance() {

    int dateBeginning = 0;
    int dateEnd = 0;

    cout << endl << "Insert beginning of desired balance period." << endl;
    dateBeginning = dateManager.getSpecificDateFromUser();
    cout << endl << "Insert end of desired balance period." << endl;
    dateEnd = dateManager.getSpecificDateFromUser();

    balanceManager.displayBalance(dateBeginning, dateEnd, incomes, expenses);

}

void BudgetManager::diplayCurrentMonthExpensesPlan() {
    double currentMonthIncome = 0;

    string strCurrentMonthExpenses = "";
    double currentMonthExpenses = 0;

    string strCurrentMonthSavings = "";
    double amountToSpendDuringMonth = 0;

    system("cls");
    cout << ">>> EXPENSES PLAN FOR CURRENT MONTH <<<" << endl << endl;

    currentMonthIncome = getCurrentMonthIncome();

    cout << "Current month income: " << currentMonthIncome << " pln." << endl << endl;

    cout << "How much savings would you like to save this month?" << endl;
    cout << "Amount of savings: ";

    strCurrentMonthSavings = HelpMethods::readLine();
    currentMonthSavings = HelpMethods::convertStringToDouble(strCurrentMonthSavings);

    amountToSpendDuringMonth = currentMonthIncome - currentMonthSavings;

    cout << "Amount of money available to spend for current month: " << amountToSpendDuringMonth << endl;







    cout << endl << endl;
    system("pause");

}

// private

void BudgetManager::addTransaction(string transactionName, string transactionTag, vector <Transactions> transactions, TransactionFile transactionFile) {
    Transactions transaction;

    int dateOfATransaction = 0;
    string item = "";
    double amount = 0;

    cout << ">>> ADD " << transactionTag << " <<<" << endl << endl;

    dateOfATransaction = addTransactionsDate(transactionName);
    item = addTransactionsCategory(transactionTag);
    amount = addTransactionsAmount(transactionName);

    transaction.setUserId(LOGGED_USER_ID);

    transactions.size() == 0 ? transaction.setTransactionId(1) : transaction.setTransactionId(transactions.back().getTransactionId() + 1); //setting transactionsId
    transaction.setDate(dateOfATransaction);
    transaction.setItem(item);
    transaction.setAmount(amount);

    transactions.push_back(transaction);

    transactionFile.addOperationToFile(transactionTag, transaction);
}

int BudgetManager::addTransactionsDate(string transactionType) {
    char chooseOption;

    int dateOfATransaction = 0;

    cout << "1 - Would you like to add " + transactionType + " with today's date?" << endl;
    cout << "2 - Would you like to add " + transactionType + " with different date?" << endl;

    cout << endl << "Option: ";

    chooseOption = HelpMethods::getCharacter();

    switch(chooseOption) {
    case '1':
        dateOfATransaction = dateManager.getDate("CURRENT", "TODAY");
        break;
    case '2':
        dateOfATransaction = dateManager.getSpecificDateFromUser();
        break;
    }
    return dateOfATransaction;
}

string BudgetManager::addTransactionsCategory(string transactionTag) {

    char chooseOption;
    string item = "";

    system("cls");
    cout << "Pick category of your transaction." << endl << endl;

    if(transactionTag == "INCOME") {
        cout << "1 - salary" << endl;
        cout << "2 - sale" << endl;
        cout << "3 - repayment" << endl;

        cout << endl << "Option: ";

        chooseOption = HelpMethods::getCharacter();

        switch(chooseOption) {
        case '1':
            item = "Salary";
            break;
        case '2':
            item = "Sale";
            break;
        case '3':
            item = "Repayment";
            break;
        }

    } else if(transactionTag == "EXPENSE") {

        cout << "1 - Food" << endl;
        cout << "2 - Transportation" << endl;
        cout << "3 - Rent" << endl;

        cout << endl << "Option: ";

        chooseOption = HelpMethods::getCharacter();

        switch(chooseOption) {
        case '1':
            item = "Food";
            break;
        case '2':
            item = "Transportation";
            break;
        case '3':
            item = "Rent";
            break;
        }
    }

    return item;
}

double BudgetManager::addTransactionsAmount(string transactionName) {
    string strAmount = "";
    double amount = 0;

    do {
        system("cls");

        cout << "What is an amount of your " << transactionName << "?" << endl;
        cout << endl << "Type amount: ";

        strAmount = HelpMethods::readLine();
        strAmount = HelpMethods::changeCommaToDot(strAmount);

        if(!HelpMethods::checkIfNumber(strAmount)) {
            cout << endl << "This is not a number. Try again." << endl << endl;
            system("pause");
        }

    } while(!HelpMethods::checkIfNumber(strAmount));

    amount = HelpMethods::convertStringToDouble(strAmount);

    return amount;

}


double BudgetManager::getCurrentMonthIncome() {
    for(vector <Transactions>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(itr->getItem() == "Salary") {
            return itr->getAmount();
        }
    }

    return 0;
}



