//8皇后问题
#include<stdio.h>
//逐行扫描，逐列遍历
//检查是否可以放置皇后(判断列，判断上对角线，判断下对角线)
//放置皇后，宣布列占据，上对角线占据，下对角线占据
//撤销皇后，解除列占据，上对角线占据，下对角线占据
int place[8];//放置在第i行的皇后占据第j列
int flag[8] = { 1,1,1,1,1,1,1,1 };//1表示可以放置,0表示不能放置
int d1[15] = { 1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1 };
int d2[15] = { 1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1 };
int num = 0;
void print()
{
	num++;
	int table[8][8] = { 0 };
	for (int row = 0; row < 8; row++)
	{
		table[row][place[row]] = 1;
	}
	printf("第%d种解法\n", num);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%3d", table[i][j]);
		}
		printf("\n");
	}
}
void generate(int row)
{
	for (int col = 0; col < 8; col++)
	{
		if (flag[col] && d2[col + row] && d1[row-col + 7])//检查判断是否可以放置皇后
		{
			place[row] = col;//放置皇后，宣布占领
			flag[col] = 0;
			d1[row - col + 7] = 0;
			d2[col + row] = 0;
			if (row < 7)
			{
				generate(row + 1);//递归，扫描下一行
			}
			else
			{
				print();
			}
			//解除占领，撤销皇后，回溯，企图找到其他解法
			flag[col] = 1;
			d1[row - col + 7] = 1;
			d2[row + col] = 1;
		}
		
	}
}
int main()
{
	int row = 0;
	generate(row);
	return 0;
}

