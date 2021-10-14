#ifndef LAB2_TBINARY_TREE_ITEM_H
#define LAB2_TBINARY_TREE_ITEM_H

#include "rhombus.h"
#include <memory>
class TBinaryTreeItem {
public:
    Rhombus rhombus;
    std::shared_ptr<TBinaryTreeItem> left;
    std::shared_ptr<TBinaryTreeItem> right;
    int cnt;
    TBinaryTreeItem(const Rhombus& romb);
    TBinaryTreeItem(const TBinaryTreeItem& other);
    Rhombus& GetRhombus();
    void SetRhombus(const Rhombus& romb);
    std::shared_ptr<TBinaryTreeItem> GetLeft();
    void SetLeft(std::shared_ptr<TBinaryTreeItem> tBinTreeItem);
    std::shared_ptr<TBinaryTreeItem> GetRight();
    void SetRight(std::shared_ptr<TBinaryTreeItem> tBinTreeItem);
    void Increase();
    void Decrease();
    int Cnt();
    void Set(int a);
    virtual ~TBinaryTreeItem();

};


#endif //LAB2_TBINARY_TREE_ITEM_H