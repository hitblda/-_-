#include "header.h"

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
	for (i = 0; i < length; i++)
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