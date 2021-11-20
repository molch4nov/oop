#include "tbinary_tree.h"
#include <memory>

template <class T>
TBinaryTree<T>::TBinaryTree(){
    this->root = nullptr;
}


template <class T>
std::shared_ptr<TBinaryTreeItem<T>> copy(std::shared_ptr<TBinaryTreeItem<T>> root){
    if(!root){
        return nullptr;
    }
    std::shared_ptr<TBinaryTreeItem<T>> cur(new TBinaryTreeItem<T>(root->GetRhombus()));
    std::shared_ptr<TBinaryTreeItem<T>> root_copy = cur;
    root_copy->SetLeft(copy(root->GetLeft())); 
    root_copy->SetRight(copy(root->GetRight())); 
    return root_copy;
}
template <class T>
TBinaryTree<T>::TBinaryTree(const TBinaryTree &other) {
    root = copy(other.root);
}
template <class T>
void rClear(std::shared_ptr <TBinaryTreeItem<T>> cur){
    if (cur != nullptr){
        rClear(cur->GetLeft());
        rClear(cur->GetRight());
        cur = NULL;
    }
}

template <class T>
void TBinaryTree<T>::Push(T romb){
    if(root == nullptr){
        std::shared_ptr<TBinaryTreeItem<T>> cur(new TBinaryTreeItem<T>(romb));    
        root = cur;
    }
    else if(root->GetRhombus() == romb){
        root->Increase();
    }
    else{
        std::shared_ptr<TBinaryTreeItem<T>> parent = root;
        std::shared_ptr<TBinaryTreeItem<T>> cur;
        int checkleft = 1;
        if(romb.GetArea() < parent->GetRhombus().GetArea()){
            cur = root->GetLeft();
        }
        else{
            cur = root->GetRight();
            checkleft = 0;
        }
        while(cur != nullptr){
            if(cur->GetRhombus() == romb){
                cur->Increase();
            }
            else{
                if(romb.GetArea() < cur->GetRhombus().GetArea()){
                    parent = cur;
                    cur = parent->GetLeft();
                    checkleft = 1;
                }
                else{
                    parent = cur;
                    cur = parent->GetRight();
                    checkleft = 0;
                }
            }
        }
        std::shared_ptr<TBinaryTreeItem<T>> help(new TBinaryTreeItem<T>(romb));
        cur = help;
        if(checkleft == 1){
            parent->SetLeft(cur);
        }
        else{
            parent->SetRight(cur);
        }
    }
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T>> mini(std::shared_ptr<TBinaryTreeItem<T>> root){
    if (root->GetLeft() == NULL){
        return root;
    }
    return mini(root->GetLeft());
}
template <class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTree<T>::Pop(std::shared_ptr<TBinaryTreeItem<T>> root, T &romb) {
    if (root == NULL) {
        return root;
    }
    else if (romb.GetArea() < root->GetRhombus().GetArea()) {
        root->left = Pop(root->left, romb);
    }
    else if (romb.GetArea() > root->GetRhombus().GetArea()) {
        root->right = Pop(root->right, romb);
    }
    else {
        //first case of deleting - we are deleting a list
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
            return root;
        }
        //second case of deleting - we are deleting a verex with only one child
        else if (root->left == NULL && root->right != NULL) {
            std::shared_ptr<TBinaryTreeItem<T>> pointer = root;
            root = root->right;
            return root;
        }
        else if (root->right == NULL && root->left != NULL) {
            std::shared_ptr<TBinaryTreeItem<T>> pointer = root;
            root = root->left;
            return root;
        }
        //third case of deleting 
        else {
            std::shared_ptr<TBinaryTreeItem<T>> pointer = mini(root->right);
            root->Set(pointer->GetRhombus().GetArea());
            root->right = Pop(root->right, pointer->GetRhombus());
        }
    }
}

template <class T>
void rCount(double minArea, double maxArea, std::shared_ptr<TBinaryTreeItem<T>> curItem, int& ans){
    if (curItem != nullptr){
        rCount(minArea, maxArea, curItem->GetLeft(), ans);
        rCount(minArea, maxArea, curItem->GetRight(), ans);
        if (minArea <= curItem->GetRhombus().GetArea() && curItem->GetRhombus().GetArea() < maxArea){
            ans += curItem->Cnt();
        }
    }
}
template <class T>
int TBinaryTree<T>::Count(double minArea, double maxArea){
    int ans = 0;
    rCount(minArea, maxArea, root, ans);
    return ans;
}
template <class T>
bool TBinaryTree<T>::Empty(){
    return root == nullptr;
}


template <class T>
void TBinaryTree<T>::Clear(){
    rClear(root);
}

template <class T>
void Print (std::ostream& os, std::shared_ptr<TBinaryTreeItem<T>> node){
    if (!node){
        return;
    }
    if( node->left){
        os << node->GetRhombus().GetArea() << ": [";
        Print (os, node->left);
        if (node->right){
            if (node->right){
                os << ", ";
                Print (os, node->right);
            }
        }
        os << "]";
    } else if (node->right) {
       os << node->GetRhombus().GetArea() << ": [";
        Print (os, node->right);
        if (node->left){
            if (node->left){
                os << ", ";
                Print (os, node->left);
            }
        }
        os << "]";
    }
    else {
        os << node->GetRhombus().GetArea();
    }
}

template <class T>
std::ostream& operator<< (std::ostream& os, TBinaryTree<T>& tree){
    Print(os, tree.root);
    os << "\n";
    return os;
}


template <class T>
T& TBinaryTree<T>::GetItemNotLess(double area, std::shared_ptr<TBinaryTreeItem<T>> root) {
    if (root->GetRhombus().GetArea() >= area) {
        return root->GetRhombus();
    }
    else {
        GetItemNotLess(area, root->right);
    }
}
template <class T>
TBinaryTree<T>::~TBinaryTree() {
    Clear();
}
template class TBinaryTree<Rhombus>;
template ostream& operator<<(ostream& os, TBinaryTree<Rhombus>& tree);