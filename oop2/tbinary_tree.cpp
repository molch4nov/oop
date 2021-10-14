#include "tbinary_tree.h"

TBinaryTree::TBinaryTree(){
    this->root = nullptr;
}


TBinaryTreeItem* copy(TBinaryTreeItem* root){
    if(!root){
        return nullptr;
    }
    TBinaryTreeItem* root_copy = new TBinaryTreeItem(root->GetRhombus());
    root_copy->SetLeft(copy(root->GetLeft())); 
    root_copy->SetRight(copy(root->GetRight())); 
    return root_copy;
}

TBinaryTree::TBinaryTree(const TBinaryTree &other) {
root = copy(other.root);
}

void rClear(TBinaryTreeItem* cur){
    if (cur != nullptr){
        rClear(cur->GetLeft());
        rClear(cur->GetRight());
            delete cur;
    }
}


void TBinaryTree::Push(Rhombus romb){
    if(root == nullptr){
        root = new TBinaryTreeItem(romb);
    }
    else if(root->GetRhombus() == romb){
        root->Increase();
    }
    else{
        TBinaryTreeItem* parent = root;
        TBinaryTreeItem* cur;
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
        cur = new TBinaryTreeItem(romb);
        if(checkleft == 1){
            parent->SetLeft(cur);
        }
        else{
            parent->SetRight(cur);
        }
    }
}


TBinaryTreeItem* mini(TBinaryTreeItem* root){
    if (root->GetLeft() == NULL){
        return root;
    }
    return mini(root->GetLeft());
}

TBinaryTreeItem* TBinaryTree::Pop(TBinaryTreeItem* root, Rhombus &romb) {
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
            delete root;
            root = NULL;
            return root;
        }
        //second case of deleting - we are deleting a verex with only one child
        else if (root->left == NULL && root->right != NULL) {
            TBinaryTreeItem* pointer = root;
            root = root->right;
            delete pointer;
            return root;
        }
        else if (root->right == NULL && root->left != NULL) {
            TBinaryTreeItem* pointer = root;
            root = root->left;
            delete pointer;
            return root;
        }
        //third case of deleting 
        else {
            TBinaryTreeItem* pointer = mini(root->right);
            root->Set(pointer->GetRhombus().GetArea());
            root->right = Pop(root->right, pointer->GetRhombus());
        }
    }
}
void rCount(double minArea, double maxArea, TBinaryTreeItem* curItem, int& ans){
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
    delete root;
}


void Print (std::ostream& os, TBinaryTreeItem* node){
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

Rhombus& TBinaryTree::GetItemNotLess(double area, TBinaryTreeItem* root) {
    if (root->GetRhombus().GetArea() >= area) {
        return root->GetRhombus();
    }
    else {
        GetItemNotLess(area, root->right);
    }
}

TBinaryTree::~TBinaryTree() {

}