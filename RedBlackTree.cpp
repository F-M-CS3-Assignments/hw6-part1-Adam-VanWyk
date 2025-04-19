


#include <iostream> 
#include "RedBlackTree.h"

using namespace std;

RedBlackTree::RedBlackTree() = default;

RedBlackTree::RedBlackTree(int newData){
    RBTNode* root = new RBTNode;
    root->data = newData;
}


void RedBlackTree::Insert(int newData){
    RBTNode* newNode = new RBTNode;
    newNode->data = newData;
    newNode->color = 0;


    if (root = nullptr){
        root = newNode;
        return;
    }
    
    RBTNode* currNode = root;
    while(currNode->IsNullNode = false){
        if(newNode->data > currNode->data){
            currNode = currNode->right;
        } else if(newNode->data < currNode->data){
            currNode = currNode->left;
        }
    }


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