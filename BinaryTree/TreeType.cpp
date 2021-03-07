#include "TreeType.h"

//CountNodes treats each new node as if it was its own binary tree.
int CountNodes(TreeNode* tree)
{
	if (tree == NULL)	return 0; //No nodes in the tree
	else				return CountNodes(tree->pLeft) + CountNodes(tree->pRight) + 1;
						//Count notes in left and right subtrees.
}

int TreeType::GetLength() const
{
	return CountNodes(pRoot);
}

void Retrieve(TreeNode* tree, ItemType& item, bool& found)
{
	if (tree == NULL)	//Reached a leaf node without finding the search item.
		found = false;
	else if (item.ComparedTo(tree->iData) == GREATER)	//Need larger keys - search right subtree.
		Retrieve(tree->pRight, item, found);
	else if (item.ComparedTo(tree->iData) == LESS)		//Need smaller keys - search left subtree.
		Retrieve(tree->pLeft, item, found);
	else //matching item found.
	{
		found = true;
		item = tree->iData;
	}
}

ItemType TreeType::GetItem(ItemType item, bool& found)
{
	Retrieve(pRoot, item, found);
	return item;	//If item is not found, original item is returned and found
					//is still set to false.
}

bool TreeType::IsFull() const
{
	TreeNode* location;
	try
	{
		location = new TreeNode;	//If failed to allocate, bad_alloc thrown.
		delete location;
		return false;
	} catch(std::bad_alloc exception) { //Memory allocation failed.
		return true;
	}
}

bool TreeType::IsEmpty() const
{
	return (pRoot == NULL);
}