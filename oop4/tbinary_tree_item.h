#ifndef LAB2_TBINARY_TREE_ITEM_H
#define LAB2_TBINARY_TREE_ITEM_H

#include "rhombus.h"
#include <memory>
template <class T>
class TBinaryTreeItem {
public:
    
    TBinaryTreeItem(const T& romb);
    TBinaryTreeItem(const TBinaryTreeItem<T>& other);
    T& GetRhombus();
    void SetRhombus(const T& romb);
    std::shared_ptr<TBinaryTreeItem<T>> GetLeft();
    void SetLeft(std::shared_ptr<TBinaryTreeItem<T>> tBinTreeItem);
    std::shared_ptr<TBinaryTreeItem<T>> GetRight();
    void SetRight(std::shared_ptr<TBinaryTreeItem<T>> tBinTreeItem);
    void Increase();
    void Decrease();
    int Cnt();
    void Set(int a);
    virtual ~TBinaryTreeItem();
    T rhombus;
    std::shared_ptr<TBinaryTreeItem<T>> left;
    std::shared_ptr<TBinaryTreeItem<T>> right;
    int cnt;

template<class A>
friend std::ostream &operator<<(std::ostream &os,  TBinaryTreeItem<A> t);



};


#endif //LAB2_TBINARY_TREE_ITEM_H