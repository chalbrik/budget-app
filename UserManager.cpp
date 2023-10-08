#include "UserManager.h"

bool UserManager::checkIfUserIsLogged() {
    if(loggedUsersId > 0) {
        return true;
    } else {
        return false;
    }
}

void UserManager::displayUsersMenu() {
    cout << ">>> Hello " << getCurrentUsersName() << " - you are now logged in. <<<" << endl << endl;

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

    cout << ">>> REGISTRATION <<<" << endl << endl;
    cout << "Insert name: ";
    user.setName(HelpMethods::readLine());
    cout << "Insert surname: ";
    user.setSurname(HelpMethods::readLine());

    do {
        cout << "Insert login: ";
        user.setLogin(HelpMethods::readLine());
    } while(checkIfLoginExists(user));

    cout << "Insert password: ";
    user.setPassword(HelpMethods::readLine());

    cout << users.size() << endl;
    system("pause");

    users.size() == 0 ? user.setUserId(1) : user.setUserId(users.back().getUserId() + 1); //setting usersId in users vector

    users.push_back(user);

    userFile.addUserToFile(user);

}

void UserManager::userLogIn() {

    string login = "";
    string password = "";

    cout << ">>> LOG IN <<<" << endl << endl;

    cout << "Login: ";
    login = HelpMethods::readLine();

    for(vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if(itr->getLogin() == login) {

            cout << "Password: ";
            password = HelpMethods::readLine();

            if( itr->getPassword() == password) {
                loggedUsersId = itr->getUserId();
                cout << endl << "Login and password are correct." << endl << endl;
                system("pause");
                return;
            } else {
                cout << endl << "The password is incorrect." << endl << endl;
                system("pause");
                return;
            }
        }
    }

    cout << "This login doesn't exist in data base." << endl << endl;
    system("pause");

    return;
}

void UserManager::changeUsersPassword() {
    string newUsersPassword = "";

    system("cls");

    cout << "Type new password: ";

    newUsersPassword = HelpMethods::readLine();

    for(size_t i = 0; i < users.size(); i++) {
        if(loggedUsersId == users[i].getUserId()) {
            users[i].setPassword(newUsersPassword);
            userFile.changeUsersPassword(loggedUsersId, newUsersPassword);
        }
    }

    cout << endl << "Password has been succsessfuly updated." << endl << endl;
    system("pause");
}

void UserManager::userLogOut() {
    loggedUsersId = 0;
}

int UserManager::getLoggedUsersId() const{
    return loggedUsersId;
}

//private

bool UserManager::checkIfLoginExists(User registerUser) {
    for(vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if(registerUser.getLogin() == itr->getLogin()) {
            system("cls");
            cout << "This login has been already taken. Please type different login." << endl << endl;
            system("pause");
            cout << endl;
            return true;
        }
    }
    return false;
}

string UserManager::getCurrentUsersName() {
    string loggedUsersName = "";
    for(vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if(loggedUsersId == itr->getUserId()) {
            loggedUsersName = itr->getName();
        }
    }
    return loggedUsersName;
}
