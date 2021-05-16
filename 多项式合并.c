//思路：
//1.定义两个链表分别存储多项式1和多项式2(本人使用带头结点单向链表)
//2.定义两个指针p,q分别指向多项式1与多项式2，
//初始时刻p指向多项式1的第一个有效节点
//q指向多项式2的第一个有效节点
//比较p与q指向节点中的指针域
//p->exp>q->exp为情况1
//p->exp==q->exp为情况2
//p->exp<q->exp为情况3
//3.将多项式2合并到多项式1上
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int exp;//指数
	int coe;//系数
	struct Node *next;//结构体自引用
}Node,*Link;
//创建一个空链表
Link createList()
{
	Link head = NULL;
	head=(Link)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}
	head->next = NULL;
	return head;
}
//按照指数由小到大的顺序插入节点
int insertNode(Link head, int exp,int coe)
{
	Link p = head->next;//p指向第一个有效节点
	Link prior_p = head;
	Link newnode = NULL;
	if ((coe == 0) && (exp == 0))
	{
		return 0;
	}
	//1.找到插入位置
	while (p)
	{
		//p节点中的指数大于exp,找到插入位置
		if (exp < p->exp)
		{
			break;
		}
		prior_p = p;
		p = p->next;
	}
	//2.插入节点
	newnode = (Link)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		return -1;
	}
	newnode->coe = coe;
	newnode->exp = exp;
	prior_p->next = newnode;
	newnode->next = p;
	return 0;
}
//展示链表
void displayList(Link head)
{
	Link p = NULL;
	printf("链表中的系数与指数依次为\n");
	for (p = head->next; p != NULL; p = p->next)
	{
		printf("%d\t%d\n", p->coe, p->exp);
	}
}
//链表的合并
int combineList(Link heada,Link headb)
{
	Link p = heada->next;
	Link prior_p = heada;
	Link q = headb->next,temp =NULL;
	Link newnode = NULL;
	while (p&& q)
	{
		if (p->exp == q->exp)
		{
			//指数不变，系数相加
			p->coe = p->coe + q->coe;
			//分类讨论，系数为0
			if (p->coe)
			{
				prior_p = p;
			}
			//系数不为0
			else
			{
				prior_p->next = p->next;				
			}
			q = q->next;
			p = p->next;

		}
		else if (p->exp > q->exp)
		{
			//1.q插在p的前面
			//2.q指向q的下一个节点
			prior_p->next = q;
			prior_p = q;
			temp = q->next;
			q->next = p;
			q = temp;
		}
		else
		{
			prior_p = p;
			p = p->next;
		}
	}
	if (p == NULL)
	{
		prior_p->next = q;
	}
	return 0;
}
//销毁链表
void destroyList(Link head)
{
	//先销毁有效节点，在销毁头结点
	Link p = NULL,q = NULL;
	for (p= head->next;p!=NULL;p=q)
	{
		q = p->next;
		free(p);
	}
	free(head);
	head = NULL;
}
int main()
{
	Link list1 = createList();
	Link list2 = createList();
	int coe = 0, exp = 0;
	printf("请输入多项式1的系数与指数,输入0 0 结束循环\n");
	do
	{
		scanf_s("%d %d", &coe, &exp);
		insertNode(list1, exp, coe);

	} while ((coe != 0) && (exp != 0));
	printf("请输入多项式2的系数与指数,输入0 0 结束循环\n");
	do
	{
		scanf_s("%d %d", &coe, &exp);
		insertNode(list2, exp, coe);
	} while ((coe != 0) && (exp != 0));
	printf("多项式1:\n");
	displayList(list1);
	printf("多项式2:\n");
	displayList(list2);
	combineList(list1, list2);
	printf("多项式1:\n");
	displayList(list1);
	destroyList(list2);
	return 0;
}
