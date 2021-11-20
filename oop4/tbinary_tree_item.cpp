#include "tbinary_tree_item.h"


#include <memory>
template <class T>
TBinaryTreeItem<T>::TBinaryTreeItem(const T& romb) {
  this->rhombus = romb;
  this->left = nullptr;
  this->right = nullptr;
  this->cnt = 1;
}

template <class T>
TBinaryTreeItem<T>::TBinaryTreeItem(const TBinaryTreeItem<T>& other) {
  this->rhombus = other.rhombus;
  this->left = other.left;
  this->right = other.right;
  this->cnt = other.cnt;
}
template <class T>
T& TBinaryTreeItem<T>::GetRhombus() {
    return this->rhombus;
}
template <class T>
void TBinaryTreeItem<T>::SetRhombus(const T& romb){
    this->rhombus = romb;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTreeItem<T>::GetLeft(){
    return this->left;
}
template <class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTreeItem<T>::GetRight(){
    return this->right;
}

template <class T>
void TBinaryTreeItem<T>::SetLeft(std::shared_ptr<TBinaryTreeItem<T>> tBinTreeItem) {
    if (this != nullptr){
        this->left = tBinTreeItem;
    }
}

template <class T>
void TBinaryTreeItem<T>::SetRight(std::shared_ptr<TBinaryTreeItem<T>> tBinTreeItem) {
    if (this != nullptr){
        this->right = tBinTreeItem;
    }
}
template <class T>
void TBinaryTreeItem<T>::Increase() {
    if (this != nullptr){
        ++cnt;
    }
}
template <class T>
void TBinaryTreeItem<T>::Decrease() {
    if (this != nullptr){
        cnt--;
    }
}
template <class T>
int TBinaryTreeItem<T>::Cnt() {
    return this->cnt;
}
template <class T>
void TBinaryTreeItem<T>::Set(int a){
    cnt = a;
}
template <class T>
TBinaryTreeItem<T>::~TBinaryTreeItem() {
    std::cout << "Destructor TBinaryTreeItem was called\n";
}

template <class T>
std::ostream &operator<<(std::ostream &os, TBinaryTreeItem<T> t)
{
    os << t.rhombus << std::endl;
    return os;
}
#include "rhombus.h"
template class TBinaryTreeItem<Rhombus>;
template std::ostream& operator<<(std::ostream& os, TBinaryTreeItem<Rhombus> t);