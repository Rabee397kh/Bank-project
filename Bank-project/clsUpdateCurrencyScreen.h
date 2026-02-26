#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"


class clsUpdateCurrencyScreen :
    protected clsScreen
{
private:
    static void _print(clsCurrency curr) {

        cout << "==========================================" << endl;
        cout << "Country Name : " << curr.getCountryname() << endl;
        cout << "Country Code : " << curr.getCurrencyCode() << endl;
        cout << "CurrencyName : " << curr.getCurrencyname() << endl;
        cout << "Rate(1$)     : " << curr.getRate() << endl;
        cout << "==========================================" << endl;

    }
public:
    static void updateCurr() {
        _drawScreenHeader("Update Currency Screen");

        string currCode = "";
        cout << "Enter Currency Code ?";
        cin >> currCode;

        while (!clsCurrency::isCurrencyExist(currCode)) {
            cout << "Not Found ,Enter Currency Code Again?";
            cin >> currCode;
        }

        clsCurrency curr = clsCurrency::findByCode(currCode);
        _print(curr);
         
        char ans = 'y';
        cout << "are you sure to perform this ?";
        cin >> ans;

        if (ans != 'y') {
            return;
        }

        float rate = 0;

        cout << "Update Rate";
        cout << "Enter new Exchange Rate" << endl;
        cin >> rate;
        curr.updateRate(rate);

        cout << "Updated Successfully" << endl;
        _print(curr);
    }
};

