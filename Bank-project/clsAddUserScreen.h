#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsAddUserScreen :
    protected clsScreen
{
private:
	static int _readPermissions() {
		int permission = 0;
		char ans = 'y';

		cout << "do you want to give full access ? ";
		cin >> ans;

		if (tolower(ans) == 'y') {
			return -1;
		}

		cout << "do you want to give  access to list clients? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			permission += clsUser::enPermissions::enListClients;
		}

		cout << "do you want to give  access to add client? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			permission += clsUser::enPermissions::enAddClient;
		}

		cout << "do you want to give  access to delete client? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			permission += clsUser::enPermissions::enDeleteClient;
		}

		cout << "do you want to give  access to update client? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			permission += clsUser::enPermissions::enUpdateClient;
		}

		cout << "do you want to give  access to find client? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			permission += clsUser::enPermissions::enFindClient;
		}

		cout << "do you want to give  access to Transactions? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			permission += clsUser::enPermissions::enTransactions;
		}

		cout << "do you want to give  access to Manage Users? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			permission += clsUser::enPermissions::enManageUsers;
		}


		cout << "do you want to give  access to show register list? ";
		cin >> ans;
		if (tolower(ans) == 'y') {
			permission += clsUser::enPermissions::enRegister;
		}

		return permission;
	}

	static void _readUserInfo(clsUser& user) {
		user.fname = clsInputValidate::readString("Enter First Name ? ");
		user.lname = clsInputValidate::readString("Enter Last Name ? ");
		user.email = clsInputValidate::readString("Enter Email ? ");
		user.phone = clsInputValidate::readString("Enter Phone ? ");
		user.password = clsInputValidate::readString("Enter Password ? ");
		/*user.password = clsUtil::EncryptText(user.password, 7);*/

		cout << "Enter Permission : " << endl;
		user.permission = _readPermissions();

	}

	static void _print(clsUser user) {
		cout << "=======================================" << endl;
		cout << "User Card" << endl;
		cout << "=======================================" << endl << endl;
		cout << "First Name  : " << user.fname << endl;
		cout << "Last Name   : " << user.lname << endl;
		cout << "Email       : " << user.email << endl;
		cout << "Phone       : " << user.phone << endl;
		cout << "User Name   : " << user.username << endl;
		//cout << "Password    : " << clsUtil::DecryptText(user.password, 7) << endl;
		cout << "Password   : " << user.password << endl;
		cout << "Permission  : " << user.permission << endl << endl;
		cout << "=======================================" << endl;
	}

public:
	static void addUser() {
		_drawScreenHeader("Add User Screen");

		string username = clsInputValidate::readString("Enter User Name ? ");

		while (clsUser::isUserExist(username)) {
			username = clsInputValidate::readString("Sorry , this User Name has Account !! , Enter User Name Again? ");

		}



		clsUser user = clsUser::getNewUserObject(username);
		_readUserInfo(user);

		clsUser::enSaveResult saveResult;

		saveResult = user.save();

		switch (saveResult) {
		case clsUser::saveSuccessed:
			cout << "User Added Successfully !" << endl;
			_print(user);
			break;
		case clsUser::saveFailed:
			cout << "User Added Failed !" << endl;;
			break;
		}
	}
};

