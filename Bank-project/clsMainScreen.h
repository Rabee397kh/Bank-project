#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsListClientScreen.h"
#include "clsAddClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "clsLoginScreen.h"
#include "clsRegisterLoginScreen.h"
#include "clsCurrencyScreen.h"
#include "global.h"
#include <iostream>
#include <iomanip>
using namespace std;


class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuOption{enlistClient = 1 , enaddClient = 2 , endeleteClient = 3 , enupdateClient = 4 , 
		enfindClient = 5, entransactions = 6 , enmanageUsers = 7 ,  enLoginRegister ,enCurrency = 9 , 
		enlogout = 10
	};

	static int _readMainMenuOption() {
		cout << setw(30) << left << "" << "choose what do you want from [1] to [10] ?";
		int choice = 0;
		choice = clsInputValidate::ReadIntNumberBetween(1, 10);
		return choice;
	}

	static void _goBackToMainMenu() {
		cout << endl << endl << setw(30) << left << "" << " Press any key to continue ...";
		system("pause > 0");
		showMainMenu();
	}

	static void _showAllClientsScreen() {
		clsListClientScreen::listClients();
		
		
	}

	static void _showAddClientsScreen() {
		clsAddClientScreen::showAddClient();
	}

	static void _showDeleteClientsScreen(){
		clsDeleteClientScreen::showDeleteClient();
	}

	static void _showUpdateClientsScreen() {
		clsUpdateClientScreen::updateClient();
	}

	static void _showFindClientsScreen() {
		clsFindClientScreen::findClient();
	}

	static void _showTransactionsScreen() {
		clsTransactionsScreen::showTransactionsScreen();
	}

	static void _showManageUsersScreen() {
		clsManageUserScreen::showManageUserScreen();
	}

	static void _showRegisterLoginScreen() {
		clsRegisterLoginScreen::registerLogin();
	}
	static void _showCurrencyScreen() {
		clsCurrencyScreen::currencyScreen();
	}

	static void _showLogoutScreen() {
		//CurrentUser = clsUser::find("", "");
		 //clsLoginScreen::loginScreen();
	}

	static void _performMainMenuOption(enMainMenuOption menuOption) {
		switch (menuOption) {
		case enMainMenuOption::enlistClient:
		{
			system("cls");
			if (checkAccessRight(clsUser::enPermissions::enListClients)) {
				system("cls");
				_showAllClientsScreen();
				_goBackToMainMenu();
				break;
			}
		}
		case enMainMenuOption::enaddClient:
		{
			if (checkAccessRight(clsUser::enPermissions::enAddClient)) {
				system("cls");
				_showAddClientsScreen();
				_goBackToMainMenu();
				break;
			}
		}
		case enMainMenuOption::endeleteClient:
		{
			system("cls");
			if (checkAccessRight(clsUser::enPermissions::enDeleteClient)) {
				system("cls");
				_showDeleteClientsScreen();
				_goBackToMainMenu();
				break;
			}
		}
		case enMainMenuOption::enupdateClient:
		{
			if (checkAccessRight(clsUser::enPermissions::enFindClient)) {
				system("cls");
				_showUpdateClientsScreen();
				_goBackToMainMenu();
				break;
			}
		}
		case enMainMenuOption::enfindClient:
		{
			if (checkAccessRight(clsUser::enPermissions::enFindClient)) {
				system("cls");
				_showFindClientsScreen();
				_goBackToMainMenu();
				break;
			}
			
		}
		case enMainMenuOption::entransactions:
		{
			if (checkAccessRight(clsUser::enPermissions::enTransactions)) {
				system("cls");
				_showTransactionsScreen();
				_goBackToMainMenu();
				break;
			}
		}
		case enMainMenuOption::enmanageUsers:
		{
			if (checkAccessRight(clsUser::enPermissions::enManageUsers)) {
				system("cls");
				_showManageUsersScreen();
				_goBackToMainMenu();
				break;
			}
		}
		case enMainMenuOption::enLoginRegister:
		{
			if (checkAccessRight(clsUser::enPermissions::enRegister) ){
				system("cls");
				_showRegisterLoginScreen();
				_goBackToMainMenu();
				break;
			}
		}
		case enMainMenuOption::enCurrency:
		{
			if (checkAccessRight(clsUser::enPermissions::enCurrency)) {
				system("cls");
				_showCurrencyScreen();
				//_goBackToMainMenu();
				break;
			}
		}
		case enMainMenuOption::enlogout:
		{
			system("cls");
			_showLogoutScreen();
			break;
		}
		}
	}



public:
	
	static void showMainMenu() {
		system("cls");
		_drawScreenHeader("\t\tMain Screen");

		cout << setw(30) << left << "" << "=================================================" << endl;
		cout << setw(30) << left << "" << "\t\tMain Menu" << endl;
		cout << setw(30) << left << "" << "=================================================" << endl;
		cout << setw(30) << left << "" << "\t[1] Show Client List" << endl;
		cout << setw(30) << left << "" << "\t[2] Add New Client" << endl;
		cout << setw(30) << left << "" << "\t[3] Delete Client" << endl;
		cout << setw(30) << left << "" << "\t[4] Update Client" << endl;
		cout << setw(30) << left << "" << "\t[5] Find Client" << endl;
		cout << setw(30) << left << "" << "\t[6] Transactions" << endl;
		cout << setw(30) << left << "" << "\t[7] Manage Users" << endl;
		cout << setw(30) << left << "" << "\t[8] Login Register List" << endl;
		cout << setw(30) << left << "" << "\t[9] Currency Exchange" << endl;
		cout << setw(30) << left << "" << "\t[10] Logout" << endl;

		_performMainMenuOption((enMainMenuOption)_readMainMenuOption());
	}
};

