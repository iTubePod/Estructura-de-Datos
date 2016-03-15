/*
Implementation of search algorithms on arrays
Gilberto Echeverria

Implementation of insertion and selection sort on arrays
Mauricio G. Coello
A01328258
*/

#include <iostream>
#include <cstdlib>      // Required to use the random functions
#include <ctime>        // Required to make use of time functions

#define MAX 1000
#define STEP 5

class Array {
private:
	int * data;
	int size;
public:
	// Class constructor
	Array(int _size);
	// Destructor
	~Array();
	void fill_random();
	void fill_ordered();
	void print_data();
	// Search methods
	bool linear_search(int item);
	bool binary_search_iterative(int item, int start, int end);
	bool binary_search_recursive(int item, int start, int end);
	void selection_sort();
	void insertion_sort();
	// Sort methods
	void bubble_sort();
	// Helper methods
	int get_last() { return size - 1; }
	void swap(int * item_1, int * item_2);
};

/*
Constructor
It creates the array of integers
*/
Array::Array(int _size)
{
	// Create the array of integers
	size = _size;
	data = new int[size];
	// Fill the array with data
	fill_random();
}

/*
Destructor
This one frees the memory used for the array
*/
Array::~Array()
{
	delete[] data;
}

void Array::fill_random()
{
	for (int i = 0; i<size; i++)
	{
		data[i] = rand() % MAX + 1;
	}
}

void Array::fill_ordered()
{
	int previous = 0;

	for (int i = 0; i<size; i++)
	{
		// Skip a few numbers after every element stored in the array
		data[i] = previous + (rand() % STEP + 1);
		previous = data[i];
	}
}

void Array::print_data()
{
	for (int i = 0; i<size; i++)
	{
		std::cout << " " << data[i];
	}
	std::cout << std::endl;
}


bool Array::linear_search(int item)
{
	for (int i = 0; i<size; i++)
	{
		if (data[i] == item)
			return true;
	}
	return false;
}

void Array::selection_sort()
{
	int min;

	for (int i = 0; i < size; i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{

			if (data[j] < data[min])
				min = j;
		}
		if (min != i)
		{
			swap(&data[i], &data[min]);
		}
	}
}

void Array::insertion_sort()
{
	int count;
	bool min=true;
	int extracted=0;
	for (int i = 0; i < size; i++) {
		count = i;
		min = true;

		while (count>0 && min) {
			if (data[count] < data[count - 1])
			{
				swap(&data[count], &data[count - 1]);
				count--;
				min = true;
			}
			else
				min = false;
		}
	}
}

bool Array::binary_search_iterative(int item, int start, int end)
{
	int middle;

	while (start < end)
	{
		middle = (start + end) / 2;
		if (item < data[middle])
		{
			end = middle - 1;
		}
		else if (item > data[middle])
		{
			start = middle + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool Array::binary_search_recursive(int item, int start, int end)
{
	if (end < start)
		return false;

	int middle = (start + end) / 2;

	if (item < data[middle])
		return binary_search_recursive(item, start, middle - 1);
	else if (item > data[middle])
		return binary_search_recursive(item, middle + 1, end);
	else
		return true;
}


void Array::bubble_sort()
{
	bool change;
	for (int i = 0; i<size; i++)
	{
		change = false;
		for (int j = 1; j<size - i; j++)
		{
			if (data[j - 1] > data[j])
			{
				swap(&data[j - 1], &data[j]);
				change = true;
			}
		}
		// Optimisation to exit if the array is already ordered
		if (!change)
			break;
	}
}

void Array::swap(int * item_1, int * item_2)
{
	int tmp;
	tmp = *item_1;
	*item_1 = *item_2;
	*item_2 = tmp;
}


int main()
{
	// Initialize the random number seed
	srand(time(NULL));

	Array array_one(20);
	Array * array_two = new Array(30);
	int search;
	bool result;

	std::cout << "Array one:" << std::endl;
	array_one.print_data();
	std::cout << std::endl;
	std::cout << "Array two:" << std::endl;
	array_two->print_data();

	array_one.selection_sort();
	std::cout << "______________________________________________________________________________" << std::endl;
	std::cout << "Array one sorted with selection sort:" << std::endl;
	array_one.print_data();
	std::cout << std::endl;
	array_two->insertion_sort();
	std::cout << "Array two sorted with insetion sort:" << std::endl;
	array_two->print_data();
	std::cout << "______________________________________" << std::endl;

	return 0;

}
