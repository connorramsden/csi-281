// Written by Connor Ramsden, Oct. 30 - Nov. 15, 2018
#ifndef HEADER_CLASS
#define HEADER_CLASS

#ifndef HEADER_IN
#define HEADER_IN

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

#endif

// 1. Struct Declarations
struct Node
{
	char nChar;

	int nFreq;

	Node *left, *right;
};

struct compare
{
	bool operator()(Node *l, Node *r)
	{
		return l->nFreq > r->nFreq;
	}
};

// 2. Function Declarations

// Node constructor
Node * getNode(char ch, int freq, Node *left, Node *right);

/*	
	Recursively pushes 0, 1 into the passed STL unordered 
	map from a priority queue (root) and a passed string
	Used in encodeMessage()
 */
void encode(Node *root, string str, unordered_map<char, string> &huffmanCode);

string decode(Node *root, int &index, string str);

// Primary Huffman Encoding Algorithm
string encodeMessage(string text);

/* 
	Inverse Huffman Coding
	Converts passed binary string into a readable message
*/
string decodeMessage(string text);

#endif