#pragma once

#include <iostream>
#include <string>

using namespace std;

class Vigenere {

public: 
	string key;
	Vigenere(string Key);
	string decrypt(string text);

};