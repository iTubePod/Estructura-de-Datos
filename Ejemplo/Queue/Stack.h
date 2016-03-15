/*
    Ivan Aram Gonzalez Su
    A01022584
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

template <class T>
class Stack{
private:
    Node<T>* head = nullptr;
    int length = 0;
public:
    Stack(){}
    Stack(Node<T>* data){ head = data; length++; }
    ~Stack(){ clear(); }
    
    bool isEmpty() { return head==nullptr; }
    Node<T>* top() { return head; }
    Node<T>* pop();
    void push(Node<T>* new_node);
    void push(T data);
    void clear();
    
    template <class S>
    friend std::ostream& operator<< (std::ostream& stream, const Stack<S>& stack);
};

template <class T>
Node<T>* Stack<T>::pop(){
    if(head==nullptr) return nullptr;
    Node<T>* element = head;
    head = head->getNext();
    element->setNext(nullptr);
    length--;
    return element;
}

template <class T>
void Stack<T>::push(Node<T>* new_node){
    if(head==nullptr) head = new_node;
    else{
        new_node->setNext(head);
        head = new_node;
    }
    length++;
}

template <class T>
void Stack<T>::push(T data){
    Node<T>* new_node = new Node<T>(data);
    push(new_node);
}

template <class T>
void Stack<T>::clear(){
    Node<T>* element = head;
    while(element != nullptr){
        head = element->getNext();
        delete element;
        element = head;
    }
    length = 0;
}

template <class S>
std::ostream& operator<< (std::ostream& stream, const Stack<S>& stack){
    Node<S>* element = stack.head;
    stream<<"[";
    while(element != nullptr){
        if(element->getNext() != nullptr) stream<<element->getData()<<", ";
        else stream<<element->getData();
        element = element->getNext();
    }
    stream<<"]";
}

#endif