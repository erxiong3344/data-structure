#ifndef HUFFTREE_H__
#define MAX_LENGTH 100
typedef struct HTNode
{
	int weight;
	int lchild, rchild, parent;
}HTNode;
HTNode* createHuffTree(int w[], int n);
void select(HTNode *HuffTree, int k, int &i1,int  &i2);
void destroyHuffTree(HTNode *HuffTree);
void createHuffCode(HTNode *HuffTree, char *HuffCode[], int n);
#endif // !HUFFTREE_H__
