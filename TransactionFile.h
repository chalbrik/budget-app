#ifndef TRANSACTIONFILE_H
#define TRANSACTIONFILE_H

#include <iostream>
#include "XmlFile.h"
#include "Transactions.h"

using namespace std;

class TransactionFile : XmlFile {

public:

    TransactionFile(string transactionFileName) : XmlFile(transactionFileName){};

    void addOperationToFile(Transactions transaction);
    void loadOperationFromFile();

};




#endif
