//
//  rbt.cpp
//  ProblemSolve
//
//  Created by  JeJn on 2020/05/07.
//  Copyright © 2020  JeJn. All rights reserved.
//

#include<fstream>
#include<vector>
#define black false
#define red true
using namespace std;

ifstream fcin("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/rbt.inp");
ofstream fcout("/Users/jejn/Desktop/ProblemSolve/ProblemSolve/rbt.out");

typedef struct Node{
    int key;
    bool color;
    struct Node *left, *right, *parent;
}Node;

Node *CreateNode(int key){
    Node *node = new(struct Node);
    node->key = key;
    node->color = red;
    node->left = node->right = node->parent = new(struct Node);
    node->left->key = node->right->key = -1;
    node->left->color = node->right->color = black;
    node->left->left = node->right->right = NULL;
    return node;
}

Node *tree;
char type; // i, d, c
int key; // node key

Node *TreeInsert(Node *subtree, int key){
    if(subtree->key == -1){
        Node *child = CreateNode(key);
        return child;
    }
    if(subtree->key > key){
        subtree->left = TreeInsert(subtree->left, key);
        subtree->left->parent = subtree;
    }
    else{
        subtree->right = TreeInsert(subtree->right,key);
        subtree->right->parent = subtree;
    }
    return subtree;
}
Node *SearchNode(int key){
    Node *search = tree;
    while(1){
        if(search->key == key) break;
        else if(search->key > key) search = search->left;
        else search = search->right;
    }
    return search;
}
void LeftRotate(Node *root){
    // 내자신 갱신
    Node *child = root->right;
    root->right = child->left;
    child->left = root;
    // 부모들 갱신
    if(root == tree){
        tree = child;
    }
    else if(root == root->parent->right){
        root->parent->right = child;
    }
    else{
        root->parent->left = child;
    }
    child->parent = root->parent;
    root->parent = child;
    root->right->parent = root;
}
void RightRotate(Node *root){
    // 내자신 갱신
    Node *child = root->left;
    root->left = child->right;
    child->right = root;
    // 부모들 갱신
    if(root == tree){
        tree = child;
    }
    else if(root == root->parent->right){
        root->parent->right = child;
    }
    else{
        root->parent->left = child;
    }
    child->parent = root->parent;
    root->parent = child;
    root->left->parent = root;
}
void rbtInsert(int key){
    // BST 트리 생성
    if(tree->key > key) { tree->left = TreeInsert(tree->left, key); tree->left->parent = tree;}
    else { tree->right = TreeInsert(tree->right, key); tree->right->parent = tree; }
    Node *x = SearchNode(key);
    
    while(x->parent != NULL && x->parent->color){
        // 부모노드가 left child인 경우
        if(x->parent == x->parent->parent->left){
            Node *y = x->parent->parent->right;
            if(y->color){ // case 1 / y->color == red
                x->parent->color = black;
                y->color = black;
                x->parent->parent->color = red;
                x = x->parent->parent;
            }
            else{ // y->color == black
                if(x == x->parent->right){ // case 2
                    x = x->parent;
                    LeftRotate(x);
                }
                // case 3
                x->parent->color = black;
                x->parent->parent->color = red;
                RightRotate(x->parent->parent);
            }
        }
        // 부모노드가 right child인 경우
        else{
            Node *y = x->parent->parent->left;
            if(y->color){ // case 1 / y->color == red
                x->parent->color = black;
                y->color = black;
                x->parent->parent->color = red;
                x = x->parent->parent;
            }
            else{ // y->color == black
                if(x == x->parent->left){ // case 2
                    x = x->parent;
                    RightRotate(x);
                }
                // case 3
                x->parent->color = black;
                x->parent->parent->color = red;
                LeftRotate(x->parent->parent);
            }
        }
    }
    tree->color = black; tree->parent = NULL;
}
Node *TreeSuccessor(Node *z){ // 오른쪽 서브트리중 제일 작은값
    while(z->left->key != -1){
        z = z->left;
    }
    return z;
}
void rbtDeleteFixup(Node *x){
    while(x != tree && !x->color){
        if(x == x->parent->left){
            Node *w = x->parent->right;
            if(w->color){ // case 1
                w->color = black;
                x->parent->color = red;
                LeftRotate(x->parent);
                w = x->parent->right;
            }
            if(!w->left->color && !w->right->color){ // case 2
                w->color = red;
                x = x->parent;
            }
            else if(!w->right->color){ // case 3
                w->left->color = black;
                w->color = red;
                RightRotate(w);
                w = x->parent->right;
            }
            if(w->right->color){ // case 4
                w->color = x->parent->color;
                x->parent->color = black;
                w->right->color = black;
                LeftRotate(x->parent);
                x = tree;
            }
        }
        else{ // x == x->parent->right
            Node *w = x->parent->left;
            if(w->color){ // case 1
                w->color = black;
                x->parent->color = red;
                RightRotate(x->parent);
                w = x->parent->left;
            }
            if(!w->left->color && !w->right->color){ // case 2
                w->color = red;
                x = x->parent;
            }
            else if(!w->left->color){ // case 3
                w->right->color = black;
                w->color = red;
                LeftRotate(w);
                w = x->parent->left;
            }
            if(w->left->color){ // case 4
                w->color = x->parent->color;
                x->parent->color = black;
                w->left->color = black;
                RightRotate(x->parent);
                x = tree;
            }
        }
    }
    x->color = black;
}
void rbtDelete(int key){
    Node *x, *y;
    Node *z = SearchNode(key);
    
    if(z->left->key == -1 || z->right->key == -1) // z has 0 or 1 child
        y = z;
    else // z has 2 child
        y = TreeSuccessor(z->right);
    // now y has 0 or 1 child, set x as one child of y
    if(y->left->key != -1)
        x = y->left;
    else
        x = y->right;
    
    //if(x->key != -1) // delete y
        x->parent = y->parent;
    
    if(y->parent == NULL) tree = x;
    else if(y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    
    if(y!=z) z->key = y->key;
    
    if(!y->color) rbtDeleteFixup(x);
    
    delete y;
}
int main(){
    fcin >> type >> key;
    tree = CreateNode(key); tree->parent = NULL; tree->color = black;// 맨처음 root 노드 생성
    while(1){
        fcin >> type >> key;
        if(key == -1) break;
        
        switch(type){
            case 'i':
                rbtInsert(key);
                break;
            case 'd':
                rbtDelete(key);
                break;
            case 'c':
                Node *x = SearchNode(key);
                string str;
                if(x->color) str = "RED";
                else str = "BLACK";
                fcout << "color(" << key << "): " << str << '\n';
                break;
        }
    }
    return 0;
}
