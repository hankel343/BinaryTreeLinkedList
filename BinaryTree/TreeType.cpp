#include "TreeType.h"

/*===== Method Helper Functions =====*/

//TreeType::DeleteItem():
void Delete(TreeNode*& tree, ItemType item);
void DeleteNode(TreeNode*& tree);
void GetPredecessor(TreeNode* tree, ItemType& data);

//TreeType::GetLength():
int CountNodes(TreeNode* tree);

//TreeType::GetItem():
void Retrieve(TreeNode* tree, ItemType& item, bool& found);

//TreeType::PutItem():
void Insert(TreeNode*& tree, ItemType item);

//TreeType::Print():
void PrintTree(TreeNode* tree);

//TreeType::~TreeType():
void Destroy(TreeNode*& tree);


/*===== Class methods =====*/
TreeType::TreeType()
{
	pRoot = NULL;
}

int TreeType::GetLength() const
{
	return CountNodes(pRoot);
}

/*CountNodes is the recursive helper function for TreeType::GetLength()*/
//CountNodes treats each new node as if it was its own binary tree.
int CountNodes(TreeNode* tree)
{
	if (tree == NULL)	return 0; //No nodes in the tree
	else				return CountNodes(tree->pLeft) + CountNodes(tree->pRight) + 1;
	//Count notes in left and right subtrees.
}

ItemType TreeType::GetItem(ItemType item, bool& found)
{
	Retrieve(pRoot, item, found);
	return item;	//If item is not found, original item is returned and found
					//is still set to false.
}

/*Retrieve is the recursive helper function for TreeType::GetItem*/
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

void TreeType::PutItem(ItemType item)
{
	Insert(pRoot, item);
}

/*Insert is the recursive helper function for TreeType::PutItem*/
//*& means that the location of the pointer is being passed.
//This is because what the passed pointer points to is going to be reassigned in the function.
void Insert(TreeNode*& tree, ItemType item)
{
	if (tree == NULL)
	{	//Insertion point found.
		tree = new TreeNode; //Allocate mem. This is why tree is passed by reference.
		tree->pRight = NULL;
		tree->pLeft = NULL;
		tree->iData = item;
	}
	else if (item.ComparedTo(tree->iData) == LESS) //Insertion point will be in left sub.
		Insert(tree->pLeft, item);
	else
		Insert(tree->pRight, item); //Insertion point will be in right sub.
}

void TreeType::DeleteItem(ItemType item)
{
	Delete(pRoot, item);
}

/*Helper function for the TreeType::DeleteItem*/
void GetPredecessor(TreeNode* tree, ItemType& data)
{
	while (tree->pRight != NULL)
		tree = tree->pRight;
	data = tree->iData;
}

/*Helper function for the TreeType::DeleteItem*/
void DeleteNode(TreeNode*& tree)
{
	ItemType data;
	TreeNode* pTemp;

	pTemp = tree;
	if (tree->pLeft == NULL)
	{
		tree = tree->pRight;
		delete pTemp;
	}
	else if (tree->pRight == NULL)
	{
		tree = tree->pLeft;
		delete pTemp;
	}
	else //If the node has two child nodes.
	{
		GetPredecessor(tree->pLeft, data);
		tree->iData = data;
		Delete(tree->pLeft, data);
	}
}

/*Helper function for the TreeType::DeleteItem*/
void Delete(TreeNode*& tree, ItemType item)
//Deletes an item from the tree.
{
	if (item.ComparedTo(tree->iData) == LESS)	//Must search left subtree.
		Delete(tree->pLeft, item);
	else if (item.ComparedTo(tree->iData) == GREATER)	//Must search right subtree. 
		Delete(tree->pRight, item);
	else	//Match found.
		DeleteNode(tree);
}

void TreeType::Print() const
{
	PrintTree(pRoot);
}

/*Helper to TreeType::Print()*/
void PrintTree(TreeNode* tree)
{
	if (tree != NULL)
	{
		PrintTree(tree->pLeft);
		std::cout << tree->iData.Get();
		PrintTree(tree->pRight);
	}
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

TreeType::~TreeType()
{
	Destroy(pRoot);
}

void Destroy(TreeNode*& tree)
{
	if (tree != NULL)
	{
		Destroy(tree->pLeft); Destroy(tree->pRight); delete tree;
	}
}