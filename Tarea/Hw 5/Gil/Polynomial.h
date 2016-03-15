#include "LinkedList.h"
#include "Term.h"

class Polynomial : public LinkedList{
	public:
		double evaluate (double x;);
		void simlify();
		Polynomial operator+(const Polynomial &other);
		Polynomial operator-(const Polynomial &other);
		friend std::ostream & operator << (std::ostream & stream, const Polynomial &poly);
};
double Polynomial::evaluate(double x)
{
	Node<Term> *item = head;
}