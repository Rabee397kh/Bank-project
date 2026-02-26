#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"


class clsCurrencyCalc :
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

    static clsCurrency _readCurrency(string currCode , string msg) {
        cout << msg << endl;
        cin >> currCode;

        while (!clsCurrency::isCurrencyExist(currCode)) {
            cout << "currency not found " << msg << "again" << endl;
            cin >> currCode;
        }

        clsCurrency curr = clsCurrency::findByCode(currCode);

        return curr;
    }
public:
   static void currencyCalc() {
       _drawScreenHeader("Currency Calculator");

       string currCode1, currCode2;
       clsCurrency curr1 = _readCurrency(currCode1 , "enter currency 1 code ");
       clsCurrency curr2 = _readCurrency(currCode2, "enter currency 2 code ");


       float amount,res = 0;
       
       cout << "enter amount" << endl;
       cin >> amount;

       cout << "Convert From " << endl;
       _print(curr1);

       amount = curr1.convertToUsd(amount);

       if (curr2.getCurrencyCode() != "USD") {
           cout << "Convert To " << endl;
           _print(curr2);
           amount = curr1.convertToOthers(amount, curr2);

       }

       cout << to_string(amount) << curr1.getCurrencyCode() << " = " << res << curr2.getCurrencyCode();

       char c = 'y';
       cout << "do you want to perform another one ?";
       cin >> c;

       if (c == 'y') {
           system("cls");
           currencyCalc();
       }

    }
};

