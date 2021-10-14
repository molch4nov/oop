#include "rhombus.h"
using namespace std;

Rhombus::Rhombus(){
    std::cout << "Empty constructor was called\n";
}

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

double Rhombus::GetArea(){
    return abs(a.x * b.y + b.x *c.y + c.x*d.y + d.x*a.y - b.x*a.y - c.x*b.y - d.x*c.y - a.x*d.y)/2;
}
size_t Rhombus::VertexNumber(){
    size_t h = 4;
    return h;
}


bool operator == (Rhombus& r1, Rhombus& r2){
    if((r1.a == r2.a) && (r1.b == r2.b) && (r1.c == r2.c) && (r1.d == r2.d)){
        return true;
    }
    else{
        return false;
    }
}


Rhombus::~Rhombus() {}