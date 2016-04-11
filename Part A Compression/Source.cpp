#include "Huffman.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	Huffman huffman;                                //-no need to add .txt at end of filenames
	cout << huffman.readFile("text") << endl;       //Read in normal text					
	cout << "\n---Tables 1.2.---\n";
	huffman.freqTablePrint();							//Builds and prints frequency Table
	huffman.huffTablePrint();							//Build and prints Huffman Table
	cout << "\n---Encode to file 3.4.---\n";
	huffman.writeHuffToFile("huffman");				//Writes the normal text in Huffman to a .txt
	cout << huffman.readFile("huffman") << endl;    //Prints out the numbers
	cout << "\n---Decode 5.---\n";
	cout << huffman.huffDecode(huffman.readFile("huffman")) << endl;            //Decodes the Huffman tree and prints out the text
	cout << "\n---Compression to file / Decompression 6.7.---\n";
	huffman.huffCompress("compressedHuff");                                     //Compresses the huffman code from the original .txt     
	cout << huffman.readFile("compressedHuff") << endl;							//Prints the compressed code
	huffman.huffDecompress("decompressedHuff");									//Decompresses back to normal Huffman and puts it in a new decompressedHuff.txt
	cout << huffman.huffDecode(huffman.readFile("decompressedHuff")) << endl;	//Prints out the .txt 

	system("pause");
	return 0;
}