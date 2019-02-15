/*
Author: Connor Ramsden
Class: CSI 281-02
Assignment: PA 01
Date Assigned: August 30th, 2018
Due Date: September 6th at 11:59 pm

Description: Demonstrates use of function templates in the sorting of arbitrary datatypes

Certification of Authenticity: I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:-Reproduce  this assignment and provide a copy to anothe  member of academic staff; and/or-Communicate a copy of this  assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)

Disclosures:
- Psuedocode for the quickSort() and partition() functions sourced from https://www.geeksforgeeks.org/quick-sort/. All code written by me, did not copy / paste from the code example at the bottom of the page
- Debugging help was received from my housemate, a Champlain alum. He did not write any code for me.
- I chose to use QuickSort() as my sorting algorithm after asking a friend what his favorite sorting algorithm was. I did not receive any additional input from this student.
- There are two warnings when building in x64 that do not appear when building in x86. These concern converting from size_t to int, though fixing these warnings results in a no-compile.
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Track.h"
using namespace std;

template <typename T>
void swap(T *xp, T *yp) // basic swap function
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/*
Critical function for quickSort().
Tracks the index of the smallest element i, and pivots elements smaller than i beneath it
Basically chooses a given point (the last vector element) and moves everything less than it behind the pivot
*/
template <typename T>
int partition(vector<T> & vec, int low, int high)
{
	T pivot = vec[high];

	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (vec[j] <= pivot)
		{
			i++;
			swap(vec[i], vec[j]);
		}
	}
	swap(vec[i + 1], vec[high]);
	return (i + 1);
}
/*
	Runs through the passed vector, pivoting elements around the partitioned pivot point
	Takes a vector, its first element, and its last element
*/
template <typename T>
void quickSort(vector<T> & vec, int low, int high)
{
	if (low < high)
	{
		int pi = partition(vec, low, high);

		quickSort(vec, low, pi - 1);
		quickSort(vec, pi + 1, high);
	}
}

template <typename T>
void printArray(vector<T> & vec)
// Runs through the given data type and prints out vec[i]. Opted to specialize my template for console readability
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i == 0)
		{
			cout << "\n" << vec[i] << endl;
		}
		else
		{
			cout << vec[i] << endl;
		}
	}
}
template<> // above template specialized for ints, based on console readability
void printArray(vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
}

int main()
{
	// Randomly generated a set of 20 unique integers at https://www.random.org/integer-sets/
	vector<int> intVec{ 317, 146, 140, 154, 56, 368, 188, 473, 424, 117, 429, 339, 172, 64, 428, 478, 283, 14, 312, 275 };

	cout << "This is a vector of integers before it is sorted: " << endl;
	printArray(intVec);
	quickSort(intVec, 0, intVec.size() - 1);
	cout << "\n\nThis is the same vector of integers after it has been sorted: " << endl;
	printArray(intVec);

	/*
	- Likely not the cleanest way to create this song vector, but its what made sense. Seven songs randomly generated @ https://www.randomlists.com/random-songs?qty=7.
	- Sorting was tested by making a Spotify playlist with these 7 songs and sorting by Artist, which has the same order as this sorting algorithm
	- Added an eight song to duplicate an artist to demonstrate the title sorting
	*/
	Song songOne("Dire Straits", "Sultans of Swing");
	Song songTwo("Taylor Swift", "Look What You Made Me Do");
	Song songThree("Radiohead", "Creep");
	Song songFour("Foo Fighters", "Everlong");
	Song songFive("Tears for Fears", "Everybody Wants to Rule the World");
	Song songSix("ABBA", "Dancing Queen");
	Song songSeven("Juice WRLD", "Lucid Dreams");
	Song songEight("ABBA", "Mamma Mia");

	vector<Song> songVec{ songOne, songTwo, songThree, songFour, songFive, songSix, songSeven, songEight };

	cout << "\n\nThis is a vector of Songs before it is sorted: " << endl;
	printArray(songVec);
	quickSort(songVec, 0, songVec.size() - 1);
	cout << "\nThis is the same vector of Songs after it has been sorted: " << endl;
	printArray(songVec);

	cout << "\nPress ENTER to exit.";
	cin.get();
	return 0;
}