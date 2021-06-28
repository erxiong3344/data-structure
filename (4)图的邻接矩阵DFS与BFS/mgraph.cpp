#include<iostream>
using namespace std;
#include "mgraph.h"
#include "Queue.h"

MGraph::MGraph(DataType v[],int n,int e)
{
	vertexNum = n;
	arcNum = e;
	int vi, vj;
	//初始化顶点数组
	for (int i = 0; i < vertexNum; i++)
	{
		vertex[i] = v[i];
		visited[i] = 0;
	}
	//初始化邻接矩阵
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}
	cout << "请输入边所依附的顶点的编号" << endl;
	//依次输入每一条边
	for (int i = 0; i < arcNum; i++)
	{
		//输入每一条边所依附的两个顶点的编号
		cin >> vi >> vj;
		arc[vi][vj] = 1;//边标志位置为1
		arc[vj][vi] = 1;
	}
}

void MGraph::printMGraph()
{
	cout << "打印邻接矩阵" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << arc[i][j] << '\t';
		}
		cout << endl;
	}
}

void MGraph::DFSGraph(int v)
{
	cout << vertex[v] << endl;//访问顶点中的数据
	visited[v] = 1;//访问标志位置为1
	for (int i = 0; i < vertexNum; i++)//遍历图中所有可能的邻接点
	{
		if (arc[v][i] == 1 && visited[i] == 0)//有边且未被访问，则递归调用函数
		{
			DFSGraph(i);
		}
	}
}

void MGraph::BFSGraph(int v)
{
	int k;
	int w;
	CirQueue q;//初始化队列
	cout << vertex[v] << endl;
	visited[v] = 1;
	q.enQueue(v);
	while (!q.isEmpty())
	{
		q.deQueue(&k);
		
		for ( w = 0; w < vertexNum; w++)
		{
			
			if ((arc[k][w] == 1 )&& (visited[w] == 0))
			{
				
				cout << vertex[w] << endl;
				visited[w] = 1;
				q.enQueue(w);
			}
		}
	}

}

void MGraph::ClearVisited()
{
	for (int i = 0; i < vertexNum; i++)
	{
		visited[i] = 0;
	}
}