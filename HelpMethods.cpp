#include "HelpMethods.h"


string HelpMethods::readLine() {
    string input = "";
    getline(cin, input);
    return input;
}

char HelpMethods::getCharacter() {
    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Try again." << endl;
    }
    return character;
}

string HelpMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int HelpMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double HelpMethods::convertStringToDouble(string number)
{
    double numberDouble;
    numberDouble = stod(number);
    return numberDouble;
}

void HelpMethods::changeCommaToDot(string input)
{
    for(size_t i = 0; i < input.size(); i++)
    {
        if(input[i] == ',')
        {
           input.replace(i, 1, ".");
        }
    }
}

