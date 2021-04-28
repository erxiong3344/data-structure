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
	//����һ��˳��list,����ʼ��
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


	/*�����±�ɾ��Ԫ�ز��ֲ��Դ��룬pos==0����ѭ��*/
	/*do {
		printf("��������Ҫɾ����Ԫ���±��1��ʼ\n");
		scanf("%d", &pos);
		err = delete_sqlist(list, pos);
		display_sqlist(list);
	} while (pos);*/


	/*�����±����Ԫ�ز��ֲ��Դ��룬pos==2000�˳�ѭ��*/
	//while (1)
	//{
	//	scanf("%d", &pos);
	//	find_sqlsit(list, pos);
	//	if (pos == 2000)
	//	{
	//		break;
	//	}
	//}


	/*����Ԫ�ز����±겿�ֲ��Դ��룬����ʧ���˳�ѭ��*/
	/*while (1)
	{
		printf("��������Ҫ���ҵ�Ԫ��\n");
		scanf("%d", &value);
		pos=find1_sqlist(list, &value);
		if (pos == 0)
		{
			printf("����ʧ��,˳�����û�и�Ԫ��\n");
			break;
		}
		else if (pos == -1)
		{
			printf("����ʧ��, ˳���Ϊ��\n");
		}
		else {
			printf("%d���±�ʱ%d\n", value, pos);
		}
	}*/
	//����һ��˳��list_next,����ʼ��
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


