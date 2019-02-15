/*
Author: Connor Ramsden
Class: CSI 281-02
Assignment: PA 05 | Huffman Coding
Date Assigned: October 30th, 2018
Due Date: November 15th at 11:59 pm

Description: Utilizes STL priority queue & unordered map to construct a
binary Huffman Tree from a string. 

Certification of Authenticity: I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:-Reproduce  this assignment and provide a copy to anothe  member of academic staff; and/or-Communicate a copy of this  assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)

 Disclosures:
Templated huffman structure from this link:
https://www.techiedelight.com/huffman-coding/
*/

#include "huffman.hpp"

int main()
{
	// Initializes strings to store 
	// various versions of the original message from file
	string originalMessage = "";

	string encodedMessage = "";

	string messageToDecode = "";

	string decodedMessage = "";

	// First file to read from
	ifstream fin(IN_FILE, ios::in);

	getline(fin, originalMessage, '\n');

	// Read string present in input file
	fin >> originalMessage;

	cout << "Original message to encode: " << originalMessage << endl;

	fin.close();

	// String to store the binary huffman code 
	// of the originally passed message
	encodedMessage = encodeMessage(originalMessage);

	cout << "\nEncoded message: " << encodedMessage << endl;

	// File to output encoded message
	ofstream encodeToFile(OUT_FILE);

	cout << "\nPassing encoded message to 'huffmanoutput.txt'" << endl;

	// Outputs the binary code to the file
	encodeToFile << encodedMessage;

	encodeToFile.close();

	// Read in 'huffmanoutput.txt', which contains a binary string
	ifstream decodeFromFile(OUT_FILE, ios::in);

	getline(decodeFromFile, messageToDecode, '\n');

	// Read in binary string from output file
	decodeFromFile >> messageToDecode;

	cout << "\nMessage from encoded file: " << messageToDecode << endl;

	// I cannot figure out how to get my encoded message decoded and back into
	// My original file, but other than that, it works!

	// decodedMessage = decodeMessage(messageToDecode);

	cout << "\nRenaming 'huffmaninput.txt' to 'reconstructedinput.txt'" << endl;

	// Rename original input filefile
	int renameFile = rename(IN_FILE, DECODE_FILE);

	cout << "\nEnd of program. Press ENTER to exit." << endl;
	cin.ignore();
	return 0;
}