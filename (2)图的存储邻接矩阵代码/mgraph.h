#ifndef MGRAPH_H__
#define DataType char
const int MAX_VERTEX = 10;
class MGraph
{
private:
	DataType vertex[MAX_VERTEX];//һά���鱣�涥����Ϣ
	int arc[MAX_VERTEX][MAX_VERTEX];//�ڽӾ��󱣴涥�����ڽӹ�ϵ
	int vertexNum;
	int arcNum;
public:
	MGraph(DataType v[], int n, int e);
	void printGraph();
};
#endif // !MGRAPH_H__
