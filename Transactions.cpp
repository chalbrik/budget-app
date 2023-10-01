#include "Transactions.h"

int Transactions::getTransactionId() {
    return transactionId;
}
int Transactions::getUserId() {
    return userId;
}
int Transactions::getDate() {
    return date;
}
string Transactions::getItem() {
    return item;
}
string Transactions::getAmount() {
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
void Transactions::setAmount(string newAmount)
{
    amount = newAmount;
}
