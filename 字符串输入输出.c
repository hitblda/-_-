#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define fastSortFN 
#define QUEEN

//////////////////////////////////////////////////////////////////////
/*
	1,利用递归,将输入的字符,逆序输出
	2,利用数组将按字节输入的数据保存,然后正序输出

	注意,VC/VS 里面的scanf 是以回车键作为输入结束标志
	而代码里面可以根据不同通信协议的要求来指定,比如此处的#

	另外,字符串 是数组 + null character空字符,即 \0
	此处,以字符 c 的格式,通过数组输出!
*/

void charInput(int *arr, int& i)
//void charInput(int arr[], int &i) //或者,这样也OK
{
	char a = 0;
	
	scanf("%c", &a);
	//arr[i++] = a;
	if (a != '#')
	{
		arr[i++] = a;
		charInput(arr, i);//此时串口中断又发生!!
	}
	else
	{
		arr[i++] = a; //保存结束标志字节
	}

	if (a != '#')
	{
		printf("%c", a);
	}
}

void charIO_test(void)
{
	int arr[100];
	int i = 0;

	printf("输入字母或者数字[以#结束]\n");
	charInput(arr, i);
	printf("\n");
	printf("数组有%d个元素\n",i);
	printf("打印数组元素:\n");

	int num;
	for (num = 0; num < i;)
	{
		printf("%c", arr[num++]);
	}
	printf("\n");
}

void  charLenTest()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9};
	double arrDB[] = {0, 1,2,3,4,5,6,7,8,9 ,89};


	//字符数组\字符串 长度的测试程序
	char str[] = { 1,2,3,4,5,6,7,8,9,'a','b','c' ,'\0'};
	const char* str1 = "Hello World";
	char str2[8] = { 'h' };
	//strlen(str);
	//sizeof(str);
	//printf("strlen(arr)的值是: %d  \n", strlen(arr));
	printf("sizeof(arr)/sizeof(arr[0]);的值是: %d \n", sizeof(arr)/sizeof(arr[0]));
	printf("sizeof(arrDB)/sizeof(arrDB[0]);的值是: %d \n", sizeof(arrDB)/sizeof(arrDB[0]));

	printf("strlen(str)的值是: %d  \n",strlen(str));
	printf("sizeof(str);的值是: %d \n", sizeof(str));

	printf("strlen(str1)的值是: %d  \n", strlen(str1));
	printf("sizeof(str1);的值是: %d \n", sizeof(str1));

}
//////////////////////////////////////////////////////////////////////

//采用指针实现字符串翻转
void StringSw(void)
{
	char c;
	int i = 0;
	//char* str = "abcdfg hijklmn";
	char str[]= "abc df";
	int len = strlen(str);
	printf("原字符串的内容是: \n");

	for (i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	char* p1 = str;
	char* p2 = str + len - 1;//取到了字符串最后一个字符的地址
	printf("p2所指向的值是 %c\n", *p2);
	printf("********************逆序打印字符串方法1*********************\n");
	printf("通过简单逆序打印,*p2的值是\n");
	for (i= len;i>0;i--)
	{	
		printf("%c", *(p2--));	 
	}
	printf("\n");
	printf("*p1的值是\n");
	for (i = len; i > 0; i--)
	{
		printf("%c", *(p1++));
	}
	printf("\n OK \n");
	printf("*************************逆序字符串*************************\n");
	p1 = str;
	p2 = str + len - 1;
	while (p1 < p2)
	{
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		printf("*p1排序之后的值是:  ");

		for (i = len; i > 0; i--)
		{
			printf("%c", str[len - i]);
		}
		p1++;
		p2--;
		printf("\n");
	}

	//len = strlen(p1);
	printf("逆序字符串的内容是: \n");
	printf("********************打印逆序之后的字符串,使用指针p1来遍历*********************\n");
	p1 = str;
	for (i=0;i<len;i++)
	{
		printf("%c", p1[i]); 
	}
	printf("\n");
	printf("********************打印逆序之后的字符串,使用指针p2来遍历*********************\n");
	p2 = str + len - 1;
	for (i = len-1; i >=0; i--)
	{
		printf("%c", *(p2-i));  //从第一个元素开始
	}
	printf("\n");
}
/*********************************************************************************/
int getlength(char* str)
{
	/*
	计算字符串的长度,不包括'\0'
	*/
	int num = 0;
	while (*str)
	{
		num++;
		str++;
	}
	return num;
}

void printStr(const char* str, int length)
{
	unsigned int i = 0;
	for ( i = 0; i < length; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
}

void strStract(char* str1, char* str2)
{
	/*
		在字符串str1的后面追加字符串str2
	*/
	int str1_len = getlength(str1);
	int str2_len = getlength(str2);

	char* pall = str1;
	pall += str1_len; //移动指针到字符串str1的尾部

	char* padd = str2;//用于获取字符串str2内容的指针

	while (*padd)
	{
		*pall = *padd; //将字符串str2的内容获取到padd中,然后赋值到str1尾部的指针
		padd++;
		pall++;
	}
	*(pall + 1) = '\0';

}
/*********************************************************************************/


/*********************************************************************************/
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
//////////////////////////////////////////////////////////////

#ifdef QUEEN
//八皇后
void EightQueen()
{


}


#endif


void main(void)
{
	//charIO_test();//字符输入,输出
	//charLenTest();//数组\字符 长度计算

	StringSw(); //指针的字符串逆序输出

	//fastSort();  //快速排序

	system("pause");
} 