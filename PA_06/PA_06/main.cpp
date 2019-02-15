#include "header.hpp"

int main()
{
	RBTree tree;

	tree.insert(7);
	tree.insert(6);
	tree.insert(5);
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);

	cout << "Inoder Traversal of Created Tree\n";
	tree.inOrder();

	cout << "\n\nLevel Order Traversal of Created Tree\n";
	tree.levelOrder();

	cout << "\nEnd of Program. Press ENTER to exit." << endl;
	cin.ignore();
	return 0;
}