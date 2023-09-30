#include "UserFile.h"

void UserFile::addUserToFile(User user)
{
    xmlFile.AddElem("USER");
    xmlFile.IntoElem();
    xmlFile.AddElem("USERID", user.getUserId());
    xmlFile.AddElem("LOGIN", user.getLogin());
    xmlFile.AddElem("PASSWORD", user.getPassword());
    xmlFile.AddElem("NAME", user.getName());
    xmlFile.AddElem("SURNAME", user.getSurname());
    xmlFile.OutOfElem();
    saveXmlFile();
}

void UserFile::loadUsersFromFile()
{
    loadXmlFile();
}
