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


//初始化方向数组
void initDirect(Direction direct[])
{
	//按照右下左上的顺序寻找出口
	direct[0].incX = 0;
	direct[0].incY = 1;
	direct[1].incX = 1;
	direct[1].incY = 0;
	direct[2].incX = 0;
	direct[2].incY = -1;
	direct[3].incX = -1;
	direct[3].incY = 0;
}

//初始化迷宫数组
void initMaze(int maze[M+2][N+2])
{
	int row = 0;
	int col = 0;
	srand((unsigned)time(NULL));
	//中间填0
	for (int i = 1; i < M + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			maze[i][j] = 0;
		}
	}
	//最外面一圈为1
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
	//随机生成MAXSIZE-2至MAXSIZE个障碍物
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

//maze矩阵中0表示空地，1表示障碍物，-1表示访问过的格子
//栈中保存一条可走的迷宫通路
bool findPath(int maze[M + 2][N + 2], Direction direct[], LinkStack &s)
{
	//初始化,将起点三元组压入栈中
	Box temp = { startx, starty, -1 };
	maze[startx][starty] = -1;
	int x, y, di;//表示当前单元格的坐标及方向信息
	int line, col;//表示下一个要处理的单元格行号与列号
	s.Push(temp);
	while (!s.isEmpty())//栈不能为空
	{
		temp = s.Pop();//弹出栈顶元素，回退
		x = temp.x;
		y = temp.y;
		di = temp.di + 1;
		while (di < 4)//4个方向试探一遍
		{
			line = x + direct[di].incX;
			col = y + direct[di].incY;
			if (maze[line][col] == 0)//下一个单元格可走
			{
				temp.x = x;
				temp.y = y;
				temp.di = di;
				s.Push(temp);//本单元格压入栈中
				x = line;//刷新本单元格的坐标
				y = col;
				maze[x][y] = -1;//防止重复访问
				if ((x == endx) && (y == endy))//找到出口
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
			else//换方向
			{
				di++;
			}
		}
	}
	return false;
}