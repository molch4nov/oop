#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

class Figure{
private:
    double area;
public:
    virtual void Print() = 0;
    virtual double GetArea() = 0;
    virtual size_t VertexNumber() = 0;
};


#endif
