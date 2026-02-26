#pragma once
#include <iostream>
#include "global.h"
using namespace std;


class clsScreen
{
protected:
	static void _drawScreenHeader(string title, string subTitle = "") {
		cout << "\t\t\t\t_________________________________________________________________" << endl;
		cout << "\t\t\t\t\t\t" << title << endl;
		//cout << "\t\t\t\t_________________________________________________________________" << endl << endl;

		//cout << "\t\t\t\tUser Name : " << CurrentUser.username << endl;
		
		 cout << endl<< "\t\t\t\tUser Name : "  << endl;
		 cout << "\t\t\t\t" << clsDate::DateToString(clsDate()) << endl;

		if (subTitle != "") {
			cout << "\t\t\t\t\t\t" << subTitle << endl;
		}

		cout << "\t\t\t\t=================================================================" << endl << endl;
		
		
	}

	static bool checkAccessRight(clsUser::enPermissions permission) {
		//!currentUser.checkPermissionAccess(permission)
		if (false) {
			cout << "\t\t\t\t_________________________________________________________________" << endl;
			cout << "\t\t\t\t\t\t" << "Access Denied" << endl;
			cout << "\t\t\t\t_________________________________________________________________" << endl << endl;
			return false;
		}
		else
			return true;
	}
};

