


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

string RedBlackTree::ToInfixString(const RBTNode *n){
    if (n == nullptr || n->IsNullNode){
        return "";
    }
    string left = ToInfixString(n->left);
    string right = ToInfixString(n->right);
    string final;

    if(!left.empty()){
        final += left;
    }
    if(n->color == 1){
        final += " B";
    } else{
        final += " R";
    }
    final += to_string(n->data) + " ";

    if (!right.empty()){
        final += right;
    }
    return final;
}
string RedBlackTree::ToPrefixString(const RBTNode *n){
    if (n == nullptr || n->IsNullNode){
        return "";
    }
    string left = ToPrefixString(n->left);
    string right = ToPrefixString(n->right);
    string final;

    if(n->color == 1){
        final += " B";
    } else{
        final += " R";
    }
    final += to_string(n->data) + " ";

    if(!left.empty()){
        final += left;
    }
    if (!right.empty()){
        final += right;
    }
    return final;
}
string RedBlackTree::ToPostfixString(const RBTNode *n){
    if (n == nullptr || n->IsNullNode){
        return "";
    }
    string left = ToPostfixString(n->left);
    string right = ToPostfixString(n->right);
    string final;

    if(!left.empty()){
        final += left;
    }
    if (!right.empty()){
        final += right;
    }
    
    if(n->color == 1){
        final += " B";
    } else{
        final += " R";
    }
    final += to_string(n->data) + " ";
    return final;
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

RBTNode * RedBlackTree::GetUncle(RBTNode *node) const{
    if (node == nullptr || node->parent == nullptr || node->parent->parent == nullptr){
        return nullptr; // no node parent or grangparent, no uncle
    }

    RBTNode* parent = node->parent;
    RBTNode* grand_parent = parent->parent;

    if(grand_parent->left == parent){
        return grand_parent->right;
    } else{
        return grand_parent->left;
    }
}

void RedBlackTree::InsertFixUp(RBTNode *node){

    if (node == root || node->parent->color == 1){
        root->color = 1;
        return;
    }

    RBTNode* parent = node->parent;
    RBTNode* grandparent = parent->parent;
    RBTNode* uncle = GetUncle(node);

    if(uncle != nullptr && uncle->color == 0){ // uncle is red - recolor
        parent->color = 1;
        uncle->color = 1;
        grandparent->color = 0;
        InsertFixUp(grandparent); // call for grandparent 
    } 
    else{ // uncle is black - rotate
        

    }

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

    while(currNode != nullptr && !currNode->IsNullNode){
        parent = currNode;
        if(newData < currNode->data){
            currNode = currNode->left;
        } else{
            currNode = currNode->right;
        }
    }
    if (parent == nullptr){
        root = newNode;
    } else{
        newNode->parent = parent;
        if(newData < parent->data){parent->left = newNode;}
        else{parent->right = newNode;}
    }

    InsertFixUp(newNode);


    delete newNode;
    return;
}


