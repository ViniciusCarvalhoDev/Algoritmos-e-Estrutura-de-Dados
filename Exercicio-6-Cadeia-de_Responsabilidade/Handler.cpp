#include <iostream>

#include "Handler.h"

using namespace std;

void fer_assert(const bool expr, const char* msg) {
  if (!expr) 
  {
    cout << msg << endl;
    exit(1);
  }
}

// remover v1 e v2 e dps adição de v1 e v2 entra na stack
void HandlerAdd::handle(Instruction *inst) {
  if (inst->msg.compare("add") == 0) {
    fer_assert(_stack->size() >= 2, "Erro: poucos argumentos na pilha.");
    const int v1 = _stack->top();
    _stack->pop();
    const int v2 = _stack->top();
    _stack->pop();
    const int vv = v1 + v2;
    _stack->push(vv);
  } else {
    fer_assert(_next != NULL, "Erro: comando desconhecido.");
    _next->handle(inst);
  }
 
}

// remover v1 e v2 e dps multiplicaçâo de v1 e v2 entra na stack
void HandlerMul::handle(Instruction *inst) {
  if (inst->msg.compare("mul") == 0) 
  {
      
    fer_assert(_stack->size() >= 2, "Erro: poucos argumentos na pilha.");
    
    const int v1 = _stack->top();
    _stack->pop();
    
    const int v2 = _stack->top();
    _stack->pop();
    
    const int vv = v1 * v2;
    _stack->push(vv);
  } 
  else 
  {
    fer_assert(_next != NULL, "Erro: comando desconhecido.");
    _next->handle(inst);
  }
 
}

void HandlerPop::handle(Instruction *inst) {
  if (inst->msg.compare("pop") == 0) 
  {
    fer_assert(_stack->size() >= 1, "Erro: poucos argumentos na pilha.");
    _stack->pop();
  } 
  else 
  {
    fer_assert(_next != NULL, "Erro: comando desconhecido.");
    _next->handle(inst);
  }

}

void HandlerPrint::handle(Instruction *inst) {
  if (inst->msg.compare("print") == 0) 
  {
    fer_assert(_stack->size() >= 1, "Erro: poucos argumentos na pilha.");
     cout << _stack->top() << endl;
  }
  else 
  {
    fer_assert(_next != NULL, "Erro: comando desconhecido.");
    _next->handle(inst);
  }

}

void HandlerPush::handle(Instruction *inst) {
  if (inst->msg.compare("push") == 0) 
  {
    _stack->push(inst->value);
  } 
  else 
  {
    fer_assert(_next != NULL, "Erro: comando desconhecido.");
    _next->handle(inst);
  }
  
}