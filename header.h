#pragma once

#ifndef HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


#define fastSortFN 
#define QUEEN
/********************�ַ������Ȳ���********************/
void  charLenTest();
void StringSw(void);  //����ָ����ַ�������洢

/********************������********************/
int FindPos(int* a, int L, int H);
void QuickSort(int* a, int L, int H);
void fastSort();

/********************�ַ���ƴ�Ӳ���********************/
int getlength(char* str);
void printStr(const char* str, int length);
void strStract(char* str1, char* str2);

#endif
