#pragma once

#ifndef HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


#define fastSortFN 
#define QUEEN
/********************字符串长度测试********************/
void  charLenTest();
void StringSw(void);  //利用指针对字符串逆序存储

/********************快排序********************/
int FindPos(int* a, int L, int H);
void QuickSort(int* a, int L, int H);
void fastSort();

/********************字符串拼接查找********************/
int getlength(char* str);
void printStr(const char* str, int length);
void strStract(char* str1, char* str2);

#endif
