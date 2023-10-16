#include "MonthlyExpensesManager.h"


void MonthlyExpensesManager::diplayCurrentMonthExpensesPlan(vector <Transactions> incomes) {

    double currentMonthIncome = 0;

    string strCurrentMonthExpenses = "";
    double currentMonthExpenses = 0;

    string strCurrentMonthSavings = "";
    double amountToSpendDuringMonth = 0;

    system("cls");
    cout << ">>> EXPENSES PLAN FOR CURRENT MONTH <<<" << endl << endl;

    // tu funkcjonalnośc w której trzeba podać datę wypłaty

    paycheckDay = getPaycheckDayFromUser();

    currentMonthIncome = getCurrentMonthIncome(incomes);

    cout << "Current month income: " << currentMonthIncome << " pln." << endl << endl;

    cout << "How much savings would you like to save this month?" << endl;
    cout << "Amount of savings: ";

    strCurrentMonthSavings = HelpMethods::readLine();
    currentMonthSavings = HelpMethods::convertStringToDouble(strCurrentMonthSavings);

    amountToSpendDuringMonth = currentMonthIncome - currentMonthSavings;

    cout << endl << "Amount of money available to spend for current month: " << amountToSpendDuringMonth << endl;

    daysLeftToNextPaycheck = calculateHowManyDaysToNextPaycheck();

    //trzeba obliczyæ ile zosta³o do pocz¹tku nastêpnej wyp³aty
    //pokaz ile tygodni zosta³o do nastêpnej wyp³aty

    cout << "There are " << daysLeftToNextPaycheck << " days / ... weeks till the next paycheck." << endl << endl;

    // musze pobraæ dzisiejsz¹ datê

    //dateMethods.getDate();

    //muszê ustawiæ date wyp³aty
    //i obliczyæ ile dni jest do kolejnej wyp³aty

    cout << "Amount of money to spend in each remaining week - ..." << endl;




    cout << endl << endl;
    system("pause");


}

//prywatne

double MonthlyExpensesManager::getCurrentMonthIncome(vector <Transactions> incomes) {

    double incomeAmount = 0;

    for(vector <Transactions>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(itr->getItem() == "Salary") {
            incomeAmount = itr->getAmount();
        }
    }

    return incomeAmount;
}

int MonthlyExpensesManager::getPaycheckDayFromUser() {
    string strPaycheckDay = "";
    int paycheckDay = 0;

    cout << "Type your paycheck day: " << endl;
    strPaycheckDay = HelpMethods::readLine();
    paycheckDay = HelpMethods::convertStringToInt(strPaycheckDay);

    return paycheckDay;

}

int MonthlyExpensesManager::calculateHowManyDaysToNextPaycheck() {

    int thirtyOneDayMonths[7] = {1, 3, 5, 7, 8, 10, 12};
    int numberOfElementsThirtyOneDayMonths = sizeof(thirtyOneDayMonths)/sizeof(thirtyOneDayMonths[0]); // może mozna to zamienić na vektory i szybciej je przeglądać
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
            daysLeftToEndOfTheMonth = 30 - currentDay;
        }
    }

    howManyDaysToNextPaycheck = daysLeftToEndOfTheMonth + 10;

    return howManyDaysToNextPaycheck;
}
