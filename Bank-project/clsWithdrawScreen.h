#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


class clsWithdrawScreen :
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
    static void withdrawScreen() {
        _drawScreenHeader("Withdraw Screen");
        string accountNum = clsInputValidate::readString("Enter Account Number ? ");

        while (!clsBankClient::isClientExist(accountNum)) {
            accountNum = clsInputValidate::readString("Sorry ! , we can't find account ,Enter Account Number Again? ");
        }

        clsBankClient client = clsBankClient::find(accountNum);
        _printClient(client);

        cout << "Enter Amount to Withdraw ?" << endl;
        int amount = 0;
        amount = clsInputValidate::ReadDblNumber();

       while (amount > client.accountBalance) {
            cout << "Sorry Your account balance isn't sufficient !! Enter another amount ?" << endl;
            amount = clsInputValidate::ReadDblNumber();
        }

       if (!_sure()) {
           cout << "Amount Withdraw Canceled !" << endl;
           return;
       }

        if (!client.withdraw(amount)) {
            cout << "Amount Withdraw Failed !" << endl;
            cout << "Account Balance = " << client.accountBalance << endl;
            cout << "Withdraw Amount = " << amount << endl;
            return;
        }
        else {
            cout << "Amount Withdraw Successfully !" << endl;
            cout << "New Balance = " << client.accountBalance << endl;
        }        
    }
    
};

