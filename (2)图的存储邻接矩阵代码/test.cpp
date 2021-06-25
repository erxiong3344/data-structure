#include<iostream>
using namespace std;
#include "mgraph.h"
int main()
{
	char v[4] = { 'A','B','C','D' };
	MGraph g(v, 4, 4);
	g.printGraph();
	return 0;
}