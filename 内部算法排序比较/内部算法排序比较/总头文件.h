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

int RandArray[MAXSIZE + 1];		//定义一个随机数数组

void RandomNum(){
	int i;
	// srand()为初始化随机数发生器，用于设置rand()产生随机数时的种子。
	//不显示调用srand()的话，将默认为srand(1)。如果我们设置某个固定的seed，那么虽然在同一次运行时，
	//会有不同的随机数产生，但是对于这段程序的多次运行所得到的结果是不变的
	//srand(2000);
	srand(time(0));
	for (i = 1; i <= MAXSIZE; i++)
		// rand()函数不需要参数，它将会返回0到RAND_MAX之间的任意的整数
		RandArray[i] = (int)rand();					//给随机数数组里存放值
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

void Display(LinkList *L){								//存入文件中
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