#include "rhombus.h"
using namespace std;

Rhombus::Rhombus(istream &is){
    cout << "Enter all data: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cout << "Rhombus created via istream" << endl;
}

void Rhombus::Print(){
    cout << "Rhombus"<< a << " " << b << " " << c << " " << d << endl;
}

double Rhombus::Area(){
    return abs(a.x() * b.y() + b.x() *c.y() + c.x()*d.y() + d.x()*a.y() - b.x()*a.y() - c.x()*b.y() - d.x()*c.y() - a.x()*d.y())/2;
}
size_t Rhombus::VertexesNumber(){
    size_t h = 4;
    return h;
}