#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsUpdateClientScreen : protected clsScreen
{
private:
	static void _readClientInfo(clsBankClient& client) {
		client.fname = clsInputValidate::readString("Enter First Name ?");
		client.lname = clsInputValidate::readString("Enter Lastst Name ?");
		client.email = clsInputValidate::readString("Enter Email ?");
		client.phone = clsInputValidate::readString("Enter Phone ?");
		client.pinCode = clsInputValidate::readString("Enter Pin Code ?");
		cout << "Enter Account Balance ?" << endl;
		client.accountBalance = clsInputValidate::ReadDblNumber();
	}

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
	static void updateClient() {
		_drawScreenHeader("Update Client Screen");
		string accountNum = "";
		accountNum = clsInputValidate::readString("Enter Account Number ? ");


		while (!clsBankClient::isClientExist(accountNum)) {
			accountNum = clsInputValidate::readString("Sorry , Account with this number isn't exist , Enter Account Number Again? ");
		}

		clsBankClient client = client.find(accountNum);
		_printClient(client);

		char getSure = clsBankClient::confirm("Are you sure to updtae this client ?");

		if (tolower(getSure) != 'y') {
			cout << "Okay .";
			return;
		}


		cout << endl << "Update Client Info " << endl;
		cout << "============================================" << endl;
		_readClientInfo(client);

		clsBankClient::enSaveResult saveResult;

		saveResult = client.save();

		switch (saveResult) {
		case(clsBankClient::saveFailed):
			cout << endl << "Save Failed";
			break;
		case clsBankClient::saveSuccessed:
			cout << endl << "Client Updated Successfully!! ";
			break;
		}
	}
};

