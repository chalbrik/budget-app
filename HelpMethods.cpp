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

string HelpMethods::changeCommaToDot(string input)
{
    string output;

    for(size_t i = 0; i < input.size(); i++)
    {
        if(input[i] == ',')
        {
           input.replace(i, 1, ".");
        }

        output.push_back(input[i]);
    }

    return output;
}

bool HelpMethods::checkIfNumber(string input)
{
    double number;
    return (istringstream(input) >> number >> ws).eof();
}

string HelpMethods::getTransactionType(TransactionTag transactionTag) {
    string transactionType = "";

    switch(transactionTag) {
    case INCOME:
        transactionType = "INCOME";
        break;
    case EXPENSE:
        transactionType = "EXPENSE";
        break;
    }

    return transactionType;
}


