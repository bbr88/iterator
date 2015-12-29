//
//  task14.cpp
//  task13
//
//  Created by Игорь Бисарнов on 10.11.15.
//  Copyright (c) 2015 Игорь Бисарнов. All rights reserved.
//

#include <iostream>

//Node class
template <typename T> //generic type
class Node {
    
private:
    T value; //Node's value
    Node* next;
    Node* previous;
    friend class iterator;

public:
    Node(T value): value(value), next(NULL), previous(NULL) { } //ctor
    
    void add(Node* node) { //add new node to the list
        Node* current = this;
        
        while (current != NULL) {
            
            if (current->next == NULL) {
                current->next = node;
                node->previous = current;
                break;
            }
            current = current->next;
            
        }
    }
    
    T& getValue() { //returns current Node's value
        return (this->value);
    }
    
    Node* getNext() {
        return this->next;
    }
    
    Node* getPrevious() {
        return this->previous;
    }
    
    Node* getLast() {
        Node* current = this;
        
        while (current->next != NULL) {
            current = current->next;
        }
        return current;
    }
    
    bool operator!= (Node& node) { //compare two list elements
        return node.value != value;
    }
};

//Node's iterator
template <typename T>
class Iterator {
    
private:
    Node<T>* p;
    
public:
    Iterator(Node<T>* node): p(node) { } //ctor
    
    T& operator* () {         //dereferencing operator
        return p->getValue(); //It returns the contents of a Node object
    }
    
    void operator++ () { //inc operator
        p = p->getNext();
    }
    void operator++ (int) {
        p = p->getNext();
    }
    
    void operator-- () { //decr operator
        p = p->getPrevious();
    }
    
    void operator-- (int) {
        Iterator* temp = this;
        temp->p = temp->p->getPrevious();
        p = temp->p;
    }
    
    bool operator!= (const Iterator<int>& iterator) {
        return p != iterator.p;
    }
    
    operator Node<T>*() { //implicit conversion from Iterator to Node
        return p;
    }
    
};

template <typename T, typename P>
void reverse ( P start, P beyond ) {
    while ( start != beyond ) {
        
        if ( start != beyond ) {
            T t = *start;
            *start = *beyond;
            *beyond = t;
            ++start;
        }
        beyond--;
    }
}

void printList(Node<int>* list) {
    while (list != NULL) {
        std::cout << list->getValue() << "  ";
        list = list->getNext();
    }
}

int main(int argc, const char * argv[]) {
    Node<int>* list = new Node<int>(1); //list initialization
    list->add(new Node<int>(10)); // add new nodes
    list->add(new Node<int>(20));
    list->add(new Node<int>(30));
    list->add(new Node<int>(40));
    list->add(new Node<int>(50));
//    list->add(new Node<int>(60));
    
    printList(list); //print out the list
    reverse<int>(Iterator<int>(list), Iterator<int>(list->getLast())); //reverse it
    std::cout << "\n";
    printList(list); //print out result list
    
    return 0;
}