#include<iostream>
using namespace std;
#include "Bitree.h"
int main()
{
	BiTree btree;
	cout << "采用前序遍历的方式创建一棵二叉树" << endl;
	cout << "前序遍历" << endl;
	btree.PreOrder();
	cout << "中序遍历" << endl;
	btree.InOrder();
	cout << "后序遍历" << endl;
	btree.PostOrder();
	cout << "层序遍历" << endl;
	btree.LevelOrder();
	return 0;
}