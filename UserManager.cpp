#include "UserManager.h"

void UserManager::signInUser() {
    User user = inputNewUserData();

    users.push_back(user);
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
