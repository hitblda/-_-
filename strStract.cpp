#include "header.h"

/*********************************************************************************/



/******************************************************************************
*  字符串输入,在被调函数里面分配内存
*******************************************************************************/
int charIO_test2(char** arr)
{
	//static int i=0;
	int ret = 0;
	int num=0,max = 100;
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
	printf("[begin]%s[end]\n", Array);

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

int get_non_space_cnt(/*inout */char** str,/*out*/ int* cnt_p)
{
	////
	//char* k = NULL;

	//char* tmp = NULL;

	//int len = 0;
	//int cnt = 0;

	//if (str == NULL || cnt_p == NULL) {
	//	fprintf(stderr, " str == NULL || cnt_p == NULL \n");
	//	return -1;
	//}
	//printf("需要分配的空间大小为: %d\n", strlen(*str));
	//tmp = (char*)malloc(strlen(*str));
	//if (tmp == NULL)
	//{
	//	return -1;
	//}

	////q = *str + strlen(*str) - 1; //指向字符串的末尾元素
	////左边遍历
	////while ((*p == ' ' && *p !='\0')  ) {

	//k = *str;//指向字符串首元素

	//while (*k != '\0')  //从头到尾
	//{
	//	if (isspace(*k))
	//	{
	//		cnt++;  //统计空格的个数
	//	}
	//	else   //非空格就存入临时指针
	//	{
	//		tmp[len++] = *k;
	//	}

	//	k++;
	//}
	//if (cnt > 0)
	//{
	//	tmp[len] = '\0'; // 如果新的字符串长度变短,那么需要补'\0'
	//}

	//*cnt_p = cnt;
	////去除空格键的字符串
	//*str = tmp;

	char* tmp = NULL;

	int len = 0;
	int cnt = 0;

	if (str == NULL || cnt_p == NULL) {
		fprintf(stderr, " str == NULL || cnt_p == NULL \n");
		return -1;
	}
	printf("需要分配的空间大小为: %d\n", strlen(*str));
	len = strlen(*str);
	if(getMem(&tmp, &len)<0)
	{
		return -1;
	}

	//左边遍历
	//while ((*p == ' ' && *p !='\0')  ) {
	strcpy(tmp, *str); //将内容复制过来
	printf("复制过来的内容是:[begin]%s[end]\n", tmp);
	len = 0;
	while (**str != '\0')  //从头到尾
	{
		if (isspace(**str))
		{
			cnt++;  //统计空格的个数
		}
		else   //非空格就存入临时指针
		{
			tmp[len++] = **str;
		}

		(*str)++; //means:(*str)++;
	}
	if (cnt > 0)
	{
		tmp[len] = '\0'; // 如果新的字符串长度变短,那么需要补'\0'
	}

	*cnt_p = cnt;
	//去除空格键的字符串
//	*str = tmp;
	strcpy(*str, tmp); //将内容复制过来

	if (tmp !=NULL)
	{
		free(tmp);
		tmp = NULL;
	}

	return 0;
}


int trimSpace(char** inbuf, char* outbuf)
{
	int i = 0;
	int j = 0;
	int len = 0;
	char* buf = NULL;

	if (inbuf == NULL || outbuf == NULL) {
		fprintf(stderr, " (inbuf == NULL || outbuf == NULL)\n  ");
		return -1;
	}

	len = strlen(*inbuf);
	if (getMem(&buf, &len) < 0)
	{
		return -1;
	}
	printf("****************************准备对第一个参数*****************************\n");
	printf("第一个参数inbuf里面的内容是:[begin]%s[end]\n", *inbuf);
	strcpy(buf, *inbuf);
	printf("buf里面的内容是:[begin]%s[end]\n", buf);

	j = strlen(*inbuf) - 1;

	//左边开始遍历
	while (isspace(buf[i]) && buf[i] != '\0') {
		i++;
	}

	//右边
	while (isspace(buf[j]) && j > i) {
		j--;
	}

	len = j - i + 1;

	strncpy(buf, *inbuf + i, len);
	//char *strncpy(char *dest, const char *src, size_t n)
	//strncpy把src所指向以'\0'结尾的字符串的前n个字符复制到dest所指的数组中，返回指向dest的指针。
	//当n>=sizeof(src)时，拷贝正确，并在dest字符串后面加入'\0';
	//当n<sizeof(src)时，只拷贝src前n-1个字符串到dest，不会为dest字符串后面加入'\0';

	//strncpy支持内存重叠

	buf[len] = '\0';

	inbuf = &buf;
	//strcpy(*outbuf, buf);
	printf("inbuf里面的内容是:[begin]%s[end]\n", *inbuf);
	printf("删除空格后字符串的长度为%d ,字符串内容是:[begin]%s[END]\n ", strlen(buf), buf);

	/////////////////////////////////////////////////////////////
	strcpy(buf, outbuf);
	printf("****************************准备对第二个参数*****************************\n");
	printf("第二个参数outbuf里面的内容是:[begin]%s[end]\n", outbuf);
	printf("buf里面的内容是:[begin]%s[end]\n", buf);

	len = strlen(outbuf);
	j = strlen(outbuf) - 1;
	//左边开始遍历
	i = 0;
	while (isspace(buf[i]) && buf[i] != '\0') {
		i++;
	}

	//右边
	while (isspace(buf[j]) && j > i) {
		j--;
	}

	len = j - i + 1;

	strncpy(buf, outbuf + i, len);
	buf[len] = '\0';
	if (strcmp(outbuf, buf) != 0)
	{
		printf("!!!!!!!!!!!!!!!!采用一级指针,不能够修改字符串数组的内容!!!!!!!!!!!!!!!!\n ");
	}
////////////////////////////////////////////////////////////////////////////////////////////
	printf("outbuf里面的内容是:[begin]%s[end]\n", outbuf);
	printf("删除空格后字符串的长度为%d ,字符串内容是:[begin]%s[END]\n ", strlen(buf), buf);
	

	freeMem(&buf);
	return 0;
}

int getMem(/*out */char** mem1, int* mem_len1)
{
	char* temp_p1 = NULL;
	int len1 = 0;

	if (mem1 == NULL || mem_len1 == NULL ) {
		fprintf(stderr, " (mem1 == NULL || mem_len1 == NULL) \n");
		return -1;
	}
	//len1 = *mem_len1;
	temp_p1 = (char*)malloc(4096);
	if (temp_p1 == NULL) {
		return -1;
	}
	memset(temp_p1, 0, 4096);

	strcpy(temp_p1, "12345678");
	len1 = strlen(temp_p1);

	//以上开辟完空间
	*mem1 = temp_p1;
	*mem_len1 = len1;

	return 0;
}

void freeMem(char** mem)
{
	char* tmem = *mem;
	if (tmem != NULL)
	{
		free(tmem);
	}
	*mem = NULL;

}

//二级指针作为输出参数
//在函数内部 在堆上开辟空间  传出去。
int get_mem(/*out */char** mem1, int* mem_len1, char** mem2, int* mem_len2)
{
	char* temp_p1 = NULL;
	char* temp_p2 = NULL;
	int len1 = 0;
	int len2 = 0;

	if (mem1 == NULL || mem2 == NULL || mem_len1 == NULL || mem_len2 == NULL) {
		fprintf(stderr, " (mem1 == NULL || mem2 == NULL || mem_len1 == NULL || mem_len2 == NULL) \n");
		return -1;
	}

	temp_p1 = (char*)malloc(4096);
	if (temp_p1 == NULL) {
		return -1;
	}
	memset(temp_p1, 0, 4096);

	strcpy(temp_p1, "12345678");
	len1 = strlen(temp_p1);

	temp_p2 = (char*)malloc(4096);
	if (temp_p2 == NULL) {
		return -1;
	}
	memset(temp_p2, 0, 4096);

	strcpy(temp_p2, "abcdefg");
	len2 = strlen(temp_p2);


	//以上开辟完空间

	*mem1 = temp_p1;
	*mem2 = temp_p2;
	*mem_len1 = len1;
	*mem_len2 = len2;

	return 0;
}

void free_mem(char** mem1, char** mem2)
{
	char* temp_mem1 = *mem1;
	char* temp_mem2 = *mem2;

	if (mem1 != NULL) {
		free(temp_mem1);
	}
	if (mem2 != NULL) {
		free(temp_mem2);
	}

	*mem1 = NULL;
	*mem2 = NULL;
}
