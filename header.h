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
int getlength(char* str);
int  charLenTest(char* str);
void StringSw(char* str, int len);   //����ָ����ַ�������洢

/********************������********************/
int FindPos(int* a, int L, int H);
void QuickSort(int* a, int L, int H);
int intInput(int** data);
void fastSort();//����ֵ���ַ������ո�ת���ֺ�,���ֵĸ���

/********************�ַ���ƴ�Ӳ���********************/
int charIO_test2(char** arr);//�ַ�������,�ڱ���������������ڴ�
void strStract(char* str1, char* str2);
int ViolentMatch(char* s, char** p);

#endif
