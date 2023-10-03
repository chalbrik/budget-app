#ifndef HELPMETHODS_H
#define HELPMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class HelpMethods {

public:

    static string readLine();

    static char getCharacter();

    static string convertIntToString(int number);

    static int convertStringToInt(string number);

    static double convertStringToDouble(string number);

    static void changeCommaToDot(string input);


};











#endif
