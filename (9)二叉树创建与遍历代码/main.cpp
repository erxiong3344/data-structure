#include<iostream>
using namespace std;
#include "Bitree.h"
int main()
{
	BiTree btree;
	cout << "����ǰ������ķ�ʽ����һ�ö�����" << endl;
	cout << "ǰ�����" << endl;
	btree.PreOrder();
	cout << "�������" << endl;
	btree.InOrder();
	cout << "�������" << endl;
	btree.PostOrder();
	cout << "�������" << endl;
	btree.LevelOrder();
	return 0;
}