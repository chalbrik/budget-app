#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "XmlFile.h"
#include "User.h"
#include "HelpMethods.h"

using namespace std;

class UserFile : XmlFile {

public:

    UserFile(string userFileName) : XmlFile(userFileName) {};

    void addUserToFile(User user);
    void loadUsersFromFile(vector <User> &users);

    void changeUsersPassword(int loggedUsersId, string newUsersPassword);

};


#endif

