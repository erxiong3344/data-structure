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
	Stack();//�޲ι��캯��
	Stack(int sz);//�вι��캯��
	~Stack();//��������
	DataType Pop();//����Ԫ��
	void Push(DataType elem);//ѹ��Ԫ��
	DataType getTop();//�õ�ջ��Ԫ��
	bool isEmpty();//�ж�ջ�Ƿ�Ϊ��
	bool isFull();//�ж�ջ�Ƿ�Ϊ��
	class Empty {};//���������쳣��
	class Full {};
};
typedef Stack<char> CharStack;
typedef Stack<int> IntStack;
int evaluatExpression(IntStack &opndStack, CharStack &optrStack);
#endif