/*
Add the following methods to the LinkedList class we are developping in class:

- insertOrdered: receives a new data item. It must be inserted in the correct position in the list, considering it is already ordered. Returns nothing.

- recursiveSearch: receives the data we are looking for in the list. Returns the position of the data if found, starting with index 0. If not found, returns -1

Hector Mauricio Gonzalez Coello
A01328258
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList numbers;
    
	std::cout << "Inserting ordered 8" << std::endl;
    numbers.insertOrdered(8);
	numbers.printList();
	std::cout << "Inserting ordered 4" << std::endl;
    numbers.insertOrdered(4);
	numbers.printList();
	std::cout << "Inserting ordered 16" << std::endl;
    numbers.insertOrdered(16);
	numbers.printList();
	std::cout << "Inserting ordered 5" << std::endl;
	numbers.insertOrdered(5);
	std::cout << "Inserting ordered 1" << std::endl;
	numbers.insertOrdered(1);
	std::cout << "Inserting ordered 3" << std::endl;
	numbers.insertOrdered(3);


	numbers.printList();
    
    int num_search = 5;
    std::cout << "Iterative search for " << num_search << ": " << numbers.searchIterative(num_search) << std::endl;
	std::cout << "Recursive search for " << num_search << ": " << numbers.searchRecursive(num_search, 0, numbers.getHead()) << std::endl;
    num_search = 9;
    std::cout << "Iterative search for " << num_search << ": " << numbers.searchIterative(num_search) << std::endl;
	std::cout << "Recursive search for " << num_search << ": " << numbers.searchRecursive(num_search, 0, numbers.getHead()) << std::endl;
	num_search = 8;
	std::cout << "Iterative search for " << num_search << ": " << numbers.searchIterative(num_search) << std::endl;
	std::cout << "Recursive search for " << num_search << ": " << numbers.searchRecursive(num_search, 0, numbers.getHead()) << std::endl;
	num_search = -2;
	std::cout << "Iterative search for " << num_search << ": " << numbers.searchIterative(num_search) << std::endl;
	std::cout << "Recursive search for " << num_search << ": " << numbers.searchRecursive(num_search, 0, numbers.getHead()) << std::endl;
    
    return 0;
}