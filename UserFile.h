#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include "XmlFile.h"

using namespace std;

class UserFile : XmlFile {

public:

    UserFile(string userFileName) : XmlFile(userFileName) {};

    addUserToFile();
    loadUsersFromFile();

};


#endif

