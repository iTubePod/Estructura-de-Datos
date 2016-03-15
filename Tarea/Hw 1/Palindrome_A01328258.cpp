/*
Hector Mauricio Gonzalez Coello
A01328258
ITC
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool test_palindrome(string x, int f, int l);//function that recieves the string, where the string starts and where it ends

int main()
{
	string in, out;
	cout << "Welcome to Palindrome tester" << endl;
	cout << "Enter the word to test: ";

	cin >> in;
	out = in;//Just for output purposes

	transform(in.begin(), in.end(), in.begin(), ::tolower);//transforms all the characters to lowercase so to avoid issues when comparing

	if (test_palindrome(in, 0, in.size() - 1))
		cout << out << " is a palindrome!" << endl;
	else
		cout << out << " is not a palindrome!" << endl;

	return 0;

}




bool test_palindrome(string x, int f, int l)
{
	if (x[f] != x[l])

		return false;
	if (f == l||f==l-1)

		return true;
	else

		return test_palindrome(x, f + 1, l - 1);//if none of the last conditions are satisfied, the function calls it self with start index +1 and end index -1 to move to the second and penultimate character to keep comparing them
}