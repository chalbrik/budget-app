#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "UserFile.h"
#include "User.h"

using namespace std;

class UserManager {

    UserFile userFile;
    vector <User> users;

public:

    UserManager();

    void userRegistration();
    void userLogIn();
    void changePassword();
    void LogOut();

};











#endif
