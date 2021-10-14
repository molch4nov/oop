#include "tbinary_tree.h"
#include <memory>
TBinaryTree::TBinaryTree(){
    this->root = nullptr;
}

std::shared_ptr<TBinaryTreeItem> copy(std::shared_ptr<TBinaryTreeItem> root){
    if(!root){
        return nullptr;
    }
    std::shared_ptr<TBinaryTreeItem> cur(new TBinaryTreeItem(root->GetRhombus()));
    std::shared_ptr<TBinaryTreeItem> root_copy = cur;
    root_copy->SetLeft(copy(root->GetLeft())); 
    root_copy->SetRight(copy(root->GetRight())); 
    return root_copy;
}

TBinaryTree::TBinaryTree(const TBinaryTree &other) {
    root = copy(other.root);
}

void rClear(std::shared_ptr<TBinaryTreeItem> cur){
    if (cur != nullptr){
        rClear(cur->GetLeft());
        rClear(cur->GetRight());
    }
}


void TBinaryTree::Push(Rhombus romb){
    if(root == nullptr){
        std::shared_ptr<TBinaryTreeItem> cur(new TBinaryTreeItem(romb));    
        root = cur;
    }
    else if(root->GetRhombus() == romb){
        root->Increase();
    }
    else{
        std::shared_ptr<TBinaryTreeItem> parent = root;
        std::shared_ptr<TBinaryTreeItem> cur;
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
        std::shared_ptr<TBinaryTreeItem> help(new TBinaryTreeItem(romb));
        cur = help;
        if(checkleft == 1){
            parent->SetLeft(cur);
        }
        else{
            parent->SetRight(cur);
        }
    }
}


std::shared_ptr<TBinaryTreeItem> mini(std::shared_ptr<TBinaryTreeItem> root){
    if (root->GetLeft() == NULL){
        return root;
    }
    return mini(root->GetLeft());
}

std::shared_ptr<TBinaryTreeItem> TBinaryTree::Pop(std::shared_ptr<TBinaryTreeItem> root, Rhombus &romb) {
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
            std::shared_ptr<TBinaryTreeItem> pointer = root;
            root = root->right;
            return root;
        }
        else if (root->right == NULL && root->left != NULL) {
            std::shared_ptr<TBinaryTreeItem> pointer = root;
            root = root->left;
            return root;
        }
        //third case of deleting 
        else {
            std::shared_ptr<TBinaryTreeItem> pointer = mini(root->right);
            root->Set(pointer->GetRhombus().GetArea());
            root->right = Pop(root->right, pointer->GetRhombus());
        }
    }
}
void rCount(double minArea, double maxArea, std::shared_ptr<TBinaryTreeItem> curItem, int& ans){
    if (curItem != nullptr){
        rCount(minArea, maxArea, curItem->GetLeft(), ans);
        rCount(minArea, maxArea, curItem->GetRight(), ans);
        if (minArea <= curItem->GetRhombus().GetArea() && curItem->GetRhombus().GetArea() < maxArea){
            ans += curItem->Cnt();
        }
    }
}

int TBinaryTree::Count(double minArea, double maxArea){
    int ans = 0;
    rCount(minArea, maxArea, root, ans);
    return ans;
}

bool TBinaryTree::Empty(){
    return root == nullptr;
}



void TBinaryTree::Clear(){
    rClear(root);
}


void Print (std::ostream& os, std::shared_ptr<TBinaryTreeItem> node){
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

std::ostream& operator<< (std::ostream& os, TBinaryTree& tree){
    Print(os, tree.root);
    os << "\n";
}

Rhombus& TBinaryTree::GetItemNotLess(double area, std::shared_ptr<TBinaryTreeItem> root) {
    if (root->GetRhombus().GetArea() >= area) {
        return root->GetRhombus();
    }
    else {
        GetItemNotLess(area, root->right);
    }
}

TBinaryTree::~TBinaryTree() {

}