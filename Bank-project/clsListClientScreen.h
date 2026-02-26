#pragma once
#include "iostream"
#include "iomanip"
#include "clsScreen.h"
#include "clsBankClient.h"


class clsListClientScreen : protected clsScreen
{
private:
	static void printClientRecord(clsBankClient client) {
		cout << left << "| " << setw(13) << client.fname << "| " << setw(13) << client.lname << "| " << setw(20)
			<< client.email << "| " << setw(15) << client.phone << "| " << setw(13) << client.getAccountNum()
			<< "| " << setw(10) << client.pinCode <<
			"| " << setw(20) << client.accountBalance << endl;

	}

public:
	static void listClients() {
		if (!checkAccessRight(clsUser::enPermissions::enListClients)) {
			return;
		}
		vector <clsBankClient> vClients = clsBankClient::getClientsData();
		string title = "List Clients Screen";
		string subTitle = to_string(vClients.size()) + " Clients List";
	

		_drawScreenHeader(title,subTitle);

		cout << "________________________________________________________________________________________________________________________" << endl;
		cout << left << setw(15) << "| First Name" << setw(15) << "| Last Name" << setw(22) << "| Email"
			<< setw(17) << "| Phone" << setw(15) << "| Account Num" << setw(12) << "| Pin Code" << setw(22)
			<< "| Account Balance"
			<< endl;
		cout << "________________________________________________________________________________________________________________________" << endl;

		if (vClients.size() == 0) {
			cout << "No Clients Availble In System !";
			return;
		}

		for (clsBankClient& client : vClients) {
			printClientRecord(client);
		}
	}
};

