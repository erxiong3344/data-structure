//迷宫问题：找到迷宫的出口,解题思路:
//方向选择，按照右下左上的顺序依次试探
//每走一步压入栈中，打上标记（当前单元格的下一个单元格可以访问时才这么做）
//遇到障碍物,回溯,弹出栈顶元素，每次回溯一个
//找到的路径保存到栈中
#include<iostream>
using namespace std;
#include "maze.h"
int main()
{
	Direction direct[4];//方向数组,4个元素
	int maze[M+2][N+2];//迷宫数组
	LinkStack s;//栈,记录走过的轨迹，记录走过的单元格的行号，列号，下一步方向
	initDirect(direct);//初始化方向数组
	initMaze(maze);//初始化迷宫数组
	//初始化后的迷宫矩阵
	for (int i = 0; i < M + 2; i++)
	{
		for (int j = 0; j < N + 2; j++)
		{
			printf("%3d", maze[i][j]);
		}
		printf("\n");
	}
	bool flag = findPath(maze, direct, s);
	if (flag)
	{
		cout << "找到了迷宫出口" << endl;
		for (int i = 0; i < M + 2; i++)
		{
			for (int j = 0; j < N + 2; j++)
			{
				printf("%3d", maze[i][j]);
			}
			printf("\n");
		}
		printf("找到的路径为\n");
		s.reverse_travel(s.getHead());
	}
	else
	{
		cout << "无法找到迷宫的出口" << endl;
	}
	return 0;
}
