/*
Mauricio G. Coello
A01328258
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <locale>

template<typename T>
void print_data(std::vector<T> x);
template<typename T>
bool binary_search(std::vector<T> x, T item, int start, int end);
template<typename T>
std::vector<T> sort(std::vector<T> x);
template<typename T>
void swap(T * item_1, T * item_2);

int main()
{
	std::vector<std::string> all;
	std::string send;
	std::string a;
	char temp[128];
	std::ifstream infile;
	infile.open("ASOIF_names.txt");
	if (infile.fail())
	{
		std::cout << "FATAL ERROR" << std::endl;
		return 0;
	}
	while (!infile.eof())
	{
		infile.getline(temp, sizeof(temp));
		std::string str(temp);
		std::cout << str << std::endl;
		if (str != "")
		{
			all.push_back(str);
		}
	}
	std::cout << all.size() << " names successfully loaded..." <<std::endl;
	all = sort(all);
	print_data(all);
	std::cout << "Enter the name to search\nTo quit enter exit" << std::endl;
	std::cout << "	";
	std::getline(std::cin, a);
	a[0]= toupper(a[0]);
	while (a!="Exit")
	{
		if (binary_search(all, a, 0, all.size()-1))
		{
			std::cout << "	" << a << " found!" << std::endl;
		}
		else
		{
			std::cout << "	" << a << " not found!" << std::endl;
		}
		std::cout << "Enter the name to search\nTo quit enter exit" << std::endl;
		std::cout << "	";
		std::getline(std::cin, a);
		a[0] = toupper(a[0]);
	}
	return 0;
}

template<typename T>
void print_data(std::vector<T> x)
{
	for (int i = 0; i < x.size(); i++)
	{
		std::cout << " " << x[i] << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
bool binary_search(std::vector<T> x, T item, int start, int end)
{
	if (end < start)
		return false;

	int middle = (start + end) / 2;

	if (item < x[middle])
		return binary_search(x, item, start, middle - 1);
	else if (item > x[middle])
		return binary_search(x, item, middle + 1, end);
	else
		return true;
}

template<typename T>
std::vector<T> sort(std::vector<T> x)
{
	int min;

	for (int i = 0; i < x.size(); i++)
	{
		min = i;

		for (int j = i + 1; j < x.size(); j++)
		{

			if (x[j] < x[min])
				min = j;
		}
		if (min != i)
		{
			swap(&x[i], &x[min]);
		}
	}
	return x;
}

template<typename T>
void swap(T * item_1, T * item_2)
{
	T tmp;
	tmp = *item_1;
	*item_1 = *item_2;
	*item_2 = tmp;
}
