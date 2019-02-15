// Written by Connor Ramsden, Oct. 30 - Nov. 15, 2018
#include "header.hpp"

// Node constructor
Node * getNode(char ch, int freq, Node *left, Node *right)
{
	Node *temp = new Node;

	temp->nChar = ch;

	temp->nFreq = freq;

	temp->left = left;
	temp->right = right;

	return temp;
}

/*
	Recursively pushes 0, 1 into the passed STL unordered
	map from a priority queue (root) and a passed string
	Used in encodeMessage()
 */
void encode(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right)
	{
		huffmanCode[root->nChar] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

/*
	Supposed to be used in decodeMessage, works but not
	without encoding an entire message and decoding it again
*/
string decode(Node *root, int &index, string str)
{
	string decodedMsg = "";

	// Nullptr / final node, return nothing
	if (!root)
	{
		return "";
	}

	// No more leaves, add in final leaf-char

	if (!root->left && !root->right)
	{
		decodedMsg += root->nChar;
		return decodedMsg;
	}

	// iterate index
	index++;

	// Left / Right recursive adding to message
	if (str[index] == '0')
		decodedMsg += decode(root->left, index, str);
	else
		decodedMsg += decode(root->right, index, str);

	return decodedMsg;
}

// Primary Huffman Encoding Algorithm
string encodeMessage(string text)
{
	// Message to be returned at end
	string secretMessage = "";

	// STL unordered map for sorting
	unordered_map<char, int> freq;

	// Builds up the map from passed file string
	for (char ch : text)
	{
		freq[ch]++;
	}

	// Sorts map node using an STL priority queue
	priority_queue<Node *, vector<Node*>, compare> pq;

	// Automatically adds items from the map to the priority queue
	for (auto pair : freq)
	{
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// Pops items from the queue and adds them back to a new queue
	// That is sorted like a binary search tree
	while (pq.size() != 1)
	{
		Node * left = pq.top();
		pq.pop();

		Node * right = pq.top();
		pq.pop();

		int sum = left->nFreq + right->nFreq;

		pq.push(getNode('\0', sum, left, right));
	}

	// Takes final priority queue (size 1) into a Node
	Node * root = pq.top();

	// Another map for encoding
	unordered_map<char, string> huffmanCode;

	// Encodes the BST / PQ with huffman codes
	encode(root, "", huffmanCode);

	// Encodes the message using the binary strings into a returnable string
	for (char ch : text)
	{
		secretMessage += huffmanCode[ch];
	}

	return secretMessage;
}

/*
only could make it work if I take the original string, re-encode it all the way,
THEN decode it, which seems like the wrong way to do this.
*/

string decodeMessage(string text)
{
	return text;
}