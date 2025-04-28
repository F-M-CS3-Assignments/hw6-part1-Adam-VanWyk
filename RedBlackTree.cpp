


#include <iostream> 
#include "RedBlackTree.h"

using namespace std;

RedBlackTree::RedBlackTree() = default;

RedBlackTree::RedBlackTree(int newData){
    root = new RBTNode;
    root->data = newData;
    root->color = 1;
    root->IsNullNode = false;
}


bool RedBlackTree::Contains(int data) const{
    if (Size() == 0){return false;}

    RBTNode* currNode = root;

    while(currNode != nullptr && !currNode->IsNullNode){
        if (currNode->data == data){
            return true;
        }
        else if(data < currNode->data){
            currNode = currNode->left;
        } else{
            currNode = currNode->right;
        }
    }
    return false;
}


void RedBlackTree::Insert(int newData){
    if(Contains(newData)){
        throw invalid_argument("Value already in tree. ");
    }

    RBTNode* newNode = new RBTNode;
    newNode->data = newData;
    newNode->color = 0;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;
    newNode->IsNullNode = false;

    if (root == nullptr){
        root = newNode;
        newNode->color = 1;
        return;
    }
    
    RBTNode* currNode = root;
    RBTNode* parent = nullptr;

    while(!currNode->IsNullNode && currNode != nullptr){
        parent = currNode;
        if(newData < currNode->data){
            currNode = currNode->left;
        } else{
            currNode = currNode->right;
        }
    }
    newNode->parent = parent;
    if(newData < parent->data){parent->left = newNode;}
    else{parent->right = newNode;}

    if(newNode->parent->color == 1){return;}



    delete newNode;
}


