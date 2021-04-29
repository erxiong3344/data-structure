#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"
LNode* create_list()
{
	LNode* ps = NULL;
	ps=(LNode*)malloc(sizeof(LNode));
	if (ps == NULL)
	{
		return -1;
	}	
	else 
	{
		ps->next = NULL;
		return ps;
	}

}


//��λ�ò���ڵ�
int list_insert_at(LNode *ps, int i, datatype* data)
{
	//���������ͷ��㣬��һ����Ч�ڵ���±�Ϊ0
	int j = 0;
	LNode* node = ps;
	LNode* newnode = NULL;
	if (i < 0)
	{
		return -1;
	}
	//�ҵ���i-1����Ч�ڵ�
	while((j < i)&&(node !=NULL))
	{
		node = node->next;
		j++;
	}
	//��i-1����Ч�ڵ����,�����½ڵ�
	if (node)
	{
		newnode =(LNode*)malloc(sizeof(LNode));
		if (newnode == NULL)
		{
			return -2;
		}
		newnode->data = *data;
		newnode->next = node->next;
		node->next = newnode;
		return 0;
	}
	else 
	{
		return -3;
	}
	
}


//����С�����˳�����Ԫ��
int list_order_insert(LNode* ps,datatype *data)
{
	LNode* prenode = ps,*curnode=ps->next,*newnode;
	while ((curnode != NULL)&&(curnode->data < *data))
	{
		prenode = curnode;
		curnode = curnode->next;
	}
	//�����½ڵ�
	newnode = (LNode*)malloc(sizeof(LNode));
	if (newnode == NULL)
	{
		return -1;
	}
	newnode->data = *data;
	newnode->next=prenode->next;
	prenode->next = newnode;
	return 0;
}
int list_display(LNode* ps)
{
	int i = 0;
	if (list_isempty(ps))
	{
		return -1;
	}
	printf("�����е�Ԫ������Ϊ:\n");
	//�ҵ������е�һ����Ч�ڵ�
	ps = ps->next;
	while (ps)
	{
		printf("�±�:%d\t����:%d\n",i, ps->data);
		ps = ps->next;
		i++;
	}
	return 0;
}


int delete_list_at(LNode *ps, int i,datatype *data)
{
	LNode *p = ps,*q=NULL;
	int j = 0;
	
	if (i < 0)
	{
		return -1;
	}
	//�ҵ���i-1���ڵ�
	while((p!=NULL) &&(j < i))
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
	{
		return -2;
	}
	else
	{
		q = p->next;
		p->next = q->next;
		*data = q->data;
		free(q);
		q = NULL;
		return 0;
	}
}


int delete_list(LNode *ps, datatype *data)
{
	LNode *prenode = ps, *curnode = ps->next;
	while ((curnode != NULL)&&(curnode->data != *data))
	{
		prenode = curnode;
		curnode = curnode->next;		
	}
	if (curnode == NULL)
	{
		return -1;
	}
	else 
	{
		prenode->next = curnode->next;
		free(curnode);
		curnode = NULL;
		return 0;
	}
}


int list_isempty(LNode* ps)
{
	if (ps->next)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


int destroy_list(LNode* ps)
{
	LNode* newnode, *node = ps->next;
	//��������Ч�ڵ�,�������ͷ���
	while (node)
	{
		newnode = node->next;
		free(node);
		node = NULL;
		node = newnode;
	}
	//����ͷ���
	free(ps);
	ps = NULL;
	return 0;
}