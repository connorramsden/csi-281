// Written by Connor Ramsden on 10/29/2018
#include "min_heap.hpp"

// Arbitrary swap function for sorting
template<class T>
void swap(T * x, T * y)
{
	T temp = *x;

	*x = *y;

	*y = temp;
}

// Returns the time to cook a passed item
int RecipeBook::timeToCook(string n)
{
	if (n == WHOB) { return 5; }
	else if (n == DOUB) { return 7; }
	else if (n == NUGG) { return 4; }
	else if (n == BON) { return  1; }
	else if (n == DRPEB) { return 1; }
	else if (n == PEB) { return 2; }
	else { return 0; }
}

// Allows orders to be printed to console
ostream & operator<<(ostream & out, const Order & ord)
{
	ord.printOrder(out);
	return out;
}

// Creates a new order, is not a c-tor
void Order::createOrder(string n, int s, int e)
{
	oName = n;
	oStartTime = s;
	oEndTime = e;
}

// Overloads = operator to assign orders
void Order::operator =(const Order &o)
{
	oName = o.oName;

	oStartTime = o.oStartTime;

	oEndTime = o.oEndTime;
}

// Overloads > for Order comparison
bool Order::operator >(const Order & o) const
{
	// If the external end time is greater than the local end time
	if (o.oEndTime > oEndTime)
	{
		return this > &o; // this is 'greater' than external
	}
	else if (o.oEndTime == oEndTime) // If end time is same
	{
		if (o.oStartTime > oStartTime) // Complete first-started order before the next
		{
			return this > &o;
		}
		else
		{
			return &o > this;
		}
	}
	else // Else external order is greater than local order
	{
		return &o > this;
	}
}

// Overloads < for Order comparison
bool Order::operator <(const Order & o) const
{
	if (oEndTime < o.oEndTime) // if local order ends before external order
	{
		return &o < this; // local order is better than external order
	}
	else if (o.oEndTime == oEndTime) // If they end at the same time
	{
		if (oStartTime < o.oStartTime) // complete the one that started first
		{
			return &o < this;
		}
		else
		{
			return this < &o;
		}
	}
	else // else the external order is better than the local order
	{
		return this < &o;
	}
}

void Order::printOrder(ostream & out) const
{
	out << oStartTime << " " << oEndTime << " " << oName;
}

// Default heap constructor
Heap::Heap(int cap)
{
	heapSize = 0;
	maxCap = cap;
	oArray = new Order[cap];
}

// Adds an order to the heap
void Heap::insertOrder(Order o)
{
	if (heapSize == maxCap)
	{
		cout << "Overflow Error: Heap at capacity\n";
		return;
	}

	heapSize++; // increments heap size to track capacity

	int i = heapSize - 1; // tracks placement index

	oArray[i] = o; // Inserts order at end of heap

	// Sort for min heap property violations
	while (i != 0 && oArray[getParent(i)] > oArray[i])
	{
		swap(&oArray[i], &oArray[getParent(i)]);

		i = getParent(i);
	}
}

// pops the minimum element (root)
Order Heap::extractRoot()
{
	// If the heap only has one element, return it
	if (heapSize == 1)
	{
		heapSize--;
		return oArray[0];
	}

	Order rootOrder = oArray[0];

	oArray[0] = oArray[heapSize - 1];

	heapSize--;

	createHeap(0);

	return rootOrder;
}

// Creates a new heap on a subtree
void Heap::createHeap(int n)
{
	int lIndex = getLeft(n);
	int rIndex = getRight(n);
	int smallest = n;

	if (lIndex < heapSize && oArray[lIndex] < oArray[n])
	{
		smallest = lIndex;
	}
	if (rIndex < heapSize && oArray[rIndex] < oArray[smallest])
	{
		smallest = rIndex;
	}
	if (smallest != n)
	{
		swap(&oArray[n], &oArray[smallest]);
		createHeap(smallest);
	}
}