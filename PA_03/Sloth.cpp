/*
Author: Connor Ramsden
Class: CSI 281-02
Assignment: PA 03
Date Assigned: September 27th, 2018
Due Date: October 4th at 11:59 pm

Description: Demonstrates my ability to implement a Binary Search Tree and determine AVL compliance

Certification of Authenticity: I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:-Reproduce  this assignment and provide a copy to anothe  member of academic staff; and/or-Communicate a copy of this  assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)

Disclosures:
- None to Report
*/

#include "header.h"
#include <fstream>

int main()
{
	ifstream fin(FILE_IN);
	int numCases = 0;

	if (fin)
	{
		fin >> numCases; // Reads first line of input file
		// positive numCases < 100
		if (numCases >= MIN_CASES && numCases <= MAX_CASES)
		{	// Operates over numCases cases
			for (int i = 1; i <= numCases; ++i)
			{
				int numInsertions = 0;
				Node *tree = nullptr;

				fin >> numInsertions; // Reads first # in a given case
				// Inserts numInsertions integers in BST format
				for (int j = 0; j < numInsertions; ++j)
				{
					int temp = 0;
					fin >> temp;
					tree = insert(tree, temp); // Inserts in BST order
				}
				if (isTreeAVL(tree))
				{
					cout << "Tree #" << i << ": KEEP" << endl;
				}
				else
				{
					cout << "Tree #" << i << ": REMOVE" << endl;
				}
			}
		}
		else
		{
			cout << "You have an improper number of test cases. Press ENTER to exit." << endl;
			cin.get();
			return 0;
		}
	}
	else
	{
		cout << "ERROR: file not found. Press ENTER to exit." << endl;
		cin.get();
		return 0;
	}

	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}