#include<iostream>
using namespace std;
#include<time.h>
#include<stdlib.h>
#include "maze.h"


LinkStack::LinkStack()
{
	top = NULL;
}


LinkStack::~LinkStack()
{
	Node *p, *q;
	for (p = top; p != NULL; p = q)
	{
		q = p->next;
		delete p;
	}
	top = NULL;
}


datatype LinkStack::Pop()
{
	if (isEmpty())
	{
		throw Empty();
	}
	else
	{
		Node *p = top;
		datatype x = top->data;
		top = top->next;
		delete p;
		return x;
	}
}


bool LinkStack::isEmpty()
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


datatype LinkStack::getTop()
{
	if (isEmpty())
	{
		throw Empty();
	}
	else
	{
		return top->data;
	}
}


void LinkStack::Push(datatype elem)
{
	Node* p=new Node;
	p->data = elem;
	p->next = top;
	top = p;
}


void LinkStack::travel()
{
	Node *p;
	for (p = top; p != NULL; p = p->next)
	{
		cout << p->data.x << "\t";
		cout << p->data.y << "\t";
		cout << p->data.di << endl;
	}
}


Node* LinkStack::getHead()
{
	return top;
}


void LinkStack::reverse_travel(Node *ps)
{
	if (ps->next)
	{
		reverse_travel(ps->next);
	}
	printf("(%d , %d)\n", (ps->data).x, (ps->data).y);

}


//��ʼ����������
void initDirect(Direction direct[])
{
	//�����������ϵ�˳��Ѱ�ҳ���
	direct[0].incX = 0;
	direct[0].incY = 1;
	direct[1].incX = 1;
	direct[1].incY = 0;
	direct[2].incX = 0;
	direct[2].incY = -1;
	direct[3].incX = -1;
	direct[3].incY = 0;
}

//��ʼ���Թ�����
void initMaze(int maze[M+2][N+2])
{
	int row = 0;
	int col = 0;
	srand((unsigned)time(NULL));
	//�м���0
	for (int i = 1; i < M + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			maze[i][j] = 0;
		}
	}
	//������һȦΪ1
	for (int i = 0; i <= M + 1; i++)
	{
		maze[i][0] = 1;
		maze[i][N + 1] = 1;
	}
	for (int j = 1; j < N + 1; j++)
	{
		maze[0][j] = 1;
		maze[M+1][j] = 1;
	}
	//�������MAXSIZE-2��MAXSIZE���ϰ���
	for (int i = 0;i < MAXSIZE;)
	{
	
			row = rand() % M + 1;
			col = rand() % N + 1;
			if (maze[row][col] == 0)
			{
				maze[row][col] = 1;
				i++;
			}
	
	}
	maze[startx][starty] = 0;
	maze[endx][endy] = 0;
}

//maze������0��ʾ�յأ�1��ʾ�ϰ��-1��ʾ���ʹ��ĸ���
//ջ�б���һ�����ߵ��Թ�ͨ·
bool findPath(int maze[M + 2][N + 2], Direction direct[], LinkStack &s)
{
	//��ʼ��,�������Ԫ��ѹ��ջ��
	Box temp = { startx, starty, -1 };
	maze[startx][starty] = -1;
	int x, y, di;//��ʾ��ǰ��Ԫ������꼰������Ϣ
	int line, col;//��ʾ��һ��Ҫ����ĵ�Ԫ���к����к�
	s.Push(temp);
	while (!s.isEmpty())//ջ����Ϊ��
	{
		temp = s.Pop();//����ջ��Ԫ�أ�����
		x = temp.x;
		y = temp.y;
		di = temp.di + 1;
		while (di < 4)//4��������̽һ��
		{
			line = x + direct[di].incX;
			col = y + direct[di].incY;
			if (maze[line][col] == 0)//��һ����Ԫ�����
			{
				temp.x = x;
				temp.y = y;
				temp.di = di;
				s.Push(temp);//����Ԫ��ѹ��ջ��
				x = line;//ˢ�±���Ԫ�������
				y = col;
				maze[x][y] = -1;//��ֹ�ظ�����
				if ((x == endx) && (y == endy))//�ҵ�����
				{
					di = 0;
					s.Push({ x,y,di });
					return true;
				}
				else
				{
					di = 0;
				}

			}
			else//������
			{
				di++;
			}
		}
	}
	return false;
}