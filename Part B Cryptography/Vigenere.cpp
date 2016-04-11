#include "Vigenere.h"

Vigenere::Vigenere(string key)
{
	for (int i = 0;i < key.size();++i) {

		if (key[i] >= 'A'&&key[i] <= 'Z')
			this->key += key[i];
		else if (key[i] >= 'a' && key[i] < 'z')
			this->key += key[i] + 'A' - 'a';
	}

}



string Vigenere::decrypt(string text)
{
	string output;

	for (int i = 0, j = 0; i < text.length(); ++i)
	{
		char c = text[i];

		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
		
			
			
			continue;

		output += (c - key[j] + 26) % 26 + 'A';
		j = (j + 1) % key.length();
	}

			return output;
};

