#include<stdio.h>
#include"test.h"
#include<string.h>
#include<stdlib.h>
#include<assert.h>
void PrintArray(int *array, int size){			//��ӡ����
	for (int i = 0; i < size; i++){
		printf("%  d", array[i]);
	}
	printf("\n");
}

//void Swap(int *pLeft, int *pRight){			//��������	
//	int temp = *pLeft;
//	*pLeft = *pRight;
//	*pRight = temp;
//
//}
//int  Partion3(int *array, int left, int right){
//	int key = array[right - 1];
//	int cur = left;
//	int pre = cur - 1;
//	while (cur < right){
//		if (array[cur] < key&&	++pre != cur)
//			Swap(&array[cur], &array[pre]);
//		cur++;
//	}
//	if (++pre != right - 1){
//		Swap(&array[++pre], &array[right - 1]);
//		return pre;
//	}
//
//
//}
////�ǵݹ��������
//void QuickSortNor(int *array, int size)
//{
//	int left = 0;
//	int right = size;
//
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, right);	//��ѹջ�ұ�
//	StackPush(&s, left);		//�����
//
//	while (!StackEmpty(&s))
//	{
//		left = StackTop(&s);
//		StackPop(&S);
//		right = StackTop(&S);
//		StackPop(&s);
//		if (left < right){
//			int div = Partion3(array, left, right);
//			StackPush(&s,right);		//�ȱ����Ҳ�
//			StackPush(&s, div + 1);			//�ٱ����Ұ벿��������
//
//			StackPush(&s, div);				//������ұ߽�
//			StackPush(&s, left);			//�������߽�
//			//��׼ֵ�����[left,div)
//			//��׼ֵ���Ҳ�[div+1,right)
//		}
//	}
//	StackDestroy(&s);
//}

void MergeData(int *array, int left, int mid, int right, int tmp[]){		//�������������У��ϳ�һ����������	����ҿ�
	int begin1 = left, endl = mid;
	int begin2 = mid, end2 = right;
	int index = left;

	while (begin1<endl&&begin2<end2)
	{
		if (array[begin1] < array[begin2]){
			tmp[index++] = array[begin1++];
		}
		else{
			tmp[index++] = array[begin2++];
		}
	}
	
	while (begin1<endl){						//��һ������û����
		tmp[index++] = array[begin1++];
	}
	while (begin2<end2){						//�ڶ�������û����
		tmp[index++] = array[begin2++];
	}

}

void _MergeSort(int *array, int left, int right,int *tmp){
	if (right - left>1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(array, left, mid,tmp);
		_MergeSort(array, mid, right,tmp);
		MergeData(array, left, mid, right, tmp);
		memcpy(array + left, tmp + left, sizeof(array[left] * (right - left)));
	}
}
void MergeSort(int *array, int size){
	int *tmp = (int *)malloc(size*sizeof(array[0]));
	if (NULL == tmp)
	{
		assert(0);
		return;
	}

	_MergeSort(array, 0, size, tmp);
	free(tmp);
}

void MergeSortNor(int *array, int size){				//�ǵݹ�鲢����
	int *tmp = (int *)malloc(size*sizeof(array[0]));
	if (NULL == tmp)
	{
		assert(0);
		return;
	}
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap){
			int left = i;
			int mid = left;
			int right = mid + gap;
			if (mid >= size){
				mid = size;
			}
			if (right >= size){
				right = size;
			}
			MergeData(array, left, mid, right, tmp);
		}
		memcpy(array, tmp, sizeof(array[0] * size));
		gap *= 2;
	}
	free(tmp);
}

//��������
void CountSort(int *array, int size){
	//�ҷ�Χ
	int minVal = array[0];
	int maxVal = array[0];
	for (int i = 1; i < size; ++i){
		if (array[i] < minVal)
			minVal = array[i];

		if (array[i]>maxVal)
			maxVal = array[i];
	}
	//���㱣������Ŀռ�
	int range = maxVal - minVal + 1;
	int *temp = (int *)malloc(sizeof(int)*range);
	if (NULL == temp){
		assert(0);
		return;
	}
	//������ռ��������Ԫ����Ϊ0
	memset(temp, 0, sizeof(int)*range);

	//ͳ��ÿ�����ݳ��ֵĴ���
	for (int i = 0; i < size; ++i){
		temp[array[i]-minVal]++;
	}

	//����
	int index = 0;
	for (int i = 0; i < range; ++i){
		while (temp[i]){
			array[index++] = i + minVal;
		}
	}
	free(temp);
}


int main(){

	int array[] = { 3, 2, 5, 8, 4, 7, 6, 9 };

	PrintArray(array, sizeof(array) / sizeof(int));

	CountSort(array, sizeof(array) / sizeof(int));
	PrintArray(array, sizeof(array) / sizeof(int));



	system("pause");
	return 0;
}