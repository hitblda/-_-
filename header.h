#pragma once
//#define  _CRT_SECURE_NO_WARNINGS 

#ifndef HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define  ArrayNo 100

#define fastSortFN 
#define QUEEN
//********************�ַ������Ȳ���********************/
int getlength(char* str);
int  charLenTest(char* str);
void StringSw(char* str, int len);   //����ָ����ַ�������洢

//********************������********************/
int FindPos(int* a, int L, int H);
void QuickSort(int* a, int L, int H);
int intInput(int** data);
void fastSort();//����ֵ���ַ������ո�ת���ֺ�,���ֵĸ���

//********************�ַ���ƴ�Ӳ���********************/
int charIO_test2(char** arr);//�ַ�������,�ڱ���������������ڴ�
void strStract(char* str1, char* str2);
int ViolentMatch(char* s, char** p);

//��ȡ��һ������,�ַ���str,�ո���ַ��ĸ�������ӵڶ����������
//����һ�������пո�ȥ��֮��,�ٴӵ�һ����������ȥ
int get_non_space_cnt(/*inout */char** str,/*out*/ int* cnt_p);
//��ȡ��һ������,�ַ���,�޳�ͷβ�Ŀո�,�����ַ���Ŀո�
int trimSpace(char** inbuf, char* outbuf);

int getMem(char** mem, int* len);
void freeMem(char** mem);

int get_mem(/*out */char** mem1, int* mem_len1, char** mem2, int* mem_len2); void free_mem(char** mem1, char** mem2);
void free_mem(char** mem1, char** mem2);

/************************************************************************/
/*			����ָ��                                                    */
/************************************************************************/
char** getMem2Pointer(int num);
void freeMem2Pointer(char** array, int num);
void print2Pointer(char** str, int num);
void sort_array(char** array, int num);
//����ָ��
void getMem3Pointer(char*** myArray, int num);
void freeMem3Pointer(char*** array, int num);

#endif



