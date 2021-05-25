#include<iostream>
using namespace std;
#include "stack.h"


template<class DataType>
Stack<DataType>::Stack()
{
	data = new DataType[MAXSIZE];
	top = -1;
	capacity = MAXSIZE;
}


template<class DataType>
Stack<DataType>::Stack(int sz)
{
	data = new DataType[sz];
	top = -1;
	capacity = sz;
}


template<class DataType>
Stack<DataType>::~Stack()
{
	delete[]  data;
}


template<class DataType>
DataType Stack<DataType>::Pop()
{
	if (isEmpty())
	{
		throw Empty();
	}
	else
	{
		return data[top--];
	}
}


template<class DataType>
void  Stack<DataType>::Push(DataType elem)
{
	if (isFull())
	{
		throw Full();
	}
	else
	{
		data[++top] = elem;
	}
}


template<class DataType>
DataType Stack<DataType>::getTop()
{
	if (isEmpty())
	{
		throw Empty();
	}
	else
	{
		return data[top];
	}
}

template<class DataType>
bool Stack<DataType>::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template<class DataType>
bool Stack<DataType>::isFull()
{
	if (top == MAXSIZE - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template class Stack<char>;
template class Stack<int>;


int operate(int num1,char optr, int num2)
{
	switch (optr)
	{
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num2 - num1;
		break;
	case '*':
		return num2 * num1;
		break;
	case '/':
		return num2 / num1;
		break;
	}
}

bool isOptr(char ch)
{
	switch (ch)
	{
	case '+':
		return true;
		break;
	case '-':
		return true;
		break;
	case '*':
		return true;
		break;
	case '/':
		return true;
		break;
	case '(':
		return true;
		break;
	case ')':
		return true;
		break;
	case '#':
		return true;
		break;
	default:
		return false;
		break;
	}
}

char  precede(char t1, char t2)
{
	char f;
	switch (t1)
	{
	case '+':
		if (t2 == '*' || t2 == '/' || t2 == '(')
		{
			f = '<';
		}
		else
		{
			f = '>';
		}
		break;
	case '-':
		if (t2 == '*' || t2 == '/' || t2 == '(')
		{
			f = '<';
		}
		else
		{
			f = '>';
		}
		break;
	case '*':
		if (t2 == '(')
		{
			f = '<';
		}
		else
		{
			f = '>';
		}
		break;
	case '/':
		if (t2 == '(')
		{
			f = '<';
		}
		else
		{
			f = '>';
		}
		break;
	case '(':
		if (t2 == ')')
		{

			f = '=';
		}
		else if (t2 == '#')
		{
			f = ' ';
		}
		else
		{
			f = '<';
		}
		break;
	case ')':
		if (t2 == '(')
		{
			f = ' ';
		}
		else
		{
			f = '>';
		}
		break;
	case '#':
		if (t2 == '#')
		{
			f = '=';
		}
		if (t2 == ')')
		{
			f = ' ';
		}
		else
		{
			f = '<';
		}
		break;
	}
	return f;
}
int evaluatExpression(IntStack &opndStack, CharStack &optrStack)
{
	char ch,optr;
	int num1, num2,res,temp;
	optrStack.Push('#');
	int isNum = 0;//�ж�ǰһ���ַ��Ƿ�Ϊ����
	cin >> ch;
	//ѭ����������,ջ��Ԫ��Ϊ'#',�Ҷ�����ַ�Ϊ'#'
	while (ch != '#' || optrStack.getTop() != '#')
	{
		if (!isOptr(ch))//������,ѹ������ջ��
		{
			if (isNum == 1)
			{
				temp = opndStack.Pop();
				temp = temp * 10 + (ch - '0');
				opndStack.Push(temp);
				isNum = 1;
				cin >> ch;
			}
			else 
			{
				isNum = 1;
				opndStack.Push(ch - '0');
				cin >> ch;
			}
			
		}
		else//���������Ƚ����ȼ�
		{
			isNum = 0;
			switch (precede(optrStack.getTop(),ch))
			{
			case '>'://ջ��Ԫ�س�ջ��������ջ����2��Ԫ��
				num1 = opndStack.Pop();
				num2 = opndStack.Pop();
				/*cout << num1 << "\t";
				cout << num2 << endl;*/
				optr = optrStack.Pop();
				res = operate(num1, optr, num2);
				opndStack.Push(res);
				break;
			case '<':
				optrStack.Push(ch);
				cin >> ch;
				break;
			case '=':
				optrStack.Pop();
				cin >> ch;
				break;
			}
		}
	}
	return opndStack.Pop();
}
