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

#if 0
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

#if 0
	char* str = (char*)"!@#$%,FGHHH,H@@@JKUY,T&**9,Aha";
	/************************************************************************/
	/*                       ջ���濪�� ,�ַ������                         */
	/************************************************************************/
	char arr[5][10]; //��һά��:�ж��ٸ���,�ڶ���ά��:ÿ�����������ж��ٸ��ַ�
	int cnt = 0;
	int ret = 0;
	int i = 0,j=0;

	printf("ԭʼ�ַ�����\n%s\n", (str + i));
//	printf("\n");
	ret = splitStr(str,',',arr,&cnt);
	if (ret<0)
	{
		fprintf(stderr, "splitStr error\n");
		return -1;
	}
	printf("���ֵ����������%d\n", cnt);

	for (i = 0;i<cnt;i++)
	{
		printf("��%d���ַ������������%s\n",i, arr[i]);

		cnt = strlen(arr[i]);
		j = 0;
		while (j<cnt)
		{
			printf("arr[%d]�е�%d���ַ���%c\n",j, i, arr[i][j]);
			j++;
		}

	}
#endif	
#if 0
	char* str = (char*)"!@#$%,FGHHH,H@@@JKUY,T&**9,Aha";
	/************************************************************************/
	/*                       �����濪�� ,�ַ������                         */
	/************************************************************************/
	char** array = NULL;
	int cnt = 0;
	int ret = 0;
	int i = 0, j = 0;

	printf("ԭʼ�ַ�����\n%s\n", (str + i));
	//	printf("\n");
	ret = splitStrStack(str, ',', &array, &cnt);
	if (ret < 0)
	{
		fprintf(stderr, "splitStr error\n");
		return -1;
	}
	printf("���ֵ����������%d\n", cnt);

	for (i = 0; i < cnt; i++)
	{
		printf("��%d���ַ������������%s\n", i, array[i]);

		cnt = strlen(array[i]);
		j = 0;
		while (j < cnt)
		{
			printf("array[%d]�е�%d���ַ���%c\n", i, j, array[i][j]);
			j++;
		}
	}

	freeMem3Pointer(&array, cnt);

#endif

#if 0
	/************************************************************************/
	/*                     ��\��ά����,����������                           */
	/************************************************************************/

	u32 b = 0;
	int a[3][5] = { 0 };
	int c[4][5][6];

	typedef int(ARRAY_INT_10)[10]; //ARRAY_INT_10 �� int[10]�ı���
	ARRAY_INT_10 B;  //�൱��int b[10]

/*
	makeArray(a);
	printArray(a);*/

	printf("**********��ʼ��ά����**********************\n");
	makeArray3(c,4,5,6);
	printArray3(c, 4, 5, 6);

#endif

#if 0
	/************************************************************************/
	/*                          �ַ�������                                  */
	/************************************************************************/
	const char* keyWords[] = {
	"while",
	"case",
	"static",
	"do",
	"Love"
	};

	int pos = 0;
	const char* key = "Lover";
	int num = sizeof(keyWords)/sizeof(*keyWords);


	int i = 0;
	for (i=0;i<num;i++)
	{
		printf(" keyWords[%d]��ֵ��%s\n", i, keyWords[i]);
	}

	SearchKey(keyWords,num, key, &pos);
	if (pos < 0)
	{
		printf("û�ҵ���@^@ָ���ؼ���%s!!!!!\n", key);
	}
	else
		printf("�ҵ���ָ���ؼ���%s��%d\n", key, pos);
#endif

#if 0
/************************************************************************/
/*                          �ṹ�����ݴ���                              */
/************************************************************************/
	
	struct teacher tp1 = { 0 }; //��ջ�Ͽ��ٵ�һ��teacher�ṹ��
	struct teacher tp2 = { 0 };

	tp1.id = 1;
	tp1.name = (char*)malloc(sizeof(char)*NAME_LEN);
	memset(tp1.name, 0, sizeof(char) * NAME_LEN);
/*
	strcpy(tp1.name, "zhang3");
*/
	printf("������ṹ������������:");
	scanf("%s", tp1.name);
	printf("\n������ṹ����������ֵ:");
	scanf("%d",&tp1.id);
	printf("�ṹ��tp1�е�������:\n");
	print_teacher(tp1);

	//copy_teacher(&tp2, &tp1);
	copy_teacher_deep(&tp2, &tp1);
	printf("�ṹ��tp2�е�������:\n");

	print_teacher(tp2);

	if (tp1.name != NULL) {
		free(tp1.name);
		tp1.name = NULL;
	}

	if (tp2.name != NULL) {
		free(tp2.name);
		tp2.name = NULL;
	}
#endif
	
#if 1

	/************************************************************************/
	/*						  ��ṹ����Ԫ�ص�ƫ�Ƶ�ַ			            */
	/************************************************************************/
	struct teacher t1 = { 0 }; //��ջ�Ͽ��ٵ�һ��teacher�ṹ��
	int id = t1.id;
	const char* name = "asdfasf";

	int offset1 = 0, offset2 = 0, offset3 = 0, offset4 = 0, offset5 = 0;

	offset1 = (int) & (((struct teacher*)0)->id);
	offset2 = (int) & (((struct teacher*)0)->name);
	offset3 = (int) & (((struct teacher*)0)->tName);
	offset4 = (int) & (((struct teacher*)0)->p1); 
	offset5 = sizeof(t1);
	printf("�ṹ��������t1.idƫ��ֵ����:%d\n",offset1);
	printf("�ṹ��������t1.nameƫ��ֵ����:%d\n", offset2);
	printf("�ṹ��������t1.tNameƫ��ֵ����:%d\n", offset3);
	printf("�ṹ��������t1.p1ƫ��ֵ����:%d\n", offset4);
	printf("�ṹ���ܳ���ֵ����:%d\n", offset5);
	printf("*******************************************");
	printf("\n�ṹ��������t1.idռ�õĿռ�:");
	printf("%d\n", offset2 - offset1);
	printf("�ṹ��������t1.nameռ�õĿռ�:");
	printf("%d\n", offset3 - offset2);
	printf("�ṹ��������t1.tNameռ�õĿռ�:");
	printf("%d\n", offset4 - offset3);
	printf("�ṹ��������t1.p1ƫ��ֵ����:");
	printf("%d\n", offset5 - offset4);



#endif

 	system("pause");
	return 0;
}