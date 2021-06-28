#ifndef ALGRAPH_H__
#define ALGRAPH_H__
#define DataType char
#define MAX_VERTEX 10
//边表
typedef struct ArcNode
{
	int vexNum;
	struct ArcNode *next;
}ArcNode;
//顶点表
struct VertexNode
{
	DataType vertex;//保存顶点信息
	ArcNode *firstEdge;
 };
class ALGraph
{
private:
	VertexNode adjList[MAX_VERTEX];
	int arcNum;
	int vertexNum;
	int visited[MAX_VERTEX];
public:
	ALGraph(DataType v[], int n, int e);
	~ALGraph();
	void printALGraph();
	void DFSTraverse(int v);
	void BFSTraverse(int v);
	void ClearVisited();
};
#endif