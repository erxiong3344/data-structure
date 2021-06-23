#include<iostream>
using namespace std;
#include "HuffTree.h"
int main()
{
	
	int n = 0;
	int temp = 0;
	char *HuffCode[MAX_LENGTH] = {NULL};
	HTNode* HuffTree=NULL;
	cout << "请输入结点个数" << endl;
	cin >> n;
	cout << "请输入" << n << "个权值" << endl;
	int *w = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		w[i] = temp;
	}
	HuffTree = createHuffTree(w, n);
	cout << "打印创建好的哈夫曼树数组内容" << endl;
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
	createHuffCode(HuffTree,HuffCode,n);
	cout << "输出Huffman编码" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << HuffCode[i] << endl;
		delete[] HuffCode[i];
	}
	destroyHuffTree(HuffTree);
	delete[] w;
	return 0;
}