#ifndef LAB2_TBINARY_TREE_H
#define LAB2_TBINARY_TREE_H

#include "tbinary_tree_item.h"
#include <memory>
template <class T>
class TBinaryTree {

public:
    std::shared_ptr<TBinaryTreeItem<T>> root;
    TBinaryTree();
    TBinaryTree(const TBinaryTree<T>& other);
    void Push(T romb);
    std::shared_ptr<TBinaryTreeItem<T>> Pop(std::shared_ptr<TBinaryTreeItem<T>> root, T& romb);
    void Clear();
    bool Empty();
    int  Count(double minArea, double maxArea);
    void Print (std::ostream& os, std::shared_ptr<TBinaryTreeItem<T>> node);
    template <class A>
    friend  std::ostream& operator<<(std::ostream& os, TBinaryTree<A>& tree);
    T& GetItemNotLess(double area, std::shared_ptr<TBinaryTreeItem<T>> root);
    virtual ~TBinaryTree();
    
};


#endif //LAB2_TBINARY_TREE_H