#include "header.h"

/************************************************************************/
/* 
实现2个API

1.以逗号分隔,形成一个二维数组 (==>在栈上),并把结果传出来;
	把二维数组行数运算结果也传出来;

2.以逗号分隔,形成一个二级指针 (=>堆上);
把一共拆分成多少行字符串的个数传出来

*/
/************************************************************************/

int splitStr(char* str, char ch, char arr[][10], int* cnt)
/************************************************************************/
/* 
	第一个参数是:输入的字符串;
	第二个参数是:要查找的字符;
	第三个参数是:输入字符串被划分的字符数组
	第四个参数是:字符数组的个数
*/
/************************************************************************/
{
	if (str == NULL||arr ==NULL||cnt ==NULL )
	{
		fprintf(stderr, "str == NULL||arr ==NULL||cnt ==NULL\n");
		return -1;
	}
	char* p = str;
	char* q = p;
	int cnt_p = 0;
	int len_p = 0;
	//在一个字符串里面查找字符,成功就返回第一个字符的地址
	//char *pointer =strchr(母串s,子串c);
	//查找字符串s中首次出现字符c的位置,返回首次出现c的位置的指针，如果s中不存在c则返回NULL

	
	while ((strchr(p, ch) != NULL))  //找到该字符
	{
		p = strchr(p, ch);  //找到该字符
		printf("查找到的内容是%c\n", *p);

		strncpy(arr[cnt_p],q, p-q);
		//strncpy(char *dest, const char *src, size_t n);
		//会将字符串src前n个字符拷贝到字符串dest,但不追加'\0'不同于strcpy会追加'\0'
		arr[cnt_p][p - q] = '\0'; 
		printf("被复制过来的内容是%s\n", arr[cnt_p]);

		p++;//p指向下一个,开始下一阶段的遍历 
		q = p;  //使q同步到p,方便下次遍历
		cnt_p++;

	//	printf("p当前指向的内容是%c\n", *p);
		if (*p == '\0') break;
	}
	//针对最后一个阶段
	if (*q != '\0')
	{
		len_p = str + strlen(str) - q;

/*
		while (len_p--)
		{
			printf("p当前指向的内容是%c\n", p[len_p]);
		}

		while (len_p--)
		{
			printf("q当前指向的内容是%c", *q++);
		}
*/
		strncpy(arr[cnt_p], q,len_p);
		printf("arr当前指向的内容是%c\n", *(arr+cnt_p)[0]);
		printf("arr当前指向的内容是%c\n", arr[cnt_p][0]);
		arr[cnt_p][len_p] = '\0';
		printf("被复制过来的内容是%s\n", arr+cnt_p);
		printf("被复制过来的内容是%s\n", arr[cnt_p]);
		cnt_p++;
	}

	*cnt = cnt_p;
	//cnt = &cnt_p;  //这样值居然传不出来
	return 0;
}

int splitStrStack(char* str, char ch, char ***arrP, int* cnt)
/************************************************************************/
/*
	第一个参数是:输入的字符串;
	第二个参数是:要查找的字符;
	第三个参数是:输入字符串被划分的字符串数组指针
	第四个参数是:字符数组的个数
*/
/************************************************************************/
{
	if (str == NULL || arrP == NULL || cnt == NULL)
	{
		fprintf(stderr, "str == NULL||arrP ==NULL||cnt ==NULL\n");
		return -1;
	}
	char* p = str;
	char* q = p;
	int cnt_p = 0;
	int len_p = 0;
	char** array = NULL;
	int str_len = 0;
	/************************************************************************/
	/*                
		1.根据拆分的个数,在堆上面开辟确定个数的指针数组;
		2.每个指针数组,分配空间
	*/
	/************************************************************************/
	while ((p = strchr(p, ch)) != NULL) //找到该字符
	{
		//printf("查找到的内容是%c\n", *p);
		cnt_p++;  //字符串数组多少个

		p++;//p指向下一个,开始下一阶段的遍历 
		q = p;  //使q同步到p,方便下次遍历
		if (*p == '\0') break;
	}
	if (*q != '\0')
	{
		cnt_p++;
	}
	/************************************************************************/
	/* 二级指针分配空间,分配的时候就必须是确定数                                                                     */
	/************************************************************************/
	array = (char**)malloc(sizeof(char*) * cnt_p);
	if (array == NULL )
	{
		fprintf(stderr, "malloc array == NULL\n");
		return -1;
	}

	p = str; 
	q = p;
	cnt_p = 0;
	while ((p=strchr(p, ch)) != NULL)
	{
		/************************************************************************/
		/* 找到一个开辟一个,开辟的长度多少?根据该字符串里面的字符个数           */
		/*		                    尤其注意,长度!!                         	*/
		/************************************************************************/
		str_len = p -q +1;
		array[cnt_p] = (char*)malloc(sizeof(char) * (str_len + 1));
		strncpy(array[cnt_p], q, p - q);   //
		//strncpy(char *dest, const char *src, size_t n);
		//会将字符串src前n个字符拷贝到字符串dest,但不追加'\0'不同于strcpy会追加'\0'
		array[cnt_p][p - q] = '\0';
		printf("第%d次被复制过来的内容是%s\n", cnt_p,array[cnt_p]);

		p++;//p指向下一个,开始下一阶段的遍历 
		q = p;  //使q同步到p,方便下次遍历
		cnt_p++;

		if (*p == '\0') break;
	}
	//针对最后一个阶段
	if (*q != '\0')
	{
		/************************************************************************/
		/*					开辟空间!! 根据该字符串里面的字符个数		         */
		/*		                    尤其注意,长度!!                         	*/
		/************************************************************************/
		len_p = str + strlen(str) - q;
		array[cnt_p] = (char*)malloc(sizeof(char)*(len_p+1));//

		//strncpy(*array+cnt_p, q, len_p);   //错误!!!
		//strncpy(*(array+cnt_p), q, len_p);  //OK
		strncpy(array[cnt_p], q, len_p);  
		printf("被复制过来的内容是%s\n", *(array + cnt_p));
		printf("array当前指向的内容是%c\n", array[cnt_p][0]);
		printf("array当前指向的内容是%c\n", array[cnt_p][len_p-2]);
		printf("array当前指向的内容是%c\n", *(*(array + cnt_p)) );
		printf("array当前指向的内容是%c\n", *(*(array + cnt_p)+1));
		printf("array当前指向的内容是%c\n", *(*(array + cnt_p)+2));

/*
		printf("array当前指向的内容是%c\n", array[cnt_p][len_p]);//超出范围!!打印出未知内容
*/

		printf("array当前指向的内容是%c\n", array[cnt_p][0]); //二级字符串指针没有这种表达式
		array[cnt_p][len_p] = '\0';
	//(*(array+cnt_p)+len_p) = '\0';

		printf("被复制过来的内容是%s\n", *(array + cnt_p));
		printf("被复制过来的内容是%s\n", array[cnt_p]);
		cnt_p++;

	}

	*cnt = cnt_p;
	*arrP = array;
	return 0;
}




