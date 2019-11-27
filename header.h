#pragma once
#define  _CRT_SECURE_NO_WARNINGS 

#ifndef HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define  ArrayNo 100

#define fastSortFN 
#define QUEEN
/********************字符串长度测试********************/
int getlength(char* str);
int  charLenTest(char* str);
void StringSw(char* str, int len);   //利用指针对字符串逆序存储

/********************快排序********************/
int FindPos(int* a, int L, int H);
void QuickSort(int* a, int L, int H);
int intInput(int** data);
void fastSort();//返回值是字符串按空格转数字后,数字的个数

/********************字符串拼接查找********************/
int charIO_test2(char** arr);//字符串输入,在被调函数里面分配内存
void strStract(char* str1, char* str2);
int ViolentMatch(char* s, char** p);

//获取第一个参数,字符串str,空格的字符的个数结果从第二个参数输出
//将第一个参数中空格去除之后,再从第一个参数传出去
int get_non_space_cnt(/*inout */char** str,/*out*/ int* cnt_p);

#endif
