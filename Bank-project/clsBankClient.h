#pragma once;
#include <iostream>
#include <iomanip>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class clsBankClient : public clsPerson {
private:
	string _accountNum;
	string _pinCode;
	float _accountBalance;
	enum enMode{emptyMode = 0 , updateMode = 1 , addMode = 2 , deleteMode = 3};
	enMode _mode;


	static clsBankClient _convertLineToClientObjetc(string line) {
		vector <string> vData = clsString::splitSt(line, "#//#");
		return clsBankClient(enMode::updateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5],
			stof(vData[6]));

	}


	static vector <clsBankClient> _loadClientsData(string fileName) {
		fstream myFile;
		vector <clsBankClient> vClients;

		myFile.open(fileName, ios::in);

		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsBankClient client = _convertLineToClientObjetc(line);
				vClients.push_back(client);
			}
			myFile.close();
		}

		return vClients;
	}

	 bool isEmpty() {
		return _mode == enMode::emptyMode;
	}

	 static string _convertClientObjectToLine(clsBankClient client , string delima = "#//#") {
		 string line = "";
		 line = client.fname + delima + client.lname + delima + client.email + delima + client.phone + delima +
			 client._accountNum + delima + client.pinCode + delima + to_string(client.accountBalance);

		 return line;
	 }


	 static void _saveClinentsDataToFile(vector <clsBankClient> vClients , string fileName) {
		 fstream myFile;
		 myFile.open(fileName, ios::out);

		 string line;
		 if (myFile.is_open()) {
			 for (clsBankClient& client : vClients) {
				 if (client._mode != deleteMode) {
					 line = _convertClientObjectToLine(client);
					 myFile << line << endl;
				 }
				
			 }
		 }
	 }

	 void _update() {
		 vector <clsBankClient> vClients = _loadClientsData("clients.txt");
		 for (clsBankClient& client : vClients) {
			 if (client._accountNum == _accountNum) {
				 client = *this;
			 }
		 }
		 _saveClinentsDataToFile(vClients , "clients.txt");
	 }

	 void _addLineToFile(string line, string fileName) {
		 fstream myFile;

		 myFile.open(fileName, ios::app | ios::out);

		 if (myFile.is_open()) {
			 myFile << line << endl;
		 }
	 
	 }


	 void _add() {
		 string line = _convertClientObjectToLine(*this);
		 _addLineToFile(line,"clients.txt");
	 }

	 void _delete() {
		 vector <clsBankClient> vClients = clsBankClient::_loadClientsData("clients.txt");
		
	     for (clsBankClient& client : vClients) {
		    if (client._accountNum == this->_accountNum) {
			    client._mode = deleteMode;
			    break;
		    }
	     }

		 *this = clsBankClient(enMode::deleteMode, "", "", "", "", "", "", 0);
	    _saveClinentsDataToFile(vClients, "clients.txt");
	 }

	static string _transferClientObjectsToLogLine(clsBankClient client1, clsBankClient client2 , string delima ,int amount) {
		string line = "";

		line = clsDate::GetSystemDateString() + delima + client1.getAccountNum() + delima +
			client2.getAccountNum() + delima + to_string(amount) + delima +
			to_string(client1.accountBalance) + delima + to_string(client2.accountBalance) + delima +
			"user";

		return line;
	 }

	struct stTransferLog;
	

	static stTransferLog _convertLineToStruct(string line) {
		stTransferLog transferLog;
		vector <string> vData = clsString::splitSt(line);

		transferLog.date = vData[0];
		transferLog.account1 = vData[1];
		transferLog.account2 = vData[2];
		transferLog.amount = stod(vData[3]);
		transferLog.balance1 = stof(vData[4]);
		transferLog.balance2 = stof(vData[5]);
		transferLog.user = vData[6];

		return transferLog;
	}
public:
	clsBankClient(enMode mode, string fname, string lname, string email, string phone, string accountNum,
		string pinCode, float accountBalance) : clsPerson(fname, lname, email, phone) {
		_mode = mode;
		_accountNum = accountNum;
		_pinCode = pinCode;
		_accountBalance = accountBalance;
	}

	struct stTransferLog {
		string date;
		string account1;
		string account2;
		double amount;
		float balance1;
		float balance2;
		string user;
	};

	static void transferLog(clsBankClient client1 , clsBankClient client2 , int amount) {
		fstream myfile;

		myfile.open("transferLog.txt", ios::out | ios::app);

		string line = _transferClientObjectsToLogLine(client1, client2, "#//#", amount);

		if (myfile.is_open()) {
			
			myfile << line << endl;
			myfile.close();
		}
	}

	string getAccountNum() {
		return _accountNum;
	}

	void setAccountBalance(float accountBalance) {
		_accountBalance = accountBalance;
	}

	float getAccountBalance() {
		return _accountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float accountBalance;

	void setPinCode(string pinCode) {
		_pinCode = pinCode;
	}

	string getPinCode() {
		return _pinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string pinCode;


	void print() {
		cout << "=================================" << endl;
		cout << "First Name      : " << fname << endl;
		cout << "Last  Name      : " << lname << endl;
		cout << "Full  Name      : " << fullName() << endl;
		cout << "Email           : " << email << endl;
		cout << "Phone           : " << phone << endl;
		cout << "Account Num     : " << _accountNum << endl;
		cout << "Pin Code        : " << pinCode << endl;
		cout << "Account Balance : " << accountBalance << endl;
	}

	static clsBankClient find(string accountNum) {
		vector <clsBankClient> vClients = _loadClientsData("clients.txt");

		for (clsBankClient& client : vClients) {
			if (client._accountNum == accountNum) {
				return client;
				break;
			}
		}
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}


	static clsBankClient find(string accountNum , string pinCode) {
		vector <clsBankClient> vClients = _loadClientsData("clients.txt");

		for (clsBankClient& client : vClients) {
			if (client._accountNum == accountNum && client.pinCode == pinCode) {
				return client;
				break;
			}
		}
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}


	static bool isClientExist(string accountNum) {
		clsBankClient client = find(accountNum);

		return (!client.isEmpty());
	}

	enum enSaveResult{saveFailed = 0 , saveSuccessed = 1 , saveFailedCauseOfAccountNumExist = 2};

    enSaveResult save() {
		 switch (_mode) {
		 case enMode::emptyMode:
			 return enSaveResult::saveFailed;
		 case enMode::updateMode:
		 {
			 _update();
			 return enSaveResult::saveSuccessed;
		 }
		 case enMode::addMode:
		 {
			 if (isClientExist(_accountNum)) {
				 return enSaveResult::saveFailedCauseOfAccountNumExist;
			 }
			 else {
				 _add();
				 _mode = enMode::updateMode;
				 return enSaveResult::saveSuccessed;
			 }
			 
		 }
		 case enMode::deleteMode:
		 {
			 _delete();
			 return enSaveResult::saveSuccessed;
		 }
		}
	}

	static clsBankClient getAddNewClientObject(string accountNum) {
		return clsBankClient(enMode::addMode, "", "", "", "", accountNum, "", 0);
	}

	static char confirm(string msg) {
		char getSure = 'y';
		cout << msg << endl;
		cin >> getSure;
		return getSure;

	}

	static clsBankClient getClientDeleted(string accountNum) {
		return clsBankClient(enMode::deleteMode,"", "", "", "", accountNum, "", 0);
	}


	static vector <clsBankClient> getClientsData() {
		return _loadClientsData("clients.txt");
	}

	void deposit(double amount) {
		_accountBalance += amount;
		save();
	}

	bool withdraw(double amount) {
		if (amount > _accountBalance) {
			return false;
		}
		_accountBalance -= amount;
		save();
		
	}

	static double getTotalBalance() {
		vector <clsBankClient> vClients = clsBankClient::getClientsData();
		double total = 0;

		for (clsBankClient& client : vClients) {
			
			total += client.accountBalance;

		}
		return total;
	}

	bool transfer(double amount , clsBankClient& destinationClient) {
		if (amount > accountBalance) {
			return false;
		}

		withdraw(amount);
		destinationClient.deposit(amount);
		return true;
	}


	


	static vector <stTransferLog> loadTransferLogDataFromFile() {
		fstream myfile;
		vector <stTransferLog> vTransLogs;

		myfile.open("transferLog.txt", ios::in);

		string line = "";

		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				stTransferLog transferLog = _convertLineToStruct(line);
				vTransLogs.push_back(transferLog);
			}
			myfile.close();
		}

		return vTransLogs;
	}
};