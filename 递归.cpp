#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

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



void main(void)
{
	charIO_test();//�ַ�����,���

	system("pause");
} 