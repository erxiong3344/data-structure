#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "sqlist.h"
int main()
{
	sqlist *list= NULL,*list_next= NULL;
	int pos = 0;
	int i, err, value;
	int arr[10] = { 10,20,30,40,50,60,70,80,90,100 };
	int arr_next[10] = { 11,22,33,44,55,66,77,88,99,111 };
	//创建一个顺表list,并初始化
	list = create_sqlist();
	if (list == NULL)
	{
		fprintf(stderr, "create_sqlist()failed\n");
	}
	for (i = 0; i < 10; i++)
	{
		add_sqlist(list, &i);
	}
	for (i = 0; i < sizeof(arr) / sizeof(*arr); i++)
	{
		if ((err = insert_sqlist(list, 2, &arr[i]))!=0)
		{
			if (err = -1)
			{
				fprintf(stderr, "The arr is full\n");
			}
			else if (err = -2)
			{
				fprintf(stderr, "The pos you want to insert is wrong\n");

			}
			else
			{
				fprintf(stderr, "ERROR\n");
			}
		}
	}
	
	display_sqlist(list);


	/*根据下标删除元素部分测试代码，pos==0跳出循环*/
	/*do {
		printf("请输入您要删除的元素下标从1开始\n");
		scanf("%d", &pos);
		err = delete_sqlist(list, pos);
		display_sqlist(list);
	} while (pos);*/


	/*给出下标查找元素部分测试代码，pos==2000退出循环*/
	//while (1)
	//{
	//	scanf("%d", &pos);
	//	find_sqlsit(list, pos);
	//	if (pos == 2000)
	//	{
	//		break;
	//	}
	//}


	/*给出元素查找下标部分测试代码，查找失败退出循环*/
	/*while (1)
	{
		printf("请输入您要查找的元素\n");
		scanf("%d", &value);
		pos=find1_sqlist(list, &value);
		if (pos == 0)
		{
			printf("查找失败,顺序表中没有该元素\n");
			break;
		}
		else if (pos == -1)
		{
			printf("查找失败, 顺序表为空\n");
		}
		else {
			printf("%d的下标时%d\n", value, pos);
		}
	}*/
	//创建一个顺表list_next,并初始化
	list_next = create_sqlist();
	if (list_next == NULL)
	{
		fprintf(stderr, "create_sqlist()failed\n");
	}
	for (i = 0; i < 10; i++)
	{
		add_sqlist(list_next, &i);
	}
	for (i = 0; i < sizeof(arr_next) / sizeof(*arr_next); i++)
	{
		if ((err = insert_sqlist(list_next, 2, &arr_next[i])) != 0)
		{
			if (err = -1)
			{
				fprintf(stderr, "The arr is full\n");
			}
			else if (err = -2)
			{
				fprintf(stderr, "The pos you want to insert is wrong\n");

			}
			else
			{
				fprintf(stderr, "ERROR\n");
			}
		}
	}
	display_sqlist(list_next);
	union_sqlist(list, list_next);
	display_sqlist(list);

	destroy_sqlist(list_next);
	destroy_sqlist(list);

}


