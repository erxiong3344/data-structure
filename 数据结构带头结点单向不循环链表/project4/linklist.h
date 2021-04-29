#ifndef LINKLIST_H__
#define LINKLIST_H__
typedef int datatype;
typedef struct LNode
{
	datatype data;
	struct LNode *next;
}LNode;
LNode* create_list();
//����С�����˳�����Ԫ��
int list_order_insert(LNode* ps, datatype *data);
//����λ�ò���ڵ�
int list_insert_at(LNode *ps, int i,datatype* data);
//��Ԫ��ɾ�������еĽڵ�
int delete_list(LNode *ps, datatype *data);
//��λ��ɾ�������еĽڵ�,data���շ���ֵ
int delete_list_at(LNode *ps, int i,datatype* data);
//��ӡ�����е�����
int list_display(LNode* ps);
//�ж������Ƿ�Ϊ��
int list_isempty(LNode* ps);
//��������
int destroy_list(LNode* ps);
#endif