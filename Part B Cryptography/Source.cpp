#include "encrypt.h"
#include "decrypt.h"
#include "vigenere.h"

using namespace std;


int main() {

	ifstream poem;
	string input;
	ofstream ePoem;

	poem.open("input.txt");
	ePoem.open("encrypted.txt");

	int myshift = 0;
	cout << "Enter Number to Shift data\n";
	cin >> myshift;
	cout << "Encrypted Text:\n " << endl;

	if (poem) {
		getline(poem, input);
		
		while (poem)
		{
			transform(input.begin(), input.end(), input.begin(), MyTransform(myshift));
			cout << input << endl;
			ePoem << input << endl;

			getline(poem, input);
		}

		poem.close();
		ePoem.close();

		remove("input.txt");
		int rc = rename("encrypted.txt", "input.txt");

	}

	system("pause&quot");
	system("CLS");
	cout << "\n\t\t\t\tDecrypting Secret File " << endl;

	ifstream secret;
	string input2;
	ofstream dSecret;

	array<double, 26> english = {
			0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228,
			0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025,
			0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
			0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
			0.01974, 0.00074 };

		VigenereAnalyser va(english);
		secret.open("secret555.txt ");
		
		
		if (secret) {
			getline(secret, input2);
			
			while (secret)
			{
				transform(input2.begin(), input2.end(), input2.begin(), ::toupper);
				getline(secret, input2);
				
			}
			secret.close();
			
					}

		
		string output = va.analyze(input2);
		Vigenere cipher(output);


		cout << "\nKey to dechiper text is : " << output << endl;
		string decrypt = cipher.decrypt(input2);
		cout << "\n\nDecrypted text:\n " << decrypt << endl;
		
		dSecret.open("DecrptyedSecret555.txt");
		dSecret << decrypt << endl;
		dSecret.close();

		system("pause&quot");
		return 0;

}