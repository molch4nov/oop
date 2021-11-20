#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figure.h"
#include <iostream>
using namespace std;

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(istream &is);
    void Print();
    double GetArea();
    size_t VertexNumber();
    friend bool operator == (Rhombus& r1, Rhombus& r2); 
    friend ostream& operator << (ostream& os, Rhombus& p);
    ~Rhombus();
private:
    Point a, b, c, d;
};

#endif 
