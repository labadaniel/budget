#include "UserManager.h"

void UserManager::signInUser() {
    User user = inputNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
}

User UserManager::inputNewUserData() {
    User user;
    user.setUserId(getNewUserId());
    int userId;
    string login;
    string password;
    string name;
    string surname;

    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin (login);
    } while (isUserLoginExist(user.getLogin()));

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::showAllUser() {
    for (int i=0; i < users.size(); i++) {
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}

bool UserManager::isUserLoginExist(string login) {
    for(int i = 0; i < users.size(); i++)
        if(users[i].getLogin() == login) {
            cout << "Uzytkownik o takim loginie juz istnieje." << endl;;
            return true;
        }
    return false;
}

void UserManager::logInUser(){
    User user;

    string login = "", password = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < users.size(); i++){
        if(users[i].getLogin() == login){
            cout << endl << "Podaj haslo: ";
            cin >> password;
            if(users[i].getPassword() == password){
                idLoggedInUser = users[i].getUserId();
                cout << "Udalo sie zalogowac" << endl;
                system("pause");
                return;
            }
            else{
                cout << "Wprowadzono bledne haslo." << endl;
                system("pause");
                return;
            }
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::changeLoggedUserPassword(){
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (int i = 0; i < users.size(); i++){
        if(users[i].getUserId() == idLoggedInUser){
            users[i].setPassword(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl;
            system("pause");
        }
        fileWithUsers.saveAllUserToFile(users);
    }
}

int UserManager::getLoggedInUserId(){
    return idLoggedInUser;
}

bool UserManager::isUserLoggedIn(){
    if (idLoggedInUser > 0)
        return true;
    else
        return false;
}

void UserManager::logOutUser(){
    idLoggedInUser = 0 ;
}


