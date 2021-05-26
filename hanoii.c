#include<stdio.h>
void move(char x,char z)
{
	printf("%c -> %c\n", x, z);
}
//将n个盘子从x经有y移动到z,注意移动过程中始终为大盘子在下，小盘子在上
void hanoii(char x, char y, char z, int n)
{
	if (n == 1)
	{
		move(x, z);
	}
	else
	{
		hanoii(x,z,y,n-1);//将n-1个盘子从x经z移动到y
		move(x, z);//将第n个盘子从x移动到z
		hanoii(y, x, z, n - 1);//将n-1个盘子从y经x移动到z
	}
	
}
int main()
{
	hanoii('a', 'b', 'c', 3);
	return 0;
}
