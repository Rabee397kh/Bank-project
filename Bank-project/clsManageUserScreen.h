#pragma once
#include "clsScreen.h"
#include "iomanip"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsListUserScreen.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsUpdateUserScreen.h"

class clsManageUserScreen : protected clsScreen
{
private:
	enum enManageUserOptions{enListUsers = 1 , enAdduser = 2 , enDeleteuser = 3 , enUpdateuser = 4 , 
		enFinduser = 5 ,enMainmenuScreen = 6};

	static int _readUserChoice() {
		cout << setw(30) << left << "" << "Enter your choice from [1 to 6] ? ";
		int choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return choice;
	}

	static void _goBackToManageUserScreen() {
		cout << "Press any key to go back to Manage User Screen ..." << endl;
		system("pause > 0");
		showManageUserScreen();
	}

	static void _listUserScreen() {
		clsListUserScreen::listUser();
	}

	static void _addUserScreen() {
		clsAddUserScreen::addUser();
	}

	static void _deleteUserScreen() {
		clsDeleteUserScreen::deleteUser();
	}

	static void _updateUserScreen() {
		clsUpdateUserScreen::updateUser();
	}

	static void _findUserScreen() {
		clsFindUserScreen::findUser();
	}

	static void _MainMenuScreen() {
		cout << "main menu  screen";
		//clsMainScreen::showMainMenu();

	}

	static void _performManageUserScreen(enManageUserOptions userOption) {
		switch (userOption) {
		case enManageUserOptions::enListUsers:
		{
			system("cls");
			_listUserScreen();
			_goBackToManageUserScreen();
			break;
		}
		case enManageUserOptions::enAdduser: 
		{
			system("cls");
			_addUserScreen();
			_goBackToManageUserScreen();
			break;
		}
		case enManageUserOptions::enDeleteuser:
		{
			system("cls");
			_deleteUserScreen();
			_goBackToManageUserScreen();
			break;
		}
		case enManageUserOptions::enUpdateuser:
		{
			system("cls");
			_updateUserScreen();
			_goBackToManageUserScreen();
			break;
		}
		case enManageUserOptions::enFinduser:
		{
			system("cls");
			_findUserScreen();
			_goBackToManageUserScreen();
			break;
		}
		case enManageUserOptions::enMainmenuScreen:
		{
			system("cls");
			_MainMenuScreen();
			//clsMainScreen::showMainMenu();
			break;
		}
		}
	}

public:
    static void showManageUserScreen() {
        system("cls");
        _drawScreenHeader("Manage User Screen");

		cout << setw(30) << left << "" << "=================================================" << endl;
		cout << setw(30) << left << "" << "\t\tManage User Menu" << endl;
		cout << setw(30) << left << "" << "=================================================" << endl;
		cout << setw(30) << left << "" << "\t[1] List Users" << endl;
		cout << setw(30) << left << "" << "\t[2] Add New User" << endl;
		cout << setw(30) << left << "" << "\t[3] Delete User" << endl;
		cout << setw(30) << left << "" << "\t[4] Update User" << endl;
		cout << setw(30) << left << "" << "\t[5] Find User" << endl;
		cout << setw(30) << left << "" << "\t[6] Main Menu" << endl;

		_performManageUserScreen((enManageUserOptions)_readUserChoice());
    }
};

