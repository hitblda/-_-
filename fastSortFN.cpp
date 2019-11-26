#include "header.h"

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

void fastSort()
{
	int  a[] = { 2,8,34,1,9,55,4,-9,-299 };
	int num = (sizeof(a) / sizeof(a[0]));
	int i;
	printf("原始数组中的元素是: \n");
	for (i = 0; i < num; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");

	QuickSort(a, 0, num - 1); //注意,参数2\3是数组下标值

	printf("\n");
	printf("快速排序之后数组中的元素是: \n");
	for (i = 0; i < num; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
#endif