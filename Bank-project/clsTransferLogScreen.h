#pragma once
#include "clsScreen.h"
class clsTransferLogScreen :
    protected clsScreen
{
private:

public:
    static void transferLog() {
        _drawScreenHeader("Transfer Log");

        vector <clsBankClient::stTransferLog> vLogs = clsBankClient::loadTransferLogDataFromFile();
        cout << "______________________________________________________________________________________________________________" << endl;
        cout << setw(24) << left << " | Time" << setw(15) << left << " | TF Account" << setw(15)
            << left << " | TT Account" << setw(15) << left << " | Amount" <<  setw(15) 
            << left << " | TF Balance" << setw(15) << left << " | TT Balance" <<
            setw(9) << left << " | UserName" << endl;
        cout << "______________________________________________________________________________________________________________" << endl;


        for (clsBankClient::stTransferLog& log : vLogs) {
            cout << setw(24) << left << " | " + log.date << setw(15) << left << " | " + log.account1
                << setw(15) << left << " | " + log.account2 << setw(15) << left << " | " + to_string(log.amount) 
                << setw(15) << left << " | " + to_string(log.balance1) << setw(15) << left << " | " +
                to_string(log.balance2) << setw(9) << left << " | " + log.user <<  endl;
        }
    }
};

