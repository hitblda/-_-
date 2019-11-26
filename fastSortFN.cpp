#include "header.h"

/************************************************************************/
/*		                  基于迭代的快速查找                            */
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
	printf("pos的值是: %d  \n", L);
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
//void charInput(int arr[], int &i) //或者,这样也OK
{
	int i = 0;
	int max = 100;
	int* tmp = 0;
	*data = (int*)malloc(sizeof(int) * max);
	for (i = 0; scanf("%d", *data + i); ++i)
	{
		if (i > max) // 如果buf已经满了, 那么内存扩大一倍
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

	printf("输入数值以空格隔开[以##结束]\n");
	K = intInput(&tmp);
	printf("\n");
	printf("输入的字符串以空格隔断的整数有%d个元素\n", K);

	printf("******************************************************\n");
	printf("原始字符串中的元素是: \n");
	for (i = 0; i < K; i++)
	{
		printf("%d  ", tmp[i]);
	}
	printf("\n");

	printf("******************************************************\n");

	QuickSort(tmp, 0, K-1); //注意,参数2\3是数组下标值

	printf("\n");
	printf("快速排序之后数组中的元素是: \n");
	for (i = 0; i < K; i++)
	{
		printf("%d  ", tmp[i]);
	}
	printf("\n");

}
#endif