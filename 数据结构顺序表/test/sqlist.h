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
void create_sqlist1(sqlist *ps);//创建顺序表
void display_sqlist(sqlist *ps);//打印顺序表
int add_sqlist(sqlist *ps,datatype *num);//顺序表结尾添加元素
int delete_sqlist(sqlist *ps,int pos);//删除顺序表pos处的元素
int insert_sqlist(sqlist *ps,int pos,datatype *num);//顺序表pos处插入元素
void destroy_sqlist(sqlist *ps);//销毁顺序表
int find_sqlsit(sqlist *ps,int pos);//给出下标找元素
int find1_sqlist(sqlist *ps, datatype* value);//给出元素查下标
int setempty_sqlist(sqlist* ps);//顺序表置为空
int union_sqlist(sqlist* list1, sqlist* list2);//顺序表的合并
#endif