#ifndef TRANSACTIONFILE_H
#define TRANSACTIONFILE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "XmlFile.h"
#include "Transactions.h"
#include "HelpMethods.h"
#include "Enums.h"


using namespace std;

class TransactionFile : XmlFile {

    //TransactionTag transactionTag;

public:

    TransactionFile(string transactionFileName) : XmlFile(transactionFileName){};

    void addOperationToFile(TransactionTag transactionTag, Transactions transaction);
    void loadOperationFromFile(vector <Transactions> &transactions, int loggedUserId, string transactionTag);

};




#endif
