#include "TransactionFile.h"

void TransactionFile::addOperationToFile(string transactionTag, Transactions transaction)
{
    xmlFile.AddElem(transactionTag);
    xmlFile.IntoElem();
    xmlFile.AddElem("INCOMEID", transaction.getTransactionId());
    xmlFile.AddElem("USERID", transaction.getUserId());
    xmlFile.AddElem("DATE", transaction.getDate());
    xmlFile.AddElem("ITEM", transaction.getItem());
    xmlFile.AddElem("AMOUNT", transaction.getAmount());
    xmlFile.OutOfElem();
    saveXmlFile();
}
