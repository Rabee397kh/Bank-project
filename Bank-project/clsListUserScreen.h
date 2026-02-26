#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"
#include <iomanip>
class clsListUserScreen :
    protected clsScreen
{
private:

public:
	static void listUser() {
		_drawScreenHeader("List User Screen");
		vector <clsUser> vUsers = clsUser::getUsers();

		cout << setw(50) << left << "" << "List Users " << endl;

		if (vUsers.size() == 0) {
			cout << "No User Found !!" << endl;
		}

		cout << "______________________________________________________________________________________________________________" << endl;
		cout <<  setw(15) << left << " | First Name" <<  setw(15) << left << " | Last Name" << setw(20) 
			  << left << " | Email" << setw(15) << left << " | Phone" << setw(15) << left <<" | User Name" 
			<< setw(15) << left << " | Password" << setw(10) << left << " | Permission" << endl;
		cout << "______________________________________________________________________________________________________________" << endl;

		for (clsUser& user : vUsers) {
			cout << setw(15) << left << " | " + user.fname << setw(15) << left << " | " + user.lname <<
				setw(20) << left << " | " + user.email << setw(15) << left << " | " + user.phone << 
				setw(15) << left << " | " + user.username << setw(15) << left << " | " + 
				user.password  <<
				setw(10) << left << " | " + to_string(user.permission)  << endl << endl;
		}
	}
};

