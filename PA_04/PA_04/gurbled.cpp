/*
Author: Connor Ramsden
Class: CSI 281-02
Assignment: PA 04 | Hamgurbled
Date Assigned: October 19th, 2018
Due Date: October 29th at 11:59 pm

Description: Demonstrates understanding of the Priority Queue Datastructure, implemented as a Heap (Binary Tree)

Certification of Authenticity: I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:-Reproduce  this assignment and provide a copy to anothe  member of academic staff; and/or-Communicate a copy of this  assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)

Disclosures / Notes:
- psuedocode for heap layout sourced from GeeksForGeeks.com, only after attempting on my own a few times.
- My first test-case is basic operation testing
- My second test-case tests if orders end at the same time, how do they resolve?
- Also tests larger order capacities, etc.
*/
#include "gurbled.hpp"

int main()
{
	// Reads in from 'orders.txt'
	ifstream fin(INPUT_FILE);

	if (fin)
	{
		int numCases = NULL; // Stores number of cases to iterate over

		fin >> numCases; // Reads line 1 from file into numCases

		// Per-Case Iterative Loop
		for (int i = 1; i <= numCases; i++)
		{
			cout << "---------------------TEST CASE " << i << "------------------------" << endl;

			// Per-Case Variable Declarations
			int numOrders = NULL; // Stores number of orders to iterate over in a case
			RecipeBook r;

			fin >> numOrders; // Reads line n from file into numOrders

			Heap h(numOrders); // creates an heap of size numOrders

			// Per-Order Iterative Loop
			for (int j = 1; j <= numOrders; j++)
			{
				// Per-Order Variable Declarations
				Order order;
				int numItems = NULL; // Stores number of items in an order
				int startTime = NULL, endTime = NULL; // Stores starting & ending time
				int cookTimeCounter = NULL; // temporarily stores time an item cooks for
				stringstream itemNames; // Stores all items in a given order

				fin >> numItems; // Reads next line from file into numItems

				// Per-Item Iterative Loop
				for (int k = 1; k <= numItems; k++)
				{
					string tempName = ""; // temporarily stores an item name

					fin >> tempName; // reads next string from file into tempName

					cookTimeCounter += r.timeToCook(tempName); // adds time to cook

					// Uses conditional to provide proper spacing for console printing at end
					if (k == numItems)
					{
						itemNames << tempName;
					}
					else
					{
						itemNames << tempName << " ";
					}
				}

				fin >> startTime; // Reads in next int to startTime

				endTime = startTime + cookTimeCounter; // Calculates end time

				order.createOrder(itemNames.str(), startTime, endTime); // Creates a new order for insertion

				h.insertOrder(order); // inserts & sorts the created order into the heap
			}

			for (int x = 0; x < numOrders; x++)
			{
				cout << h.extractRoot() << endl; // prints sorted order by popping root from queue
			}
		}
	}
	else
	{
		cout << "ERROR: File not found. Press ENTER to exit." << endl;
		cin.ignore();
		return 0;
	}

	cout << "End of file. Press ENTER to exit." << endl;
	cin.ignore();
	return 0;
}