#include "MonthlyExpensesManager.h"


void MonthlyExpensesManager::diplayCurrentMonthExpensesPlan(vector <Transactions> incomes, vector <Transactions> expenses) {

    double currentMonthIncome = 0;

    double amountToSpendDuringMonth = 0;

    double amountOfMoneyToSpentInEveryWeek = 0;

    int numberOfWeeksLeftToNextPaycheck = 0;
    int restOfDaysLeftToNextPaycheck = 0;

    currentMonthIncome = getCurrentMonthIncome(incomes);
    paycheckDay = getPaycheckDayFromUser();
    currentMonthSavings = askForCurrentMonthSavings();


    system("cls");
    cout << ">>> EXPENSES PLAN FOR CURRENT MONTH <<<" << endl << endl;


    cout << "Current month income: " << currentMonthIncome << " pln." << endl << endl;

    amountToSpendDuringMonth = currentMonthIncome - currentMonthSavings;
    amountOfMoneyToSpentInEveryWeek = amountToSpendDuringMonth / NUMBER_OF_WEEKS_IN_MONTH;

    cout << "Amount of money available to spend for current month - " << amountToSpendDuringMonth << " pln" << endl;
    cout << "Amount of money to spend in each remaining week - " << amountOfMoneyToSpentInEveryWeek << " pln" << endl << endl;

    daysLeftToNextPaycheck = calculateHowManyDaysToNextPaycheck();
    numberOfWeeksLeftToNextPaycheck = daysLeftToNextPaycheck / NUMBER_OF_DAYS_IN_WEEK;
    restOfDaysLeftToNextPaycheck = daysLeftToNextPaycheck % NUMBER_OF_DAYS_IN_WEEK;

    cout << "There are " << daysLeftToNextPaycheck << " days / " << numberOfWeeksLeftToNextPaycheck << " weeks and " << restOfDaysLeftToNextPaycheck << " days till the next paycheck." << endl << endl;

// trzeba napisaæ ile juz wyda³em w tym miesi¹cu

    sumOfCurrentMonthExpenses = getSumOfCurrentMonthExpenses(expenses);

    cout << "You already spent " << sumOfCurrentMonthExpenses << " pln this month." << endl;


    cout << endl << endl;
    system("pause");


}

//prywatne

double MonthlyExpensesManager::getCurrentMonthIncome(vector <Transactions> incomes) {

    double incomeAmount = 0;

    for(vector <Transactions>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(itr->getItem() == "Salary") {//tu jeszcze trzeba dodaæ warunek ze z tego miesi¹ca
            incomeAmount = itr->getAmount();
        }
    }

    return incomeAmount;
}

double MonthlyExpensesManager::getSumOfCurrentMonthExpenses(vector <Transactions> expenses) {

    double calculatedSumOfCurrentMonthExpenses = 0;
    vector <Transactions> filteredExpenses;

    int firstDayOfCurrentMonthDate = 0;
    int currentDate = 0;

    currentDate = dateMethods.getDate(CURRENT, TODAY);

    firstDayOfCurrentMonthDate = dateMethods.getDate(CURRENT, FIRST);

    filteredExpenses = balanceManagerMethods.filterTransactions(expenses, firstDayOfCurrentMonthDate, currentDate);

    calculatedSumOfCurrentMonthExpenses = balanceManagerMethods.showSumOfTransactions(filteredExpenses);

    return calculatedSumOfCurrentMonthExpenses;

}


double MonthlyExpensesManager::askForCurrentMonthSavings() {
    string strGivenCurrentMonthSavings = "";
    double givenCurrentMonthSavings = 0;

    system("cls");
    cout << "How much savings would you like to save this month? - ";

    strGivenCurrentMonthSavings = HelpMethods::readLine();
    givenCurrentMonthSavings = HelpMethods::convertStringToDouble(strGivenCurrentMonthSavings);

    return givenCurrentMonthSavings;
}

int MonthlyExpensesManager::getPaycheckDayFromUser() {
    string strPaycheckDay = "";
    int paycheckDay = 0;

    system("cls");
    cout << "Type your paycheck day - ";
    strPaycheckDay = HelpMethods::readLine();
    paycheckDay = HelpMethods::convertStringToInt(strPaycheckDay);

    return paycheckDay;

}

int MonthlyExpensesManager::calculateHowManyDaysToNextPaycheck() {

    int thirtyOneDayMonths[7] = {1, 3, 5, 7, 8, 10, 12};
    int numberOfElementsThirtyOneDayMonths = sizeof(thirtyOneDayMonths)/sizeof(thirtyOneDayMonths[0]); // mo¿e mozna to zamieniæ na vektory i szybciej je przegl¹daæ
    int thirtyDayMonths[4] = {4, 6, 9, 11};
    int numberOfElementsThirtyDayMonths = sizeof(thirtyDayMonths)/sizeof(thirtyDayMonths[0]);

    int currentDate = 0;

    string strCurrentDate = "";
    string strCurrentMonth = "";
    int currentMonth = 0;
    string strCurrentDay = "";
    int currentDay = 0;

    int daysLeftToEndOfTheMonth = 0;

    int howManyDaysToNextPaycheck = 0;

    currentDate = dateMethods.getDate(CURRENT, TODAY);

    strCurrentDate = HelpMethods::convertIntToString(currentDate);

    strCurrentMonth = strCurrentDate.substr(4,2);
    strCurrentDay = strCurrentDate.substr(6,2);

    currentMonth = HelpMethods::convertStringToInt(strCurrentMonth);

    currentDay = HelpMethods::convertStringToInt(strCurrentDay);

    for(int i = 0; i < numberOfElementsThirtyDayMonths; i++) {
        if(currentMonth == thirtyDayMonths[i]) {
            daysLeftToEndOfTheMonth = 30 - currentDay;
        }
    }

    for(int i = 0; i < numberOfElementsThirtyOneDayMonths; i++) {
        if(currentMonth == thirtyOneDayMonths[i]) {
            daysLeftToEndOfTheMonth = 31 - currentDay;
        }
    }

    howManyDaysToNextPaycheck = daysLeftToEndOfTheMonth + 10;

    return howManyDaysToNextPaycheck;
}

