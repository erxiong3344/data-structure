#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include "linklist.h"
int main()
{
	LNode* list=NULL;
	int i = 0,err =0;
	datatype a = 40,return_value=0;
	datatype arr[] = { 20,10,90,100,50,40,20,60,70,80 };
	//创建链表
	list = create_list();
	if (list == NULL)
	{
		fprintf(stderr, "create_list()failed\n");
		return -1;
	}
	//链表中插入数据，按照从小到大的顺序插入
	for (i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		//插入失败，返回-2
		list_order_insert(list,&arr[i]);
			
	}
	//打印链表
	list_display(list);
	//按照元素删除链表中data域为40的节点
	//delete_list(list, &a);
	//list_display(list);
	//按位置删除链表中下标为3的节点,注意链表中有效节点的下标从0开始,retun_value接收返回值
	/*delete_list_at(list,3,&return_value);
	printf("删除节点的数据为%d\n", return_value);
	list_display(list);*/
	destroy_list(list);
}


