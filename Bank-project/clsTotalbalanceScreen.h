#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTotalbalanceScreen :
    public clsScreen
{
private:
	static void _printClientBalances(clsBankClient client) {

		cout << left << "| " << setw(30) << client.fullName() << "| " << setw(20) << client.accountBalance << endl;

	}


public:

	static void getTotalBalance() {
		vector <clsBankClient> vClients = clsBankClient::getClientsData();

		_drawScreenHeader("Total Balances Screen");

		cout << endl << "\t\t\t\t\t\t[" << vClients.size() << "]" << " Clients List" << endl << endl;

		if (vClients.size() == 0) {
			cout << "No Clients Availble In System !";
			return;
		}

		cout << "________________________________________________________________________________________________________________________" << endl;
		cout << left << setw(32) << "| Client Name" << setw(22) << "| Account Balance"
			<< endl;
		cout << "________________________________________________________________________________________________________________________" << endl;

		for (clsBankClient& client : vClients) {
			_printClientBalances(client);
		

		}
		

		

		cout << endl << endl << "                                                  Total Balance = "
			<< clsBankClient::getTotalBalance() << endl;
	}
};

