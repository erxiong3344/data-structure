//�Թ����⣺�ҵ��Թ��ĳ���,����˼·:
//����ѡ�񣬰����������ϵ�˳��������̽
//ÿ��һ��ѹ��ջ�У����ϱ�ǣ���ǰ��Ԫ�����һ����Ԫ����Է���ʱ����ô����
//�����ϰ���,����,����ջ��Ԫ�أ�ÿ�λ���һ��
//�ҵ���·�����浽ջ��
#include<iostream>
using namespace std;
#include "maze.h"
int main()
{
	Direction direct[4];//��������,4��Ԫ��
	int maze[M+2][N+2];//�Թ�����
	LinkStack s;//ջ,��¼�߹��Ĺ켣����¼�߹��ĵ�Ԫ����кţ��кţ���һ������
	initDirect(direct);//��ʼ����������
	initMaze(maze);//��ʼ���Թ�����
	//��ʼ������Թ�����
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
		cout << "�ҵ����Թ�����" << endl;
		for (int i = 0; i < M + 2; i++)
		{
			for (int j = 0; j < N + 2; j++)
			{
				printf("%3d", maze[i][j]);
			}
			printf("\n");
		}
		printf("�ҵ���·��Ϊ\n");
		s.reverse_travel(s.getHead());
	}
	else
	{
		cout << "�޷��ҵ��Թ��ĳ���" << endl;
	}
	return 0;
}
