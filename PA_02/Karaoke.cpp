	/*
Author: Connor Ramsden
Class: CSI 281-02
Assignment: PA 02
Date Assigned: September 11th, 2018
Due Date: September 27th at 11:59 pm

Description: Demonstrates my understanding of hashtables and hashfunctions, as well as LinkedLists

Certification of Authenticity: I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:-Reproduce  this assignment and provide a copy to anothe  member of academic staff; and/or-Communicate a copy of this  assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)

Disclosures:
- I talked over my code (in place of a rubber duck) with another third-year, but they did not write any code or offer any assistance
*/
#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
using namespace std;

int main()
{
	ifstream fin(FILE_IN); // Opens karaoke.txt		
	int numCases; // For storing the first line of the input file

	if (fin)
	{
		fin >> numCases; // Reads in num testcases from file

		for (int i = 0; i < numCases; i++)
		{
			cout << "---------------------TEST CASE " << (i + 1) << "---------------------" << endl;

			List *jukebox = nullptr; // Instantiates list of pointers, setting them to null
			int maxInsertions, maxActions; // Stores additions and instructions

			jukebox = new List[TABLE_SIZE]; // initializes our list to be of size 127 (prime)

			fin >> maxInsertions >> maxActions; // Reads in lines 2, 3, and then again later if there's another test case			

			for (int j = 0; j < maxActions; j++)
			{
				Node * song = new Node; // Stores a single song
				int key = 0; // Stores key from hashFunction()
				string lineFunction; // Stores ADD || LIST || DELETE

				fin >> lineFunction; // Reads in ADD || LIST || DELETE

				if (lineFunction == DO_ADD)
				{
					addSong(fin, key, song, jukebox);
				}
				else if (lineFunction == DO_LIST)
				{
					listSong(fin, key, song, jukebox);
				}
				else if (lineFunction == DO_DELETE)
				{
					deleteSong(fin, key, song, jukebox);
				}
				else
				{
					cout << "Error in reading from file." << endl; // Debugging
				}
			}
			delete[] jukebox; // Deletes linked list, frees memory
			jukebox = nullptr; // Re-sets jukebox to nullptr
		}
	}
	else
	{
		cout << "ERROR: File Not Found. Press ENTER to exit." << endl;
		cin.get();
		return 0;
	}

	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}