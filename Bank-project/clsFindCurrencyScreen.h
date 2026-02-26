#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsFindCurrencyScreen :
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

    static void _showResult(clsCurrency curr) {
        if (curr.isEmpty()) {
            cout << "Currency Not Found " << endl;
        }
        else {
            cout << "Currency Found " << endl;
            _print(curr);
        }
    }

public:
    static void findCurrency() {
        _drawScreenHeader("Find Currency Screen");

        int ch = 0;
        cout << "Find By [1]Code   or  [2]Country ?";
        cin >> ch;

        if (ch == 1) {
            string currCode = "";
            cout << "Enter currency Code ?";
            cin >> currCode;
            clsCurrency curr = clsCurrency::findByCode(currCode);
            _showResult(curr);


        }else if (ch == 2) {
            string country = "";

            cout << "Enter country ?";
            cin >> country;
            clsCurrency curr = clsCurrency::findByCountry(country);
            _showResult(curr);
        }
    }
};

