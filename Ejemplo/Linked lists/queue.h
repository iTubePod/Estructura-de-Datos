/*
Queue inplemented with dynamic memory
*/

#include <iostream>
#include "Node.h"

template <class T>
class Queue {
	private:
		Node <T> *head;
		Node <T> *tail;
		int lenght;
	public:
		Queue () {}
		Queue (Node <T> * data)
		{
			head=data;
		}
		~Queue();
		bool isEmpty();
		Node<T> *top();
		Node<T> *pop();
		void push (Node<T. * new_node);

}