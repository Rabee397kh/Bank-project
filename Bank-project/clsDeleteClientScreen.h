#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsAddClientScreen.h"
class clsDeleteClientScreen : protected clsScreen
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
	static void showDeleteClient() {
		if (!checkAccessRight(clsUser::enPermissions::enDeleteClient)) {
			return;
		}
		_drawScreenHeader("Delete Client Screen");
		string accountNum = clsInputValidate::readString("Enter Account Number to delete ?");

		while (!clsBankClient::isClientExist(accountNum)) {
			accountNum = clsInputValidate::readString(" Sorry Account not Found !! ,Enter Another Account Number to delete ?");
		}

		clsBankClient client = clsBankClient::find(accountNum);

		_printClient(client);

		char getSure = clsBankClient::confirm("Are you sure to delete this client ?");

		if (tolower(getSure) != 'y') {
			cout << "Okay .";
			return;
		}

		client = clsBankClient::getClientDeleted(accountNum);

		clsBankClient::enSaveResult saveResult;
		saveResult = client.save();

		

		switch (saveResult) {
		case clsBankClient::saveSuccessed:
			cout << "Client Deleted Successuflly !";
			break;
		case clsBankClient::saveFailed:
			cout << "Client isn't Deleted !";
			break;
		}


	}
};

