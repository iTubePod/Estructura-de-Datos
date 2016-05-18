#include <iostream>
#include "BinaryTree.h"

int main()
{
	BinaryTree<int> tree;

	tree.insert(20);
	tree.insert(7);
	tree.insert(35);
	tree.insert(9);
	tree.insert(12);

	tree.printInOrder();
}