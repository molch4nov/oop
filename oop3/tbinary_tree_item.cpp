#include "tbinary_tree_item.h"
#include <memory>
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
std::shared_ptr<TBinaryTreeItem> TBinaryTreeItem::GetLeft(){
    return this->left;
}
std::shared_ptr<TBinaryTreeItem> TBinaryTreeItem::GetRight(){
    return this->right;
}


void TBinaryTreeItem::SetLeft(std::shared_ptr<TBinaryTreeItem> tBinTreeItem) {
    if (this != nullptr){
        this->left = tBinTreeItem;
    }
}

void TBinaryTreeItem::SetRight(std::shared_ptr<TBinaryTreeItem> tBinTreeItem) {
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
int TBinaryTreeItem::Cnt() {
    return this->cnt;
}

void TBinaryTreeItem::Set(int a){
    cnt = a;
}

TBinaryTreeItem::~TBinaryTreeItem() {
    std::cout << "Destructor TBinaryTreeItem was called\n";
}