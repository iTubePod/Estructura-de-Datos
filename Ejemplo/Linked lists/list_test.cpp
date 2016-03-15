/*
   Gilberto Echeverria

   Sample program to use the linked list library
*/

#include <iostream>
#include "LinkedList.h"

int main(void)
{
    LinkedList<std::string> test_list;
    Node<std::string> * item = nullptr;
    int i;

    item = new Node<std::string>; // This item will be deleted with the rest of the list
    item->setData("Hola");

    std::cout << "Size of node: " << sizeof (Node<std::string>) << std::endl;
    std::cout << "Initial length: " << test_list.getLength() << std::endl;

    // Insert at the end
    test_list.insertTail(item);
    test_list.insertTail("Adios");
    test_list.insertTail("Que onda");
    test_list.printList();

    return 0;
}
