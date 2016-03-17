/*
   Polynomial class
   Inherits from a Linked List, using Terms as data

Name: Hector Mauricio Gonzalez Coello
ID number: A01328258
2016
*/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

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
        void insertOrdered(Term data);
        void insertOrdered(Node<Term> * new_node);
        // Overload the operator to add two polynomials
        Polynomial operator+(const Polynomial & other);

        // Method to print out a polynomial
        friend std::ostream & operator<< (std::ostream & stream, Polynomial & poly);
};

double Polynomial::evaluate(double x)
{
    // Remember to indicate that the nodes used in this class contain Terms
    Node<Term> * item = head;
    double xvalue=0;
    while(item!=nullptr)
    {
    	xvalue=xvalue+(item->getData().getConstant()*pow(x, item->getData().getExponent()));
    	item=item->getNext();
    }
    return xvalue;
}
void Polynomial::simplify()
{
	Node<Term> * current = head;
	Node<Term> * previous = nullptr;
	Term sum;
	while (current->getNext()!=nullptr)
	{
        if (current==head)
        {
            if(head->getData().getExponent()==head->getNext()->getData().getExponent())
            {
                //head->getData().setConstant((head->getData().getConstant()) + (head->getNext()->getData().getConstant()));
				sum = Term(head->getData().getConstant() + head->getNext()->getData().getConstant(), head->getData().getExponent());
				head->setData(sum);
                head-> setNext(head->getNext()->getNext());
                length--;
            }
        }
        else
        {
    		if(previous->getData().getExponent()==current->getData().getExponent())
    		{
                //previous->getData().setConstant(previous->getData().getConstant()+current->getData().getConstant());
				sum = Term(previous->getData().getConstant() + current->getData().getConstant(), previous->getData().getExponent());
				previous->setData(sum);
                previous->setNext(current->getNext());
                length--;
    		}
        }
        previous = current;
        current = current->getNext();
	}
}
void Polynomial::insertOrdered(Term data) 
{
	Node <Term> * new_node=new Node<Term>(data);
	insertOrdered(new_node);
}

void Polynomial::insertOrdered(Node<Term> * new_node)
{
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node<Term> * item = head;
        Node<Term> * previous = nullptr;
        while (item != nullptr)
        {
            if (item->getData().getExponent() >= new_node->getData().getExponent())
            {
                break;
            }
            else
            {
                previous = item;
                item = item->getNext();
            }
        }
        if (item == head)
        {
            new_node->setNext(head);
            head = new_node;
        }
        else
        {
            new_node->setNext(item);
            previous->setNext(new_node);
        }
    }
    length++;
}
inline Polynomial Polynomial::operator + (const Polynomial & other)
{
	Polynomial sum;
	sum.head = head;
	Node<Term> * item = other.head;
	while(item != nullptr)
	{
		item=item->getNext();
		sum.insertOrdered(item);
		sum.print();
	}
    sum.simplify();
    return sum;
}
std::ostream & operator << (std::ostream & stream, Polynomial & poly)
{
	//Polynomial p = poly;
    Node<Term> * item = poly.getHead();
	if (item != nullptr && item->getData().getConstant()<0)
			stream << " - ";
    while(item != nullptr)
    {
    	if(item->getData().getConstant()>0)
        	stream << item->getData().getConstant();
        else if (item->getData().getConstant()<0)
        	stream << -1*(item->getData().getConstant());
        stream << "x^"<<item->getData().getExponent();
        item = item->getNext();
		if (item != nullptr && item->getData().getConstant()>0)
			stream << " + ";
		else if (item != nullptr && item->getData().getConstant()<0)
			stream << " - ";
		else
		{
			stream << std::endl;
			break;
		}
    }
    return stream;
}
#endif