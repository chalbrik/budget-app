#include "TransactionFile.h"

void TransactionFile::addOperationToFile(string transactionTag, Transactions transaction) {
    xmlFile.AddElem(transactionTag);
    xmlFile.IntoElem();
    xmlFile.AddElem(transactionTag + "ID", transaction.getTransactionId());
    xmlFile.AddElem("USERID", transaction.getUserId());
    xmlFile.AddElem("DATE", transaction.getDate());
    xmlFile.AddElem("ITEM", transaction.getItem());

    ostringstream amountStr;
    amountStr << fixed << setprecision(2) << transaction.getAmount();
    xmlFile.AddElem("AMOUNT", amountStr.str());

    xmlFile.OutOfElem();
    saveXmlFile();
}

void TransactionFile::loadOperationFromFile(vector <Transactions> &transactions, int loggedUserId, string transactionTag) {
    Transactions transaction;
    string strLoggedUsersId = "";

    strLoggedUsersId = HelpMethods::convertIntToString(loggedUserId);

    loadXmlFile();

    while(xmlFile.FindElem(transactionTag)) {

        xmlFile.FindChildElem("USERID");
        if(MCD_STR (xmlFile.GetChildData()) == strLoggedUsersId) {
            xmlFile.ResetChildPos();
            xmlFile.FindChildElem(transactionTag + "ID");
            transaction.setTransactionId(atoi(MCD_2PCSZ(xmlFile.GetChildData())));
            xmlFile.FindChildElem("USERID");
            transaction.setUserId(atoi(MCD_2PCSZ (xmlFile.GetChildData())));
            xmlFile.FindChildElem("DATE");
            transaction.setDate(atoi(MCD_2PCSZ (xmlFile.GetChildData())));
            xmlFile.FindChildElem("ITEM");
            transaction.setItem(xmlFile.GetChildData());
            xmlFile.FindChildElem("AMOUNT");
            transaction.setAmount(stod(MCD_2PCSZ (xmlFile.GetChildData())));
            transactions.push_back(transaction);
        }
    }
}
