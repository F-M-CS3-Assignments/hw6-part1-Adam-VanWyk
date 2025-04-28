#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H


#define COLOR_RED 0
#define COLOR_BLACK 1
#define COLOR_DOUBLE_BLACK 2

#include <iostream>

using namespace std;


struct RBTNode {
	int data;
	unsigned short int color;
	RBTNode *left = nullptr;
	RBTNode *right = nullptr;
	RBTNode *parent = nullptr;
	bool IsNullNode = false;
};


class RedBlackTree {
	
	public:
		// regular constructor
		RedBlackTree();
		// contrusctor with int
		RedBlackTree(int newData);
		// copy constructor
		RedBlackTree(const RedBlackTree &rbt);

		string ToInfixString() const {return ToInfixString(root);};
		string ToPrefixString() const { return ToPrefixString(root);};
		string ToPostfixString() const { return ToPostfixString(root);};

		// takes an integer to insert and returns void, complicated, lots of cases
		void Insert(int newData);

		// takes an integer and returns true if the integer is in the tree
		bool Contains(int data) const ;
		size_t Size() const {return numItems;};
		// returns min int
		int GetMin() const;
		// returns max int
		int GetMax() const;
		
	
	private: 
		unsigned long long int numItems  = 0;
		RBTNode *root = nullptr;
		
		static string ToInfixString(const RBTNode *n);
		static string ToPrefixString(const RBTNode *n);
		static string ToPostfixString(const RBTNode *n);
		
		static string GetColorString(const RBTNode *n);
		static string GetNodeString(const RBTNode *n);
		
		void BasicInsert(RBTNode *node);
		void InsertFixUp(RBTNode *node);
		
		RBTNode *GetUncle(RBTNode *node) const;
		
		bool IsLeftChild(RBTNode *node) const;
		bool IsRightChild(RBTNode *node) const;
		
		bool RBTreeSetChild(RBTNode* parent, string whichChild, RBTNode* child);
		bool RBTreeReplaceChild(RBTNode* parent, RBTNode* currentChild, RBTNode* newChild);

		void LeftRotate(RBTNode *node);
		void RightRotate(RBTNode *node);
		
		RBTNode *CopyOf(const RBTNode *node);


		RBTNode *Get(int data) const;

};

#endif
