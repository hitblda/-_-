#include "header.h"


/************************************************************************/
/*		                  �ݹ���ַ�������                              */
/************************************************************************/
/*
	1,���õݹ�,��������ַ�,�������
	2,�������齫���ֽ���������ݱ���,Ȼ���������

	ע��,VC/VS �����scanf ���Իس�����Ϊ���������־
	������������Ը��ݲ�ͬͨ��Э���Ҫ����ָ��,����˴���#
	//�޸�Ϊ���������� ## Ϊ������־,��ASCII��Ϊ0x23 

	����,�ַ��� ������ + null character���ַ�,�� \0
	�˴�,���ַ� c �ĸ�ʽ,ͨ���������!
*/

//void charInput(char* arr, int& i)
////void charInput(int arr[], int &i) //����,����ҲOK
//{
//	char a = 0;
//
//	scanf("%c", &a);
//	//arr[i++] = a;
//	if (a != '#')
//	{
//		arr[i++] = a;
//		charInput(arr, i);//��ʱ�����ж��ַ���!!
//	}
//	else
//	{
//		arr[i++] = a; //���������־�ֽ�
//	}
//
//	if (a != '#')
//	{
//		printf("%c", a);
//	}
//}
void charInput(char* arr, int& i)
{
	char a = 0;
	static char flag = 0;

	scanf("%[^\n]", arr);
	getchar(); //getchar��������ʶ��ո�ͻس����������Խ��س����յ���
	//fflush(stdin);
	//arr[i++] = a;
	//if (flag ==1 )   //�Ѿ��յ�һ��#,���յ�һ��#ʱ
	//{
	//	if (a != '#')
	//	{
	//		flag = 0;
	//		charInput(arr, i);//��ʱ�����ж��ַ���!!
	//	}
	//	flag = 0;
	//} 
	//else
	//{
	//	if (a == '#')
	//	{
	//		flag = 1;
	//	}
	//	charInput(arr, i);//��ʱ�����ж��ַ���!!
	//}
	i = strlen(arr);
}

void charIO_test(char * arr, int& i)
{

	printf("�����ַ���[��##����]\n");
	charInput(arr, i);
	printf("\n");
	printf("�ַ�����%d��Ԫ��\n", i);
	printf("��ӡ�ַ���Ԫ��:\n");

	int num;
	for (num = 0; num < i;)
	{
		printf("%c", arr[num++]);
	}
	printf("\n");
}

/////////////////////////////////////////////////////////////


int main(void)
{
#if 0
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* ���ڲ�������������ջ�����ڴ�,�����һ���ַ���,
   �����������Զѷ����ڴ�,����ڶ����ַ���,
   Ȼ��,�ڵ�һ�ַ�������Ѱ���Ƿ��еڶ��ַ�������
*/
/************************************************************************/
	unsigned int lenStr = 0;

	int num[ArrayNo] = {0};
	char *arr =(char *)num;  //
	char* A;
/************************************************************************/
/*	��ͼ:���ַ�������,		                                            */
/*�������ASCIIֵ �Կո��Ϊ���� ���浽����,�Խ�������                  */
/************************************************************************/

	int i = 0,k=0;
	printf("******************************************************\n");
	charIO_test(arr,i);//�ַ�����,���
	printf("�����ַ�������i��ֵ��: %d\n", i);

	lenStr = charLenTest(arr);//����\�ַ� ���ȼ���
	printf("lenStr = charLenTest(arr) ��ֵ��:  %d\n", lenStr);
	
	//�����ӡ,���򱣴����
	//StringSw(arr,lenStr);

	printf("��������һ�ַ���[�����ж������һ���Ƿ����֮]: \n");
	k =	charIO_test2(&A);
	printf("*********************�ص�������*********************\n");
	printf("�ڶ���������ַ�����\n");
	printf("%s\n", A);
	printf("������ַ���������:  %d\n", k);
	printf("*********************��ʼ���ַ�������*********************\n");
	i= ViolentMatch(arr, &A);
	if (i==-1)
	{
		printf("*********************����ʧ��!!*********************\n");
	} 
	else
	{
		printf("*********************���ҳɹ�!!********************\n");
		printf("��arr�ַ�����%dλ���ҵ��ַ���A����! \n",i);
	}

	if (A != NULL)
	{
		free(A);
		A = NULL;
	}
#endif

#if 0
	//��������,����������������ַ���
	fastSort();  
#endif

#if 0

	char* str = (char*)" 1     8 10 c ef      25 ";
	int len = 0, cnt = 0;
	len = strlen(str);
	printf("���ⳤ��Ϊ%d ���ַ�����: %s\n", len, str);
	get_non_space_cnt(&str, &cnt);

	printf("�����ַ����пո��ַ��ĸ�����: cnt = %d\n", cnt);
	printf("ɾ���ո���ַ����ĳ���Ϊ%d �ַ���������: %s\n ", len - cnt, str);

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}

#endif

#if 0
	char* buf1 = NULL;
	char* buf2 = NULL;
	char* buf3 = NULL;
	int len1 = 0;
	int len2 = 0;
	int len3 = 0;


	if (get_mem(&buf1, &len1, &buf2, &len2) < 0) {
		return -1;
	}
	printf("buf1: %s, buf2:%s\n", buf1, buf2);
	free_mem(&buf1, &buf2);

	if (getMem(&buf3, &len3) < 0) {
		return -1;
	}
	printf("buf3: %s\n", buf3);
	freeMem(&buf3);

#endif

#if 0
	/************************************************************************/
	/*          һ��ָ����÷�:���� ;����ָ����÷�:�ش�                    */
	/************************************************************************/

	char* str = (char *)" 1     8 10 c ef      25   ";
	char tmp[1024];
	char* key = NULL;

	int len=0,cnt = 0;
	len = strlen(str);
//	printf("������ַ�����: %s����Ϊ%d \n" ,str, len);

	getMem(&key, &len);
	printf("��̬�����˶��Ŀռ�:%d\n",len);
	//getMem(&tmp, &len);
	//strcpy(key, str);  //����ı��ļ�
	//memcpy(tmp, str, len);
	printf("�����������ַ�:\n");
	scanf("%[^\n]",tmp);
	getchar(); //getchar��������ʶ��ո�ͻس����������Խ��س����յ���

	cnt = strlen(tmp);
	printf("һ��������%d���ַ�:\n",cnt);

	strcpy(key, (char*)&tmp);  //����ı��ļ�
	printf("���ƹ�����������:[begin]%s[end]\n", key);
	len = strlen(tmp);
	get_non_space_cnt(&key, &cnt);//ͨ������ָ��ı�ԭʼֵ,������
	printf("�����ַ����пո��ַ��ĸ�����: cnt = %d\n", cnt);
	printf("ɾ���ո���ַ����ĳ���Ϊ%d �ַ���������:[begin]%s[end]\n", len - cnt, key);

	printf("������ַ�����:[begin]%s[end]����Ϊ%d \n", str, len);
	len = trimSpace(&str, tmp); //һά�ַ������� ȡ��ַ =?=> �����ַ���ָ�� 

//	freeMem(&key);

#endif

#if 0
	/************************************************************************/
	/*                       ����ָ����÷�����                             */
	/************************************************************************/

	char** my_array = NULL;
	int num = 5;
	my_array = getMem2Pointer(num);
	if (my_array ==NULL)
	{
		fprintf(stderr, "my_array ==NULL");
		return -1;
	}
	print2Pointer(my_array, num);
	sort_array(my_array,num);
	print2Pointer(my_array,num);
 
	freeMem2Pointer(my_array, num);



#endif

#if 1


	/************************************************************************/
	/*                              ����ָ��                                */
	/************************************************************************/
	char** my_array = NULL;
	int num = 5;
	getMem3Pointer(&my_array, num);
	    
	//print2Pointer(my_array, num);
	//sort_array(my_array, num);
	//print2Pointer(my_array, num);

	freeMem3Pointer(&my_array, num);

#endif

 	system("pause");
	return 0;
}