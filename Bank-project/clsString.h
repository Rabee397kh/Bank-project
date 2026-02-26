#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class clsString
{
private:
	string _value;

public:
	clsString() {
		_value = "";
	}

	clsString(string st) {
		_value = st;
	}

	void setValue(string st) {
		_value = st;
	}

	string getValue() {
		return _value;
	}

	__declspec(property(get = getValue, put = setValue)) string st;

	//count-word
	static short countWord(string st , string delima = " ") {
		string word = "";
		int pos , counter = 0;
		while ((pos = st.find(delima)) != std::string::npos) {
			word = st.substr(0, pos);
			if (word != "") {
				counter++;
			}
			st.erase(0, pos + delima.length());
		}
		if (st != "") {
			counter++;
		}
		return counter;
	}

	int countWord() {
		return countWord(_value);
	}


	//split
	static vector <string> splitSt(string st, string delima = "#//#") {
		string word = "";
		vector <string> vWord;
		int pos = 0;
		while ((pos = st.find(delima)) != std::string::npos) {
			word = st.substr(0, pos);
			if (word != "") {
				vWord.push_back(word);
			}
			st.erase(0, pos + delima.length());
		}
		if (st != "") {
			vWord.push_back(st);
		}
		return vWord;
	}

	vector <string> splitSt() {
		return splitSt(_value);
	}

	//join
	
	static string joinSt(vector <string> vWords, string delima = " ") {
		string st = "";

		for (int i = 0; i < vWords.size(); i++) {
			st += vWords[i] + delima;
		}
		st = st.substr(0, st.length() - delima.length());
		return st;
	}



	//uppercase

	static string uppercaseSt(string st) {
		string upperSt = "";
		for (int i = 0; i < st.length(); i++) {
			upperSt += toupper(st[i]);
		}

		return upperSt;
	}

	string uppercaseSt() {
		return uppercaseSt(_value);
	}

	//lowercase

	static string lowercaseSt(string st) {
		string lowerSt = "";
		for (int i = 0; i < st.length(); i++) {
			lowerSt += tolower(st[i]);
		}

		return lowerSt;
	}

	string lowercaseSt() {
		return lowercaseSt(_value);
		
	}



	//invert charcter case
	static char invertCase(char c) {
		return islower(c) ?  toupper(c) : tolower(c);
	}

	//invert All letter case

	static string invertAll(string st) {

		for (int i = 0; i < st.length(); i++) {
			st[i] = invertCase(st[i]);
		}

		return st;
	}

	string invertAll() {
		return invertAll(_value);
	}


	//count small letter
	static short countSmallLetter(string st) {
		short counter = 0;
		for (int i = 0; i < st.length(); i++) {
			islower(st[i]) && counter++;
		}
		return counter;
	}


	//count capital letter
	static short countCapitalLetter(string st) {
		short counter = 0;
		for (int i = 0; i < st.length(); i++) {
			isupper(st[i]) && counter++;
		}
		return counter;
	}

	short countCapitalLetter() {
		return countCapitalLetter(_value);
	}



	//count small-capital-all
	enum enLetters{capital = 1 , small = 2 , all = 3};
	
	static short countletters(string st, enLetters letters = enLetters::all) {
		short counter = 0;
		if (enLetters::all) {
			return st.length();
		}

		for (int i = 0; i < st.length(); i++) {
			if (letters == enLetters::small && islower(st[i])) {
				counter++;
			}
			else if (letters == enLetters::capital && isupper(st[i])) {
				counter++;
			}
		}
		return counter;
		
	}


	//count character in string

	static short countCharInString(string st, char c ,bool matchcase = false) {
		short counter = 0;
		if (matchcase == false) {
			for (int i = 0; i < st.length(); i++) {

				tolower(c) == tolower(st[i]) && counter++;
			}
		}
		else {
			for (int i = 0; i < st.length(); i++) {

				c == st[i] && counter++;
			}
		}
			
		
		return counter;
	}



	//is vowel

	static bool isVowel(char c) {
		vector <char> vChars = { 'a' , 'e' , 'i' , 'o' , 'u' };

		for (char &ch : vChars) {
			if (tolower(c) == ch) {
				return true;
			}
		}

		return false;
	}


	//count vowel in string

	static short countVowel(string st) {
		short counter = 0;

		for (int i = 0; i < st.length(); i++) {
			/*for (int j = 0; j < vChars.size(); j++) {
				if (tolower(st[i]) == vChars[j]) {
					counter++;
				}
			}*/
			isVowel(st[i]) && counter++;
		}

		return counter;
	}

	short countVowel() {
		return countVowel(_value);
	}

	static void printVowel(string st) {
		
		

		for (int i = 0; i < st.length(); i++) {
			
				if (isVowel(st[i])){
					cout << st[i] << " ";
			    }
		}

		
	}




	//printEachWordInString
	static void printEachWordInString(string st , string delima ) {
		vector <string> vWords = splitSt(st , delima);

		for (int i = 0; i < vWords.size(); i++) {
			cout << vWords[i] << endl;
		}
	}

	

	//trim
	//trim left

	static string trimLeft(string st) {
		for (int i = 0; i < st.length(); i++) {
			if (st[i] != ' ') {
				return st.substr(i, st.length() - i);
			}
		}
	}

	static string trimRight(string st) {
		for (int i = st.length()-1; i >= 0; i--) {
			if (st[i] != ' ') {
				return st.substr(0,i+1);
			}
		}
	}

	static string trim(string st) {
		return trimRight(trimLeft(st));
	}




	//reverse
	static string reverse(string st) {
		vector <string> vWords = splitSt(st);

		string reversed = "";
		for (int i = vWords.size() - 1; i >= 0; i--) {
			reversed += vWords[i] + " ";
		}
		reversed = reversed.substr(0, reversed.length() - 1);
		return reversed;
	}

	string reverse() {
		return reverse(_value);
	}

	//replace


	static string replace(string st, string replaced, string replaceBy) {
		short pos = st.find(replaced);

		while (pos != std::string::npos) {
			st = st.replace(pos, replaced.length(), replaceBy);
			pos = st.find(replaced);
		}

		return st;
	}




	//custom replace
	static string customReplace(string st, string replaced, string replaceBy , bool match = false) {
		vector <string> vWords = splitSt(st);


		string newSt = "";
		if (match) {
			for (string& word : vWords) {

				if (replaced == word) {
					word = replaceBy;
				}
				//newSt += word + " ";
			}
		}
		else {
			for (string& word : vWords) {

				if (lowercaseSt(replaced) == lowercaseSt(word)) {
					word = replaceBy;
				}
				//newSt += word + " ";
			}
		}
		
		//newSt = newSt.substr(0, newSt.length() - 1);
		//return newSt;
		st = joinSt(vWords);
		return st;
	}

	//remove punctuations
	static string removePunctuation(string st) {
		string st2 = "";

		for (int i = 0; i < st.length(); i++) {
			if (!ispunct(st[i])) {
				st2 += st[i];
			}
		}

		return st2;
	}
};

