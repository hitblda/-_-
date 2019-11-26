#include "header.h"

/************************************************************************/
/*		                  ���ڵ����Ŀ��ٲ���                            */
/************************************************************************/
#ifdef fastSortFN
int FindPos(int* a, int L, int H)
{
	a[H] = a[H];
	a[L] = a[L];
	int val = a[L];
	while (L < H)
	{
		while (L < H && a[H] >= val)
			--H;
		a[L] = a[H];

		while (L < H && a[L] <= val)
			++L;
		a[H] = a[L];

	}
	a[L] = val;
	printf("pos��ֵ��: %d  \n", L);
	return L;
}


void QuickSort(int* a, int L, int H)
{
	int pos;
	if (L < H)
	{
		pos = FindPos(a, L, H);
		QuickSort(a, L, pos - 1);
		QuickSort(a, pos + 1, H);
	}

}
int intInput(int**data)
//void charInput(int arr[], int &i) //����,����ҲOK
{
	int i = 0;
	int max = 100;
	int* tmp = 0;
	*data = (int*)malloc(sizeof(int) * max);
	for (i = 0; scanf("%d", *data + i); ++i)
	{
		if (i > max) // ���buf�Ѿ�����, ��ô�ڴ�����һ��
			*data = (int*)realloc(*data, sizeof(int) * (max *= 2));
	}
	
	return i;
}


void fastSort(void)
{
	int i=0,K=0;
	int* tmp;
	printf("\n");
	printf("******************************************************\n");

	printf("������ֵ�Կո����[��##����]\n");
	K = intInput(&tmp);
	printf("\n");
	printf("������ַ����Կո���ϵ�������%d��Ԫ��\n", K);

	printf("******************************************************\n");
	printf("ԭʼ�ַ����е�Ԫ����: \n");
	for (i = 0; i < K; i++)
	{
		printf("%d  ", tmp[i]);
	}
	printf("\n");

	printf("******************************************************\n");

	QuickSort(tmp, 0, K-1); //ע��,����2\3�������±�ֵ

	printf("\n");
	printf("��������֮�������е�Ԫ����: \n");
	for (i = 0; i < K; i++)
	{
		printf("%d  ", tmp[i]);
	}
	printf("\n");

}
#endif