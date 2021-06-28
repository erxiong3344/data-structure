#include<iostream>
using namespace std;
#include "ALGraph.h"
#include "Queue.h"

ALGraph::ALGraph(DataType v[],int n,int e)
{
	vertexNum = n;
	arcNum = e;
	int vi, vj;
	ArcNode *s = NULL;
	//初始化顶点数组
	for (int i = 0; i < vertexNum; i++)
	{
		adjList[i].vertex = v[i];
		adjList[i].firstEdge = NULL;
		visited[i] = 0;
	}
	//依次输入每一条边
	cout << "依次输入每一条弧的起点与终点" << endl;
	for (int i = 0; i < arcNum; i++)
	{
		cin >> vi >> vj;
		s = new ArcNode;
		s->vexNum = vj;
		s->next = adjList[vi].firstEdge;
		adjList[vi].firstEdge = s;

	}

}
ALGraph::~ALGraph()
{
	ArcNode *p,*q;
	for (int i = 0; i < vertexNum; i++)
	{
		p = adjList[i].firstEdge;
		while (p)
		{
			q = p->next;
			
			delete p;
			p = q;
		}		
	}
	arcNum = 0;
	vertexNum = 0;
}
void ALGraph::printALGraph()
{
	cout << "打印邻接表" << endl;
	ArcNode *p;
	for (int i = 0; i < vertexNum; i++)
	{
		cout << i << ":";
		cout << adjList[i].vertex <<"->";
		p = adjList[i].firstEdge;
		while (p)
		{
			
			cout << p->vexNum << "->";
			p = p->next;
		}
		cout << endl;
	}
}
void ALGraph::DFSTraverse(int v)
{
	cout << adjList[v].vertex << endl;
	visited[v] = 1;
	ArcNode *p = adjList[v].firstEdge;
	while (p)
	{
		if (visited[p->vexNum] == 0)//顶点未被访问
		{
			DFSTraverse(p->vexNum);
		}
		p = p->next;
	}
}


void ALGraph::BFSTraverse(int v)
{
	CirQueue q;
	ArcNode *p;
	cout << adjList[v].vertex << endl;
	visited[v] = 1;
	q.enQueue(adjList[v].firstEdge);
	while (!q.isEmpty())
	{
		q.deQueue(&p);
		while (p)
		{
			if (visited[p->vexNum] == 0)
			{
				cout << adjList[p->vexNum].vertex << endl;
				visited[p->vexNum] = 1;
				q.enQueue(adjList[p->vexNum].firstEdge);
			}
			
			
			p = p->next;
		}
		
	}
}

void ALGraph::ClearVisited()
{
	for (int i = 0; i < vertexNum; i++)
	{
		visited[i] = 0;
	}
}