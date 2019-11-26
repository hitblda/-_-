#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define fastSortFN 
#define QUEEN

//////////////////////////////////////////////////////////////////////
/*
	1,���õݹ�,��������ַ�,�������
	2,�������齫���ֽ���������ݱ���,Ȼ���������

	ע��,VC/VS �����scanf ���Իس�����Ϊ���������־
	������������Ը��ݲ�ͬͨ��Э���Ҫ����ָ��,����˴���#

	����,�ַ��� ������ + null character���ַ�,�� \0
	�˴�,���ַ� c �ĸ�ʽ,ͨ���������!
*/

void charInput(int *arr, int& i)
//void charInput(int arr[], int &i) //����,����ҲOK
{
	char a = 0;
	
	scanf("%c", &a);
	//arr[i++] = a;
	if (a != '#')
	{
		arr[i++] = a;
		charInput(arr, i);//��ʱ�����ж��ַ���!!
	}
	else
	{
		arr[i++] = a; //���������־�ֽ�
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

	printf("������ĸ��������[��#����]\n");
	charInput(arr, i);
	printf("\n");
	printf("������%d��Ԫ��\n",i);
	printf("��ӡ����Ԫ��:\n");

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


	//�ַ�����\�ַ��� ���ȵĲ��Գ���
	char str[] = { 1,2,3,4,5,6,7,8,9,'a','b','c' ,'\0'};
	const char* str1 = "Hello World";
	char str2[8] = { 'h' };
	//strlen(str);
	//sizeof(str);
	//printf("strlen(arr)��ֵ��: %d  \n", strlen(arr));
	printf("sizeof(arr)/sizeof(arr[0]);��ֵ��: %d \n", sizeof(arr)/sizeof(arr[0]));
	printf("sizeof(arrDB)/sizeof(arrDB[0]);��ֵ��: %d \n", sizeof(arrDB)/sizeof(arrDB[0]));

	printf("strlen(str)��ֵ��: %d  \n",strlen(str));
	printf("sizeof(str);��ֵ��: %d \n", sizeof(str));

	printf("strlen(str1)��ֵ��: %d  \n", strlen(str1));
	printf("sizeof(str1);��ֵ��: %d \n", sizeof(str1));

}
//////////////////////////////////////////////////////////////////////

//����ָ��ʵ���ַ�����ת
void StringSw(void)
{
	char c;
	int i = 0;
	//char* str = "abcdfg hijklmn";
	char str[]= "abc df";
	int len = strlen(str);
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
	for (i= len;i>0;i--)
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
	for (i=0;i<len;i++)
	{
		printf("%c", p1[i]); 
	}
	printf("\n");
	printf("********************��ӡ����֮����ַ���,ʹ��ָ��p2������*********************\n");
	p2 = str + len - 1;
	for (i = len-1; i >=0; i--)
	{
		printf("%c", *(p2-i));  //�ӵ�һ��Ԫ�ؿ�ʼ
	}
	printf("\n");
}
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
	for ( i = 0; i < length; i++)
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
	printf("pos��ֵ��: %d  \n", L);
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
	printf("ԭʼ�����е�Ԫ����: \n");
	for (i = 0; i < num; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");

	QuickSort(a, 0, num - 1); //ע��,����2\3�������±�ֵ

	printf("\n");
	printf("��������֮�������е�Ԫ����: \n");
	for (i = 0; i < num; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
#endif
//////////////////////////////////////////////////////////////

#ifdef QUEEN
//�˻ʺ�
void EightQueen()
{


}


#endif


void main(void)
{
	//charIO_test();//�ַ�����,���
	//charLenTest();//����\�ַ� ���ȼ���

	StringSw(); //ָ����ַ����������

	//fastSort();  //��������

	system("pause");
} 