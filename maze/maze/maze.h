#ifndef LINKSTACK_H__
#define LINKSTACK_H__
typedef struct Box//��Ԫ����к�,�к�,��һ���ķ���
{
	int x;
	int y;
	int di;
}Box;
#define datatype Box
#define M 8 //�Թ�����Ĵ�С
#define N 8
#define MAXSIZE 10//�ϰ���ĸ���ΪMAXSIZE-2��MAXSIZE��
#define startx 1//�������
#define starty  1
#define endx M  //�յ�����
#define endy N
typedef struct Direction//��������,�ɸ��ݵ�ǰ��Ԫ���뷽�����������һ����Ԫ��
{
	int incX;
	int incY;
}Direction;
typedef struct Node
{
	datatype data;
	struct Node *next;
}Node;
//ʹ����ͷ�ڵ㵥��ѭ��������ģ����ջ
class LinkStack
{
private:
	Node *top;
public:
	LinkStack();
	~LinkStack();
	datatype Pop();
	datatype getTop();
	void Push(datatype elem);
	Node* getHead();//�õ�ͷָ��
	void travel();//�������
	void reverse_travel(Node *ps);//�������
	bool isEmpty();
	class Empty{};
};
void initDirect(Direction direct[]);
void initMaze(int maze[M+2][N+2]);
bool findPath(int maze[M + 2][N + 2], Direction direc[], LinkStack &s);
#endif