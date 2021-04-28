#ifndef SQLIST_H__
#define SQLIST_H_
#define MAX_LENGTH 1024
typedef int datatype;

typedef struct sqlist
{
	datatype data[MAX_LENGTH];
	int size;
}sqlist;
sqlist* create_sqlist(void);
void create_sqlist1(sqlist *ps);//����˳���
void display_sqlist(sqlist *ps);//��ӡ˳���
int add_sqlist(sqlist *ps,datatype *num);//˳����β���Ԫ��
int delete_sqlist(sqlist *ps,int pos);//ɾ��˳���pos����Ԫ��
int insert_sqlist(sqlist *ps,int pos,datatype *num);//˳���pos������Ԫ��
void destroy_sqlist(sqlist *ps);//����˳���
int find_sqlsit(sqlist *ps,int pos);//�����±���Ԫ��
int find1_sqlist(sqlist *ps, datatype* value);//����Ԫ�ز��±�
int setempty_sqlist(sqlist* ps);//˳�����Ϊ��
int union_sqlist(sqlist* list1, sqlist* list2);//˳���ĺϲ�
#endif