#define _CRT_SECURE_NO_WARNINGS

#include"排序.h"


void SelectSort(){
	printf("1. 测试插入排序\n");
	printf("2. 测试希尔排序\n");
	printf("3. 测试快速排序\n");
	printf("4. 测试堆排序\n");
	printf("5. 测试冒泡排序\n");
	printf("6. 测试选择排序\n");
	printf("7. 测试以上所有排序方式\n");
	printf("8. 退出程序\n\n");
	printf("请输入你要执行的选择:\n");
}
void AllAbove(LinkList *L, int *CmpNum, int *ChgNum){
	int TempTime, i, j;
	int SpendTime;
	int dlta[3] = {
		7, 3, 1
	};
	int Indata[1] = {
		1
	};
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //随机数列复位 


	printf("\n插入排序:\n");
	TempTime = (int)GetTickCount();
	ShellSort(L, Indata, 1, &CmpNum[0], &ChgNum[0]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n", CmpNum[0],
		ChgNum[0], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //随机数列复位 


	printf("\n希尔排序:\n");
	TempTime = (int)GetTickCount();
	ShellSort(L, dlta, 3, &CmpNum[1], &ChgNum[1]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n", CmpNum[1],
		ChgNum[1], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //随机数列复位 


	printf("\n快速排序:\n");
	TempTime = (int)GetTickCount();
	QuickSort(L, &CmpNum[2], &ChgNum[2]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n", CmpNum[2],
		ChgNum[2], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //随机数列复位 


	printf("\n堆排序:\n");
	TempTime = (int)GetTickCount();
	HeapSort(L, &CmpNum[3], &ChgNum[3]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n", CmpNum[3],
		ChgNum[3], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //随机数列复位 


	printf("\n冒泡排序:\n");
	TempTime = (int)GetTickCount();
	BubbleSort(L, &CmpNum[4], &ChgNum[4]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n", CmpNum[4],
		ChgNum[4], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //随机数列复位 


	printf("\n选择排序:\n");
	TempTime = (int)GetTickCount();
	SelSort(L, &CmpNum[5], &ChgNum[5]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n", CmpNum[5],
		ChgNum[5], SpendTime);
}
void main(){
	int i, j;
	int select = 0;
	int dlta[3] = { 7, 3, 1 };
	int Indata[1] = { 1 };
	int CmpNum[8], ChgNum[8];
	int SpendTime = 0;
	int TempTime;
	LinkList L;
	InitLinkList(&L);
	memset(CmpNum, 0, sizeof(CmpNum));
	memset(ChgNum, 0, sizeof(ChgNum));
	do{
		SelectSort();
		for (i = 0; i < MAXSIZE; i++)
			L.r[i].key = RandArray[i]; //随机数列复位 
		scanf("%d", &select);
		switch (select){
		case 1:
			printf("\n插入排序:\n");
			TempTime = (int)GetTickCount();
			ShellSort(&L, Indata, 1, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 2:
			printf("\n希尔排序:\n");
			TempTime = (int)GetTickCount();
			ShellSort(&L, dlta, 3, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 3:
			printf("\n快速排序:\n");
			TempTime = (int)GetTickCount();
			QuickSort(&L, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 4:
			printf("\n堆排序:\n");
			TempTime = (int)GetTickCount();
			HeapSort(&L, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n关键字的比较次数=%d\t关键字移动次数=%d\t\t花费的时间=%dms\n", CmpNum[select],
				ChgNum[select], SpendTime);
			break;
		case 5:
			printf("\n冒泡排序:\n");
			TempTime = (int)GetTickCount();
			BubbleSort(&L, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 6:
			printf("\n选择排序:\n");
			TempTime = (int)GetTickCount();
			SelSort(&L, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n关键字的比较次数=%d\t关键字移动次数=%d\t花费的时间=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 7:
			AllAbove(&L, CmpNum, ChgNum);
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (select != 8);
	Display(&L);
}


