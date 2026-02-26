#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsDepositScreen :
    protected clsScreen
{
private:

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

    static bool _sure() {
        char s = 'y';

        cout << "Are you sure to perform this ? ";
        cin >> s;

        return tolower(s) == 'y';
    }

public:
    static void depositScreen() {
        _drawScreenHeader("Deposit Screen");
        string accountNum = clsInputValidate::readString("Enter Account Number ? ");

        while (!clsBankClient::isClientExist(accountNum) ){
            accountNum = clsInputValidate::readString("Sorry ! , we can't find account ,Enter Account Number Again? ");
        }

        clsBankClient client = clsBankClient::find(accountNum);
        _printClient(client);

        cout << "Enter Amount to Deposit ?" << endl;
        int amount = clsInputValidate::ReadDblNumber();

        if (!_sure()) {
            cout << "Amount Deposited Canceled !" << endl;
            return;
        }

        /*client.accountBalance += amount;
        client.save();
        */
        client.deposit(amount);

        cout << "Amount Deposited Successfully !" << endl; 
        cout << "New Balance = " << client.accountBalance << endl;
    }
};

