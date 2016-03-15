/*
First Partial Evaluation, version 2
Data Structures TC1018.1
January 2016

Name: Hector Mauricio Gonzalez Coello
ID Number: A01328258

Complete the program accroding to the requirements
1. Overload the < and > operators so that you can compare ranches.
The comparison is made based on the total value of the ranch, which is computed as
the total area X price per square meter plus the number of cattle heads X price per head
Hint: Show the value of the ranch when printing it, so that you can see if the comparison is done correctly.
*/
/*
Class to store information about a ranch, given the dimensions, number of cattle heads and prices.
*/

#include <iostream>
#include <string>

class Ranch {
private:
	std::string name;
	double width;
	double length;
	double price_per_square_meter;
	int herd_size;
	double price_per_cattle_head;
public:
	// Constructors
	Ranch() {}
	Ranch(std::string _name, double _width, double _length, double _price_meter, int _herd_size, double _price_head) :
		name(_name), width(_width), length(_length), price_per_square_meter(_price_meter), herd_size(_herd_size), price_per_cattle_head(_price_head)
	{}
	// Access methods
	double get_width() const { return width; }
	double get_length() const { return length; }
	double get_price_per_square_meter() const { return price_per_square_meter; }
	int get_herd_size() const { return herd_size; }
	double get_price_per_cattle_head() const { return price_per_cattle_head; }


	friend std::ostream & operator<< (std::ostream & stream, const Ranch & ranch);
};

std::ostream & operator<< (std::ostream & stream, const Ranch & ranch)
{
	stream << "== " << ranch.name << " Ranch ==" << std::endl;
	stream << ranch.width << " X " << ranch.length << " meters. " << ranch.herd_size << " heads of cattle" << std::endl;

	return stream;
}
inline bool operator < (const Ranch & ranch, const Ranch & ranch1)
{
	if ((ranch.get_herd_size()*ranch.get_price_per_cattle_head() + ranch.get_length()*ranch.get_width()) < (ranch1.get_herd_size()*ranch1.get_price_per_cattle_head() + ranch1.get_length()*ranch1.get_width()))
		return true;
	else
		return false;
}
inline bool operator > (const Ranch &ranch, const Ranch &ranch1)
{
	if ((ranch.get_herd_size()*ranch.get_price_per_cattle_head() + ranch.get_length()*ranch.get_width()) > (ranch1.get_herd_size()*ranch1.get_price_per_cattle_head() + ranch1.get_length()*ranch1.get_width()))
		return true;
	else
		return false;
}
