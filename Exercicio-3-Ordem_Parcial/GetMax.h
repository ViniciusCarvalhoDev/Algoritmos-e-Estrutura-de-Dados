#ifndef GET_MAX_H
#define GET_MAX_H
#include <string>

#include <iostream>

struct BitSet {
    
  BitSet(unsigned value): _set(value) {}
  const unsigned _set;


  friend std::ostream & operator<<(std::ostream& os, const BitSet& i) {
  
    os << '<';
    for (int aux = 0; aux < 32; aux++) {
      unsigned mask = 1 << aux;
      if (i._set & mask) {
        os << "|";
      } else {
        os << "-";
      }
    }
    os << '>';
    return os;
  }
   bool operator>=(BitSet valor){
     std::string string1 = (std::string) (*this);
     std::string string2 = (std::string) (valor);
	 bool aux = false;
     for(int i=0; i< 32; i++){
       if(string1[i] < string2[i]){
         aux = false;
       }
     } 
	 aux = true;
	 return aux;
   }

    operator std::string() const {
      
    std::string number;
    number = "";
    
      for (int i = 0; i < 32; i++) {
            unsigned mask = 1 << i;
            
        if (this->_set & mask) number += "1";
        else number += "0";
    }
    
    return number;
  }
};


struct Interval {
  Interval(int left, int right): _l(left), _r(right) {}
  const int _r;
  const int _l;
  friend std::ostream & operator<<(std::ostream& os, const Interval& i) {
    os << '(' << i._l << ", " << i._r << ')';
    return os;
  }
  bool operator>=(Interval interval){
    return(Interval::_l <= interval._l && Interval::_r >= interval._r);
   }
};


template <class T>
T GetMaxDefault (T a, T b, T dflt) {
    
  if(a >= b) return a;
  else if(b >= a) return b;
  else return dflt;
  
}
#endif