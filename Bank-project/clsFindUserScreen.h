#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen :
    protected clsScreen
{
private:
	static void _print(clsUser user) {
		cout << "=======================================" << endl;
		cout << "User Card" << endl;
		cout << "=======================================" << endl << endl;
		cout << "First Name  : " << user.fname << endl;
		cout << "Last Name   : " << user.lname << endl;
		cout << "Email       : " << user.email << endl;
		cout << "Phone       : " << user.phone << endl;
		cout << "User Name   : " << user.username << endl;
		cout << "Password    : " << user.password << endl;
		cout << "Permission  : " << user.permission << endl << endl;
		cout << "=======================================" << endl;
	}

public:
    static void findUser() {
		_drawScreenHeader("Find User Screen");
        string username = clsInputValidate::readString("Enter User Name?");

        while (!clsUser::isUserExist(username)) {
            username = clsInputValidate::readString("User Not Found , Enter Another User Name ?");
        }

		clsUser user = clsUser::find(username);
		_print(user);
    }
};

