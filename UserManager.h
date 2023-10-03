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
    int loggedUsersId;

    char chosenOptionFromUsersMenu;

public:

    UserManager(string userFileName) : userFile(userFileName) {

        loggedUsersId = 0;

        userFile.loadUsersFromFile(users);

    };

    bool checkIfUserIsLogged();
    void displayUsersMenu();
    char getChosenOptionFromUsersMenu();

    void userRegistration();
    void userLogIn();
    void changeUsersPassword();
    void userLogOut();

    int getLoggedUsersId();

};











#endif
