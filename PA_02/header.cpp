// Written by Connor Ramsden for CSI-281-02
#include "header.h"
using namespace std;

// Converts a string to its ascii / char values, and returns the sum of those values
int stringToASCII(string s)
{
	int sum = 0;
	for (int i = 0; i < (int)s.length(); i++)
	{
		sum += (int)s[i];
	}

	return sum;
}

// Takes the sum from stringToASCII() and mods it by TABLE_SIZE (127) to get a hash key
int hashFunction(Node * element)
{
	int key = stringToASCII(element->artist) % TABLE_SIZE;

	return key;
}

// Adds a song (node) to the head of a linked list, or if head is occupied, a slot after the tail
void List::addNode(Node * element)
{
	Node *temp = new Node;
	temp->artist = element->artist;
	temp->title = element->title;
	temp->next = nullptr;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		temp = nullptr;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}

	cout << "Adding " << element->artist << " " << element->title << endl;
}
// Searches a LinkedList to print elements only by a given artist
void List::printByArtist(Node * element)
{
	Node* temp = new Node;

	if (head != nullptr)
	{
		cout << "Songs by " << element->artist << ": ";
		temp = head;
		while (temp != nullptr)
		{
			if (temp->artist == element->artist)
			{
				cout << temp->title << " ";
				temp = temp->next;
			}
		}
		cout << endl;
	}
}
// Searches a LinkedList and removes a passed song from that list
void List::removeSong(Node * element)
{
	Node *temp = new Node;
	Node *prev = new Node;

	temp = head;

	if (temp != nullptr && temp->title == element->title)
	{
		head = temp->next;
		delete temp;
	}
	else
	{
		while (temp != nullptr && temp->title != element->title)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			cout << "The song to be deleted was not present in the jukebox." << endl;
		}
		prev->next = temp->next;
		delete temp;
	}

	cout << "Deleted " << element->artist << " " << element->title << endl;
}
// Condenses adding a song to a single line in main()
void addSong(istream & f, int & hash, Node * element, List arr[])
{
	f >> element->artist >> element->title;
	hash = hashFunction(element);
	arr[hash].addNode(element);
}
// Condenses listing songs by an artist to a single line in main()
void listSong(istream & f, int & hash, Node * element, List arr[])
{
	f >> element->artist;
	hash = hashFunction(element);
	arr[hash].printByArtist(element);
}
// Condenses deleting a song to a single line in main()
void deleteSong(istream & f, int & hash, Node * element, List arr[])
{
	f >> element->artist >> element->title;
	hash = hashFunction(element);
	arr[hash].removeSong(element);
}