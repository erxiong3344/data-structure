#include<iostream>
using namespace std;
#include"ALGraph.h"
int main()
{
	int n = 0;
	int e = 0;
	DataType v[MAX_VERTEX];
	cout << "���������붥�������ߵĸ���" << endl;
	cin >> n >> e;
	cout << "���������붥�������и�����" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	ALGraph g(v, n, e);
	g.printALGraph();
	cout << "������ȱ���" << endl;
	g.ClearVisited();
	g.DFSTraverse(0);
	cout << "������ȱ���" << endl;
	g.ClearVisited();
	g.BFSTraverse(0);
	return 0;
}