#include "BudgetManager.h"

void BudgetManager::addIncome() {

    setTransactionTag(INCOME);

    addTransaction(incomes, incomeFile);
}

void BudgetManager::addExpense() {

    setTransactionTag(EXPENSE);

    addTransaction(expenses, expensesFile);
}

void BudgetManager::displayBalanceMenu() {
    balanceManager.displayBalanceMenu(incomes, expenses);
}


void BudgetManager::diplayCurrentMonthExpensesPlan() {
    monthlyExpensesManager.diplayCurrentMonthExpensesPlan(incomes);
}


// private

void BudgetManager::addTransaction(vector <Transactions> &transactions, TransactionFile transactionFile) {
    Transactions transaction;

    int dateOfATransaction = 0;
    string item = "";
    double amount = 0;

    cout << ">>> ADD " << HelpMethods::getTransactionType(transactionTag) << " <<<" << endl << endl;


    dateOfATransaction = addTransactionsDate();
    item = addTransactionsCategory();
    amount = addTransactionsAmount();

    transaction.setUserId(LOGGED_USER_ID);

    transactions.size() == 0 ? transaction.setTransactionId(1) : transaction.setTransactionId(transactions.back().getTransactionId() + 1); //setting transactionsId
    transaction.setDate(dateOfATransaction);
    transaction.setItem(item);
    transaction.setAmount(amount);

    transactions.push_back(transaction);

    transactionFile.addOperationToFile(transactionTag, transaction);
}

int BudgetManager::addTransactionsDate() {
    char chooseOption;

    int dateOfATransaction = 0;

    cout << "1 - Would you like to add " + HelpMethods::getTransactionType(transactionTag) + " with today's date?" << endl;
    cout << "2 - Would you like to add " + HelpMethods::getTransactionType(transactionTag) + " with different date?" << endl;

    cout << endl << "Option: ";

    chooseOption = HelpMethods::getCharacter();

    switch(chooseOption) {
    case '1':
        dateOfATransaction = dateMethods.getDate(CURRENT, TODAY);
        break;
    case '2':
        dateOfATransaction = dateMethods.getSpecificDateFromUser();
        break;
    }
    return dateOfATransaction;
}

string BudgetManager::addTransactionsCategory() {

    char chooseOption;
    string item = "";

    string transactionType = "";

    system("cls");
    cout << "Pick category of your transaction." << endl << endl;

    if(transactionTag == INCOME) {
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

    } else if(transactionTag == EXPENSE) {

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

double BudgetManager::addTransactionsAmount() {
    string strAmount = "";
    double amount = 0;

    do {
        system("cls");

        cout << "What is an amount of your " << HelpMethods::getTransactionType(transactionTag) << "?" << endl;
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

void BudgetManager::setTransactionTag(TransactionTag newTag) {
    transactionTag = newTag;
}

void BudgetManager::setMonthTag(MonthTag newTag) {
    monthTag = newTag;
}



