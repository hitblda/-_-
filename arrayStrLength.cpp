#include "header.h"

/************************************************************************/
/*	           ����\�ַ��� ���ȵ�strlen()��sizeof() ��֤                */
/************************************************************************/

int  charLenTest(char* str)
{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	double arrDB[] = { 0, 1,2,3,4,5,6,7,8,9 ,89 };
//
//
//	//�ַ�����\�ַ��� ���ȵĲ��Գ���
//	//char str[] = { 1,2,3,4,5,6,7,8,9,'a','b','c' ,'\0' };
//	const char* str1 = "Hello World";
//	char str2[8] = { 'h' };
//	//strlen(str);
//	//sizeof(str);
//	printf("/************************************/ \n");
//	printf("char str2[8] = { 'h' };\n");
//	printf("strlen(str2)��ֵ��: %d  \n", strlen(str2));
//	printf("sizeof(str2);��ֵ��: %d \n", sizeof(str2));
//
//	printf("/************************************/ \n");
//	printf("int arr[] = { 1,2,3,4,5,6,7,8,9 }; \n");
//	printf("sizeof(arr)/sizeof(arr[0]);��ֵ��: %d \n", sizeof(arr) / sizeof(arr[0]));
//	printf("/************************************/ \n");
//	printf("double arrDB[] = { 0, 1,2,3,4,5,6,7,8,9 ,89 }; \n");
//	printf("sizeof(arrDB)/sizeof(arrDB[0]);��ֵ��: %d \n", sizeof(arrDB) / sizeof(arrDB[0]));
//
//	printf("/************************************/ \n");
//	printf("const char* str1 = Hello World; \n");
//	printf("strlen(str1)��ֵ��: %d  \n", strlen(str1));
//	printf("sizeof(str1);��ֵ��: %d \n", sizeof(str1));
//
//	printf("/************************************/ \n");
//	printf("strlen(str)��ֵ��: %d  \n", strlen(str));
//	printf("sizeof(str)/sizeof(str[0])��ֵ��: %d \n", sizeof(str)/sizeof(str[0]));
//	printf("sizeof(str)��ֵ��: %d \n", sizeof(str));

	printf("/************************************/ \n"); 
	int tmpL = getlength( str);
	printf("tmpL = getlength( str)��ֵ��: %d  \n", tmpL);
	

	return  tmpL;
}

////////////////////////////////////////////////////
//����ָ��ʵ���ַ�����ת
void StringSw(char* str,int len)
{
	char c;
	int i = 0;
	//char* str = "abcdfg hijklmn";
	//char str[] = "abc df";
	//int len = strlen(str);
	printf("ԭ�ַ�����������: \n");

	for (i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	char* p1 = str;
	char* p2 = str + len - 1;//ȡ�����ַ������һ���ַ��ĵ�ַ
	printf("p2��ָ���ֵ�� %c\n", *p2);
	printf("********************�����ӡ�ַ�������1*********************\n");
	printf("ͨ���������ӡ,*p2��ֵ��\n");
	for (i = len; i > 0; i--)
	{
		printf("%c", *(p2--));
	}
	printf("\n");
	printf("*p1��ֵ��\n");
	for (i = len; i > 0; i--)
	{
		printf("%c", *(p1++));
	}
	printf("\n OK \n");
	printf("*************************�����ַ���*************************\n");
	p1 = str;
	p2 = str + len - 1;
	while (p1 < p2)
	{
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		printf("*p1����֮���ֵ��:  ");

		for (i = len; i > 0; i--)
		{
			printf("%c", str[len - i]);
		}
		p1++;
		p2--;
		printf("\n");
	}

	//len = strlen(p1);
	printf("�����ַ�����������: \n");
	printf("********************��ӡ����֮����ַ���,ʹ��ָ��p1������*********************\n");
	p1 = str;
	for (i = 0; i < len; i++)
	{
		printf("%c", p1[i]);
	}
	printf("\n");
	printf("********************��ӡ����֮����ַ���,ʹ��ָ��p2������*********************\n");
	p2 = str + len - 1;
	for (i = len - 1; i >= 0; i--)
	{
		printf("%c", *(p2 - i));  //�ӵ�һ��Ԫ�ؿ�ʼ
	}
	printf("\n");
}