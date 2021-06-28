#ifndef ALGRAPH_H__
#define ALGRAPH_H__
#define DataType char
#define MAX_VERTEX 10
//�߱�
typedef struct ArcNode
{
	int vexNum;
	struct ArcNode *next;
}ArcNode;
//�����
struct VertexNode
{
	DataType vertex;//���涥����Ϣ
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