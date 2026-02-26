#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsString.h"
using namespace std;



class clsCurrency
{
private:
	string _countryName;
	string _currencyCode;
	string _currencyName;
	float _exchangeRate;

	enum enMode{emptyMode = 1 , updateMode = 2};
	enMode _mode;

	static clsCurrency _convertLineToObject(string line) {
		vector <string> vData = clsString::splitSt(line);

		return clsCurrency(enMode::updateMode, vData[0], vData[1], vData[2], stof(vData[3]));
	}

	static vector <clsCurrency> _loadCurrencyData(string filename) {
		fstream myfile;
		vector <clsCurrency> vcurrs;

		myfile.open(filename, ios::in);

		string line = "";
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				clsCurrency currencyObject = _convertLineToObject(line);
				vcurrs.push_back(currencyObject);
			}
			myfile.close();
		}

		return vcurrs;
	}


	string _convertObjectToLine(clsCurrency curr) {
		string line = "";
		string delima = "#//#";
		
		line = curr._countryName + delima + curr._currencyCode + delima + curr._countryName + delima
			+ to_string(curr._exchangeRate);

		return line;
	}


	void _saveCurrencyDataToFile(vector <clsCurrency> vCurrs) {
		fstream myfile;

		myfile.open("Currencies.txt", ios::out);

		string line = "";
		if (myfile.is_open()) {
			for (clsCurrency& curr : vCurrs) {
				line = _convertObjectToLine(curr);
				myfile << line << endl;
			}
			myfile.close();
		}
	}

	void _update() {
		vector <clsCurrency> vCurrs = _loadCurrencyData("Currencies.txt");

		for (clsCurrency& curr : vCurrs) {
			if (curr._currencyCode == getCurrencyCode()) {
				curr = *this;
				break;
			}
		}
		_saveCurrencyDataToFile(vCurrs);
	}

public:

	clsCurrency( enMode mode , string countryname, string currencycode, string currencyname, float exchangeRate) {
		_countryName = countryname;
		_currencyCode = currencycode;
		_currencyName = currencyname;
		_exchangeRate = exchangeRate;
		_mode = mode;
	}

	string getCountryname() {
		return _countryName;
	}

	string getCurrencyCode() {
		return _currencyCode;
	}

	string getCurrencyname() {
		return _currencyName;
	}

	float getRate() {
		return _exchangeRate;
	}

	void updateRate(float exchangeRate) {
		_exchangeRate = exchangeRate;
		_update();
	}

	bool isEmpty() {
		return (_mode == enMode::emptyMode);
	}

	static clsCurrency findByCode(string currCode) {
		vector <clsCurrency> vcurrs = _loadCurrencyData("Currencies.txt");

		currCode = clsString::uppercaseSt(currCode);

		for (clsCurrency &curr : vcurrs) {
			if (curr._currencyCode == currCode) {
				return curr;
			}
		}

		return clsCurrency(enMode::emptyMode, "", "", "", 0);
	}

	static clsCurrency findByCountry(string countryname) {
		vector <clsCurrency> vcurrs = _loadCurrencyData("Currencies.txt");

		countryname = clsString::uppercaseSt(countryname);

		for (clsCurrency& curr : vcurrs) {
			if (clsString::uppercaseSt(curr.getCountryname()) == countryname) {
				return curr;
			}
		}

		return clsCurrency(enMode::emptyMode, "", "", "", 0);
	}

	static bool isCurrencyExist(string currCode) {
		clsCurrency curr = findByCode(currCode);

		return (!curr.isEmpty());

	}

	static vector <clsCurrency> getCurrencyList() {
		return _loadCurrencyData("Currencies.txt");
	}

	float convertToUsd(float amount) {
		return ((float)amount / getRate());
	}

	float convertToOthers(float amount ,clsCurrency curr2) {
		float amountInUsd = convertToUsd(amount);

		if (curr2._currencyCode == "USD") {
			return amountInUsd;
		}

		return (float)amountInUsd * curr2.getRate();
	}
};

