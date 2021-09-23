#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figure.h"
#include <iostream>
using namespace std;

class Rhombus : public Figure {
public:
    Rhombus(istream &is);
    void Print();
    double Area();
    size_t VertexesNumber();
private:
    Point a, b, c, d;
};

#endif 
