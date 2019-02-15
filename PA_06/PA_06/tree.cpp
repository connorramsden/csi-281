#include "tree.hpp"

void inOrderHelper(Vertex * root)
{
	if (!root)
		return;
	inOrderHelper(root->lChild);

	cout << root->data << " ";

	inOrderHelper(root->rChild);
}

Vertex * BSTInsert(Vertex * root, Vertex * pt)
{
	if (!root)
		return pt;
	if (pt->data < root->data)
	{
		root->lChild = BSTInsert(root->lChild, pt);
		root->lChild->parent = root;
	}
	else if (pt->data > root->data)
	{
		root->rChild = BSTInsert(root->rChild, pt);
		root->rChild->parent = root;
	}

	return root;
}

void levelOrderHelper(Vertex * root)
{
	if (!root)
		return;

	queue<Vertex *> q;
	q.push(root);

	while (!q.empty())
	{
		Vertex *temp = q.front();

		cout << temp->data << " ";

		q.pop();

		if (temp->lChild)
			q.push(temp->lChild);
		if (temp->rChild)
			q.push(temp->rChild);
	}
}

void RBTree::rotateLeft(Vertex *&root, Vertex *&pt)
{
	Vertex *pt_right = pt->rChild;

	pt->rChild = pt_right->lChild;

	if (pt->rChild)
	{
		pt->rChild->parent = pt;
	}

	pt_right->parent = pt->parent;

	if (!pt->parent)
		root = pt_right;
	else if (pt == pt->parent->lChild)
		pt->parent->lChild = pt_right;
	else
		pt->parent->rChild = pt_right;

	pt_right->lChild = pt;
	pt->parent = pt_right;
}

void RBTree::rotateRight(Vertex *& root, Vertex *& pt)
{
	Vertex *pt_left = pt->lChild;

	pt->lChild = pt_left->rChild;

	if (pt->lChild)
	{
		pt->lChild->parent = pt;
	}

	pt_left->parent = pt->parent;

	if (!pt->parent)
		root = pt_left;
	else if (pt == pt->parent->lChild)
		pt->parent->lChild = pt_left;
	else
		pt->parent->rChild = pt_left;

	pt_left->rChild = pt;
	pt->parent = pt_left;
}

void RBTree::fixViolation(Vertex *& root, Vertex *& pt)
{
	Vertex *parent_pt = nullptr;
	Vertex *grand_parent_pt = nullptr;

	while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
	{
		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;

		/* Case : A
			Parent of pt is left child of Grand-parent of pt */
		if (parent_pt == grand_parent_pt->lChild)
		{
			Vertex *uncle_pt = grand_parent_pt->rChild;

			/* Case: 1
				The uncle of pt is also red
				Only recoloring required */
			if (uncle_pt && uncle_pt->color == RED)
			{
				grand_parent_pt->color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;
			}
			else
			{
				/* Case : 2
					pt is right child of its parent
					Left-rotation required */
				if (pt == parent_pt->rChild)
				{
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* Case : 3
					pt is left child of its parent
					Right rotation required */
				rotateRight(root, grand_parent_pt);
				swap(parent_pt->color, grand_parent_pt->color);
				pt = parent_pt;
			}
		}
		/* Case : B
			Parent of pt is right child of Grand-parent pt */
		else
		{
			Vertex *uncle_pt = grand_parent_pt->lChild;

			/* Case : 1
				The uncle of pt is also red
				Only recoloring required */
			if (uncle_pt && (uncle_pt->color == RED))
			{
				grand_parent_pt->color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;
			}
			else
			{
				/* Case : 2
					pt is left child of its parent
					Right-rotation required */
				if (pt == parent_pt->lChild)
				{
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* Case : 3
					pt is right child of its parent
					Left-rotation required */
				rotateLeft(root, grand_parent_pt);
				swap(parent_pt->color, grand_parent_pt->color);
				pt = parent_pt;
			}
		}
	}

	root->color = BLACK;
}

void RBTree::insert(const int & n)
{
	Vertex *pt = new Vertex(n);

	root = BSTInsert(root, pt);

	fixViolation(root, pt);
}

void RBTree::inOrder() { inOrderHelper(root); }

void RBTree::levelOrder() { levelOrderHelper(root); }