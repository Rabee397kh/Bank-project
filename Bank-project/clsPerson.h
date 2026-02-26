#pragma once
#include <iostream>
#include "interfaceCommunication.h"
using namespace std;


class clsPerson  : public interfaceCommunication{
private:
	string _fname;
	string _lname;
	string _email;
	string _phone;

public:

	void sendEmail(string title , string body) {

	}


	void sendFax(string title, string body) {

	}


	clsPerson(string fname, string lname, string email, string phone) {
		_fname = fname;
		_lname = lname;
		_email = email;
		_phone = phone;
	}

	void setFname(string fname) {
		_fname = fname;
	}

	string getFname() {
		return _fname;
	}

	__declspec(property(get = getFname, put = setFname)) string fname; 

	void setLname(string lname) {
		_lname = lname;
	}

	string getLname() {
		return _lname;
	}

	__declspec(property(get = getLname, put = setLname)) string lname;

	void setEmail(string email) {
		_email = email;
	}

	string getEmail() {
		return _email;
	}

	__declspec(property(get = getEmail, put = setEmail)) string email;

	void setPhone(string phone) {
		_phone = phone;
	}

	string getPhone() {
		return _phone;
	}

	__declspec(property(get = getPhone, put = setPhone)) string phone;

	string fullName() {
		return _fname + " " + _lname;
	}
};