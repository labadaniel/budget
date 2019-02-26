#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>


#include "User.h"

using namespace std;

class UserManager
{
    vector <User> users;
    int idLoggedInUser;
    User inputNewUserData();
    int getNewUserId();
    bool isUserLoginExist(string login);

public:
    UserManager()
    {
        idLoggedInUser = 0;
    };
    void showAllUser();
    void signInUser();
    void logInUser();
    void changeLoggedUserPassword();
};
#endif
