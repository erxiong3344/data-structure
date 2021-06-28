#include<iostream>
using namespace std;
#include "mgraph.h"
#include "Queue.h"
int main()
{
	int n = 0;
	int e = 0;
	DataType v[MAX_VERTEX];
	cout << "请输入顶点的个数" << endl;
	cin >> n;
	cout << "请输入边的数量" << endl;
	cin >> e;
	cout << "请输入顶点数组中的顶点" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	MGraph g(v, n, e);
	g.printMGraph();
	cout << "深度优先遍历" << endl;
	g.ClearVisited();
	g.DFSGraph(0);
	cout << "广度优先遍历" << endl;
	g.ClearVisited();
	g.BFSGraph(0);
	
	return 0;
}