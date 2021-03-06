/*
	Hector Mauricio Gonzalez Coello
	A01328258
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

template <class T>
class Queue{
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int length = 0;
public:
    Queue(){}
    Queue(Node<T>* data){ head = data; tail = data; length++; }
    ~Queue(){ clear(); }
    
    bool isEmpty() { return head==nullptr; }
    Node<T>* top() { return head; }
    Node<T>* pop();
    void push(Node<T>* new_node);
    void push(T data);
    void clear();
    
    template <class S>
    friend std::ostream& operator<< (std::ostream& stream, const Queue<S>& queue);
};

template <class T>
Node<T>* Queue<T>::pop(){
    if(head==nullptr) return nullptr;
    Node<T>* element = head;
    head = head->getNext();
    element->setNext(nullptr);
    length--;
    return element;
}

template <class T>
void Queue<T>::push(Node<T>* new_node){
    if(head==nullptr){
        head = new_node;
        tail = new_node;
    }
    else{
        tail->setNext(new_node);
        tail = new_node;
    }
    length++;
}

template <class T>
void Queue<T>::push(T data){
    Node<T>* new_node = new Node<T>(data);
    push(new_node);
}

template <class T>
void Queue<T>::clear(){
    Node<T>* element = head;
    while(element != nullptr){
        head = element->getNext();
        delete element;
        element = head;
    }
    length = 0;
    tail = nullptr;
}

template <class S>
std::ostream& operator<< (std::ostream& stream, const Queue<S>& queue){
    Node<S>* element = queue.head;
    stream<<"[";
    while(element != nullptr){
        if(element != queue.tail) stream<<element->getData()<<", ";
        else stream<<element->getData();
        element = element->getNext();
    }
    stream<<"]";
}

#endif