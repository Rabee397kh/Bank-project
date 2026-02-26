#pragma once
#include "clsScreen.h"
class clsTransferScreen :
    protected clsScreen
{

private:


public:
    static void transferScreen() {
        _drawScreenHeader("Transfer Screen");

        string accountNum1 = clsInputValidate::readString("Enter Account Number to transfer from ? ");

        while (!clsBankClient::isClientExist(accountNum1)) {
            accountNum1 = clsInputValidate::readString("Account not found , Enter another Account ? ");
        }

        clsBankClient client1 = clsBankClient::find(accountNum1);
        client1.print();

        string accountNum2 = clsInputValidate::readString("Enter Account Number to transfer to ? ");

        while (!clsBankClient::isClientExist(accountNum2)) {
            accountNum2 = clsInputValidate::readString("Account not found , Enter another Account ? ");
        }

        while (accountNum2 == accountNum1) {
            accountNum2 = clsInputValidate::readString("You cannot Transfer to same Account , Enter another Account ? ");
        }
        clsBankClient client2 = clsBankClient::find(accountNum2);
        client2.print();

        int amount = 0;
        cout << "Enter Transfer Amount ?" << endl;
        cin >> amount;

        char ch = 'y';
        cout << "are you sure to perform this ?" << endl;
        cin >> ch;
        if (ch != 'y') {
            return;
        }

        /*while (amount > client1.accountBalance) {
            cout << " Amount Exceeds balance , Enter another Minmum Amount ?" << endl;
            cin >> amount;
        }

        char ch = 'y';
        cout << "are you sure to perform this ?" << endl;
        cin >> ch;
        if (ch != 'y') {
            return;
        }


        client1.accountBalance -= amount;
        client2.accountBalance += amount;

        client1.save();
        client2.save();

        cout << "Transfer Done Successfully !" << endl;

        client1.print();
        client2.print();*/

        if (client1.transfer(amount, client2)){
            cout << "Transfer done Successfully" << endl;
            clsBankClient::transferLog(client1, client2, amount);
        }
        else {
            cout << "Transfer Failed" << endl;
        }

        client1.print();
        client2.print();
    }
};

