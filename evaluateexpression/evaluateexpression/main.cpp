#include<iostream>
using namespace std;
#include "stack.h"

int main()
{
	IntStack opndStack;
	CharStack optrStack;
	cout << "��������ʽ��#��β" << endl;
	cout<<evaluatExpression(opndStack,optrStack)<<endl;
	return 0;
}