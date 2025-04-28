


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
        final += left + " ";
    }
    if(n->color == 1){
        final += "B";
    } else{
        final += "R";
    }
    final += to_string(n->data);

    if (!right.empty()){
        final += " " + right;
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
        final += "B";
    } else{
        final += "R";
    }
    final += to_string(n->data);

    if(!left.empty()){
        final += " " + left;
    }
    if (!right.empty()){
        final += " " + right;
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
        final += left + " ";
    }
    if (!right.empty()){
        final += right + " ";
    }
    
    if(n->color == 1){
        final += "B";
    } else{
        final += "R";
    }
    final += to_string(n->data);
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


