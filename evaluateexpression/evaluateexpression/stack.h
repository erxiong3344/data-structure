#ifndef STACK_H__
#define STACK_H__
#define MAXSIZE 20
template<class DataType>
class Stack
{
private:
	DataType *data;
	int top;
	int capacity;
public:
	Stack();//无参构造函数
	Stack(int sz);//有参构造函数
	~Stack();//析构函数
	DataType Pop();//弹出元素
	void Push(DataType elem);//压入元素
	DataType getTop();//得到栈顶元素
	bool isEmpty();//判断栈是否为空
	bool isFull();//判断栈是否为满
	class Empty {};//设置内置异常类
	class Full {};
};
typedef Stack<char> CharStack;
typedef Stack<int> IntStack;
int evaluatExpression(IntStack &opndStack, CharStack &optrStack);
#endif