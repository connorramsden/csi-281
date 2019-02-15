// Written by Connor Ramsden for CSI 281-02
#pragma once
#include <iostream>
#include <string>
using namespace std;

// Constant variables
const string FILE_IN = "trees.txt";
const int MIN_CASES = 1;
const int MAX_CASES = 99;

struct Node
{
	int key;
	Node *left, *right;
};
// Creates a new tree
Node *newNode(int element);
// Inserts elements to a BST in-order
Node *insert(Node *node, int element);
// Finds the height of a node's left || right subtree
int getHeight(Node *node);
// Determines if a tree is AVL-compliant
bool isTreeAVL(Node *node);