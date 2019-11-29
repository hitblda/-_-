#include "header.h"

char** getMem2Pointer(int num)
{
	char** array = NULL;
	array = (char**)malloc(sizeof(char*)*num);
	//����num��char*���͵�ָ��,��,ָ������array[0]~array[num-1]
	if (array==NULL)
	{
		fprintf(stderr, "malloc char ** array error\n");
		return NULL; 
	}
	memset(array, 0, sizeof(char*)*num);
	for (int i=0;i<num;i++)
	{
		array[i] = (char*)malloc(64); //
		if (array[i]==NULL)
		{
			fprintf(stderr, "malloc array[%d] error\n",i);
			return NULL;
		}
		//�����ݳ�ʼ��,��ֵ
		memset(array[i], 0, 64);
		sprintf(array[i], "%d%d%d%d%d ",9-i,9-i,9-i,9-i,9-i);
	}
	return array;
}

void freeMem2Pointer(char** array, int num)
{
	int i = 0;
	if (array == NULL)
	{
		return;
	}
	char** tmem = array;

	for (i = 0; i < num; i++)
	{
		if (tmem[i] != NULL)
		{
			free(tmem[i]);
			tmem[i] = NULL;
		}
	}

	freeMem(tmem);
	array = NULL; //ʹ����ָ��ĵ�ַΪ0
}

void print2Pointer(char** str, int num)
{
	int i = 0;
	for (i=0;i<num;i++)
	{
		printf("%s\n", str[i]);
		//printf("%s\n", *(str+i));  //����дҲ��
	}
}

void sort_array(char** array,int num)
{
	int i = 0, j = 0;
	char* tmp = NULL; 

	for (i=0;i<num;i++)
	{
		for (j=i;j<num;j++)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
}

/************************************************************************/
/*                               ����ָ��                               */
/************************************************************************/
void getMem3Pointer(char*** myArray, int num)
{
	char** array = NULL;
	if (myArray == NULL)
	{
		return;
	}
	array = (char**)malloc(sizeof(char*) * num);
	//����num��char*���͵�ָ��,��,ָ������array[0]~array[num-1]
	if (array == NULL)
	{
		fprintf(stderr, "malloc char ** array error\n");
		return;
	}
	memset(array, 0, sizeof(char*) * num);
	for (int i = 0; i < num; i++)
	{
		array[i] = (char*)malloc(64); //
		if (array[i] == NULL)
		{
			fprintf(stderr, "malloc array[%d] error\n", i);
			return;
		}
		//�����ݳ�ʼ��,��ֵ
		memset(array[i], 0, 64);
		sprintf(array[i], "%d%d%d%d%d ", 9 - i, 9 - i, 9 - i, 9 - i, 9 - i);
	}
	myArray = &array;
}

void freeMem3Pointer(char*** array_p, int num)
{
	int i = 0;
	if (array_p == NULL)
	{
		return;
	}
	char** array = *array_p;

	for (i = 0; i < num; i++)
	{
		if (array[i] != NULL)  //�ͷ�һ�����ַ���
		{
			free(array[i]);
			array[i] = NULL;
		}
	}

	freeMem(array);		//�ͷ��ַ�������
	*array_p = NULL; //ʹ����ָ�������,������ָ��ĵ�ַΪNULL (0)
}


void print3Pointer(char** str, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", str[i]);
		//printf("%s\n", *(str+i));  //����дҲ��
	}
}

void sort_array3(char** array, int num)
{
	int i = 0, j = 0;
	char* tmp = NULL;

	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
}