#ifndef LINKLIST_H__
#define LINKLIST_H__
typedef int datatype;
typedef struct LNode
{
	datatype data;
	struct LNode *next;
}LNode;
LNode* create_list();
//按从小到大的顺序插入元素
int list_order_insert(LNode* ps, datatype *data);
//任意位置插入节点
int list_insert_at(LNode *ps, int i,datatype* data);
//按元素删除链表中的节点
int delete_list(LNode *ps, datatype *data);
//按位置删除链表中的节点,data接收返回值
int delete_list_at(LNode *ps, int i,datatype* data);
//打印链表中的数据
int list_display(LNode* ps);
//判断链表是否为空
int list_isempty(LNode* ps);
//销毁链表
int destroy_list(LNode* ps);
#endif