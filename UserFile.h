#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include "XmlFile.h"
#include "User.h"

using namespace std;

class UserFile : XmlFile {

public:

    UserFile(string userFileName) : XmlFile(userFileName) {};

    void addUserToFile(User user);
    void loadUsersFromFile();

};


#endif

