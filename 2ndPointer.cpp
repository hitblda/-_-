#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//// ָ������������
//int splitStr(const char* str, char* c, char*** mp, int* count)
//{
//	int ret = 0;
//	if (str == NULL || count == NULL)
//	{
//		printf("���ݲ����쳣");
//		ret = -1;
//		return ret;
//	}
//	char** myp = NULL;
//	char* pStr = (char*)str;
//	char* pTmp = (char*)c;
//	int tmpCount = 0;
//	// ��һ��ɨ��:���count
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
//	// �����ڴ�
//	myp = (char**)malloc(sizeof(char*) * tmpCount);
//	if (myp == NULL)
//	{
//		ret = -2;
//		printf("func splitStr err : %d malloc(sizeof(char *) * tmpCount)", ret);
//		goto END;
//	}
//	memset(myp, 0, tmpCount * sizeof(char*));
//
//	// ��λ
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
//	// �ڴ�������ʱ�Ĵ�����  ,һ����ڶ������,ͳһ�ر��һ������
//	// ��ͳһ��������ڵĵط�, �����е��ڴ���Դ�ͷŵ�
//END:
//	if (ret != 0) // ʧ��
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
//		*mp = myp;   // �ɹ�
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
//	// ��ӡ
//	for (i = 0; i < nCount; i++)
//	{
//		printf("%s \n", p[i]);
//	}
//
//	// �ͷ��ڴ�
//	FreeMem(p, nCount);
//
//	system("pause");
//	return 0;
//}
