/*
First Partial Evaluation
Data Structures TC1018.1
January 2016

Name: Hector Mauricio Gonzalez Coello
ID Number: A01328258

Complete the program accroding to the requirements:
1. Write the 'sort_decreasing' method. This time it must be based on Insertion Sort.
*/

#include <iostream>

template <class T>
class Array {
private:
	T * data;
	int size;
public:
	// Class constructor
	Array(int _size);
	// Destructor
	~Array();
	// Helper methods
	void swap(T * item_1, T * item_2);
	void print_data();
	// Operator overloads
	T& operator[](std::size_t idx) { return data[idx]; };
	const T& operator[](std::size_t idx) const { return data[idx]; };

	///// EVALUATION QUESTION /////
	void sort_decreasing();
};

/*
Constructor
It creates the array of integers
*/
template <class T>
Array<T>::Array(int _size)
{
	// Create the array of type T
	size = _size;
	data = new T[size];
}

/*
Destructor
This one frees the memory used for the array
*/
template <class T>
Array<T>::~Array()
{
	delete[] data;
}

/*
Show the contents of the array
*/
template <class T>
void Array<T>::print_data()
{
	for (int i = 0; i<size; i++)
	{
		std::cout << " " << data[i];
	}
	std::cout << std::endl;
}

template<class T>
inline void Array<T>::sort_decreasing()
{
	T tmp;
	int j=0;
	for (int i = 1; i<size; i++)
	{
		tmp = data[i];
		for (j = i; j>0; j--)
		{
			if (tmp > data[j - 1])
				swap(&data[j], &data[j - 1]);
			else
				break;
		}
	}
}

/*
Exchange the contents of the array at two different indices
*/
template <class T>
void Array<T>::swap(T * item_1, T * item_2)
{
	T tmp;
	tmp = *item_1;
	*item_1 = *item_2;
	*item_2 = tmp;
}
