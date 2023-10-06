#ifndef TRANSACTIONFILE_H
#define TRANSACTIONFILE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "XmlFile.h"
#include "Transactions.h"
#include "HelpMethods.h"

using namespace std;

class TransactionFile : XmlFile {

public:

    TransactionFile(string transactionFileName) : XmlFile(transactionFileName){};

    void addOperationToFile(string transactionName, Transactions transaction);
    void loadOperationFromFile(vector <Transactions> &transactions, int loggedUserId, string transactionTag);

};




#endif
