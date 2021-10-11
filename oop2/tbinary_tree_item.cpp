#include "tbinary_tree_item.h"

TBinaryTreeItem::TBinaryTreeItem(const Rhombus& romb) {
  this->rhombus = romb;
  this->left = nullptr;
  this->right = nullptr;
  this->cnt = 1;
}
 
TBinaryTreeItem::TBinaryTreeItem(const TBinaryTreeItem& other) {
  this->rhombus = other.rhombus;
  this->left = other.left;
  this->right = other.right;
  this->cnt = other.cnt;
}

Rhombus& TBinaryTreeItem::GetRhombus() {
    return this->rhombus;
}
 
void TBinaryTreeItem::SetRhombus(const Rhombus& romb){
    this->rhombus = romb;
}
TBinaryTreeItem* TBinaryTreeItem::GetLeft(){
    return this->left;
}
TBinaryTreeItem* TBinaryTreeItem::GetRight(){
    return this->right;
}

void TBinaryTreeItem::SetLeft(TBinaryTreeItem* tBinTreeItem) {
    if (this != nullptr){
        this->left = tBinTreeItem;
    }
}

void TBinaryTreeItem::SetRight(TBinaryTreeItem* tBinTreeItem) {
    if (this != nullptr){
        this->right = tBinTreeItem;
    }
}

void TBinaryTreeItem::Increase() {
    if (this != nullptr){
        ++cnt;
    }
}
void TBinaryTreeItem::Decrease() {
    if (this != nullptr){
        cnt--;
    }
}

TBinaryTreeItem::~TBinaryTreeItem() {
    std::cout << "Destructor TBinaryTreeItem was called\n";
}