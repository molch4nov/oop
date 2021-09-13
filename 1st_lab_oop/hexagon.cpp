#include "hexagon.h"
#include <cmath>
using namespace std;

Hexagon::Hexagon(istream &is){
    cout << "Enter all data: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    cout << "Hexagon created via istream" << endl;
}

void Hexagon::Print(){
    cout << "Hexagon"<< a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
}

double Hexagon::Area(){
    return abs(a.x() * b.y() + b.x() *c.y() + c.x()*d.y() + d.x()*e.y() + e.x()*f.y() + f.x()*a.y() - b.x()*a.y() - c.x()*b.y() - d.x()*c.y() - e.x()*d.y() - f.x()*e.y() - a.x()*f.y())/2;
}

size_t Hexagon::VertexNumber(){
    size_t h = 6;
    return h;
}