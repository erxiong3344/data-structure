#include<iostream>
using namespace std;
#include "HuffTree.h"
int main()
{
	
	int n = 0;
	int temp = 0;
	HTNode* HuffTree=NULL;
	cout << "�����������" << endl;
	cin >> n;
	cout << "������" << n << "��Ȩֵ" << endl;
	int *w = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		w[i] = temp;
	}
	HuffTree = createHuffTree(w, n);
	cout << "��ӡ�����õĹ���������������" << endl;
	cout << "weight" << "\t";
	cout << "parent" << "\t";
	cout << "lchild" << "\t";
	cout << "rchild" << endl;
	for (int i = 0; i < 2*n-1; i++)
	{
		cout << HuffTree[i].weight << "\t";
		cout<< HuffTree[i].parent<< "\t";
		cout<<HuffTree[i].lchild<< "\t";
		cout << HuffTree[i].rchild << endl;
	}
	destroyHuffTree(HuffTree);
	delete[] w;
	return 0;
}