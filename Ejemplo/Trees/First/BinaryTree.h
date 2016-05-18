/*
	Depth First
		Pre-Order: root L R
		Post-Order: L R root
		In-Order: L root Right 
	Breadth first


*/
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TreeNode.h"

template <class T>
class BinaryTree {
	private:
		TreeNode<T> * root;

		void recursiveInsert(TreeNode <T> * _root, TreeNode<T> * _node);
		void recursivePrintInOrder(TreeNode <T> * _root);
		TreeNode<T> * recursiveGetMin(TreeNode<T> * _node);
	public:
		BinaryTree () {}
		BinaryTree (TreeNode<T> * _node) {root=_node;}
		~BinaryTree() {clear();}

		void setRoot (TreeNode <T> * _node) {root=_node;}
		TreeNode<T> * getRoot () {return root;}

		void clear ();

		void insert (T _data);
		void insert (TreeNode<T> * _node);
		TreeNode<T> * removeNode (T _data);

		bool search (T _data);

		void printInOrder();
		TreeNode <T> * recursiveDelete(TreeNode<T> * _root, TreeNode<T> * _data);
		void deleteNode(T _data);
};

template <class T>
void BinaryTree<T>::insert (T _data)
{
	TreeNode<T> * node = new TreeNode <T>(_data);
	insert(node);
}
template <class T>
void BinaryTree<T>::insert (TreeNode<T> * _node)
{
	if(root==nullptr)
		root= _node;
	else
		recursiveInsert(root, _node);
}
template <class T>
void BinaryTree<T>::recursiveInsert(TreeNode <T> * _root, TreeNode<T> * _node)
{
	if(_root->getData()==_node->getData())
		return;
	if (_node->getData() < _root->getData())
	{
		if (_root->getLeft()==nullptr)
			_root->setLeft(_node);
		else
			recursiveInsert(_root->getLeft(), _node);

	}
	if (_node->getData() > _root->getData())
	{
		if (_root->getRight()==nullptr)
			_root->setRight(_node);
		else
			recursiveInsert(_root->getRight(), _node);
	}
}
template <class T>
void BinaryTree<T>::printInOrder()
{
	if (root != nullptr)
	{
		recursivePrintInOrder(root);
		std::cout << std::endl;
	}
}
template <class T>
void BinaryTree<T>::recursivePrintInOrder(TreeNode <T> * _root)
{
	if(_root == nullptr)
		return;
	recursivePrintInOrder(_root->getLeft());
	std::cout<<_root->getData()<<" ";
	recursivePrintInOrder(_root->getRight());
}
template <class T>
void BinaryTree<T>::clear()
{
	return;
}
template <class T>
void BinaryTree<T>::deleteNode(T _data)
{
	if (root==nullptr)
		return;
	root = recursiveDelete(root, _data);
}
template <class T>
TreeNode <T> * BinaryTree<T>::recursiveDelete(TreeNode<T> * _root, TreeNode<T> * _data)
{
	if (_root == nullptr)
		return nullptr;
	if(_data < _root->getData())
		return _root->setLeft(recursiveDelete(_data->getLeft(), _data));
	if(_data > _root->getData())
		return _root->setRight(recursiveDelete(_data->getRight(), _data));
	//found
	else
	{
		//Case 1 Leaf
		if(_root->getLeft()==nullptr && _root->getRight()==nullptr)
		{
			delete root;
			return nullptr;
		}
		//Case 2: Right child only
		else if(_root->getLeft()==nullptr)
		{
			TreeNode<T> * tmp = _root->getRight();
			delete _root;
			return tmp;
		}
		//Case 3: Left child only
		else if(_root->getRight()==nullptr)
		{
			TreeNode<T> * tmp = _root->getLeft();
			delete _root;
			return tmp;
		}
		//Case 4: Two children
		else
		{
			TreeNode<T> * tmp = getMin(_root->getRight());
			_root->setData(tmp->getData());
			_root->setRight(recursiveDelete(_root->getRight(), tmp->getData()));
		}
	}
}
template <class T>
TreeNode<T> * BinaryTree<T>::recursiveGetMin(TreeNode<T> * _node)
{
	if(_node->getLeft()==nullptr)
		return _node;
	return recursiveGetMin(_node->getLeft());
}
#endif