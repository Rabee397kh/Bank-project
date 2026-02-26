#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsDeleteUserScreen :
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
	static void deleteUser() {
		_drawScreenHeader("Delete User Screen");
		string username = clsInputValidate::readString("Enter User Name ?");

		while (!clsUser::isUserExist(username)) {
			username = clsInputValidate::readString("User not Found , Enter Another User Name ?");
		}

		clsUser user = clsUser::find(username);
		_print(user);

		char ch = 'y';

		cout << "do you want to continue this process ? " << endl;
		cin >> ch;

		if (tolower(ch) != 'y') {
			return;
		}

		if (user.deleteUserFromFile()) {
			cout << "User Deleted Successfully !" << endl;
		}
		else {
			cout << "User Deleted Failed !";
		}

	}

};

