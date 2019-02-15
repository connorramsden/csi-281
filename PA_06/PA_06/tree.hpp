#ifndef TREE_CLASS
#define TREE_CLASS

#ifndef TREE_HEADER
#define TREE_HEADER

// Global Project Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#endif

enum Color { RED, BLACK };

struct Vertex
{
	int data;
	bool color;
	Vertex *lChild, *rChild, *parent;

	Vertex(int d)
	{
		this->data = d;
		lChild = rChild = parent = nullptr;
	}
};

class RBTree
{
private:
	Vertex *root;
protected:
	void rotateLeft(Vertex *&root, Vertex *&pt);

	void rotateRight(Vertex *&root, Vertex *&pt);

	void fixViolation(Vertex *&root, Vertex *&pt);
public:
	RBTree() { root = nullptr; }

	void insert(const int &n);

	void inOrder();

	void levelOrder();
};

void inOrderHelper(Vertex *root);

Vertex * BSTInsert(Vertex *root, Vertex *pt);

void levelOrderHelper(Vertex *root);

#endif