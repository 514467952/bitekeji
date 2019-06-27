#include"×ÜÍ·ÎÄ¼þ.h"

//Ï£¶ûÅÅÐò 
void ShellInsert(LinkList *L, int dk, int *CmpNum, int *ChgNum){
	int i, j;
	RedType Temp;
	for (i = dk; i < L->Length; i++){
		if (LT(L->r[i].key, L->r[i - dk].key, CmpNum)){
			memcpy(&Temp, &L->r[i], sizeof(RedType));
			for (j = i - dk; j >= 0 && LT(Temp.key, L->r[j].key, CmpNum); j -= dk){
				(*ChgNum)++;
				memcpy(&L->r[j + dk], &L->r[j], sizeof(RedType));
			}
			memcpy(&L->r[j + dk], &Temp, sizeof(RedType));
		}
	}
}
void ShellSort(LinkList *L, int dlta[], int t, int *CmpNum, int *ChgNum){
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(L, dlta[k], CmpNum, ChgNum);
}


//¿ìËÙÅÅÐò 
int Partition(LinkList *L, int low, int high, int *CmpNum, int *ChgNum){
	RedType Temp;
	int PivotKey;
	memcpy(&Temp, &L->r[low], sizeof(RedType));
	PivotKey = L->r[low].key;
	while (low < high){
		while (low < high && L->r[high].key >= PivotKey){
			high--;
			(*CmpNum)++;
		}
		(*ChgNum)++;
		memcpy(&L->r[low], &L->r[high], sizeof(RedType));
		while (low < high && L->r[low].key <= PivotKey){
			low++;
			(*CmpNum)++;
		}
		(*ChgNum)++;
		memcpy(&L->r[high], &L->r[low], sizeof(RedType));
	}
	memcpy(&L->r[low], &Temp, sizeof(RedType));
	return low;
}
void QSort(LinkList *L, int low, int high, int *CmpNum, int *ChgNum){
	int PivotLoc = 0;
	if (low < high){
		PivotLoc = Partition(L, low, high, CmpNum, ChgNum);
		QSort(L, low, PivotLoc - 1, CmpNum, ChgNum);
		QSort(L, PivotLoc + 1, high, CmpNum, ChgNum);
	}
}
void QuickSort(LinkList *L, int *CmpNum, int *ChgNum){
	QSort(L, 0, L->Length - 1, CmpNum, ChgNum);
}


//¶ÑÅÅÐò 
void HeapAdjust(LinkList *L, int s, int m, int *CmpNum, int *ChgNum){
	RedType Temp;
	int j = 0;
	s++;
	memcpy(&Temp, &L->r[s - 1], sizeof(RedType));
	for (j = 2 * s; j <= m; j *= 2){
		if (j < m && LT(L->r[j - 1].key, L->r[j].key, CmpNum))
			++j;
		if (!LT(Temp.key, L->r[j - 1].key, CmpNum))
			break;
		(*ChgNum)++;
		memcpy(&L->r[s - 1], &L->r[j - 1], sizeof(RedType));
		s = j;
	}
	memcpy(&L->r[s - 1], &Temp, sizeof(RedType));
}
void HeapSort(LinkList *L, int *CmpNum, int *ChgNum){
	int i = 0;
	RedType Temp;
	for (i = L->Length / 2 - 1; i >= 0; i--)
		HeapAdjust(L, i, L->Length, CmpNum, ChgNum);
	for (i = L->Length; i > 1; i--){
		memcpy(&Temp, &L->r[0], sizeof(RedType));
		(*ChgNum)++;
		memcpy(&L->r[0], &L->r[i - 1], sizeof(RedType));
		memcpy(&L->r[i - 1], &Temp, sizeof(RedType));
		HeapAdjust(L, 0, i - 1, CmpNum, ChgNum);
	}
}


//Ã°ÅÝÅÅÐò 
void BubbleSort(LinkList *L, int *CmpNum, int *ChgNum){
	int i, j;
	RedType temp;
	for (i = 1; i <= MAXSIZE; i++){
		for (j = 1; j <= MAXSIZE - i; j++){
			if (!LT(L->r[j].key, L->r[j + 1].key, CmpNum)){
				(*ChgNum)++;
				memcpy(&temp, &L->r[j], sizeof(RedType));
				memcpy(&L->r[j], &L->r[j + 1], sizeof(RedType));
				memcpy(&L->r[j + 1], &temp, sizeof(RedType));
			}
		}
	}
}
//Ñ¡ÔñÅÅÐò 
int SelectMinKey(LinkList *L, int k, int *CmpNum){
	int Min = k;
	for (; k < L->Length; k++){
		if (!LT(L->r[Min].key, L->r[k].key, CmpNum))
			Min = k;
	}
	return Min;
}
void SelSort(LinkList *L, int *CmpNum, int *ChgNum){
	int i, j;
	RedType temp;
	for (i = 0; i < L->Length; i++){
		j = SelectMinKey(L, i, CmpNum);
		if (i != j){
			(*ChgNum)++;
			memcpy(&temp, &L->r[i], sizeof(RedType));
			memcpy(&L->r[i], &L->r[j], sizeof(RedType));
			memcpy(&L->r[j], &temp, sizeof(RedType));
		}
	}
}