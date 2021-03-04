#ifndef LIST_HPP
#define LIST_HPP
#include "Node.hpp"
using namespace std;

class List {

private:
  Node* _head; 
  unsigned  _size;        
 
  public:
    
    List();
    ~List();
    void insert(int value);
    int remove();
    int isEmpty();
    unsigned int size() const;
    int middle() const;
    int last() const;
    void rotate();
    Node* getElement(int pos) const;
    void eliminaDoInicio();
    void destroiLista();
};

#endif