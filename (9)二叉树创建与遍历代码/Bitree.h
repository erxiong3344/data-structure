#ifndef BITREE_H__
#define BITREE_H__
#define datatype1 char
#define datatype2 BiNode*
const int QUEUESIZE = 30;
typedef struct BiNode 
{
	datatype1  data;
	struct BiNode *lchild, *rchild;
}BiNode;
class CirQueue
{
private:
	int front;
	int rear;
	datatype2  *data;
	int length;
public:
	CirQueue();
	CirQueue(int sz);
	~CirQueue();
	bool enQueue(datatype2 elem);
	bool deQueue(datatype2  *elem);
	bool getFront(datatype2  *elem);
	bool isEmpty();
	bool isFull();
	void clearQueue();
	int queueLength();
};
//C++°æ±¾
class BiTree
{
private:
	BiNode *root;
private:
	void createBitree(BiNode *&bt);
	void destroyBitree(BiNode *bt);
	void PreOrder(BiNode *bt);
	void InOrder(BiNode *bt);
	void PostOrder(BiNode *bt);
public:
	 BiTree()
	{
		createBitree(root);
	}
    ~BiTree()
	{
		destroyBitree(root);
	}
	void PreOrder()
	{
		PreOrder(root);
	}
	void InOrder()
	{
		InOrder(root);
	}
	void PostOrder()
	{
		PostOrder(root);
	}
	void LevelOrder();
};
//C°æ±¾
//BiNode* createBitree(BiNode *bt);
//void destroyBitree(BiNode *bt);
//void PreOrder(BiNode *bt);
//void InOrder(BiNode *bt);
//void PostOrder(BiNode *bt);
//void LevelOrder(BiNode *root);
#endif // !BITREE_H__
