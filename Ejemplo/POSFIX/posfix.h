#include <string>
#include "Stack.h"

class Postfix{
private:
	std::string infix;
	std::string posfix;

	int comparePrecedence(char operator_1, char operator_2);

	public:
		Postfix() {}
		Postfix(std::string _infix) {infix = _infix;}
		void setData(std::string _infix) {infix=_infix;}
		void convert();

};
