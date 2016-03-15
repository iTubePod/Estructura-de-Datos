/*
First Partial Evaluation, version 2
Data Structures TC1018.1
January 2016

Name: Hector Mauricio Gonzalez Coello
ID Number: A01328258

Complete the program accroding to the requirements

1. Write a RECURSIVE function that will add all the total values of all ranches.
Remeber the total value is computed as:
the total area X price per square meter plus the number of cattle heads X price per head
*/

#include <iostream>
#include <iomanip>
#include "Array.h"
#include "Ranch.h"

float total(Array <Ranch> *r[], float tmp, int i);

int main()
{
	Array<Ranch> ranches(6);

	ranches[0] = Ranch("San Rafael", 400, 600, 54.4, 300, 130.0);
	ranches[1] = Ranch("El Frijolillo", 900, 300, 83.1, 420, 158.5);
	ranches[2] = Ranch("La Soledad", 1300, 800, 32.5, 750, 114.8);
	ranches[3] = Ranch("El Antiguo", 500, 740, 47.8, 269, 145.0);
	ranches[4] = Ranch("Don Julian", 1280, 950, 59.7, 840, 123.7);
	ranches[5] = Ranch("Bravo", 730, 880, 64.6, 633, 147.9);

	std::cout << std::setprecision(10);

	std::cout << "Unordered:" << std::endl;
	ranches.print_data();

	ranches.sort_decreasing();
	std::cout << "Ordered:" << std::endl;
	ranches.print_data();

	//std::cout << "Total value of ranches: $" << total(&ranches, 0,0) << "." << std::endl;

	return 0;
}
/*
float total(Ranch *R, float tmp, int i, Array<Ranch> ran)
{
	if (R == nullptr)
		return tmp;
	else
	{
		R[i]->
		tmp = tmp + ((R->get_herd_size()*R->get_price_per_cattle_head() + R->get_length()*R->get_width());
		return total(&R[i+1], tmp, i + 1, ran);
}*/