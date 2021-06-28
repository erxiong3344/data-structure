#include<iostream>
using namespace std;
#include"ALGraph.h"
int main()
{
	int n = 0;
	int e = 0;
	DataType v[MAX_VERTEX];
	cout << "请依次输入顶点个数与边的个数" << endl;
	cin >> n >> e;
	cout << "请依次输入顶点数组中各顶点" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	ALGraph g(v, n, e);
	g.printALGraph();
	cout << "深度优先遍历" << endl;
	g.ClearVisited();
	g.DFSTraverse(0);
	cout << "广度优先遍历" << endl;
	g.ClearVisited();
	g.BFSTraverse(0);
	return 0;
}