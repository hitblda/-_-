#include "header.h"

void makeArray(int a[3][5])
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = 10*j+100*i;
		}
	}
}
/************************************************************************/
/*           相当于是向量:第一个向量有row个有效元素,如此类推            */
/************************************************************************/
void makeArray3(int(*cube)[5][6], int row, int col, int height)
{
	int i = 0, j = 0,k=0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			for (k = 0; k < height; k++)
			{
				cube[i][j][k] = 10 * j + 100 * i+ k;
			}			
		}
	}
}

void printArray(int a[3][5])
{
	int i = 0, j = 0;
	for (i=0;i<3;i++)
	{
		for (j=0;j<5;j++)
		{
			printf("a[%d][%d]:%d\t", i, j, a[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
}

void printArray3(int a[][5][6], int row, int col, int height)
{
	int i = 0, j = 0, k = 0;
	printf("\n开始打印输出height对应array ******************\n");
	for (k = 0; k < height; k++)
	{
		printf("a[%d][%d][%d]=%d\t", i, j, k, a[i][j][k]);
	}
	printf("\n");

	i = 0; j = 0; k = 0;
	printf("\n开始打印输出col对应array ******************\n");
	for (j = 0; j < col; j++)
	{
		printf("a[%d][%d][%d]=%d\t", i, j, k, a[i][j][k]);
	}
	printf("\n");

	i = 0; j = 0; k = 0;
	printf("\n开始打印输出row对应array ******************\n");
	for (i = 0; i < row; i++)
	{
		printf("a[%d][%d][%d]=%d\t", i, j, k, a[i][j][k]);
	}
	printf("\n");

	printf("\n开始通过轮i,j,k打印输出array ******************\n");
	i = 0; j = 0; k = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			for (k = 0; k < height; k++) 
			{
				printf("a[%d][%d][%d]=%d\t", i, j, k, a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");

	printf("\n采用一维指针开始打印输出array ******************\n");
	int* p = (int*)a;
	for (i = 0; i < 120; i++)  //4*5*6 =120
	{
		printf("%d\n", p[i]);
	}
	//结果当然一样!!!
	/************************************************************************/
	/*                 由此,可见数组是连续存放数据                          */
	/*                而且由a[i][j][k]的a[i][j][k] 最低位开始变化           */
	/************************************************************************/

}













