#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//// 指针做函数参数
//int splitStr(const char* str, char* c, char*** mp, int* count)
//{
//	int ret = 0;
//	if (str == NULL || count == NULL)
//	{
//		printf("传递参数异常");
//		ret = -1;
//		return ret;
//	}
//	char** myp = NULL;
//	char* pStr = (char*)str;
//	char* pTmp = (char*)c;
//	int tmpCount = 0;
//	// 第一遍扫描:求出count
//	do {
//		pStr = strrchr(pStr, *c);
//		if (pStr!= NULL)
//		{
//			tmpCount++;
//			pTmp = pStr = pStr + 1;
//		}
//		else
//		{
//			break;
//		}
//	} while (*pStr != '\0');
//	*count = tmpCount;
//	// 分配内存
//	myp = (char**)malloc(sizeof(char*) * tmpCount);
//	if (myp == NULL)
//	{
//		ret = -2;
//		printf("func splitStr err : %d malloc(sizeof(char *) * tmpCount)", ret);
//		goto END;
//	}
//	memset(myp, 0, tmpCount * sizeof(char*));
//
//	// 归位
//	tmpCount = 0;
//	pStr = (char*)str;
//	pTmp = (char*)str;
//	do
//	{
//		pStr= strrchr(pStr, *c);
//		if (pStr!= NULL)
//		{
//			if (pStr- pTmp > 0)
//			{
//				myp[tmpCount] = (char*)malloc(sizeof(char) * (pStr- pTmp + 1));
//				if (myp[tmpCount] == NULL)
//				{
//					ret = -3;
//					printf("func splitStr() err:%d malloc(sizeof(char) * (pStr- pTmp + 1))", ret);
//					goto END;
//				}
//				strncpy(myp[tmpCount], pTmp, pStr- pTmp);
//				myp[tmpCount][pStr- pTmp] = '\0';
//				tmpCount++;
//				pTmp = pStr= pStr+ 1;
//			}
//		}
//		else
//		{
//			break;
//		}
//	} while (*pStr!= '\0');
//
//
//	// 内存分配错误时的错误处理  ,一个入口多个出口,统一地变成一个出口
//	// 在统一的这个出口的地方, 把所有的内存资源释放掉
//END:
//	if (ret != 0) // 失败
//	{
//		int i = 0;
//		if (myp == NULL)
//		{
//			return ret;
//		}
//		for (i = 0; i < tmpCount; i++)
//		{
//			if (myp[i] != NULL)
//			{
//				free(myp[i]);
//			}
//		}
//		free(myp);
//	}
//	else
//	{
//		*mp = myp;   // 成功
//	}
//}
//
//void FreeMem(char** pStr)
//{
//	char* p = NULL;
//	p = *pStr;
//	if (p != NULL)
//	{
//		free(p);
//		*pStr = NULL;
//	}
//
//}
//
//
//
//int  Tmain()
//{
//	char* strP = (char*)"asbdfiawefd,aewferf,tyjufyj,";
//	char** p;
//	char* cTmp = (char*)',';
//	int ret = 0, nCount = 0;
//	int i = 0;
//	ret = splitStr(strP, cTmp, &p, &nCount);
//	if (ret == -1)
//	{
//		printf("func err %d\n", ret);
//		return -1;
//	}
//	// 打印
//	for (i = 0; i < nCount; i++)
//	{
//		printf("%s \n", p[i]);
//	}
//
//	// 释放内存
//	FreeMem(p, nCount);
//
//	system("pause");
//	return 0;
//}
