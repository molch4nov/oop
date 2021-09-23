#include "pentagon.h"
#include <cmath>
using namespace std;

Pentagon::Pentagon(istream &is){
    cout << "Enter all data: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cout << "Pentagon created via istream" << endl;
}

void Pentagon::Print(){
    cout << "Pentagon:"<< a << " " << b << " " << c << " " << d << " " << e <<endl;
}

double Pentagon::Area(){
    return abs(a.x() * b.y() + b.x() *c.y() + c.x()*d.y() + d.x()*e.y() + e.x()*a.y() - b.x()*a.y() - c.x()*b.y() - d.x()*c.y() - e.x()*d.y() - a.x()*e.y() )/2;

}

size_t Pentagon::VertexesNumber(){
    size_t h = 5;
    return h;
}