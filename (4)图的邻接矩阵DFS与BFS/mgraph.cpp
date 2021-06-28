#include<iostream>
using namespace std;
#include "mgraph.h"
#include "Queue.h"

MGraph::MGraph(DataType v[],int n,int e)
{
	vertexNum = n;
	arcNum = e;
	int vi, vj;
	//��ʼ����������
	for (int i = 0; i < vertexNum; i++)
	{
		vertex[i] = v[i];
		visited[i] = 0;
	}
	//��ʼ���ڽӾ���
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}
	cout << "��������������Ķ���ı��" << endl;
	//��������ÿһ����
	for (int i = 0; i < arcNum; i++)
	{
		//����ÿһ��������������������ı��
		cin >> vi >> vj;
		arc[vi][vj] = 1;//�߱�־λ��Ϊ1
		arc[vj][vi] = 1;
	}
}

void MGraph::printMGraph()
{
	cout << "��ӡ�ڽӾ���" << endl;
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
	cout << vertex[v] << endl;//���ʶ����е�����
	visited[v] = 1;//���ʱ�־λ��Ϊ1
	for (int i = 0; i < vertexNum; i++)//����ͼ�����п��ܵ��ڽӵ�
	{
		if (arc[v][i] == 1 && visited[i] == 0)//�б���δ�����ʣ���ݹ���ú���
		{
			DFSGraph(i);
		}
	}
}

void MGraph::BFSGraph(int v)
{
	int k;
	int w;
	CirQueue q;//��ʼ������
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