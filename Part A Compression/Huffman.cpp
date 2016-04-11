#include "Huffman.h"

string Huffman::readFile(string in)
{
	cout << "\nRead file " << in << ".txt  :" << endl;
	ifstream instream(in + ".txt");

	if (instream.is_open()) {
		while (getline(instream, words)) {
			instream >> words;
		}
	}
	return words;
}

void Huffman::writeFile(string text, string n)
{
	cout << "\nWritten :\n" << text << "\nto File " << n << ".txt" << endl;
	ofstream outStream;
	outStream.open(n + ".txt");
	outStream << text;
	outStream.close();
}

void Huffman::freqBuild()
{
	for (int i = 0; i < words.length(); i++) {
		if (freqTab.find(words[i]) == freqTab.end()) {
			freqTab.insert(pair<char, int>(words[i], 1));
		}
		else { //If letter is found increment counter
			freqTab.find(words[i])->second++;
		}
	}
}

void Huffman::freqTablePrint()
{
	freqBuild(); //Put the build here for a cleaner main
	cout << endl << "\t-Frequency Table-" << endl;
	for (map<char, int>::iterator it = freqTab.begin(); it != freqTab.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
}

/***************************************************************************************
*	 Title: An In-Depth Look At Huffman Encoding
*    Author: KYA
*    Date: March 2016
*    Availability: http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
*
***************************************************************************************/
//Used the other provided moodle links too and StackOverflow

void Huffman::buildHeap()
{
	for (map<char, int>::iterator it = freqTab.begin(); it != freqTab.end(); ++it) {
		queue.emplace(new HuffNode(it->first, it->second)); //pushes node into priority queue
	}
	while (queue.size() != 1) {
		HuffNode *left = new HuffNode(queue.top()); //store the top
		queue.pop(); // pop the top from the heap
		HuffNode *right = new HuffNode(queue.top());
		queue.pop();
		HuffNode *heap = new HuffNode(left, right);
		queue.emplace(heap);
	}
	root = queue.top(); //root is the last node
	queue.pop();
}

void Huffman::huffEncode(HuffNode * root, string code)
{
	if (root->getLeft() == NULL) {  //Once it reaches the end it gets stored in a map and loop ends
		huffTab.insert(pair<char, string>(root->getData(), code));
		return;
	}
	else {											//each traversal adds a bit
		huffEncode(root->getLeft(), code + '0');   // left = 0
		huffEncode(root->getRight(), code + '1'); // right = 1
	}
}

string Huffman::huffDecode(string in)
{
	string text = "";
	HuffNode* ptr = root;
	for (int i = 0; i != words.size(); i++) {
		if (words[i] == '0') { //0 == left
			ptr = ptr->getLeft();
		}
		if (words[i] == '1') { //1 == right
			ptr = ptr->getRight();
		}
		if (ptr->getLeft() == nullptr && ptr->getRight() == nullptr) {
			text += ptr->getData(); 
			ptr = root; //put it to root
		}	
	}
	return text;
}

void Huffman::huffTablePrint()
{
	buildHeap();
	huffEncode(root, "");
	cout << "\t-Binary Table-" << endl;

	for (map<char, string>::iterator it = huffTab.begin(); it != huffTab.end(); it++) {
		cout << it->first << " " << it->second << endl;    //prints out the table
	}
	cout << endl;
}

void Huffman::writeHuffToFile(string file)
{
	for (int i = 0; i <words.size(); i++) { // Loop through imput
		code += huffTab.find(words[i])->second; //Encode the characters with huffman into a string
	}
	writeFile(code, file);  //Put it in a txt
}

void Huffman::huffCompress(string file)
{
	string compress;
	bitset<8> byte;

	while (code.size() % 8 != 0) {
		code.append("0"); //adds 0 till divisible by 8
	}
	stringstream stream(code);

	while (!stream.eof()) { //Loops till end of the string and puts the ascii into a string
		stream >> byte;
		char letter = char(byte.to_ulong());
		compress += letter;
	}
	compress.pop_back(); //get rid of extra 0's

	writeFile(compress, file);
}

string Huffman::huffDecompress(string file)    // only decompresses the previously compressed Huffmancode, not really specified if required to decompress or compress different Files.
{
	string decompress;
	bitset<8> byte;

	for (int i = 0; i < words.length(); i++) {
		byte = words[i];
		decompress += byte.to_string();
	}
	writeFile(decompress,file);
	return decompress;
}

