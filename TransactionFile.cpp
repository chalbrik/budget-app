#include "TransactionFile.h"

void TransactionFile::addOperationToFile(string transactionTag, Transactions transaction) {
    xmlFile.AddElem(transactionTag);
    xmlFile.IntoElem();
    xmlFile.AddElem(transactionTag + "ID", transaction.getTransactionId());
    xmlFile.AddElem("USERID", transaction.getUserId());
    xmlFile.AddElem("DATE", transaction.getDate());
    xmlFile.AddElem("ITEM", transaction.getItem());
    xmlFile.AddElem("AMOUNT", transaction.getAmount());
    xmlFile.OutOfElem();
    saveXmlFile();
}

void TransactionFile::loadOperationFromFile(vector <Transactions> &transactions, int loggedUserId) {
    Transactions transaction;
    string strLoggedUsersId = "";

    strLoggedUsersId = HelpMethods::convertIntToString(loggedUserId);

    loadXmlFile();

    if(FILE_NAME == "Incomes.xml") {
        while(xmlFile.FindElem("INCOME")) {

            xmlFile.FindChildElem("USERID");
            if(MCD_STR (xmlFile.GetChildData()) == strLoggedUsersId) {
                xmlFile.ResetChildPos();
                xmlFile.FindChildElem("INCOMEID");
                transaction.setTransactionId(atoi(MCD_2PCSZ(xmlFile.GetChildData())));
                xmlFile.FindChildElem("USERID");
                transaction.setUserId(atoi(MCD_2PCSZ (xmlFile.GetChildData())));
                xmlFile.FindChildElem("DATE");
                transaction.setDate(atoi(MCD_2PCSZ (xmlFile.GetChildData())));
                xmlFile.FindChildElem("ITEM");
                transaction.setItem(xmlFile.GetChildData());
                xmlFile.FindChildElem("AMOUNT");
                transaction.setAmount(atoi(MCD_2PCSZ (xmlFile.GetChildData())));
                transactions.push_back(transaction);
            }
        }
    } else if(FILE_NAME == "Expenses.xml") {
        while(xmlFile.FindElem("EXPENSE")) {

            xmlFile.FindChildElem("USERID");
            if(MCD_STR (xmlFile.GetChildData()) == strLoggedUsersId) {
                xmlFile.ResetChildPos();
                xmlFile.FindChildElem("EXPENSEID");
                transaction.setTransactionId(atoi(MCD_2PCSZ(xmlFile.GetChildData())));
                xmlFile.FindChildElem("USERID");
                transaction.setUserId(atoi(MCD_2PCSZ (xmlFile.GetChildData())));
                xmlFile.FindChildElem("DATE");
                transaction.setDate(atoi(MCD_2PCSZ (xmlFile.GetChildData())));
                xmlFile.FindChildElem("ITEM");
                transaction.setItem(xmlFile.GetChildData());
                xmlFile.FindChildElem("AMOUNT");
                transaction.setAmount(atoi(MCD_2PCSZ (xmlFile.GetChildData())));

                transactions.push_back(transaction);
            }
        }
    }

}
