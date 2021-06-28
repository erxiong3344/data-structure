#include<iostream>
using namespace std;
#include "Queue.h"



CirQueue::CirQueue()
{
	data = new myDataType[QUEUE_SIZE];
	front = 0;
	rear = 0;
	capacity = QUEUE_SIZE;
}
CirQueue::CirQueue(int sz)
{
	data = new myDataType[sz];
	front = 0;
	rear = 0;
	capacity = sz;
}
CirQueue::~CirQueue()
{
	delete[] data;

}
bool CirQueue::enQueue(myDataType elem)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		rear = (rear + 1) % capacity;
		data[rear] = elem;
		return true;
	}
}
bool CirQueue::deQueue(myDataType *elem)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		front = (front + 1) % capacity;
		*elem = data[front];

		return true;
	}
}
bool CirQueue::getFront(myDataType *elem)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		int temp = (front + 1) % capacity;
		*elem = data[temp];
		return true;
	}
}
bool CirQueue::isEmpty()
{
	if (front == rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CirQueue::isFull()
{
	if ((rear + 1) % capacity == front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CirQueue::clearQueue()
{
	rear = front;
}

int CirQueue::QueueLength()
{
	if (rear >= front)
	{
		return rear - front;
	}
	else
	{
		return rear + capacity - front;
	}
}