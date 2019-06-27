#define _CRT_SECURE_NO_WARNINGS

#include"����.h"


void SelectSort(){
	printf("1. ���Բ�������\n");
	printf("2. ����ϣ������\n");
	printf("3. ���Կ�������\n");
	printf("4. ���Զ�����\n");
	printf("5. ����ð������\n");
	printf("6. ����ѡ������\n");
	printf("7. ����������������ʽ\n");
	printf("8. �˳�����\n\n");
	printf("��������Ҫִ�е�ѡ��:\n");
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
		L->r[i].key = RandArray[i]; //������и�λ 


	printf("\n��������:\n");
	TempTime = (int)GetTickCount();
	ShellSort(L, Indata, 1, &CmpNum[0], &ChgNum[0]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n", CmpNum[0],
		ChgNum[0], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //������и�λ 


	printf("\nϣ������:\n");
	TempTime = (int)GetTickCount();
	ShellSort(L, dlta, 3, &CmpNum[1], &ChgNum[1]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n", CmpNum[1],
		ChgNum[1], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //������и�λ 


	printf("\n��������:\n");
	TempTime = (int)GetTickCount();
	QuickSort(L, &CmpNum[2], &ChgNum[2]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n", CmpNum[2],
		ChgNum[2], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //������и�λ 


	printf("\n������:\n");
	TempTime = (int)GetTickCount();
	HeapSort(L, &CmpNum[3], &ChgNum[3]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n", CmpNum[3],
		ChgNum[3], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //������и�λ 


	printf("\nð������:\n");
	TempTime = (int)GetTickCount();
	BubbleSort(L, &CmpNum[4], &ChgNum[4]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n", CmpNum[4],
		ChgNum[4], SpendTime);
	for (i = 1; i <= MAXSIZE; i++)
		L->r[i].key = RandArray[i]; //������и�λ 


	printf("\nѡ������:\n");
	TempTime = (int)GetTickCount();
	SelSort(L, &CmpNum[5], &ChgNum[5]);
	SpendTime = (int)GetTickCount() - TempTime;
	printf("\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n", CmpNum[5],
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
			L.r[i].key = RandArray[i]; //������и�λ 
		scanf("%d", &select);
		switch (select){
		case 1:
			printf("\n��������:\n");
			TempTime = (int)GetTickCount();
			ShellSort(&L, Indata, 1, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 2:
			printf("\nϣ������:\n");
			TempTime = (int)GetTickCount();
			ShellSort(&L, dlta, 3, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 3:
			printf("\n��������:\n");
			TempTime = (int)GetTickCount();
			QuickSort(&L, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 4:
			printf("\n������:\n");
			TempTime = (int)GetTickCount();
			HeapSort(&L, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t\t���ѵ�ʱ��=%dms\n", CmpNum[select],
				ChgNum[select], SpendTime);
			break;
		case 5:
			printf("\nð������:\n");
			TempTime = (int)GetTickCount();
			BubbleSort(&L, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 6:
			printf("\nѡ������:\n");
			TempTime = (int)GetTickCount();
			SelSort(&L, &CmpNum[select], &ChgNum[select]);
			SpendTime = (int)GetTickCount() - TempTime;
			for (i = 1; i <= MAXSIZE; i++){
				printf("%5d ", L.r[i].key);
				if (++j % 10 == 0)printf("\n");
			}
			printf("\n\n�ؼ��ֵıȽϴ���=%d\t�ؼ����ƶ�����=%d\t���ѵ�ʱ��=%dms\n",
				CmpNum[select], ChgNum[select], SpendTime);
			break;
		case 7:
			AllAbove(&L, CmpNum, ChgNum);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (select != 8);
	Display(&L);
}


