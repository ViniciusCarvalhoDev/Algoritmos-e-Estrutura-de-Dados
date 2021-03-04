#include <iostream>

#include "Point.h"

std::ostream & operator << (std::ostream &out, const Point &p) {
  
  out << "(" << p.x << ", " << p.y << ")" ;
  return out;
}

std::istream & operator >> (std::istream &in,  Point &p) {
  in >> p.x >> p.y;
  return in;
}

Point Point::operator + (const Point &p) {
    
    int px = this->x + p.x;
    int py = this->y + p.y;
    
    Point aux(px,py);
    return aux;
}

Point& Point::operator += (const Point &p) {
    
    this->x += p.x;
    this->y += p.y;
    return *this;
 
}