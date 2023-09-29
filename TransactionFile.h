#ifndef TRANSACTIONFILE_H
#define TRANSACTIONFILE_H

#include <iostream>
#include "XmlFile.h"

using namespace std;

class TransactionFile : XmlFile {

public:

    TransactionFile();

    addOperationToFile();
    loadOperationFromFile();

};




#endif
