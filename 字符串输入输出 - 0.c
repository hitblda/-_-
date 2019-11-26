#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


/*
	1,利用递归,将输入的字符,逆序输出
	2,利用数组将按字节输入的数据保存,然后正序输出

	注意,VC/VS 里面的scanf 是以回车键作为输入结束标志
	而代码里面可以根据不同通信协议的要求来指定,比如此处的#
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
		arr[i++] = a; //保存结束标志字节
	}

	if (a != '#')
	{		
		printf("%c", a);
	}	

}


void main(void)
{
	printf("输入字母或者数字[以#结束]\n");
	print();
	printf("\n");
	printf("打印数组元素:\n");
	int num;
	for (num=0;num<i;)
	{
		printf("%c", arr[num++]);
	}

	system("pause");
}