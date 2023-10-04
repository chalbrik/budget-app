#ifndef TRANSACTIONFILE_H
#define TRANSACTIONFILE_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "Transactions.h"

using namespace std;

class TransactionFile : XmlFile {

public:

    TransactionFile(string transactionFileName) : XmlFile(transactionFileName){};

    void addOperationToFile(string transactionName, Transactions transaction);
    void loadOperationFromFile(vector <Transactions> &transactions);

};




#endif
