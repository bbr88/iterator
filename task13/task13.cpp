//
//  main.cpp
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
    
public:
    Node(T value): value(value), next(NULL) { } //ctor
    
    void add(Node* node) { //add new node to the list
        node->next = this->next;
        this->next = node;
    }
    
    T getValue() { //returns current Node's value
        return this->value;
    }
    
    Node* getNext() {
        return this->next;
    }
    
    bool operator!= (Node& node) { //compare two list elements
        return node.value != value;
    }
    
    friend class iterator;
};

//Node's iterator
template <typename T>
class Iterator {

private:
    Node<T>* p;

public:
    Iterator(Node<T>* node): p(node) { } //ctor
    
    T operator* () {     //dereferencing operator
        return p->getValue(); //It returns the contents of a Node object
    }
    
    void operator++ () { //inc operator
        p = p->getNext();
    }
    void operator++ (int) {
        p = p->getNext();
    }
    
    bool operator!= (const Iterator<int>& iterator) {
        return p != iterator.p;
    }
    
    operator Node<T>*() {
        return p;
    }
    
};

template < typename T, typename P >
P find5 ( P first, P beyond, const T& x ) {
    P p = first;
    while ( p != beyond && *p != x ) {
        p++;
    }
    return p;
}

//int main(int argc, const char * argv[]) {
//    Node<int>* list = new Node<int>(1);
//    list->add(new Node<int>(10));
//    list->add(new Node<int>(4));
//    list->add(new Node<int>(51));
//    list->add(new Node<int>(8));
//    list->add(new Node<int>(100));
//    
//    Iterator<int> find = find5( Iterator<int>(list), Iterator<int>(0), int(8) );
//    std::cout << *find << std::endl;
//    return 0;
//}
