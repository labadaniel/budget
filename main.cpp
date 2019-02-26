#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager;


        userManager.signInUser();

        userManager.logInUser();
        userManager.showAllUser();
        userManager.changeLoggedUserPassword();

        userManager.showAllUser();


    return 0;
}
