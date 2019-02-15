// Written by Connor Ramsden for CSI 281-02
#include "header.h"
// Creates a new BST
Node *newNode(int element)
{
	Node *temp = new Node;
	temp->key = element;
	temp->left = temp->right = nullptr;
	return temp;
}
// BST insertion (left, right)
Node * insert(Node *node, int element)
{
	if (node == nullptr) // Creates a new BST if no tree exists q
		return newNode(element);
	// Places an element left if less than key
	if (element < node->key)
	{
		node->left = insert(node->left, element);
	} // Places element right if greater than key	
	else if (element > node->key)
	{
		node->right = insert(node->right, element);
	}

	return node;
}

int getHeight(Node * node)
{
	if (node == nullptr)
	{ // Cancels out the + 1 return
		return -1;
	}
	else
	{ // Recursively gets height of left & right subtrees
		int lHeight = getHeight(node->left);
		int rHeight = getHeight(node->right);

		if (lHeight > rHeight)
		{
			return lHeight + 1;
		}
		else
		{
			return rHeight + 1;
		}
	}
}

bool isTreeAVL(Node * node)
{
	if (node == nullptr)
	{ // Empty trees are AVL compliant
		return true;
	}
	else
	{
		if ((getHeight(node->left) - getHeight(node->right)) > 1 || (getHeight(node->right) - getHeight(node->left)) > 1)
		{ // If there's a height difference > 1, not AVL compliant
			return false;
		}
		else
		{
			return true;
		}
	}
}