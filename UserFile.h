#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include "XmlFile.h"

using namespace std;

class UserFile : XmlFile {

public:

    UserFile() {};

    addUserToFile();
    loadUsersFromFile();

};


#endif

