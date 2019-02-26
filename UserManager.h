#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {
    vector <User> users;
    int idLoggedInUser;
    User inputNewUserData();
    int getNewUserId();
    bool isUserLoginExist(string login);
    FileWithUsers fileWithUsers;

public:
    UserManager() {
        idLoggedInUser = 0;
        users = fileWithUsers.loadUserFromFile();
    };
    void showAllUser();
    void signInUser();
    void logInUser();
    void changeLoggedUserPassword();

};
#endif
