#ifndef HELPMETHODS_H
#define HELPMETHODS_H

#include <iostream>
#include <sstream>

#include "Enums.h"



using namespace std;

class HelpMethods {

public:

    static string readLine();

    static char getCharacter();

    static string convertIntToString(int number);

    static int convertStringToInt(string number);

    static double convertStringToDouble(string number);

    static string changeCommaToDot(string input);

    static bool checkIfNumber(string input);

    static string getTransactionType(TransactionTag transactionTag);

};



#endif
