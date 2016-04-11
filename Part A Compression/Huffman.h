#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <bitset>
#include <sstream>
#include "HuffNode.h"
using namespace std;

class Huffman {
private:
	map<char, int> freqTab; // Character Frequency
	map<char, string> huffTab; // Characters and Huffman code
	priority_queue<HuffNode*, vector<HuffNode*>, HuffCompare> queue;
	HuffNode *root = nullptr;
	string words, code;

	void huffEncode(HuffNode*, string);  //private cause Security
	void buildHeap(); // Word and Freq put in Queue, Build tree.

public:
	string readFile(string); // Read the txt
	void writeFile(string, string); //Quick way of making a new file to store in a txt.

	void freqBuild(); //Frequency
	void freqTablePrint();

	void huffTablePrint();

	string huffDecode(string);

	void writeHuffToFile(string); //Write a txt using the table and the input text

	void huffCompress(string);
	string huffDecompress(string);

};