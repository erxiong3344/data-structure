#include<iostream>
using namespace std;
#include "mgraph.h"
#include "Queue.h"
int main()
{
	int n = 0;
	int e = 0;
	DataType v[MAX_VERTEX];
	cout << "�����붥��ĸ���" << endl;
	cin >> n;
	cout << "������ߵ�����" << endl;
	cin >> e;
	cout << "�����붥�������еĶ���" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	MGraph g(v, n, e);
	g.printMGraph();
	cout << "������ȱ���" << endl;
	g.ClearVisited();
	g.DFSGraph(0);
	cout << "������ȱ���" << endl;
	g.ClearVisited();
	g.BFSGraph(0);
	
	return 0;
}