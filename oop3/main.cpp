#include <iostream>
#include "rhombus.h"
#include "tbinary_tree.h"
#include <memory>
using namespace std;
int main(){
    Rhombus r1(cin);
    Rhombus r2(cin);

    TBinaryTree lol;
    lol.Push(r1);
    lol.Push(r2);

    cout << lol;
    lol.root = lol.Pop(lol.root, r1);
    cout << lol.Count(0,100) << " two" << endl;
    cout << lol;
system("pause");
    return 0;
}
