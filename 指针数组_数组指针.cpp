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
/*           �൱��������:��һ��������row����ЧԪ��,�������            */
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
	printf("\n��ʼ��ӡ���height��Ӧarray ******************\n");
	for (k = 0; k < height; k++)
	{
		printf("a[%d][%d][%d]=%d\t", i, j, k, a[i][j][k]);
	}
	printf("\n");

	i = 0; j = 0; k = 0;
	printf("\n��ʼ��ӡ���col��Ӧarray ******************\n");
	for (j = 0; j < col; j++)
	{
		printf("a[%d][%d][%d]=%d\t", i, j, k, a[i][j][k]);
	}
	printf("\n");

	i = 0; j = 0; k = 0;
	printf("\n��ʼ��ӡ���row��Ӧarray ******************\n");
	for (i = 0; i < row; i++)
	{
		printf("a[%d][%d][%d]=%d\t", i, j, k, a[i][j][k]);
	}
	printf("\n");

	printf("\n��ʼͨ����i,j,k��ӡ���array ******************\n");
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

	printf("\n����һάָ�뿪ʼ��ӡ���array ******************\n");
	int* p = (int*)a;
	for (i = 0; i < 120; i++)  //4*5*6 =120
	{
		printf("%d\n", p[i]);
	}
	//�����Ȼһ��!!!
	/************************************************************************/
	/*                 �ɴ�,�ɼ������������������                          */
	/*                ������a[i][j][k]��a[i][j][k] ���λ��ʼ�仯           */
	/************************************************************************/

}













