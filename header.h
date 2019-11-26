#pragma once

#ifndef HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define  ArrayNo 100

#define fastSortFN 
#define QUEEN
/********************字符串长度测试********************/
int  charLenTest(char* str);
void StringSw(char* str, int len);   //利用指针对字符串逆序存储

/********************快排序********************/
int FindPos(int* a, int L, int H);
void QuickSort(int* a, int L, int H);
int intInput(int** data);
void fastSort();//返回值是字符串按空格转数字后,数字的个数

/********************字符串拼接查找********************/
int getlength(char* str);
void printStr(const char* str, int length);
void strStract(char* str1, char* str2);

#endif
