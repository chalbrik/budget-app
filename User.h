#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {

int userId;
    string login;
    string password;
    string name;
    string surname;

public:

    int getUserId() const;
    string getLogin() const;
    string getPassword() const;
    string getName() const;
    string getSurname() const;

    void setUserId(int newUserId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);

};









#endif
