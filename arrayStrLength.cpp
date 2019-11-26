#include "header.h"

/************************************************************************/
/*	           数组\字符串 长度的strlen()和sizeof() 验证                */
/************************************************************************/

int  charLenTest(char* str)
{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	double arrDB[] = { 0, 1,2,3,4,5,6,7,8,9 ,89 };
//
//
//	//字符数组\字符串 长度的测试程序
//	//char str[] = { 1,2,3,4,5,6,7,8,9,'a','b','c' ,'\0' };
//	const char* str1 = "Hello World";
//	char str2[8] = { 'h' };
//	//strlen(str);
//	//sizeof(str);
//	printf("/************************************/ \n");
//	printf("char str2[8] = { 'h' };\n");
//	printf("strlen(str2)的值是: %d  \n", strlen(str2));
//	printf("sizeof(str2);的值是: %d \n", sizeof(str2));
//
//	printf("/************************************/ \n");
//	printf("int arr[] = { 1,2,3,4,5,6,7,8,9 }; \n");
//	printf("sizeof(arr)/sizeof(arr[0]);的值是: %d \n", sizeof(arr) / sizeof(arr[0]));
//	printf("/************************************/ \n");
//	printf("double arrDB[] = { 0, 1,2,3,4,5,6,7,8,9 ,89 }; \n");
//	printf("sizeof(arrDB)/sizeof(arrDB[0]);的值是: %d \n", sizeof(arrDB) / sizeof(arrDB[0]));
//
//	printf("/************************************/ \n");
//	printf("const char* str1 = Hello World; \n");
//	printf("strlen(str1)的值是: %d  \n", strlen(str1));
//	printf("sizeof(str1);的值是: %d \n", sizeof(str1));
//
//	printf("/************************************/ \n");
//	printf("strlen(str)的值是: %d  \n", strlen(str));
//	printf("sizeof(str)/sizeof(str[0])的值是: %d \n", sizeof(str)/sizeof(str[0]));
//	printf("sizeof(str)的值是: %d \n", sizeof(str));

	printf("/************************************/ \n"); 
	int tmpL = getlength( str);
	printf("tmpL = getlength( str)的值是: %d  \n", tmpL);
	

	return  tmpL;
}

////////////////////////////////////////////////////
//采用指针实现字符串翻转
void StringSw(char* str,int len)
{
	char c;
	int i = 0;
	//char* str = "abcdfg hijklmn";
	//char str[] = "abc df";
	//int len = strlen(str);
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
	for (i = len; i > 0; i--)
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
	for (i = 0; i < len; i++)
	{
		printf("%c", p1[i]);
	}
	printf("\n");
	printf("********************打印逆序之后的字符串,使用指针p2来遍历*********************\n");
	p2 = str + len - 1;
	for (i = len - 1; i >= 0; i--)
	{
		printf("%c", *(p2 - i));  //从第一个元素开始
	}
	printf("\n");
}