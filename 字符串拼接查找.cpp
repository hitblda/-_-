#include "header.h"

/*********************************************************************************/
int getlength(char* str)
{
	/*
	�����ַ����ĳ���,������'\0'
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
		���ַ���str1�ĺ���׷���ַ���str2
	*/
	int str1_len = getlength(str1);
	int str2_len = getlength(str2);

	char* pall = str1;
	pall += str1_len; //�ƶ�ָ�뵽�ַ���str1��β��

	char* padd = str2;//���ڻ�ȡ�ַ���str2���ݵ�ָ��

	while (*padd)
	{
		*pall = *padd; //���ַ���str2�����ݻ�ȡ��padd��,Ȼ��ֵ��str1β����ָ��
		padd++;
		pall++;
	}
	*(pall + 1) = '\0';

}