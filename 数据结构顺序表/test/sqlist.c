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
		printf("数组为空\n");
		return ;
	}
	int i = 0;
	printf("数组中元素个数为%d\n", ps->size);
	printf("数组中的元素依次为:\n");
	for (i = 0; i < ps->size; i++)
	{
		printf("%d : %d\n", i + 1, ps->data[i]);
	}
}
int  add_sqlist(sqlist *ps,datatype *num)
{
	ps->data[ps->size] = *num;
	ps->size++;
	//printf("元素添加成功\n");
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
	/*printf("元素插入成功\n");*/
	return 0;


}

int  delete_sqlist(sqlist *ps, int pos)
{
	int i = 0;
	pos = pos - 1;
	if (ps->size == 0)
	{
		printf("删除失败, 顺序表为空\n");
		return -1;
	}
	if (pos<0 || pos>=ps->size)
	{
		printf("删除失败,pos处没有元素\n");
		return -2;
	}
	for (i = pos; i < ps->size-1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
	printf("pos处的元素删除成功\n");
	return 0;
}


//给出下标找元素
int find_sqlsit(sqlist *ps,int pos)
{

	if (ps->size == 0)
	{
		printf("查找失败, 顺序表为空\n");
		return -1;
	}
	if (pos <= 0 || pos > ps->size)
	{
		printf("查找失败,pos处没有元素\n");
		return -2;
	}
	printf("顺序表中第%d个元素为%d",pos, ps->data[pos -1]);
	printf("查找成功\n");
	return 0;
}

//给出元素查下标
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

int union_sqlist(sqlist* list1, sqlist* list2)//顺序表的合并
{
	int i = 0;
	//list1后面追加list2中与list1中不同的元素
	//list1 12 34 56 78 90
	//list2 23 90 45 67 78 
	//合并后的结果list1 12 34 56 78 90 23 45 67 
	//思路：先查找在插入
	//查找：list1中是否有list2中第i个元素，若有则不插入，若无则插入
	if (list2 == NULL&&list1 !=NULL) 
	{
		printf("list1与list2合并成功\n");
		return 0;
	}
	if (list1 == NULL)
	{
		printf("list1与list2合并失败\n");
		return -1;
	}
	for (i = 0; i < list2->size; i++)
	{
		if ((find1_sqlist(list1, &list2->data[i])) <= 0)
		{
			insert_sqlist(list1, list1->size, &list2->data[i]);
		}
	}
	printf("list1与list2合并成功\n");
	return 0;
}

void destroy_sqlist(sqlist *ps)
{
	free(ps);
	ps = NULL;

}