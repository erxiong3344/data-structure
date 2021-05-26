#ifndef LINKSTACK_H__
#define LINKSTACK_H__
typedef struct Box//单元格的行号,列号,下一步的方向
{
	int x;
	int y;
	int di;
}Box;
#define datatype Box
#define M 8 //迷宫数组的大小
#define N 8
#define MAXSIZE 10//障碍物的个数为MAXSIZE-2到MAXSIZE个
#define startx 1//起点坐标
#define starty  1
#define endx M  //终点坐标
#define endy N
typedef struct Direction//方向数组,可根据当前单元格与方向数组计算下一个单元格
{
	int incX;
	int incY;
}Direction;
typedef struct Node
{
	datatype data;
	struct Node *next;
}Node;
//使用无头节点单向不循环链表来模拟链栈
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
	Node* getHead();//得到头指针
	void travel();//正序遍历
	void reverse_travel(Node *ps);//逆序遍历
	bool isEmpty();
	class Empty{};
};
void initDirect(Direction direct[]);
void initMaze(int maze[M+2][N+2]);
bool findPath(int maze[M + 2][N + 2], Direction direc[], LinkStack &s);
#endif