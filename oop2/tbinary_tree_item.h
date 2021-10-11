#ifndef LAB2_TBINARY_TREE_ITEM_H
#define LAB2_TBINARY_TREE_ITEM_H

#include "rhombus.h"

class TBinaryTreeItem {
private:
    Rhombus rhombus;
    TBinaryTreeItem* left;
    TBinaryTreeItem* right;
    int cnt;
public:
    TBinaryTreeItem(const Rhombus& romb);
    TBinaryTreeItem(const TBinaryTreeItem& other);
    Rhombus& GetRhombus();
    void SetRhombus(const Rhombus& romb);
    TBinaryTreeItem* GetLeft();
    void SetLeft(TBinaryTreeItem* tBinTreeItem);
    TBinaryTreeItem* GetRight();
    void SetRight(TBinaryTreeItem* tBinTreeItem);
    void Increase();
    void Decrease();
    virtual ~TBinaryTreeItem();

};


#endif //LAB2_TBINARY_TREE_ITEM_H