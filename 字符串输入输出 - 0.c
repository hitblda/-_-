#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


/*
	1,���õݹ�,��������ַ�,�������
	2,�������齫���ֽ���������ݱ���,Ȼ���������

	ע��,VC/VS �����scanf ���Իس�����Ϊ���������־
	������������Ը��ݲ�ͬͨ��Э���Ҫ����ָ��,����˴���#
*/

int arr[100];
char i = 0;

void print()
{
	char a = 0;
	scanf("%c",&a);
	//arr[i++] = a;
	if (a != '#')
	{
		arr[i++] = a;
		print();
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


void main(void)
{
	printf("������ĸ��������[��#����]\n");
	print();
	printf("\n");
	printf("��ӡ����Ԫ��:\n");
	int num;
	for (num=0;num<i;)
	{
		printf("%c", arr[num++]);
	}

	system("pause");
}