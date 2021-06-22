#include<iostream>
using namespace std;
#include "Bitree.h"
CirQueue::CirQueue()
{
	data = new datatype2[QUEUESIZE];
	length = QUEUESIZE;
	front = 0;
	rear = 0;
}
CirQueue::CirQueue(int sz)
{
	data = new datatype2[sz];
	length = sz;
	front = 0;
	rear = 0;
}
CirQueue::~CirQueue()
{
	
	delete[] data;
}
bool CirQueue::enQueue(datatype2  elem)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		rear = (rear + 1) % length;
		data[rear] = elem;
		return true;
	}
}
bool CirQueue::deQueue(datatype2  *elem)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		front = (front + 1) % length;
		*elem = data[front];
		return true;
	}
}
bool CirQueue::getFront(datatype2  *elem)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		int i = front;
		i = (i + 1) %length;
		*elem = data[i];
		return true;
	}
}
bool CirQueue::isEmpty()
{
	if (rear == front)
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
	if (front == (rear+1)%length)
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
	front = rear;
}
int CirQueue::queueLength()
{
	if (front <= rear)
	{
		return rear - front;
	}
	else
	{
		return rear + length - front;
	}
}
void BiTree::PreOrder(BiNode *bt)
{
	if (bt == NULL)
		return;
	else
	{
		cout << bt->data << endl;
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void BiTree::InOrder(BiNode *bt)
{
	if (bt == NULL)
		return;
	else
	{		
		InOrder(bt->lchild);
		cout << bt->data << endl;
		InOrder(bt->rchild);
	}
}



void BiTree::PostOrder(BiNode *bt)
{
	if (bt == NULL)
		return;
	else
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data << endl;
	}
}


void BiTree::LevelOrder()
{
	CirQueue queue;
	BiNode* bt=NULL;
	if (root == NULL)
		return;
	queue.enQueue(root);
	while (!queue.isEmpty())
	{
		queue.deQueue(&bt);
		cout << bt->data << endl;
		if (bt->lchild)
		{
			queue.enQueue(bt->lchild);
		}

		if (bt->rchild)
		{
			queue.enQueue(bt->rchild);
		}
	}
}


//BiNode* BiTree::createBitree(BiNode *bt)
//{
//	char ch;
//	cin >> ch;
//	if (ch == '#')
//	{
//		bt = NULL;
//	}
//	else
//	{
//		bt = new BiNode;
//		bt->data = ch;
//		bt->lchild = createBitree(bt->lchild);
//		bt->rchild = createBitree(bt->rchild);
//	}
//	return bt;
//}

void  BiTree::createBitree(BiNode *&bt)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		bt = NULL;
	}
	else
	{
		bt = new BiNode;
		bt->data = ch;
		createBitree(bt->lchild);
		createBitree(bt->rchild);
	}
	
}
void BiTree::destroyBitree(BiNode *bt)
{
	if (bt == NULL)
	{
		return;
	}
	else
	{
		destroyBitree(bt->lchild);
		destroyBitree(bt->rchild);
		delete bt;
		bt = NULL;
	}
	

}
