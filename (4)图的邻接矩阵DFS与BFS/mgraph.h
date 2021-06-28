#ifndef MGRAPH_H__
#define MGRAPH_H__
#define MAX_VERTEX 10
#define DataType char
class MGraph
{
private:
	DataType vertex[MAX_VERTEX];//一维数组保存顶点信息
	int arc[MAX_VERTEX][MAX_VERTEX];//邻接矩阵保存顶点间的邻接关系
	int vertexNum;
	int arcNum;
	int visited[MAX_VERTEX];//访问标志数组
public:
	MGraph(DataType v[], int n, int e);
	void printMGraph();
	void DFSGraph(int v);
	void BFSGraph(int v);
	void ClearVisited();

};

#endif