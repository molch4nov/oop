#ifndef LAB2_TBINARY_TREE_H
#define LAB2_TBINARY_TREE_H

#include "tbinary_tree_item.h"

class TBinaryTree {

public:
    TBinaryTreeItem* root;
    TBinaryTree();
    TBinaryTree(const TBinaryTree& other);
    void Push(Rhombus romb);
    TBinaryTreeItem* Pop(TBinaryTreeItem* root, Rhombus& romb);
    void Clear();
    bool Empty();
    int  Count(double minArea, double maxArea);
    void Print (std::ostream& os, TBinaryTreeItem* node);
    friend  ostream& operator<< (std::ostream& os, TBinaryTree& tree);
    Rhombus& GetItemNotLess(double area, TBinaryTreeItem* root);
    virtual ~TBinaryTree();
    
};


#endif //LAB2_TBINARY_TREE_H