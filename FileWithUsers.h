#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"

using namespace std;

class FileWithUsers {

    string fileWithUsers;

public:

    FileWithUsers(){
        fileWithUsers = "Users.xml";
    };
    void addUserToFile(User user);
    vector <User> loadUserFromFile();
    void saveAllUserToFile (vector <User> &users);
};

#endif
