#include "Queue.h"

Queue::Queue()
{
	pFront = nullptr;
	pFront = nullptr;
}

void Queue::MakeEmpty()
{
	Node* pTemp;

	while (pFront != nullptr)
	{
		pTemp = pFront;
		pFront = pFront->pNext;
		delete pTemp;
	}

	pRear = nullptr;
}

void Queue::Enqueue(ItemType iNewItem)
{
	if (IsFull() == true)
		throw FullQueue();
	else
	{
		//Allocate memory for a new node:
		Node* pNewNode = new Node;
		pNewNode->iData = iNewItem;
		pNewNode->pNext = nullptr;

		//If there is no rear pointer, then the first node must also be the front node.
		if (pRear == nullptr)
			pFront = pNewNode;
		else //Set rear's next to the new node's address:
			pRear->pNext = pNewNode;

		pRear = pNewNode; //Make the new node the new rear pointer.
	}
}

void Queue::Dequeue(ItemType& iRemovedItem)
{
	if (IsEmpty() == true)
		throw EmptyQueue();
	else
	{
		Node* pTemp = pFront;

		iRemovedItem = pFront->iData; //Preserve data
		pFront = pFront->pNext; //Advance front pointer to the next address. 

		if (pFront == nullptr) //If pFront is not pointing to anything.
			pRear = nullptr; //pRear is also not pointing to anything.

		delete pTemp; //Remove the previous front node.
	}
}

bool Queue::IsFull() const
{
	try
	{
		Node* pTest = new Node; //This will throw an exception if memory fails to allocate.
		delete pTest;
		return false;

	}
	catch (std::bad_alloc exception) {
		return true;
	}
}

bool Queue::IsEmpty() const
{
	return (pFront == nullptr);
}

Queue::~Queue()
{
	MakeEmpty();
}