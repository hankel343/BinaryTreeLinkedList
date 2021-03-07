#ifndef TREE_H
#define TREE_H
#include "ItemType.h"	//Note that ItemType stores chars for this class.
#include "Queue.h"
#include <iostream>

/*Node declaration of individual node that makes up the tree.*/
struct TreeNode
{
	ItemType iData;
	TreeNode* pRight;	//Link to right subtree
	TreeNode* pLeft;	//Link to left subtree
};

/*Enum for traversal types of accessing the tree*/
enum OrderType {PREORDER, INORDER, POSTORDER};

class TreeType
{
private:
	TreeNode* pRoot;
	Queue PreQueue;
	Queue InQueue;
	Queue postQueue;

public:
	TreeType();
	~TreeType();
	TreeType(const TreeType& originalTree);
	void operator=(const TreeType& originalTree);
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int GetLength() const;
	ItemType GetItem(ItemType item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetTree(OrderType order);
	ItemType GetNextItem(OrderType order, bool& finished);
	void Print() const;
};

#endif TREE_H