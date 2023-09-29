#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <iostream>

using namespace std;

class Transactions{

    int transactionId;
    int userId;
    string date;
    string item;
    string amount;

public:

    int getTransactionId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();

    void setTransactionId(int newTransactionId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);


};



#endif
