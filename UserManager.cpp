#include "UserManager.h"

void UserManager::userRegistration() {
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

    cout << users.size() << endl;
    system("pause");

    users.size() == 0 ? user.setUserId(1) : user.setUserId(users.back().getUserId() + 1); //output usersId depending on users' vector size

    users.push_back(user);

    userFile.addUserToFile(user);

    cout << users.size() << endl;
    system("pause");


}
