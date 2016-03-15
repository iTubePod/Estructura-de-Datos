/*
   Gilberto Echeverria

   Implementation of the Linked list
*/

#include <iostream>
#include "Node.h"

template <class T>
class LinkedList {
    protected:
        Node<T> * head = nullptr;
        //Node<T> * tail = nullptr;
        int length = 0;
    public:
        // Constructors
        LinkedList () {}
        LinkedList (Node<T> * item) { head = item; }
        // Destructor
        ~LinkedList ();

        // Return the current length of the list
        int getLength() { return this->length; }
        // Get the position in the list of a given item
        int getPositionOf(Node<T> * item);
        // Get a reference to items in the list
        Node<T> * getHead() { return this->head; }
        Node<T> * getTail() { return getItemAt(this->length-1); }
        Node<T> * getItemAt(int position);
        // Add new items to the list
        void insertAtPosition(Node<T> * item, int position);
        void insertAtPosition(const T & data, int position);
        void insertHead(Node<T> * item);
        void insertHead(const T & data);
        void insertTail(Node<T> * item);
        void insertTail(const T & data);
        // Remove items from the list
		Node<T> * deleteFromPosition(int position);
        Node<T> * deleteHead();
        Node<T> * deleteTail();
        void deleteNode(Node<T> item);
        // Print the contents of a list
        void printList();
        // Remove all nodes
        void clear();
};

// Destructor
template <class T>
LinkedList<T>::~LinkedList()
{
    // Simply call the function to delete all nodes in the list
    this->clear();
}

// Add items to the list
template <class T>
void LinkedList<T>::insertTail(Node<T> * item)
{
    // Make sure to stop the pointer in the list
    item->setNext(nullptr);

    // If the list is empty, this node is the new head
    if (this->head == nullptr)
    {
        this->head = item;
    }
    else
    {
        Node<T> * listItem = this->head;

        while (listItem->getNext() != nullptr)
        {
            listItem = listItem->getNext();
        }
        listItem->setNext(item);
    }
    // Increment the size of the list
    this->length++;
}


template <class T>
void LinkedList<T>::insertTail(const T & data)
{
    Node<T> * item = new Node<T>(data);
    this->insertTail(item);
}

template <class T>
void LinkedList<T>::insertHead(Node<T> * item)
{
    // Make this node point to the previous head
    item->setNext(this->head);
    // The node becomes the head of the list
    this->head = item;
    // Increment the size of the list
    this->length++;
}

template <class T>
void LinkedList<T>::insertHead(const T & data)
{
    Node<T> * item = new Node<T>(data);
    this->insertHead(item);
}

template <class T>
void LinkedList<T>::insertAtPosition(Node<T> * new_item, int position)
{
    int index = 1;
    Node<T> * item = this->head;

    // Return nothing for invalid positions
    if (position > this->length || position < 0)
    {
        return;
    }
    // Special case when adding at position 0
    if (position == 0)
    {
        // Make the new item point to the current head
        new_item->setNext(this->head);
        // Update the head
        this->head = new_item;
    }
    else
    {
        // Loop to search for the item
        while (index < position)
        {
            item = item->getNext();
            index++;
        }
        // Update the connections in the list
        new_item->setNext(item->getNext());
        item->setNext(new_item);
    }
    // Increase the length of the list
    this->length++;
}


template <class T>
void LinkedList<T>::insertAtPosition(const T & data, int position)
{
    Node<T> * item = new Node<T>(data);
    this->insertAtPosition(item, position);
}

template <class T>
int LinkedList<T>::getPositionOf(Node<T> * item)
{
    int index = 0;
    Node<T> * test = this->head;

    while ( item != nullptr && item->getData() != test->getData() )
    {
        test = test->getNext();
        index++;
    }
    if (index == this->length)
        return -1;
    return index;
}

template <class T>
Node<T> * LinkedList<T>::getItemAt(int position)
{
    int index = 0;
    Node<T> * item = this->head;

    // Return nothing for invalid positions
    if (position > this->length || position < 0)
    {
        return nullptr;
    }
    // Loop to search for the item
    while (index < position && item != nullptr)
    {
        item = item->getNext();
        index++;
    }
    return item;
}

template <class T>
Node<T> * LinkedList<T>::deleteHead()
{
    Node<T> * item = this->head;
    // Check that the list is not empty
    if (this->head == nullptr)
    {
    	return nullptr;
    }
    else
    {
	    // Make the head point to the second item
	    this->head = item->getNext();
	    // Make the item point to nothing
	    item->setNext(nullptr);
	    // Reduce the length of the list
	    this->length--;
	    return item;
	}
}

template <class T>
Node<T> * LinkedList<T>::deleteTail()
{
    // Check that the list is not empty
    if (this->head == nullptr)
    {
    	return nullptr;
    }
    if (this->head->getNext()==nullptr)
    {
    	return deleteHead();
    }
    else
    {
    	Node<T> * previous = head;
    	Node<T> * item = previous->getNext();
    	while(item->getNext() !=nullptr)
    	{
    		previous = previous->getNext();
    		item=item->getNext();
    	}
    	//Como el penultimo ahora seria el ultimo, le asignas a su netx un nullptr para que ya no apunte a nadie
    	previous->setNext(nullptr);
    	//Reduce el tamano de la lista
    	this->length--;//
	}
}


template <class T>
Node<T> * LinkedList<T>::deleteFromPosition(int position)
{
    if (position <0 || position>length-1)
    {
    	std::cout<<"The specified position is invalid\n";
    	std::cout<<"You must provide number less than or equal to 1"<<std::endl;
    	return nullptr;

    }
    else if (position ==0)
    {
    	return deleteHead();
    }
    else if(position==length-1)
    {
    	return deleteTail();
    }
    else
    {
    	Node<T> * previous = head;
    	Node<T> * item = previous->getNext();
    	for (int i=1; i<position;i++)
    	{
    		previous = item;
    		item=item->getNext();
    	}
    	previous->setNext(item->getNext());
    	item->setNext(nullptr);
    	length--;
    }
}

template <class T>
void LinkedList<T>::deleteNode(Node<T> item)
{
    Node<T> * list_item = this->head;
    int index = 0;

    if (list_item == nullptr)
        return;
    // Loop to search for the item
    while (list_item->getData() != item.getData())
    {
        list_item = list_item->getNext();
        index++;
    }
    // If the item was found before the end of the list, remove it
    if (index < getLength())
        deleteFromPosition(index); 
}


/*
Simple function to print the contents of the list
*/
template <class T>
void LinkedList<T>::printList()
{
    Node<T> * item;
    int counter = 0;

    item = head;
    while (item != nullptr)
    {
        std::cout << "Item " << counter++ << " = " << item->getData() << std::endl;
        item = item->getNext();
    }
}

/*
Empty the list, and free the memory for all nodes
*/
template <class T>
void LinkedList<T>::clear()
{
    Node<T> * item;

    item = head;
    while (item != nullptr)
    {
        std::cout << "Deleting item " << item->getData() << std::endl;
        head = item->getNext();
        delete item;
        item = head;
    }
    length = 0;
    head = nullptr;
}
