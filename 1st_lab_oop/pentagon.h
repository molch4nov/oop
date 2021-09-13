#ifndef PENTAGON_H
#define PENTAGON_H
#include "figure.h"
#include <iostream>
using namespace std;

class Pentagon : public Figure {
public:
    Pentagon(istream &is);
    void Print();
    double Area();
    size_t VertexNumber();
private:
    Point a, b, c, d, e;
};

#endif 
