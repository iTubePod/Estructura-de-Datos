#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TreeNode.h"

template <class T>
class BinaryTree {
	private:
		TreeNode<T> * root;

		void recursiveInsert(TreeNode <T> * _root, TreeNode<T> * _node);
	public:
		BinaryTree () {}
		BinaryTree (TreeNode<T> * _node) {root=_node;}
		~BinaryTree() {clear();}

		void setRoot (TreeNode <T> * _node) {root=_node;}
		TreeNode<T> * getRoot () {return root;}

		void clear ();

		void insert (T_data);
		void insert (TreeNode<T> * _node);
		TreeNode<T> * removeNode (T _data);

		bool search (T _data);

};

#endif