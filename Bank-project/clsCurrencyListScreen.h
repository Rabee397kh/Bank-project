#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrencyListScreen :
    protected clsScreen
{
private:
    static void _print(clsCurrency curr) {
        cout << setw(30) << left << " | " + curr.getCountryname() << setw(5) << left 
            << " | " + curr.getCurrencyCode() << setw(30)<< left << " | " + curr.getCurrencyname() << setw(10) 
            << left << " | " + to_string(curr.getRate()) << endl;

    }
public:
    static void listCurrency() {
        vector <clsCurrency> vCurrs = clsCurrency::getCurrencyList();
        _drawScreenHeader("List Currency");

        cout << "________________________________________________________________________________________" << endl;
        cout << setw(30) << left << " | Country" << setw(5) << left << " | Code" << setw(30)
            << left << " | Name" << setw(10) << left << " | Rate(1$)" << endl;
        cout << "________________________________________________________________________________________" << endl;

        for (clsCurrency& curr : vCurrs) {
            _print(curr);
        }
        cout << "________________________________________________________________________________________" << endl;

    }
};

