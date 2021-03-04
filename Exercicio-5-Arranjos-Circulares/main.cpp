#include <iostream>

#include "RingArray.h"

void fer_assert(const bool expr, const char* msg) {
  if (!expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}

template <class T, unsigned N>
void RingArray<T, N>::add(T value) { 
    
  int_use += 1;
  
  fer_assert(!isFull(), "Erro: anel cheio.");

  buf[_last] = value;

  if(_last + 1 > N)
    _last = 0;
   else 
    _last++;
}

template <class T, unsigned N>
T RingArray<T, N>::get() {
    
  fer_assert(!isEmpty(), "Erro: anel vazio.");
  
  T auxiliar = buf[_first];

  if(_first + 1 > N) _first = 0; 
  else _first++;
  int_use -= 1;
  
  return auxiliar;
}

template <class T, unsigned N>
bool RingArray<T, N>::isFull() const { 
    
    if(int_use == N)
        return true;
    else
        return false;
}

template <class T, unsigned N>
bool RingArray<T, N>::isEmpty() const {
     if(int_use == 0)
        return true;
    else
        return false;
}

template <class T>
void test_add_then_get() {
  RingArray<T, 8> r;
  
  T v;
  
  while (std::cin >> v) {
    r.add(v);
  }
  while (r.isEmpty() != true) {
    std::cout << r.get() << std::endl;
  }
}

template <class T>
void test_add_or_get() {
  RingArray<T, 8> r;
  T value;
  char c;
  while (std::cin >> c) {
    if (c == '+') {
      std::cin >> value;
      r.add(value);
    } else if (c == '-') {
      std::cout << r.get() << std::endl;
    } else {
      std::cout << "Invalid operation\n";
    }
  }
}

int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'd': test_add_then_get<double>();
                break;
      case 's': test_add_then_get<std::string>();
                break;
      case 'D': test_add_or_get<double>();
                break;
      case 'S': test_add_or_get<std::string>();
                break;
      default: std::cout << "Invalid type\n";
    }
  }
  return 0;
}