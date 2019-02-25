#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager;

    while(1){
        userManager.signInUser();

        userManager.showAllUser();
    }
    return 0;
}
