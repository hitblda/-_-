#include "header.h"


/************************************************************************/
/*		                  递归的字符串逆序                              */
/************************************************************************/
/*
	1,利用递归,将输入的字符,逆序输出
	2,利用数组将按字节输入的数据保存,然后正序输出

	注意,VC/VS 里面的scanf 是以回车键作为输入结束标志
	而代码里面可以根据不同通信协议的要求来指定,比如此处的#
	//修改为连续的两个 ## 为结束标志,其ASCII码为0x23 

	另外,字符串 是数组 + null character空字符,即 \0
	此处,以字符 c 的格式,通过数组输出!
*/

//void charInput(char* arr, int& i)
////void charInput(int arr[], int &i) //或者,这样也OK
//{
//	char a = 0;
//
//	scanf("%c", &a);
//	//arr[i++] = a;
//	if (a != '#')
//	{
//		arr[i++] = a;
//		charInput(arr, i);//此时串口中断又发生!!
//	}
//	else
//	{
//		arr[i++] = a; //保存结束标志字节
//	}
//
//	if (a != '#')
//	{
//		printf("%c", a);
//	}
//}
void charInput(char* arr, int& i)
{
	char a = 0;
	static char flag = 0;

	scanf("%[^\n]", arr);
	getchar(); //getchar函数可以识别空格和回车，用它可以将回车吸收掉。
	//fflush(stdin);
	//arr[i++] = a;
	//if (flag ==1 )   //已经收到一个#,再收到一个#时
	//{
	//	if (a != '#')
	//	{
	//		flag = 0;
	//		charInput(arr, i);//此时串口中断又发生!!
	//	}
	//	flag = 0;
	//} 
	//else
	//{
	//	if (a == '#')
	//	{
	//		flag = 1;
	//	}
	//	charInput(arr, i);//此时串口中断又发生!!
	//}
	i = strlen(arr);
}

void charIO_test(char * arr, int& i)
{

	printf("输入字符串[以##结束]\n");
	charInput(arr, i);
	printf("\n");
	printf("字符串有%d个元素\n", i);
	printf("打印字符串元素:\n");

	int num;
	for (num = 0; num < i;)
	{
		printf("%c", arr[num++]);
	}
	printf("\n");
}

/////////////////////////////////////////////////////////////

int main(void)
{
#if 0
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* 用于测试主函数中以栈分配内存,输入第一串字符串,
   被调函数中以堆分配内存,输入第二串字符串,
   然后,在第一字符串里面寻找是否有第二字符串出现
*/
/************************************************************************/
	unsigned int lenStr = 0;

	int num[ArrayNo] = {0};
	char *arr =(char *)num;  //
	char* A;
/************************************************************************/
/*	意图:以字符串输入,		                                            */
/*将输入的ASCII值 以空格键为区分 保存到数组,以进行排序                  */
/************************************************************************/

	int i = 0,k=0;
	printf("******************************************************\n");
	charIO_test(arr,i);//字符输入,输出
	printf("输入字符串个数i的值是: %d\n", i);

	lenStr = charLenTest(arr);//数组\字符 长度计算
	printf("lenStr = charLenTest(arr) 的值是:  %d\n", lenStr);
	
	//逆序打印,逆序保存输出
	//StringSw(arr,lenStr);

	printf("请再输入一字符串[用于判断上面的一串是否包含之]: \n");
	k =	charIO_test2(&A);
	printf("*********************回到主函数*********************\n");
	printf("第二次输入的字符串是\n");
	printf("%s\n", A);
	printf("输入的字符串长度是:  %d\n", k);
	printf("*********************开始两字符串查找*********************\n");
	i= ViolentMatch(arr, &A);
	if (i==-1)
	{
		printf("*********************查找失败!!*********************\n");
	} 
	else
	{
		printf("*********************查找成功!!********************\n");
		printf("在arr字符串的%d位置找到字符串A出现! \n",i);
	}

	if (A != NULL)
	{
		free(A);
		A = NULL;
	}
#endif

#if 0
	//快速排序,需针对整数不能是字符串
	fastSort();  
#endif

#if 0

	char* str = (char*)" 1     8 10 c ef      25 ";
	int len = 0, cnt = 0;
	len = strlen(str);
	printf("被测长度为%d 的字符串是: %s\n", len, str);
	get_non_space_cnt(&str, &cnt);

	printf("被测字符串中空格字符的个数是: cnt = %d\n", cnt);
	printf("删除空格后字符串的长度为%d 字符串内容是: %s\n ", len - cnt, str);

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}

#endif

#if 0
	char* buf1 = NULL;
	char* buf2 = NULL;
	char* buf3 = NULL;
	int len1 = 0;
	int len2 = 0;
	int len3 = 0;


	if (get_mem(&buf1, &len1, &buf2, &len2) < 0) {
		return -1;
	}
	printf("buf1: %s, buf2:%s\n", buf1, buf2);
	free_mem(&buf1, &buf2);

	if (getMem(&buf3, &len3) < 0) {
		return -1;
	}
	printf("buf3: %s\n", buf3);
	freeMem(&buf3);

#endif

#if 0
	/************************************************************************/
	/*          一级指针的用法:输入 ;二级指针的用法:回传                    */
	/************************************************************************/

	char* str = (char *)" 1     8 10 c ef      25   ";
	char tmp[1024];
	char* key = NULL;

	int len=0,cnt = 0;
	len = strlen(str);
//	printf("被测的字符串是: %s长度为%d \n" ,str, len);

	getMem(&key, &len);
	printf("动态分配了多大的空间:%d\n",len);
	//getMem(&tmp, &len);
	//strcpy(key, str);  //针对文本文件
	//memcpy(tmp, str, len);
	printf("请输入若干字符:\n");
	scanf("%[^\n]",tmp);
	getchar(); //getchar函数可以识别空格和回车，用它可以将回车吸收掉。

	cnt = strlen(tmp);
	printf("一共输入了%d个字符:\n",cnt);

	strcpy(key, (char*)&tmp);  //针对文本文件
	printf("复制过来的内容是:[begin]%s[end]\n", key);
	len = strlen(tmp);
	get_non_space_cnt(&key, &cnt);//通过二级指针改变原始值,传出来
	printf("被测字符串中空格字符的个数是: cnt = %d\n", cnt);
	printf("删除空格后字符串的长度为%d 字符串内容是:[begin]%s[end]\n", len - cnt, key);

	printf("被测的字符串是:[begin]%s[end]长度为%d \n", str, len);
	len = trimSpace(&str, tmp); //一维字符串数组 取地址 =?=> 二级字符串指针 

//	freeMem(&key);

#endif

#if 0
	/************************************************************************/
	/*                       二级指针的用法测试                             */
	/************************************************************************/

	char** my_array = NULL;
	int num = 5;
	my_array = getMem2Pointer(num);
	if (my_array ==NULL)
	{
		fprintf(stderr, "my_array ==NULL");
		return -1;
	}
	print2Pointer(my_array, num);
	sort_array(my_array,num);
	print2Pointer(my_array,num);
 
	freeMem2Pointer(my_array, num);

#endif

#if 0
	/************************************************************************/
	/*                              三级指针                                */
	/************************************************************************/
	char** my_array = NULL;
	int num = 5;
	getMem3Pointer(&my_array, num);
	    
	//print2Pointer(my_array, num);
	//sort_array(my_array, num);
	//print2Pointer(my_array, num);

	freeMem3Pointer(&my_array, num);

#endif

#if 0
	char* str = (char*)"!@#$%,FGHHH,H@@@JKUY,T&**9,Aha";
	/************************************************************************/
	/*                       栈上面开辟 ,字符串拆分                         */
	/************************************************************************/
	char arr[5][10]; //第一维度:有多少个串,第二个维度:每个串最多可以有多少个字符
	int cnt = 0;
	int ret = 0;
	int i = 0,j=0;

	printf("原始字符串是\n%s\n", (str + i));
//	printf("\n");
	ret = splitStr(str,',',arr,&cnt);
	if (ret<0)
	{
		fprintf(stderr, "splitStr error\n");
		return -1;
	}
	printf("划分的数组个数是%d\n", cnt);

	for (i = 0;i<cnt;i++)
	{
		printf("第%d个字符数组的内容是%s\n",i, arr[i]);

		cnt = strlen(arr[i]);
		j = 0;
		while (j<cnt)
		{
			printf("arr[%d]中的%d个字符是%c\n",j, i, arr[i][j]);
			j++;
		}

	}
#endif	
#if 0
	char* str = (char*)"!@#$%,FGHHH,H@@@JKUY,T&**9,Aha";
	/************************************************************************/
	/*                       堆上面开辟 ,字符串拆分                         */
	/************************************************************************/
	char** array = NULL;
	int cnt = 0;
	int ret = 0;
	int i = 0, j = 0;

	printf("原始字符串是\n%s\n", (str + i));
	//	printf("\n");
	ret = splitStrStack(str, ',', &array, &cnt);
	if (ret < 0)
	{
		fprintf(stderr, "splitStr error\n");
		return -1;
	}
	printf("划分的数组个数是%d\n", cnt);

	for (i = 0; i < cnt; i++)
	{
		printf("第%d个字符数组的内容是%s\n", i, array[i]);

		cnt = strlen(array[i]);
		j = 0;
		while (j < cnt)
		{
			printf("array[%d]中的%d个字符是%c\n", i, j, array[i][j]);
			j++;
		}
	}

	freeMem3Pointer(&array, cnt);

#endif

#if 0
	/************************************************************************/
	/*                     二\三维数组,做函数参数                           */
	/************************************************************************/

	u32 b = 0;
	int a[3][5] = { 0 };
	int c[4][5][6];

	typedef int(ARRAY_INT_10)[10]; //ARRAY_INT_10 是 int[10]的别名
	ARRAY_INT_10 B;  //相当于int b[10]

/*
	makeArray(a);
	printArray(a);*/

	printf("**********开始三维数组**********************\n");
	makeArray3(c,4,5,6);
	printArray3(c, 4, 5, 6);

#endif

#if 0
	/************************************************************************/
	/*                          字符串查找                                  */
	/************************************************************************/
	const char* keyWords[] = {
	"while",
	"case",
	"static",
	"do",
	"Love"
	};

	int pos = 0;
	const char* key = "Lover";
	int num = sizeof(keyWords)/sizeof(*keyWords);


	int i = 0;
	for (i=0;i<num;i++)
	{
		printf(" keyWords[%d]的值是%s\n", i, keyWords[i]);
	}

	SearchKey(keyWords,num, key, &pos);
	if (pos < 0)
	{
		printf("没找到了@^@指定关键字%s!!!!!\n", key);
	}
	else
		printf("找到了指定关键字%s在%d\n", key, pos);
#endif

#if 0
/************************************************************************/
/*                          结构体数据处理                              */
/************************************************************************/
	
	struct teacher tp1 = { 0 }; //在栈上开辟的一个teacher结构体
	struct teacher tp2 = { 0 };

	tp1.id = 1;
	tp1.name = (char*)malloc(sizeof(char)*NAME_LEN);
	memset(tp1.name, 0, sizeof(char) * NAME_LEN);
/*
	strcpy(tp1.name, "zhang3");
*/
	printf("请输入结构体内数据名字:");
	scanf("%s", tp1.name);
	printf("\n请输入结构体内数据数值:");
	scanf("%d",&tp1.id);
	printf("结构体tp1中的内容是:\n");
	print_teacher(tp1);

	//copy_teacher(&tp2, &tp1);
	copy_teacher_deep(&tp2, &tp1);
	printf("结构体tp2中的内容是:\n");

	print_teacher(tp2);

	if (tp1.name != NULL) {
		free(tp1.name);
		tp1.name = NULL;
	}

	if (tp2.name != NULL) {
		free(tp2.name);
		tp2.name = NULL;
	}
#endif
	
#if 1

	/************************************************************************/
	/*						  求结构体中元素的偏移地址			            */
	/************************************************************************/
	struct teacher t1 = { 0 }; //在栈上开辟的一个teacher结构体
	int id = t1.id;
	const char* name = "asdfasf";

	int offset1 = 0, offset2 = 0, offset3 = 0, offset4 = 0, offset5 = 0;

	offset1 = (int) & (((struct teacher*)0)->id);
	offset2 = (int) & (((struct teacher*)0)->name);
	offset3 = (int) & (((struct teacher*)0)->tName);
	offset4 = (int) & (((struct teacher*)0)->p1); 
	offset5 = sizeof(t1);
	printf("结构体内数据t1.id偏移值计算:%d\n",offset1);
	printf("结构体内数据t1.name偏移值计算:%d\n", offset2);
	printf("结构体内数据t1.tName偏移值计算:%d\n", offset3);
	printf("结构体内数据t1.p1偏移值计算:%d\n", offset4);
	printf("结构体总长度值计算:%d\n", offset5);
	printf("*******************************************");
	printf("\n结构体内数据t1.id占用的空间:");
	printf("%d\n", offset2 - offset1);
	printf("结构体内数据t1.name占用的空间:");
	printf("%d\n", offset3 - offset2);
	printf("结构体内数据t1.tName占用的空间:");
	printf("%d\n", offset4 - offset3);
	printf("结构体内数据t1.p1偏移值计算:");
	printf("%d\n", offset5 - offset4);



#endif

 	system("pause");
	return 0;
}