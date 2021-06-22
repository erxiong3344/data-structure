#ifndef HUFFTREE_H__
typedef struct HTNode
{
	int weight;
	int lchild, rchild, parent;
}HTNode;
HTNode* createHuffTree(int w[], int n);
void select(HTNode *HuffTree, int k, int &i1,int  &i2);
void destroyHuffTree(HTNode *HuffTree);
#endif // !HUFFTREE_H__
