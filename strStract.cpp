#include "header.h"

/*********************************************************************************/

void printStr(const char** str)
{
	//char* pp = (char*)*str;
	//unsigned int i = 0;
	printf("%s\n", str);
	//for (i = 0; i < length; i++)
	//{
	//	printf("%c", *(str+i));
	//	//printf("%c", pp + i);
	//}
	printf("\n");
}

/******************************************************************************
*  字符串输入,在被调函数里面分配内存
*******************************************************************************/
int charIO_test2(char** arr)
{
	//static int i=0;
	int ret = 0;
	int num=0,max = 100;
	char c;
	char *Array = (char*)malloc(sizeof(char*) * max);
	if (Array ==NULL)
	{
		ret = -2;
		printf("func splitStr err : %d malloc(sizeof(char *) * tmpCount)", ret);
		goto END;
	}
	memset(Array, 0, max * sizeof(char*));

	printf("输入字符串\n");

//	scanf("%s", *Array); //遇到空格就停止
/*
	采用定制结束符
*/
	scanf("%[^\n]", Array);

	num = strlen(Array);
	if (num > max) // 如果*data已经满了, 那么内存扩大一倍
	{
		Array = (char*)realloc(Array, sizeof(char) * (max *= 2));
	}
	printf("\n");
	//printStr((const char**)Array, num);
	printf("输入的字符串是\n");
	printf("%s\n", Array);

	// 在统一的这个出口的地方, 把所有的内存资源释放掉
END:
	if (ret != 0) // 失败
	{
		int i = 0;
		if (Array == NULL)
		{
			return ret;
		}
		/*for (i = 0; i < max; i++)
		{
			if (Array[i] != NULL)
			{
				free(Array[i]);
			}
		}*/
		free(Array);
	}
	else
	{
		*arr = Array;   // 成功
	}

	//if (Array != NULL)
	//{
	//	free(Array);
	//	Array = NULL;
	//}

	return num;
}
/******************************************************************************
*  字符串拼接
*******************************************************************************/
void strStract(char* str1, char* str2)
{
	/*
		在字符串str1的后面追加字符串str2
	*/
	int str1_len = strlen(str1);
	int str2_len = strlen(str2);

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
/******************************************************************************
*  字符串1中是否有字符串2存在
*	暴力匹配
*******************************************************************************/
int ViolentMatch(char* s, char** pp)
{
	char* p = NULL;
	p = *pp;
	int sLen = strlen(s);
	int pLen = strlen(p);  //????

	int i = 0;
	int j = 0;
	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			//①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++    
			i++;
			j++;
		}
		else
		{
			//②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0    
			i = i - j + 1;
			j = 0;
		}
	}
	//匹配成功，返回模式串p在文本串s中的位置，否则返回-1
	if (j == pLen)
		return i - j;
	else
		return -1;
}