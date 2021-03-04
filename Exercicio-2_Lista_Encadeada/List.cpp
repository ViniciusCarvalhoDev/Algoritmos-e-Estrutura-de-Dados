#include "Node.hpp"
#include "List.hpp"
#include <functional>
#include <stdexcept>
#include <stdio.h>

using namespace std;
    

    List::List(){
        this-> _size = 0;
        this-> _head = nullptr;
        
    }
    
void List::eliminaDoInicio() {
    if (isEmpty()==1)
     throw std::invalid_argument("A lista esta vazia // retiraDoInicio()");

    Node *saiu = _head;
    _head = saiu->getNext();
    _size -= 1;
    delete saiu;
  }
    
List::~List(){
        while(!isEmpty() != 0)
        eliminaDoInicio();
    }
    
    /** Essa função insere um elemento no começo da lista.
     */
    void List::insert(int value){
        
        Node* novo;
        novo = new Node(value, nullptr);
        
        if(isEmpty()){
            this-> _size += 1;
            this->_head = novo;
            novo->setNext(nullptr);
            
        }else{
            this-> _size += 1;
            novo->setNext(_head);
            this->_head = novo;
            
        }
        
        
    }
    /** Essa função remove o primeiro nó da lista, e retorna o dado armazenado nele.
       @retorna um inteiro armazenado no primeiro nó da lista.
     */
    int List::remove(){
        int aux1;
        
        aux1 = this->_head->getData();
        Node *aux2 = _head->getNext();
        
        _size -= 1;
        delete this-> _head;
        this->_head = aux2;
        return aux1;
    
    }
    /** Esse método indica se a lista está vazia.
       @retorna verdadeiro se a lista está vazia, e falso caso contrário.
     */
    int List::isEmpty(){
        
        if((_head == nullptr)){
            return 1;
        }
        else{
            return 0;
        }
    }
    /** Informa o número de elementos da lista.
       @retorna um inteiro n, onde n é o número de nó da lista.
     */
    unsigned int List::size() const{return _size;}
    /** Retorna o elemento do meio da lista.
       Se a lista possui 2*n ou 2*n + 1 elementos, então o elemento do meio é
       o que está no índice n, assumindo que o primeiro índice é 0.
       @retorna o elemento do meio da lista.
     */
    int List::middle()const {
        
        Node *elemento = nullptr;
        int pos;
        
        if(_size == 1){
            elemento = getElement(0);
            return elemento -> getData();
        }
        else if(_size == 2){
            elemento = getElement(1);
            return elemento -> getData();
        }
        if(_size % 2 == 0){
            
            pos = _size / 2;
            elemento = getElement(pos);
            return elemento -> getData();
            
        }else{
            pos = _size / 2;
            elemento = getElement(pos);
            return elemento -> getData();
        }
        
    }
    /** Retorna o último elemento da lista.
       @retorna o inteiro armazenado no último nó da lista.
     */
    int List::last() const{
        Node *elemento = nullptr;
        
        elemento = getElement(_size-1);
        return elemento -> getData();
    }
    /** Esse método move o primeiro nó da lista para última posição.
       Em outras palavras, rotate() + last() == head.
     */
    void List::rotate() {
        
    Node *aux;
    Node *cauda;
    
    cauda = this->_head;
    aux =this->_head->getNext();
    
    for (int i=0;i<size()-1;i++){
        cauda=cauda->getNext();
    }
    
    cauda->setNext(_head);
    this->_head = aux;
    cauda->getNext()->setNext(nullptr);
    
}

  Node* List::getElement(int pos) const{
        
        Node *verifica = _head;
        
        for (int i = 0; i != pos; ++i)
        verifica = verifica->getNext();

        return verifica;
    }
    




