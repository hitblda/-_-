#include "header.h"

/*********************************************************************************/



/******************************************************************************
*  �ַ�������,�ڱ���������������ڴ�
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

	printf("�����ַ���\n");

//	scanf("%s", *Array); //�����ո��ֹͣ
/*
	���ö��ƽ�����
*/
	scanf("%[^\n]", Array);

	num = strlen(Array);
	if (num > max) // ���*data�Ѿ�����, ��ô�ڴ�����һ��
	{
		Array = (char*)realloc(Array, sizeof(char) * (max *= 2));
	}
	printf("\n");
	//printStr((const char**)Array, num);
	printf("������ַ�����\n");
	printf("[begin]%s[end]\n", Array);

	// ��ͳһ��������ڵĵط�, �����е��ڴ���Դ�ͷŵ�
END:
	if (ret != 0) // ʧ��
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
		*arr = Array;   // �ɹ�
	}

	//if (Array != NULL)
	//{
	//	free(Array);
	//	Array = NULL;
	//}

	return num;
}
/******************************************************************************
*  �ַ���ƴ��
*******************************************************************************/
void strStract(char* str1, char* str2)
{
	/*
		���ַ���str1�ĺ���׷���ַ���str2
	*/
	int str1_len = strlen(str1);
	int str2_len = strlen(str2);

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
/******************************************************************************
*  �ַ���1���Ƿ����ַ���2����
*	����ƥ��
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
			//�������ǰ�ַ�ƥ��ɹ�����S[i] == P[j]������i++��j++    
			i++;
			j++;
		}
		else
		{
			//�����ʧ�䣨��S[i]! = P[j]������i = i - (j - 1)��j = 0    
			i = i - j + 1;
			j = 0;
		}
	}
	//ƥ��ɹ�������ģʽ��p���ı���s�е�λ�ã����򷵻�-1
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
	//printf("��Ҫ����Ŀռ��СΪ: %d\n", strlen(*str));
	//tmp = (char*)malloc(strlen(*str));
	//if (tmp == NULL)
	//{
	//	return -1;
	//}

	////q = *str + strlen(*str) - 1; //ָ���ַ�����ĩβԪ��
	////��߱���
	////while ((*p == ' ' && *p !='\0')  ) {

	//k = *str;//ָ���ַ�����Ԫ��

	//while (*k != '\0')  //��ͷ��β
	//{
	//	if (isspace(*k))
	//	{
	//		cnt++;  //ͳ�ƿո�ĸ���
	//	}
	//	else   //�ǿո�ʹ�����ʱָ��
	//	{
	//		tmp[len++] = *k;
	//	}

	//	k++;
	//}
	//if (cnt > 0)
	//{
	//	tmp[len] = '\0'; // ����µ��ַ������ȱ��,��ô��Ҫ��'\0'
	//}

	//*cnt_p = cnt;
	////ȥ���ո�����ַ���
	//*str = tmp;

	char* tmp = NULL;

	int len = 0;
	int cnt = 0;

	if (str == NULL || cnt_p == NULL) {
		fprintf(stderr, " str == NULL || cnt_p == NULL \n");
		return -1;
	}
	printf("��Ҫ����Ŀռ��СΪ: %d\n", strlen(*str));
	len = strlen(*str);
	if(getMem(&tmp, &len)<0)
	{
		return -1;
	}

	//��߱���
	//while ((*p == ' ' && *p !='\0')  ) {
	strcpy(tmp, *str); //�����ݸ��ƹ���
	printf("���ƹ�����������:[begin]%s[end]\n", tmp);
	len = 0;
	while (**str != '\0')  //��ͷ��β
	{
		if (isspace(**str))
		{
			cnt++;  //ͳ�ƿո�ĸ���
		}
		else   //�ǿո�ʹ�����ʱָ��
		{
			tmp[len++] = **str;
		}

		(*str)++; //means:(*str)++;
	}
	if (cnt > 0)
	{
		tmp[len] = '\0'; // ����µ��ַ������ȱ��,��ô��Ҫ��'\0'
	}

	*cnt_p = cnt;
	//ȥ���ո�����ַ���
//	*str = tmp;
	strcpy(*str, tmp); //�����ݸ��ƹ���

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
	printf("****************************׼���Ե�һ������*****************************\n");
	printf("��һ������inbuf�����������:[begin]%s[end]\n", *inbuf);
	strcpy(buf, *inbuf);
	printf("buf�����������:[begin]%s[end]\n", buf);

	j = strlen(*inbuf) - 1;

	//��߿�ʼ����
	while (isspace(buf[i]) && buf[i] != '\0') {
		i++;
	}

	//�ұ�
	while (isspace(buf[j]) && j > i) {
		j--;
	}

	len = j - i + 1;

	strncpy(buf, *inbuf + i, len);
	//char *strncpy(char *dest, const char *src, size_t n)
	//strncpy��src��ָ����'\0'��β���ַ�����ǰn���ַ����Ƶ�dest��ָ�������У�����ָ��dest��ָ�롣
	//��n>=sizeof(src)ʱ��������ȷ������dest�ַ����������'\0';
	//��n<sizeof(src)ʱ��ֻ����srcǰn-1���ַ�����dest������Ϊdest�ַ����������'\0';

	//strncpy֧���ڴ��ص�

	buf[len] = '\0';

	inbuf = &buf;
	//strcpy(*outbuf, buf);
	printf("inbuf�����������:[begin]%s[end]\n", *inbuf);
	printf("ɾ���ո���ַ����ĳ���Ϊ%d ,�ַ���������:[begin]%s[END]\n ", strlen(buf), buf);

	/////////////////////////////////////////////////////////////
	strcpy(buf, outbuf);
	printf("****************************׼���Եڶ�������*****************************\n");
	printf("�ڶ�������outbuf�����������:[begin]%s[end]\n", outbuf);
	printf("buf�����������:[begin]%s[end]\n", buf);

	len = strlen(outbuf);
	j = strlen(outbuf) - 1;
	//��߿�ʼ����
	i = 0;
	while (isspace(buf[i]) && buf[i] != '\0') {
		i++;
	}

	//�ұ�
	while (isspace(buf[j]) && j > i) {
		j--;
	}

	len = j - i + 1;

	strncpy(buf, outbuf + i, len);
	buf[len] = '\0';
	if (strcmp(outbuf, buf) != 0)
	{
		printf("!!!!!!!!!!!!!!!!����һ��ָ��,���ܹ��޸��ַ������������!!!!!!!!!!!!!!!!\n ");
	}
////////////////////////////////////////////////////////////////////////////////////////////
	printf("outbuf�����������:[begin]%s[end]\n", outbuf);
	printf("ɾ���ո���ַ����ĳ���Ϊ%d ,�ַ���������:[begin]%s[END]\n ", strlen(buf), buf);
	

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

	//���Ͽ�����ռ�
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

//����ָ����Ϊ�������
//�ں����ڲ� �ڶ��Ͽ��ٿռ�  ����ȥ��
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


	//���Ͽ�����ռ�

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
