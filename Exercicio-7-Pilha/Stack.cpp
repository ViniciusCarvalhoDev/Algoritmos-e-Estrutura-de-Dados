#include "Stack.h"
#include <exception>

struct Node {
  unsigned data;
  Node* next;
};

class EmptyException : public std::exception {
    const char * what () const throw () {
      return "Empty Exception";
   }
};
    
Stack::Stack() {
   
    this->_top = nullptr;
    this-> _count = 0;
    
  // TODO.
}

void Stack::push(unsigned elem) {
    
    Node *ptr = new Node();
    ptr->data = elem;
    ptr->next = ptr;
    this->_top = ptr;
    this->_count++;

}

void Stack::pop() {
    if(isempty()){
        throw Stack::EmptyException();
    }
    else{
        Node *ptr = this->_top;
        this-> _top = this->_top-> next;
        delete(ptr);
        this-> _count--;
    }
  
}

unsigned Stack::top() {
     if(isempty()){
      throw Stack::EmptyException();
    }
    else{
        return this->_top->data;
    }
  return 0;  
  
}

unsigned Stack::count() const {
  return this-> _count; 
}

bool Stack::isempty(){
    
    if(this->_top == nullptr){
        return true;
    }
    else{
        return false;
    }
}