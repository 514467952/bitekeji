#include<stdio.h>
#include"test.h"
#include<string.h>
#include<stdlib.h>
#include<assert.h>
void PrintArray(int *array, int size){			//打印函数
	for (int i = 0; i < size; i++){
		printf("%  d", array[i]);
	}
	printf("\n");
}

//void Swap(int *pLeft, int *pRight){			//交换函数	
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
////非递归快速排序
//void QuickSortNor(int *array, int size)
//{
//	int left = 0;
//	int right = size;
//
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, right);	//先压栈右边
//	StackPush(&s, left);		//再左边
//
//	while (!StackEmpty(&s))
//	{
//		left = StackTop(&s);
//		StackPop(&S);
//		right = StackTop(&S);
//		StackPop(&s);
//		if (left < right){
//			int div = Partion3(array, left, right);
//			StackPush(&s,right);		//先保存右侧
//			StackPush(&s, div + 1);			//再保存右半部分左区间
//
//			StackPush(&s, div);				//左半侧的右边界
//			StackPush(&s, left);			//左半侧的左边界
//			//基准值的左侧[left,div)
//			//基准值的右侧[div+1,right)
//		}
//	}
//	StackDestroy(&s);
//}

void MergeData(int *array, int left, int mid, int right, int tmp[]){		//把两个有序序列，合成一个有序序列	左闭右开
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
	
	while (begin1<endl){						//第一个数组没搬完
		tmp[index++] = array[begin1++];
	}
	while (begin2<end2){						//第二个数组没搬完
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

void MergeSortNor(int *array, int size){				//非递归归并排序
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

//计数排序
void CountSort(int *array, int size){
	//找范围
	int minVal = array[0];
	int maxVal = array[0];
	for (int i = 1; i < size; ++i){
		if (array[i] < minVal)
			minVal = array[i];

		if (array[i]>maxVal)
			maxVal = array[i];
	}
	//计算保存计数的空间
	int range = maxVal - minVal + 1;
	int *temp = (int *)malloc(sizeof(int)*range);
	if (NULL == temp){
		assert(0);
		return;
	}
	//把申请空间里的所有元素置为0
	memset(temp, 0, sizeof(int)*range);

	//统计每个数据出现的次数
	for (int i = 0; i < size; ++i){
		temp[array[i]-minVal]++;
	}

	//回收
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