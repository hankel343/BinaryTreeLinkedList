#ifndef QUEUE_H
#define QUEUE_H
#include "ItemType.h"
#include <cstddef>
#include <new>

struct Node
{
	ItemType iData;
	Node* pNext;
};

class FullQueue {};
class EmptyQueue {};

class Queue
{
private:
	Node* pFront;
	Node* pRear;

public:
	//Constructor:
	Queue();

	//Methods:
	void MakeEmpty();
	//Pre: The queue object exists.
	//Post: All contents of the queue have been removed and their memory deallocated.

	void Enqueue(ItemType iNewItem);
	//Pre: A queue object exists and the call to the method is in a try block that catches a FullQueue() exception.
	//Post: Memory is allocated for a new node and enqueued.

	void Dequeue(ItemType& iRemovedItem);
	//Pre: A queue object exists and the call to the method is in a try block that catches an EmptyQueue() exception.
	//Post: The memory of the first node in the queue is deallocated.

	bool IsEmpty() const;
	//Pre: A queue object exists.
	//Post: A boolean value is returned representing if the queue is empty or not.

	bool IsFull() const;
	//Pre: A queue object exists.
	//Post: A boolean value is returned representing if the queue is full or not.

	//Destructor:
	~Queue();
};

#endif QUEUE_H