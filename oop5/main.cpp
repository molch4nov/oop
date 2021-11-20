#include <iostream>
#include "rhombus.h"
#include "tbinary_tree.h"
#include <memory>
using namespace std;
int main(){
    Rhombus r1(cin);
    Rhombus r2(cin);

    TBinaryTree<Rhombus> tree;
    tree.Push(r1);
    tree.Push(r2);

    cout << tree << endl;
    



    TIterator<TBinaryTreeItem<Rhombus>, Rhombus> iter(tree.root);
    std:: cout << "The figure that you have put in root is: " << *iter << std:: endl;
    iter.GoToLeft();
    std:: cout << "The first result of Left-Iter function is: " << *iter << std:: endl;
    TIterator<TBinaryTreeItem<Rhombus>, Rhombus> first(tree.root->GetLeft());
    TIterator<TBinaryTreeItem<Rhombus>, Rhombus> second(tree.root->GetLeft());
    if (first == second) {
        std:: cout << "YES, YOUR ITERATORS ARE EQUALS" << std::endl;
    }

    return 0;
}
