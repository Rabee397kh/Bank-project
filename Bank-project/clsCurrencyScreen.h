#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalc.h"
class clsCurrencyScreen :
    protected clsScreen
{

private:
    enum enCurrencyMenu{enList = 1 , enFind = 2 , enUpdate = 3 , enCalc = 4 , enMain = 5};

    static int _readUserChoice() {
        int ch;
        cout << setw(30) << "" << "Choose from [1] to [5] ? ";
        cin >> ch;
        return ch;
    }

    static  void _goBackToCurrencyScreen() {
        cout << endl << endl << setw(30) << "" << "Go Back to Currency Screen ...";
        system("pause > 0");
        currencyScreen();

    }

    static void _showListCurrencyScreen() {
        clsCurrencyListScreen::listCurrency();
    }

    static void _showFindCurrencyScreen() {
        clsFindCurrencyScreen::findCurrency();
    }

    static void _showUpdateCurrencyScreen() {
        clsUpdateCurrencyScreen::updateCurr();
    }

    static void _showCalcCurrencyScreen() {
        clsCurrencyCalc::currencyCalc();
    }

    static  void _showMainMenuScreen() {
        //clsMainScreen::showMainMenu();
    }


   static void _performChoice(enCurrencyMenu currMenu) {
        switch (currMenu) {
        case enCurrencyMenu::enList:
        {
            system("cls");
            _showListCurrencyScreen();
            _goBackToCurrencyScreen();
            break;
        }
        case enCurrencyMenu::enFind:
        {
            system("cls");
            _showFindCurrencyScreen();
            _goBackToCurrencyScreen();
            break;
        }
        case enCurrencyMenu::enUpdate:
        {
            system("cls");
            _showUpdateCurrencyScreen();
            _goBackToCurrencyScreen();
            break;
        }
        case enCurrencyMenu::enCalc:
        {
            system("cls");
            _showCalcCurrencyScreen();
            _goBackToCurrencyScreen();
            break;
        }
        case enCurrencyMenu::enMain:
        {
            //system("cls");
            //_showMainMenuScreen();
            break;
        }
        }
    }

public:
    static void currencyScreen() {
        system("cls");
        _drawScreenHeader("Currency Exchange Main Screen");

        cout << setw(30) << "" << "=========================================================== " << endl;
        cout << setw(30) << "" << "                      Currency Exchange Menu" << endl;
        cout << setw(30) << "" << "===========================================================" << endl;
        cout << setw(30) << "" << "[1] List Currency." << endl;
        cout << setw(30) << "" << "[2] Find Currency." << endl;
        cout << setw(30) << "" << "[3] Update Currency." << endl;
        cout << setw(30) << "" << "[4] Currency Calculator." << endl;
        cout << setw(30) << "" << "[5] Main Menu." << endl;

        _performChoice((enCurrencyMenu)_readUserChoice());
    }
};

