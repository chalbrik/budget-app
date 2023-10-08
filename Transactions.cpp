#include "Transactions.h"

int Transactions::getTransactionId() const{
    return transactionId;
}
int Transactions::getUserId() const{
    return userId;
}
int Transactions::getDate() const{
    return date;
}
string Transactions::getItem() const{
    return item;
}
double Transactions::getAmount() const{
    return amount;
}

void Transactions::setTransactionId(int newTransactionId)
{
    transactionId = newTransactionId;
}
void Transactions::setUserId(int newUserId)
{
    userId = newUserId;
}
void Transactions::setDate(int newDate)
{
    date = newDate;
}
void Transactions::setItem(string newItem)
{
    item = newItem;
}
void Transactions::setAmount(double newAmount)
{
    amount = newAmount;
}

bool Transactions::operator<(const Transactions& other) const
{
    return date < other.date;
}
