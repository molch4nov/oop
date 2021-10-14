#ifndef LAB2_TBINARY_TREE_H
#define LAB2_TBINARY_TREE_H

#include "tbinary_tree_item.h"
#include <memory>
class TBinaryTree {

public:
    std::shared_ptr<TBinaryTreeItem> root;
    TBinaryTree();
    TBinaryTree(const TBinaryTree& other);
    void Push(Rhombus romb);
    std::shared_ptr<TBinaryTreeItem> Pop(std::shared_ptr<TBinaryTreeItem> root, Rhombus& romb);
    void Clear();
    bool Empty();
    int  Count(double minArea, double maxArea);
    void Print (std::ostream& os, std::shared_ptr<TBinaryTreeItem> node);
    friend  ostream& operator<< (std::ostream& os, TBinaryTree& tree);
    Rhombus& GetItemNotLess(double area, std::shared_ptr<TBinaryTreeItem> root);
    virtual ~TBinaryTree();
    
};


#endif //LAB2_TBINARY_TREE_H