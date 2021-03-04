#include "Node.hpp"
using namespace std;



  
    Node::Node(int data, Node* next): _data(data), _next(next){}
    
    void Node::setData(int data){
        this->_next->_data = data;
    }
    Node::~Node() { delete &_data; }

    void Node::setNext(Node *next){
         this->_next = next;
    }
    int Node::getData() const{
     return this->_data;
    }
    Node* Node::getNext() const{
        return this->_next;
    }
