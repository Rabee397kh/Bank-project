#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
#include <fstream>
#include <string>
#include <vector>
#include "global.h"

class clsUser : public clsPerson
{
private:
	enum enMode{emptyMode = 0 , updateMode = 1 , addMode = 2};
	enMode _mode;

	string _username;
	string _password;
	string _time;
	int _permission;
	bool _markToDelete = false;


	static clsUser _convertLineToUserObject(string line) {
		vector <string> vData = clsString::splitSt(line, "#//#");
		return clsUser(enMode::updateMode, vData[0], vData[1], vData[2], vData[3], 
			vData[4], clsUtil::DecryptText(vData[5],7), stoi(vData[6]));
	}

	static vector <clsUser> _loadUsersData(string filename) {
		vector <clsUser> vUsers;
		fstream myfile;

		myfile.open(filename, ios::in);

		string line;
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				clsUser user = _convertLineToUserObject(line);
				vUsers.push_back(user);
			}
			myfile.close();
		}

		return vUsers;
	}

	static clsUser _getEmptyUser() {
		return clsUser(enMode::emptyMode, "", "", "", "", "", "", 0);
	}


	string _convertUserObjectToLine(clsUser user , string delima = "#//#"){
		string line = "";
		line = user.fname + delima + user.lname + delima + user.email + delima + user.phone + delima +
			user.username + delima + clsUtil::EncryptText(user.password,7) + delima + to_string(user._permission);
		return line;
	}

	void _saveLineToFile(string line, string filename) {
		fstream myfile;

		myfile.open(filename, ios::app | ios::out);

		if (myfile.is_open()) {
			myfile <<  line << endl;
			myfile.close();
		}
	}


	void _add() {
		string line = _convertUserObjectToLine(*this);
		_saveLineToFile(line , "users.txt");
	}
	

	void _update() {
		vector <clsUser> vUsers = _loadUsersData("users.txt");

		for (clsUser& user : vUsers) {
			if (user.username == this->username) {
				user = *this;
			}
		}

		_saveUsersToFile(vUsers , "users.txt");
	}

	void _saveUsersToFile(vector <clsUser> vUsres , string filename) {
		fstream myfile;

		myfile.open(filename, ios::out);

		string line;
		if (myfile.is_open()) {
			for (clsUser& user : vUsres) {
				if (user._markToDelete == false) {
					line = _convertUserObjectToLine(user);
					myfile << line << endl;
				}
			}
			myfile.close();
		}
	}

	 string _convertUserObjectToLogLine( string delima = "#//#") {
		string log = "";
		log = clsDate::GetSystemDateString() + delima + username + delima + clsUtil::EncryptText(password,7) +
			delima + to_string(permission) ;

		return log;
	}

	 struct stRegisterLogin;

	 static stRegisterLogin _convertLogLineToStruct(string line) {
		 vector <string> vData = clsString::splitSt(line,"#//#");
		 stRegisterLogin registerLogin;
		 registerLogin.time = vData[0];
		 registerLogin.username = vData[1];
		 registerLogin.password = clsUtil::DecryptText(vData[2],7);
		 registerLogin.permission = stoi(vData[3]);
		 
		 return registerLogin;

	 }

	 

public:

	clsUser(enMode mode, string fname, string lname, string email, string phone, string username,
		string password, int permission) : clsPerson(fname, lname, email, phone) {
		_mode = mode;
		_username = username;
		_password = password;
		_permission = permission;
	}

	enum enPermissions {
		enAll = -1 , enListClients = 1 , enAddClient = 2 , enDeleteClient = 4 , enUpdateClient = 8 ,
		enFindClient = 16 , enTransactions = 32 , enManageUsers = 64 , enRegister = 128 , enCurrency = 256
	};

	void registerLogin() {
		fstream myfile;

		myfile.open("loginRegister.txt", ios::out | ios::app);

		string line = _convertUserObjectToLogLine();
		if (myfile.is_open()) {
		
			myfile <<  endl << line;
			myfile.close();
		}
	}

	struct stRegisterLogin {
		string time;
		string username;
		string password;
		int permission;
	};

	

	static vector <stRegisterLogin> getLoginRegister() {
		fstream myfile;
		vector <stRegisterLogin> vRegisters;

		myfile.open("loginRegister.txt", ios::in);

		string line = "";
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				stRegisterLogin registerLog = _convertLogLineToStruct(line);
				vRegisters.push_back(registerLog);
			}
			myfile.close();
		}
		return vRegisters;
	}

	bool isEmpty() {
		return _mode == enMode::emptyMode;
	}


	void setUsername(string username) {
		_username = username;
	}

	string getUsername() {
		return _username;
	}

	__declspec(property(get = getUsername, put = setUsername)) string username;

	void setPassword(string password) {
		_password = password;
	}

	string getPassword() {
		return _password;
	}

	__declspec(property(get = getPassword, put = setPassword)) string password;

	void setPermission(int permission) {
		_permission = permission;
	}

	int getPermission() {
		return _permission;
	}

	__declspec(property(get = getPermission, put = setPermission)) int permission;


	static clsUser find(string username) {
		vector <clsUser> vUsers = _loadUsersData("users.txt");

		for (clsUser& user : vUsers) {
			if (user.username == username) {
				return user;
			}
		}
		return _getEmptyUser();
	}

	static clsUser find(string username , string password) {
		vector <clsUser> vUsers = _loadUsersData("users.txt");

		

		for (clsUser& user : vUsers) {
			if (user.username == username && user.password == password){
				return user;
			}
		}
		return _getEmptyUser();
	}

	static bool isUserExist(string username) {
		clsUser user = find(username );

		return (!user.isEmpty());
	}


	static clsUser getNewUserObject(string username) {
		return clsUser(enMode::addMode, "" , "", "", "", username, "", 0);
	}


	enum enSaveResult{saveFailed = 0 , saveSuccessed = 1 };

	enSaveResult save() {
		switch (_mode) {
		case enMode::emptyMode:
		{
			return enSaveResult::saveFailed;
			break;
		}
		case enMode::addMode:
		{
			if (isUserExist(_username)) {
				return enSaveResult::saveFailed;
				
			}
			else {
				_add();
				_mode = enMode::updateMode;
				return enSaveResult::saveSuccessed;
				
			}
			break;
		}
		case enMode::updateMode:
		{
			_update();
			return enSaveResult::saveSuccessed;
			break;
		}
		}
	}

	bool deleteUserFromFile() {
		vector <clsUser> vUsres = _loadUsersData("users.txt");

		for (clsUser& user : vUsres) {
			if (user.username == this->username) {
				user._markToDelete = true;
			}
		}
		_saveUsersToFile(vUsres, "users.txt");
		*this = _getEmptyUser();
		return true;
	}

	static vector <clsUser> getUsers() {
		return _loadUsersData("users.txt");
	}

	bool checkPermissionAccess(enPermissions permission) {
		if (this->permission == enPermissions::enAll) {
			return true;
		}

		if ((permission & this->permission) == permission)
			return true;
		else
			return false;
	}

	/*static vector getRegisters() {

	}*/

};

