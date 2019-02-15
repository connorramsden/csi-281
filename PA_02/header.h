// Written by Connor Ramsden for CSI-281-02
#pragma once
#include <iostream>
#include <string>
using namespace std;

// Table size in main, prime
const int TABLE_SIZE = 127;
// File to open
const string FILE_IN = "karaoke.txt";
// Strings to check conditionals for actions read in from file
const string DO_ADD = "ADD";
const string DO_LIST = "LIST";
const string DO_DELETE = "DELETE";

struct Node
{
	string artist, title;
	Node* next;
};

class List
{
private:
	Node *head, *tail;

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	void addNode(Node *element); // Adds a song to a list
	void printByArtist(Node *element); // Prints all songs by a given artist in a list
	void removeSong(Node *element); // Removes a song from a list
};

int stringToASCII(string s); // Used in hashFunction() 

int hashFunction(Node * element); // Returns a hash key

// I think I could've likely condensed these into a single function, but due to how I structured main it seemed less possible
void addSong(istream & f, int & hash, Node * element, List arr[]);
void listSong(istream & f, int & hash, Node * element, List arr[]);
void deleteSong(istream &f, int & hash, Node * element, List arr[]);