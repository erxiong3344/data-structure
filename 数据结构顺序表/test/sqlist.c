#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include "sqlist.h"
sqlist* create_sqlist(void)
{
	sqlist *ps;
	ps=(sqlist*)malloc(sizeof(sqlist));
	if (ps == NULL)
	{
		return NULL;
	}
	else
	{
		ps->size = 0;
		return ps;
	}
}


void create_sqlist1(sqlist *ps)
{
	
	ps = malloc(sizeof(sqlist));
	if (ps == NULL)
	{
		return;
	}
	else
	{
		ps->size = 0;
		return;
	}
}


void display_sqlist(sqlist *ps)
{
	if (ps->size == 0)
	{
		printf("����Ϊ��\n");
		return ;
	}
	int i = 0;
	printf("������Ԫ�ظ���Ϊ%d\n", ps->size);
	printf("�����е�Ԫ������Ϊ:\n");
	for (i = 0; i < ps->size; i++)
	{
		printf("%d : %d\n", i + 1, ps->data[i]);
	}
}
int  add_sqlist(sqlist *ps,datatype *num)
{
	ps->data[ps->size] = *num;
	ps->size++;
	//printf("Ԫ����ӳɹ�\n");
	return 0;

}


int insert_sqlist(sqlist *ps, int pos, datatype *num)
{
	int j = 0;
	if (ps->size == MAX_LENGTH)
	{
		return -1;
	}
	if (pos < 0 || pos > ps->size)
	{
		return -2;
	}
	
	for (j = ps->size;j > pos;j--)

	{
		ps->data[j] = ps->data[j-1];
	}
	ps->data[pos] = *num;
	ps->size++;
	/*printf("Ԫ�ز���ɹ�\n");*/
	return 0;


}

int  delete_sqlist(sqlist *ps, int pos)
{
	int i = 0;
	pos = pos - 1;
	if (ps->size == 0)
	{
		printf("ɾ��ʧ��, ˳���Ϊ��\n");
		return -1;
	}
	if (pos<0 || pos>=ps->size)
	{
		printf("ɾ��ʧ��,pos��û��Ԫ��\n");
		return -2;
	}
	for (i = pos; i < ps->size-1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
	printf("pos����Ԫ��ɾ���ɹ�\n");
	return 0;
}


//�����±���Ԫ��
int find_sqlsit(sqlist *ps,int pos)
{

	if (ps->size == 0)
	{
		printf("����ʧ��, ˳���Ϊ��\n");
		return -1;
	}
	if (pos <= 0 || pos > ps->size)
	{
		printf("����ʧ��,pos��û��Ԫ��\n");
		return -2;
	}
	printf("˳����е�%d��Ԫ��Ϊ%d",pos, ps->data[pos -1]);
	printf("���ҳɹ�\n");
	return 0;
}

//����Ԫ�ز��±�
int find1_sqlist(sqlist *ps, datatype* value)
{
	
	int i = 0;
	
	if (ps->size == 0)
	{
		
		return -1;
	}
	for (i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == *value)
		{
			return i + 1;
		}
	}
	return 0;
}

int setempty_sqlist(sqlist* ps)
{
	ps->size = 0;
	return 0;
}

int union_sqlist(sqlist* list1, sqlist* list2)//˳���ĺϲ�
{
	int i = 0;
	//list1����׷��list2����list1�в�ͬ��Ԫ��
	//list1 12 34 56 78 90
	//list2 23 90 45 67 78 
	//�ϲ���Ľ��list1 12 34 56 78 90 23 45 67 
	//˼·���Ȳ����ڲ���
	//���ң�list1���Ƿ���list2�е�i��Ԫ�أ������򲻲��룬���������
	if (list2 == NULL&&list1 !=NULL) 
	{
		printf("list1��list2�ϲ��ɹ�\n");
		return 0;
	}
	if (list1 == NULL)
	{
		printf("list1��list2�ϲ�ʧ��\n");
		return -1;
	}
	for (i = 0; i < list2->size; i++)
	{
		if ((find1_sqlist(list1, &list2->data[i])) <= 0)
		{
			insert_sqlist(list1, list1->size, &list2->data[i]);
		}
	}
	printf("list1��list2�ϲ��ɹ�\n");
	return 0;
}

void destroy_sqlist(sqlist *ps)
{
	free(ps);
	ps = NULL;

}