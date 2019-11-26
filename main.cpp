#include "header.h"

///////////////////////////递归的字符串逆序////////////////////////////////
/*
	1,利用递归,将输入的字符,逆序输出
	2,利用数组将按字节输入的数据保存,然后正序输出

	注意,VC/VS 里面的scanf 是以回车键作为输入结束标志
	而代码里面可以根据不同通信协议的要求来指定,比如此处的#

	另外,字符串 是数组 + null character空字符,即 \0
	此处,以字符 c 的格式,通过数组输出!
*/

void charInput(int* arr, int& i)
//void charInput(int arr[], int &i) //或者,这样也OK
{
	char a = 0;

	scanf("%c", &a);
	//arr[i++] = a;
	if (a != '#')
	{
		arr[i++] = a;
		charInput(arr, i);//此时串口中断又发生!!
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

void charIO_test(void)
{
	int arr[100];
	int i = 0;

	printf("输入字母或者数字[以#结束]\n");
	charInput(arr, i);
	printf("\n");
	printf("数组有%d个元素\n", i);
	printf("打印数组元素:\n");

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
	charIO_test();//字符输入,输出

	//charLenTest();//数组\字符 长度计算
	StringSw();

	//fastSort();  //快速排序

	system("pause");
}