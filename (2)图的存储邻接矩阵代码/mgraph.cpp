#include<iostream>
using namespace std;
#include "mgraph.h"
MGraph::MGraph(DataType v[],int n,int e)
{
	arcNum = e;
	vertexNum = n;
	int i1 = 0,i2 = 0;
	//初始化一维数组
	for (int i = 0; i < n; i++)
	{
		vertex[i] = v[i];
	}
	//初始化邻接矩阵
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arc[i][j] = 0;
		}
	}
	cout << "先输入行编号再输入列编号" << endl;
	//依次输入每一条边
	for (int i = 0; i < e; i++)
	{
		//输入每一条边所依附的两个顶点的编号
		cin >> i1 >> i2;
		arc[i1][i2] = 1;//有边标志
		arc[i2][i1] = 1;
	}
}

void MGraph::printGraph()
{
	cout << "打印出图" << endl;
	//依次输入每一条边
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << arc[i][j]<<'\t' ;
		}
			cout << endl;
	}
}