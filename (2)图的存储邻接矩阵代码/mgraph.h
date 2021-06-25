#ifndef MGRAPH_H__
#define DataType char
const int MAX_VERTEX = 10;
class MGraph
{
private:
	DataType vertex[MAX_VERTEX];//一维数组保存顶点信息
	int arc[MAX_VERTEX][MAX_VERTEX];//邻接矩阵保存顶点间的邻接关系
	int vertexNum;
	int arcNum;
public:
	MGraph(DataType v[], int n, int e);
	void printGraph();
};
#endif // !MGRAPH_H__
