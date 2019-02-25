#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>

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
};
#endif
