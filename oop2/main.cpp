#include <iostream>
#include "rhombus.h"
#include "tbinary_tree.h"
using namespace std;
int main(){
    Rhombus r1(cin);
    r1.Print();
    TBinaryTree lol;
    lol.Empty();
    lol.Push(r1);
    lol.Empty();
    lol.Count(0.0, 15.0);
    system("pause");
    return 0;
}
