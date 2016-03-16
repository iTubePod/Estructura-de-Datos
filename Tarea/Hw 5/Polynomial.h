/*
   Polynomial class
   Inherits from a Linked List, using Terms as data

Name: Hector Mauricio Gonzalez Coello
ID number: A01328258
*/

#include "LinkedList.h"
#include "Term.h"

class Polynomial : public LinkedList<Term> {
    public:
        // Method to compute the results of a polynomial evaluated
        //  with a given value for the variable
        double evaluate(double x);
        // Add up all the terms with equal exponents
        void simplify();
        // Optional: Change the method to insert in decreasing order
        //void insertOrdered(Term data);
        void insertOrdered(Node<Term> * new_node);
        // Overload the operator to add two polynomials
        Polynomial operator+(const Polynomial & other);

        // Method to print out a polynomial
        friend std::ostream & operator<< (std::ostream & stream, const Polynomial & poly);
};

double Polynomial::evaluate(double x)
{
    // Remember to indicate that the nodes used in this class contain Terms
    Node<Term> * item = head;
    double xvalue=0;
    while(item->getNext()!=nullptr)
    {
    	xvalue=xvalue+(item->getConstant()*(x^item->getExponent()));
    	item=item->getNext();
    }
    return xvalue;
}
void simplify()
{
	Node<Term> * current = head;
	Node<Term> * previous = nullptr;
	while (current->getNext()!=nullptr)
	{
        if (current==head)
        {
            if(head->getExponent()==head->getNext()->getExponent())
            {
                head->SetConstant(head->getConstant()+head->getNext()->getConstant());
                head->setNext(head->getNext()->getNext());
            }
        }
        else
        {
    		if(previous->getExponent()==current->getExponent())
    		{
                previous->SetConstant(previous->getConstant()+current->getConstant());
                previous->setNext(current->getNext());
    		}
        }
        previous = item;
        item = item->getNext();
	}
}
