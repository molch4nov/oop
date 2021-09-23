#ifndef HEXAGON_H
#define HEXAGON_H
#include "figure.h"
#include <iostream>
using namespace std;

class Hexagon: public Figure {
public:
    Hexagon(istream &is);
    void Print();
    double Area();
    size_t VertexesNumber();
private:
    Point a, b, c, d, e, f;
};

#endif 
