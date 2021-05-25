#include<iostream>
using namespace std;
#include "stack.h"

int main()
{
	IntStack opndStack;
	CharStack optrStack;
	cout << "请输入表达式以#结尾" << endl;
	cout<<evaluatExpression(opndStack,optrStack)<<endl;
	return 0;
}