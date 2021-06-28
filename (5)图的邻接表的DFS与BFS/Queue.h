#ifndef QUEUE_H__
#define QUEUE_H__
#include "ALGraph.h"
#define myDataType ArcNode*
const int QUEUE_SIZE = 20;
class CirQueue
{
private:
	myDataType *data;
	int front;
	int rear;
	int capacity;

public:
	CirQueue();
	CirQueue(int sz);
	~CirQueue();
	bool enQueue(myDataType elem);
	bool deQueue(myDataType *elem);
	bool getFront(myDataType *elem);
	bool isEmpty();
	bool isFull();
	void clearQueue();
	int QueueLength();
};
#endif