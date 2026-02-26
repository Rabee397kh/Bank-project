#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsAddClientScreen : protected clsScreen
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
	static void showAddClient() {
		string title = "Add New Client Screen";
		_drawScreenHeader(title);

		string accountNum = "";
		accountNum = clsInputValidate::readString("Enter Account Number ? ");

		while (clsBankClient::isClientExist(accountNum)) {
			accountNum = clsInputValidate::readString("Sorry , this Account number is Lincked to Existing Account ,Enter Another Account Number ? ");
		}

		

		clsBankClient client = clsBankClient::getAddNewClientObject(accountNum);
		_readClientInfo(client);

		clsBankClient::enSaveResult saveResult;

		saveResult = client.save();

		switch (saveResult) {
		case clsBankClient::saveFailed:
			cout << endl << "Client not added";
			break;
		case clsBankClient::saveSuccessed:
			cout << endl << "Client Added Successfully ";
			_printClient(client);
			break;
		case clsBankClient::saveFailedCauseOfAccountNumExist:
			cout << endl << "Client not added , Because Account Number Used!!";
		}

	}
};

