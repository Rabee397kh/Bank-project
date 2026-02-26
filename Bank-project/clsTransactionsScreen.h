#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include  "clsTotalbalanceScreen.h"
#include  "clsTransferScreen.h"
#include  "clsTransferLogScreen.h"
#include "iomanip"

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsOptions{enDeposit = 1 , enWithdraw = 2, enShowTotalBalances = 3 ,  enTransfer = 4  ,
		enTransferLog = 5    ,enBackToMainmenu = 6};

	static int _readTransactionsOptions() {
		cout << setw(30) << left << "" << "choose what do you want from [1 to 6] ?";
		int option = clsInputValidate::ReadIntNumberBetween(1,6);
		return option;
	}

	static void _goBackToTransactionsScreen() {
		cout << "Press any key to go back to Transactions Menu ...";
		system("pause > 0");
		showTransactionsScreen();
	}

	static void _showDepositScreen() {
		clsDepositScreen::depositScreen();
	}

	static void _showWithdrawScreen() {
		clsWithdrawScreen::withdrawScreen();
	}

	static void _showTotalBalancesScreen() {
		clsTotalbalanceScreen::getTotalBalance();
	}

	static void _showTransferScreen() {
		clsTransferScreen::transferScreen();
	}

	static void _showTransferLogScreen() {
		clsTransferLogScreen::transferLog();
	}

	static void _showMainMenuScreen() {
		/*clsMainScreen::showMainMenu();*/
	}

	static void _performTransactionsOption(enTransactionsOptions transactionOption) {
		switch (transactionOption) {
		case enTransactionsOptions::enDeposit:
		{
			system("cls");
			_showDepositScreen();
			_goBackToTransactionsScreen();
			break;
		}
		case enTransactionsOptions::enWithdraw:
		{
			system("cls");
			_showWithdrawScreen();
			_goBackToTransactionsScreen();
			break;
		}
		case enTransactionsOptions::enShowTotalBalances:
		{
			system("cls");
			_showTotalBalancesScreen();
			_goBackToTransactionsScreen();
			break;
		}
		case enTransactionsOptions::enTransfer:
		{
			system("cls");
			_showTransferScreen();
			_goBackToTransactionsScreen();
			break;
		}
		case enTransactionsOptions::enTransferLog:
		{
			system("cls");
			_showTransferLogScreen();
			_goBackToTransactionsScreen();
			break;
		}
		case enTransactionsOptions::enBackToMainmenu:
		{
			_showMainMenuScreen();
		
			break;
		}
		}
	}

public:
	static void showTransactionsScreen() {
		system("cls");
		_drawScreenHeader("Transactions Screen");

		cout << setw(30) << left << "" << "=================================================" << endl;
		cout << setw(30) << left << "" << "\t\tTransactions Menu" << endl;
		cout << setw(30) << left << "" << "=================================================" << endl;
		cout << setw(30) << left << "" << "\t[1] Deposit" << endl;
		cout << setw(30) << left << "" << "\t[2] Withdraw" << endl;
		cout << setw(30) << left << "" << "\t[3] Total Balances" << endl;
		cout << setw(30) << left << "" << "\t[4] Transfer" << endl;
		cout << setw(30) << left << "" << "\t[5] Transfer Log" << endl;
		cout << setw(30) << left << "" << "\t[6] Main Menu" << endl;
		cout << setw(30) << left << "" << "=================================================" << endl;

		_performTransactionsOption((enTransactionsOptions)_readTransactionsOptions());
	}
};

