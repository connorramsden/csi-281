// Written by Connor Ramsden on 10/29/2018
#ifndef HEAP_CLASS
#define HEAP_CLASS

#ifndef HEAP_HEAD
#define HEAP_HEAD

#include <iostream>
#include <string>
using namespace std;

#endif

// Arbitrary swap function for sorting
template <class T>
void swap(T *x, T *y);

// Stores all item names, and how long they each take to cook
class RecipeBook
{
protected:
	const string WHOB = "Whobber";
	const string DOUB = "double_Whobber_with_bees";
	const string NUGG = "dingo_nuggets";
	const string BON = "bonbons";
	const string DRPEB = "dr_pebber";
	const string PEB = "pebsi";
public:
	// Generic Functions
	// Determines how long the passed item takes to cook
	int timeToCook(string n);
};

// Order 'Node' structure
struct Order : public RecipeBook
{
	// Variable Declarations
	string oName; // Name(s) of item(s) in a given order
	int oStartTime, oEndTime; // start and end time of a given order

	// Function Declarations
	void createOrder(string n, int s, int e); // Creates an order, not a ctor

	void operator =(const Order &o); // Overloaps = to assign one Order to another

	bool operator >(const Order & o) const; // Overloads > comparison operator

	bool operator <(const Order & o) const; // Overloads < comparison operator

	void printOrder(ostream & out = cout) const;
};

// Heap Management class
class Heap : public Order
{
private:
	Order *oArray; // points to array of Order elements
	int maxCap; // maximum size of a given heap
	int heapSize; // current size of a given heap
public:
	// Default Heap Constructor
	Heap(int cap);

	// Insert an order to the heap
	void insertOrder(Order o);

	// Finds the root, the minimum element
	Order extractRoot();

	// Creates a heap at index n
	void createHeap(int n);

	// Finds parent of a given node-index
	int getParent(int p) { return (p - 1) / 2; }

	// Finds left child of a given root
	int getLeft(int l) { return (2 * l + 1); }

	// Finds right child of a given root
	int getRight(int r) { return (2 * r + 2); }

	// Get order at passed index
	Order getOrder(int j) { return oArray[j]; }
};

// Overloads ostream << to be able to print orders
ostream & operator << (ostream & out, const Order & ord);

#endif