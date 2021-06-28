#ifndef MGRAPH_H__
#define MGRAPH_H__
#define MAX_VERTEX 10
#define DataType char
class MGraph
{
private:
	DataType vertex[MAX_VERTEX];//һά���鱣�涥����Ϣ
	int arc[MAX_VERTEX][MAX_VERTEX];//�ڽӾ��󱣴涥�����ڽӹ�ϵ
	int vertexNum;
	int arcNum;
	int visited[MAX_VERTEX];//���ʱ�־����
public:
	MGraph(DataType v[], int n, int e);
	void printMGraph();
	void DFSGraph(int v);
	void BFSGraph(int v);
	void ClearVisited();

};

#endif