#include<iostream>
using namespace std;
#include "mgraph.h"
MGraph::MGraph(DataType v[],int n,int e)
{
	arcNum = e;
	vertexNum = n;
	int i1 = 0,i2 = 0;
	//��ʼ��һά����
	for (int i = 0; i < n; i++)
	{
		vertex[i] = v[i];
	}
	//��ʼ���ڽӾ���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arc[i][j] = 0;
		}
	}
	cout << "�������б���������б��" << endl;
	//��������ÿһ����
	for (int i = 0; i < e; i++)
	{
		//����ÿһ��������������������ı��
		cin >> i1 >> i2;
		arc[i1][i2] = 1;//�б߱�־
		arc[i2][i1] = 1;
	}
}

void MGraph::printGraph()
{
	cout << "��ӡ��ͼ" << endl;
	//��������ÿһ����
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << arc[i][j]<<'\t' ;
		}
			cout << endl;
	}
}