#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

using namespace std;

class Node {

private:
    int _data;
    Node * _next;
public:
    Node(int data, Node* next);
    void setData(int data);
    ~Node();
    int getData() const;
    void setNext(Node *next);
    Node* getNext() const;
};


#endif