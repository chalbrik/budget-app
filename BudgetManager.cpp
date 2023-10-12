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

    cout << endl << "Amount of money available to spend for current month: " << amountToSpendDuringMonth << endl;

    //trzeba obliczy� ile zosta�o do pocz�tku nast�pnej wyp�aty
    //pokaz ile tygodni zosta�o do nast�pnej wyp�aty

    cout << "There are ... days / ... weeks till the next paycheck." << endl << endl;

    // musze pobra� dzisiejsz� dat�

    //dateMethods.getDate();

    //musz� ustawi� date wyp�aty
    //i obliczy� ile dni jest do kolejnej wyp�aty

    cout << "Amount of money to spend in each remaining week - ..." << endl;




    cout << endl << endl;
    system("pause");

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

double BudgetManager::getCurrentMonthIncome() {

    double incomeAmount = 0;

    for(vector <Transactions>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(itr->getItem() == "Salary") {
            incomeAmount = itr->getAmount();
        }
    }

    return incomeAmount;
}

void BudgetManager::setTransactionTag(TransactionTag newTag) {
    transactionTag = newTag;
}

void BudgetManager::setMonthTag(MonthTag newTag) {
    monthTag = newTag;
}



