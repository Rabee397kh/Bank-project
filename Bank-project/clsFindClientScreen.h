#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"


class clsFindClientScreen : protected clsScreen
{
private:
	static void _printClient(clsBankClient client) {
		cout << "=================================" << endl;
		cout << "First Name      : " << client.fname << endl;
		cout << "Last  Name      : " << client.lname << endl;
		cout << "Full  Name      : " << client.fullName() << endl;
		cout << "Email           : " << client.email << endl;
		cout << "Phone           : " << client.phone << endl;
		cout << "Account Num     : " << client.getAccountNum() << endl;
		cout << "Pin Code        : " << client.pinCode << endl;
		cout << "Account Balance : " << client.accountBalance << endl;
	}


public:
	static void findClient() {
		if (!checkAccessRight(clsUser::enPermissions::enFindClient)) {
			return;
		}
		_drawScreenHeader("Find Client Screen");

		string accountNum = clsInputValidate::readString("Enter Account Number to find ?");

		while (!clsBankClient::isClientExist(accountNum)) {
			accountNum = clsInputValidate::readString(" Sorry Account not Found !! ,Enter Another Account Number to delete ?");
		}

		clsBankClient client = clsBankClient::find(accountNum);

		_printClient(client);

	}
};

