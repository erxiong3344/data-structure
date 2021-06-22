#include "HuffTree.h"
#include<iostream>
using namespace std;

HTNode* createHuffTree(int w[], int n)
{
	int i = 0;
	int k = 0;
	int i1 = 0;//i1��ӦȨֵ��С�Ľ��
	int i2 = 0;//i2��ӦȨֵ��С�Ľ��
	HTNode *HuffTree = new HTNode[2 * n - 1];
	//1.��ʼ��HuffTree,lchild��rchild��parent��ֵΪ-1
	for (i = 0; i < 2 * n - 1; i++)
	{
		HuffTree[i].parent = -1;
		HuffTree[i].lchild = -1;
		HuffTree[i].rchild = -1;
	}
	//2.HuffTree��ǰn����㸳Ȩֵ
	for (i = 0; i < n; i++)
	{
		HuffTree[i].weight = w[i];
	}
	//3.����һ��HuffTree,ѡ��ϲ���ɾ������
	for (k = n; k < 2 * n - 1; k++)
	{
		//��parent==-1�Ľ������ѡ��Ȩֵ��С��������㣬��Сi1,��Сi2
		select(HuffTree, k, i1, i2);
		cout << "��С�±�:" << i1 <<" ";
		cout << "��С�±�:" << i2 << endl;
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


void destroyHuffTree(HTNode *HuffTree)
{
	delete[] HuffTree;
}