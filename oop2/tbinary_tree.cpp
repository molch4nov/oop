#include "tbinary_tree.h"

TBinaryTree::TBinaryTree(){
    this->root = nullptr;
}

TBinaryTree::TBinaryTree(const TBinaryTree& otherBinTree) : TBinaryTree(){
    
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

/*TBinaryTreeItem* mini(TBinaryTreeItem* root){
    if(root->GetLeft == nullptr)
        return root;
    return mini(root->GetLeft);
}

void Pop(Rhombus& romb){
    if(root == nullptr){
        cout << "Нечего удалять";
    }
    else if (root->GetRhombus == romb){
        if(root->cnt > 1){
            root->Decrease();
        }
        else{
            root = root->GetRight();
        }
    }
}*/

void rCount(double minArea, double maxArea, TBinaryTreeItem* curItem, int& ans){
    if (curItem != nullptr){
        rCount(minArea, maxArea, curItem->GetLeft(), ans);
        rCount(minArea, maxArea, curItem->GetRight(), ans);
        if (minArea <= curItem->GetRhombus().GetArea() && curItem->GetRhombus().GetArea() < maxArea){
            ++ans;
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

void rClear(TBinaryTreeItem* cur){
    if (cur != nullptr){
        rClear(cur->GetLeft());
        rClear(cur->GetRight());
            delete cur;
    }
}

void TBinaryTree::Clear(){
    rClear(root);
    delete root;
}

TBinaryTree::~TBinaryTree() {

}