#include "UserFile.h"

void UserFile::addUserToFile(User user) {
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

void UserFile::loadUsersFromFile(vector <User> &users) {
    User user;

    loadXmlFile();

    while(xmlFile.FindElem("USER")) {
        xmlFile.FindChildElem("USERID");
        user.setUserId(atoi(MCD_2PCSZ(xmlFile.GetChildData())));
        xmlFile.FindChildElem("LOGIN");
        user.setLogin(xmlFile.GetChildData());
        xmlFile.FindChildElem("PASSWORD");
        user.setPassword(xmlFile.GetChildData());
        xmlFile.FindChildElem("NAME");
        user.setName(xmlFile.GetChildData());
        xmlFile.FindChildElem("SURNAME");
        user.setSurname(xmlFile.GetChildData());

        users.push_back(user);
    }
}

void UserFile::changeUsersPassword(int loggedUsersId, string newUsersPassword) {
    string strLoggedUsersId = "";

    strLoggedUsersId = HelpMethods::convertIntToString(loggedUsersId);
    loadXmlFile();

    while(xmlFile.FindElem("USER")) {
        xmlFile.FindChildElem("USERID");
        if(MCD_STR (xmlFile.GetChildData()) == strLoggedUsersId) {
            xmlFile.FindChildElem("PASSWORD");
            xmlFile.SetChildData(newUsersPassword);
        }
    }

    saveXmlFile();
}
