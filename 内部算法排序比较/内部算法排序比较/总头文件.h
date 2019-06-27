#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
#include <windows.h> 
#include <winbase.h> 
#define MAXSIZE 5000 
#define TRUE 1 
#define FALSE 0 

typedef int BOOL;   

typedef struct{
	int key;
} RedType;

typedef struct LinkList{
	RedType r[MAXSIZE + 1];
	int Length;
} LinkList;

int RandArray[MAXSIZE + 1];		//����һ�����������

void RandomNum(){
	int i;
	// srand()Ϊ��ʼ�����������������������rand()���������ʱ�����ӡ�
	//����ʾ����srand()�Ļ�����Ĭ��Ϊsrand(1)�������������ĳ���̶���seed����ô��Ȼ��ͬһ������ʱ��
	//���в�ͬ����������������Ƕ�����γ���Ķ���������õ��Ľ���ǲ����
	//srand(2000);
	srand(time(0));
	for (i = 1; i <= MAXSIZE; i++)
		// rand()��������Ҫ�����������᷵��0��RAND_MAX֮������������
		RandArray[i] = (int)rand();					//���������������ֵ
}

void InitLinkList(LinkList *L){
	int i;
	memset(L, 0, sizeof(LinkList));
	RandomNum();
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i];
	L->Length = i;
}
bool LT(int i, int j, int *CmpNum){
	(*CmpNum)++;
	if (i < j)
		return TRUE;
	else
		return FALSE;
}

void Display(LinkList *L){								//�����ļ���
	FILE *f;
	int i;
	if ((f = fopen("SortRes.txt", "w")) == NULL){
		printf("can't open file\n");
		exit(0);
	}
	for (i = 0; i < L->Length; i++)
		fprintf(f, "%d\n", L->r[i].key);
	fclose(f);
}