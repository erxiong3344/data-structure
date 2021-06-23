#include "HuffTree.h"
#include<iostream>
using namespace std;

HTNode* createHuffTree(int w[], int n)
{
	int i = 0;
	int k = 0;
	int i1 = 0;//i1对应权值最小的结点
	int i2 = 0;//i2对应权值次小的结点
	HTNode *HuffTree = new HTNode[2 * n - 1];
	//1.初始化HuffTree,lchild、rchild、parent域赋值为-1
	for (i = 0; i < 2 * n - 1; i++)
	{
		HuffTree[i].parent = -1;
		HuffTree[i].lchild = -1;
		HuffTree[i].rchild = -1;
	}
	//2.HuffTree中前n个结点赋权值
	for (i = 0; i < n; i++)
	{
		HuffTree[i].weight = w[i];
	}
	//3.创建一棵HuffTree,选择合并，删除加入
	for (k = n; k < 2 * n - 1; k++)
	{
		//从parent==-1的结点中挑选出权值最小的两个结点，最小i1,次小i2
		select(HuffTree, k, i1, i2);
		cout << "最小下标:" << i1 <<" ";
		cout << "次小下标:" << i2 << endl;
		HuffTree[i1].parent = k;
		HuffTree[i2].parent = k;
		HuffTree[k].lchild = i1;
		HuffTree[k].rchild = i2;
		HuffTree[k].weight = HuffTree[i1].weight + HuffTree[i2].weight;

	}
	return HuffTree;
}


void select(HTNode *HuffTree, int k, int &i1, int  &i2)
{
	int m1, m2;
	int i = 0;
	int min1 = 9999, min2 = 9999;
	for (i = 0; i < k; i++)
	{
		if (HuffTree[i].parent == -1)
		{
			if (HuffTree[i].weight < min2)
			{
				if (HuffTree[i].weight < min1)
				{
					min2 = min1;
					min1 = HuffTree[i].weight;
					m1 = i;
				}
				else
				{
					min2 = HuffTree[i].weight;
					m2 = i;
				}
			}
		}
	}
	i2 = m2;
	i1 = m1;

}
void mystrcpy(char *dest, char*src)
{
	while (*dest++ = *src++)
	{
		;
	}
}

void createHuffCode(HTNode *HuffTree, char *HuffCode[], int n)
{
	char *temp = new char[n];//定义工作空间,临时存储叶子结点的HuffCode
	temp[n - 1] = '\0';
	int start,pos,parent;
	//遍历哈夫曼树生成哈夫曼编码,只需要前n个结点即可
	for (int i = 0; i < n; i++)
	{
		//从叶子结点到根结点逆向求每个字符的HuffCode
		start = n - 1;
		pos = i;//表示当前结点
		parent = HuffTree[pos].parent;//当前结点的双亲结点
		while (parent != -1)//哈夫曼编码停止条件,当前结点为根结点
		{
			if (HuffTree[parent].lchild == pos)//判断是左子树,还是右子树
			{
				temp[--start] = '0';
			}
			else
			{
				temp[--start] = '1';
			}
			pos = parent;
			parent = HuffTree[pos].parent;
		}
		HuffCode[i] = new char[n - start];//建立HuffCode实际需要的内存空间
		mystrcpy(HuffCode[i],&temp[start] );//将临时存储空间中的HuffCode拷贝到HuffCode[i]中
	}
	
	delete[] temp;
}



void destroyHuffTree(HTNode *HuffTree)
{
	delete[] HuffTree;
}