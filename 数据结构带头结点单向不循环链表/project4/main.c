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
	//��������
	list = create_list();
	if (list == NULL)
	{
		fprintf(stderr, "create_list()failed\n");
		return -1;
	}
	//�����в������ݣ����մ�С�����˳�����
	for (i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		//����ʧ�ܣ�����-2
		list_order_insert(list,&arr[i]);
			
	}
	//��ӡ����
	list_display(list);
	//����Ԫ��ɾ��������data��Ϊ40�Ľڵ�
	//delete_list(list, &a);
	//list_display(list);
	//��λ��ɾ���������±�Ϊ3�Ľڵ�,ע����������Ч�ڵ���±��0��ʼ,retun_value���շ���ֵ
	/*delete_list_at(list,3,&return_value);
	printf("ɾ���ڵ������Ϊ%d\n", return_value);
	list_display(list);*/
	destroy_list(list);
}


