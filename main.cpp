#include "header.h"

///////////////////////////�ݹ���ַ�������////////////////////////////////
/*
	1,���õݹ�,��������ַ�,�������
	2,�������齫���ֽ���������ݱ���,Ȼ���������

	ע��,VC/VS �����scanf ���Իس�����Ϊ���������־
	������������Ը��ݲ�ͬͨ��Э���Ҫ����ָ��,����˴���#

	����,�ַ��� ������ + null character���ַ�,�� \0
	�˴�,���ַ� c �ĸ�ʽ,ͨ���������!
*/

void charInput(int* arr, int& i)
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
	printf("������%d��Ԫ��\n", i);
	printf("��ӡ����Ԫ��:\n");

	int num;
	for (num = 0; num < i;)
	{
		printf("%c", arr[num++]);
	}
	printf("\n");
}

/////////////////////////////////////////////////////////////


void main(void)
{
	charIO_test();//�ַ�����,���

	//charLenTest();//����\�ַ� ���ȼ���
	StringSw();

	//fastSort();  //��������

	system("pause");
}