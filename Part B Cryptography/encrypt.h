#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;


class MyTransform {

private:
	int shift;

	/***************************************************************************************
	*    Title:Caesar cipher
	*    Author: RosettaCode
	*    Date:  21 March 2016
	*    Availability: http://rosettacode.org/wiki/Caesar_cipher#C.2B.2B
	*
	************************************************************************************/

public:
	
	MyTransform(int s) : shift(s) {}

	char operator()(char c) {

		if (isspace(c))
			return ' ';
		else if (isalpha(c)) {

			static string letters("abcdefghijklmnopqrstuvwxyz");
			string::size_type found = letters.find(tolower(c));

			int shiftedpos = (static_cast<int>(found) + shift) % 26;
			if (shiftedpos < 0)

				shiftedpos = 26 + shiftedpos;
			char shifted = letters[shiftedpos];
			return shifted;
		}
		else {

			return c;
		}

	}
};