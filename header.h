#pragma once

#ifndef HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define  ArrayNo 100

#define fastSortFN 
#define QUEEN
/********************�ַ������Ȳ���********************/
int  charLenTest(char* str);
void StringSw(char* str, int len);   //����ָ����ַ�������洢

/********************������********************/
int FindPos(int* a, int L, int H);
void QuickSort(int* a, int L, int H);
int intInput(int** data);
void fastSort();//����ֵ���ַ������ո�ת���ֺ�,���ֵĸ���

/********************�ַ���ƴ�Ӳ���********************/
int getlength(char* str);
void printStr(const char* str, int length);
void strStract(char* str1, char* str2);

#endif
