#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "UserFile.h"
#include "User.h"
#include "HelpMethods.h"

using namespace std;

class UserManager {

    UserFile userFile;
    vector <User> users;

public:

    UserManager(string userFileName) : userFile(userFileName) {

    userFile.loadUsersFromFile();

    };

    void userRegistration();
    void userLogIn();
    void changePassword();
    void LogOut();

};











#endif
