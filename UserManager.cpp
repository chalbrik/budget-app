#include "UserManager.h"

void UserManager::userRegistration()
{
    User user;

    cout << "REGISTRATION" << endl;
    cout << "Insert name: ";
    user.setName(HelpMethods::readLine());
    cout << "Insert surname: ";
    user.setSurname(HelpMethods::readLine());
    cout << "Insert login: ";
    user.setLogin(HelpMethods::readLine());
    cout << "Insert password: ";
    user.setPassword(HelpMethods::readLine());

    users.push_back(user);

}
