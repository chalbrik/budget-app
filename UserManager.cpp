#include "UserManager.h"

bool UserManager::checkIfUserIsLogged() {
    if(loggedUsersId > 0) {
        return true;
    } else {
        return false;
    }
}

void UserManager::displayUsersMenu() {
    cout << "You are logged in" << endl;
    cout << "1 - Add income" << endl;
    cout << "2 - Add expense" << endl;
    cout << "3 - Check account balance" << endl;
    cout << "4 - Change password" << endl;
    cout << "5 - Log out" << endl;

    cout << endl << "Option: ";

    chosenOptionFromUsersMenu = HelpMethods::getCharacter();
}

char UserManager::getChosenOptionFromUsersMenu() {
    return chosenOptionFromUsersMenu;
}

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

    users.size() == 0 ? user.setUserId(1) : user.setUserId(users.back().getUserId() + 1); //setting usersId in users vector

    users.push_back(user);

    userFile.addUserToFile(user);

}

void UserManager::userLogIn() {

    string login = "";
    string password = "";

    cout << "LOGGING" << endl;

    cout << "Login: ";
    login = HelpMethods::readLine();

    for(vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if(itr->getLogin() == login) {

            cout << "Password: ";
            password = HelpMethods::readLine();

            itr->getPassword() == password ? cout << "You are logged in." << endl : cout << "Password is incorrect." << endl;
            system("pause");

            loggedUsersId = itr->getUserId();
        }
    }
    return;

    cout << "This login doesn't exist" << endl;
}

void UserManager::changeUsersPassword() {
    string newUsersPassword = "";

    cout << "Type new password: ";

    newUsersPassword = HelpMethods::readLine();

    //trzeba to zrobiæ w vektorze najpierw

    for(size_t i = 0; i < users.size(); i++) {
        if(loggedUsersId == users[i].getUserId()) {
            users[i].setPassword(newUsersPassword);
            userFile.changeUsersPassword(loggedUsersId, newUsersPassword);
        }
    }

    //userFile.changeUsersPassword();

}

void UserManager::userLogOut() {
    loggedUsersId = 0;
}

int UserManager::getLoggedUsersId() {
    return loggedUsersId;
}
