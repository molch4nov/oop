#include <iostream>
#include "rhombus.h"
#include "hexagon.h"
#include "pentagon.h"
using namespace std;
int main(){
    Rhombus Romb(cin);
    cout << "Area is: " << Romb.Area() << "\n";
    Romb.Print();
    Romb.VertexesNumber();
    cout << "\n";
    Rhombus Hexagon(cin);
    cout << "Area is: " << Hexagon.Area() << "\n";
    Hexagon.Print();
    Hexagon.VertexesNumber();
    cout << "\n";
    Pentagon Pentagon(cin);
    cout << "Area is: " << Pentagon.Area() << "\n";
    Pentagon.Print();
    Pentagon.VertexesNumber();
    cout << "\n";
    
    return 0;
}
