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
*  �ַ�������,�ڱ���������������ڴ�
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
	printf("%s\n", Array);

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
	char* k = NULL;

	char* tmp = NULL;

	int len = 0;
	int cnt = 0;

	if (str == NULL || cnt_p == NULL) {
		fprintf(stderr, " str == NULL || cnt_p == NULL \n");
		return -1;
	}
	printf("��Ҫ����Ŀռ��СΪ: %d\n", strlen(*str));
	tmp = (char*)malloc(strlen(*str));
	if (tmp == NULL)
	{
		return -1;
	}

	//q = *str + strlen(*str) - 1; //ָ���ַ�����ĩβԪ��
	//��߱���
	//while ((*p == ' ' && *p !='\0')  ) {

	k = *str;//ָ���ַ�����Ԫ��

	while (*k != '\0')  //��ͷ��β
	{
		if (isspace(*k))
		{
			cnt++;  //ͳ�ƿո�ĸ���
		} 
		else   //�ǿո�ʹ�����ʱָ��
		{
			tmp[len++] = *k;
		}
		
		k++;
	}
	if (cnt>0)
	{
		tmp[len] = '\0'; // ����µ��ַ������ȱ��,��ô��Ҫ��'\0'
	}
	 
	*cnt_p = cnt;
	//ȥ���ո�����ַ���
	*str = tmp;

	return 0;
}