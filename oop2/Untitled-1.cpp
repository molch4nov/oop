#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>

struct node{
    int field;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root, int field){
    if (root == NULL){
        struct node* createnode = malloc(sizeof(struct node));
        createnode->field = field;
        createnode->right = NULL;
        createnode->left = NULL;
    return createnode;
    };
    if (field < root->field){
        root->left = insert(root->left, field);
    } 
    else if (field > root->field){
        root->right = insert(root->right, field);
    }
    return root;
};

void printtree(struct node* root){
    if(root == NULL){
         return;
    }
    printtree(root->left);
    printf("%d -> ", root->field);
    printtree(root->right);
}


bool search(struct node* root, int number){
    if(root == NULL){
        return 0;
    }
    else if(number == root->field){
        return 1;

    }
    else if((number < root->field) && (root->left != NULL)){
        return search(root->left, number);
    }
    else if((number > root->field) && (root->right != NULL)){
        return search(root->right, number);
    }
}

bool search_l(struct node* root, int number){
    if(root == NULL){
        return 0;
    }
    else if((number == root->field) && (root->left == NULL) && (root->right == NULL)){
        return 1;
    }
    else if((number < root->field) && (root->left != NULL)){
        return search_l(root->left, number);
    }
    else if((number > root->field) && (root->right != NULL)){
        return search_l(root->right, number);
    }
    return 0;
}

int level(struct node* root, int number, int cnt){
    cnt += 1;
    if(number == root->field){
        return cnt;

    }
    else if((number < root->field) && (root->left != NULL)){
        return level(root->left, number, cnt);
    }
    else if((number > root->field) && (root->right != NULL)){
        return level(root->right, number, cnt);
    }
    return 0;
}

struct node* mini(struct node* root){
    if (root->left == NULL)
        return root;
    return mini(root->left);
};

struct node* delete1(struct node* root, int field){
        if (root == NULL) return root;
        else if (field < root->field){
            root->left = delete1(root->left, field);   
            }
        else if (field > root->field){
            root->right = delete1(root->right, field);
        }
        else if (root->left != NULL && root->right != NULL){
            
            root->field = mini(root->right)->field;
            root->right = delete1(root->right, root->field);
        }
        else
            if (root->left != NULL) {
                struct node* left = root->left;
                free(root);
                root = left;

            }
            else if (root->right != NULL) {
                struct node* right = root->right;
                free(root);
                root = right;
            }
            else {
                free(root);
                root = NULL;
                
            }
    return root;
};

struct node* deleteNode(struct node* root, int field) {
    if (root == NULL)
        return root;
    if (field < root->field)
        root->left = deleteNode(root->left, field);
    else if (field > root->field)
        root->right = deleteNode(root->right, field);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = mini(root->right);
        root->field = temp->field;
        root->right = deleteNode(root->right, temp->field);
    }
    return root;
}



struct node* clear(struct node* root){
    if(root == NULL) return root;
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if (root->right != NULL){
        root->right = clear(root->right);
    }
    if (root->left != NULL){
        root->left = clear(root->left);
    }
    return clear(root);
};

int main() {
    int number = 0;
    int n = 0;
    int cnt = 0;
    int cnt_el = 0;
    char symbol;
    struct node *root = NULL;
    int *g = (int*)calloc(1,sizeof(int));
    int *b = (int*)calloc(1,sizeof(int));
    while((symbol = getchar()) != EOF){
        if((symbol != ' ') && (symbol != '+') && (symbol != 'p') && (symbol != '?') && (symbol != '\n') && (symbol != '-') && (symbol != 'f')) {
            number *= 10;
            number += symbol-'0';
        }
        else if(symbol == '+') {
            root = insert(root, number);
            g = (int*)realloc(g, sizeof(int) * (n+1));
            b = (int*)realloc(b, sizeof(int) * (n+1));
            g[n] = number;
            n += 1;
            number = 0;
        }
        else if (symbol == 'p') {
            printtree(root);
            printf("\n");
            number = 0;
        }
        else if (symbol == '?') {
            if (search(root, number) == 1) {
                printf("\n%s\n", "founded");
            }
            else printf("\n%s\n", "not founded");
            number = 0;
        }
        else if (symbol == '-'){
            if (search(root, number) == 1) {
                root = delete1(root, number);
                for(int i = 0; i < n; i++){
                if(g[i] != number){
                    continue;
                }
                else{
                    g[i] = 0;
                    b[i] = 0;
                }
            }
                printf("\n%s\n", "deleted");
            }
            else printf("\n%s\n", "not deleted");
            
            number = 0;
            
        }
        else if (symbol == 'f') {
            for(int i = 0; i < n; i++){
                if(search_l(root, g[i])){
                    b[i] = level(root, g[i], cnt);
                    cnt_el += 1;
                    cnt = 0;
                }
                else{
                    continue;
                }
            }
            int h = 0;
            int help = 0;
            for(int i = 0; i < n; i++){
                if(b[i] != 0){
                    h = b[i];
                    help = i;
                    break;
                }
            }
            if(help != n){
            for(int i = help + 1; i < n; i++){
                if(b[i] != 0){
                    h ^= b[i];
                }
            }
            }
            else{
                h = 0;
            }
            if(h == 0 || cnt_el == 1){
                printf("%s", "na odnom");
            }
            else{
                printf("%s", "ne na odnom");
            }
        }
        else {
            continue;
        }
        
        }
        free(g);
        free(b);
    clear(root);
}