#include "User.h"

int User::getUserId() const{
    return userId;
}
string User::getLogin() const{
    return login;
}
string User::getPassword() const{
    return password;
}
string User::getName() const{
    return name;
}
string User::getSurname() const{
    return surname;
}

void User::setUserId(int newUserId) {
    userId = newUserId;
}
void User::setLogin(string newLogin) {
    login = newLogin;
}
void User::setPassword(string newPassword) {
    password = newPassword;
}
void User::setName(string newName) {
    name = newName;
}
void User::setSurname(string newSurname) {
    surname = newSurname;
}
