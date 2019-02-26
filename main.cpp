#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager;

    /*userManager.signInUser();
    userManager.signInUser();*/

    userManager.showAllUser();
    userManager.logInUser();
    userManager.changeLoggedUserPassword();
    userManager.showAllUser();

    return 0;
}
