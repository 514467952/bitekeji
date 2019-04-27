#

#include<stdio.h>
#include<stdlib.h>



//void swap(int arr[] , int index1, int index2) {
//	int tmp = arr[index1];
//	arr[index1] = arr[index2];
//	arr[index2] = tmp;
//}
//
//
//void heapInsert(int arr[], int value, int index) {		//����в���Ԫ��
//	arr[index] = value;									//��ֵ
//	while (index != 0) {								//�±겻Ϊ0ʱ��Ҳ���Ƕ��в�ֹһ��Ԫ��ʱ�����е���
//		int parent = (index - 1) / 2;					//�ҵ�����㣬
//		if (arr[parent] < arr[index]) {					//���������ֵ�ȴ�������ֵС���н���
//			swap(arr, parent, index);
//			index = parent;								//�±��Ƶ���ǰ�����������±꣬׼����һ�ν���
//		}
//		else {
//			break;										//�����ǰ������ֵ���ڴ�������ֵ�����õ���������ѭ��
//		}
//	}
//
//void  heapify(int arr[], int index�� int heapSize)	{			//��������ѣ�������0��Ҳ��������ĵ�һ���±�Ϳ���
//
//		int left = index * 2 + 1;			//��ǰ�����ӵ��ڵ�ǰ�±�*2+1
//		int right = index * 2 + 2;			//��ǰ���Һ��ӵ��ڵ�ǰ�±�*2+2          
//		int largest = index;				//���赱ǰ���������±�Ϊindex
//
//
//		while (left < heapSize) {			//�������±�С�ڶѵ���󳤶�
//			if (arr[left] > arr[largest]) {		//���Ƚϣ���ǰ���ӵ�ֵ���ڸ����
//				largest = left;					//���������±��Ϊleft
//			}
//			if (right < heapSize && arr[right] > arr[largest]) {	//���С�ڣ���Ҫ���Һ����ǲ��Ǵ���
//				largest = right;									//����ǣ��±���Ϊ�Һ��ӵ��±�
//			}
//			if (largest != index) {							//���������±��������
//				swap(arr, largest, index);					//����н���
//			}
//			else {											//û�䣬������ѭ��
//				break;
//			}
//			index = largest;							//��ǰ���±���Ϊ���������±�
//			left = index * 2 + 1;						//��ǰ�����ӵ��ڵ�ǰ�±�*2+1
//			right = index * 2 + 2;						//��ǰ���Һ��ӵ��ڵ�ǰ�±�*2+2
//		}
//	}


/*
С��
���µ���
array ����Ŀ�ʼλ��
size ����ĳ���
root Ҫ�������±�
*/


void  AdjustDown(int array[], int size, int root)		//���µ���
{
	//�ж�root�Ƿ���Ҷ�ӽ��
	//��Ϊ������ȫ���� ��������û������һ��û���Һ��ӣ�����û����һ����Ҷ�ӽ��
	//����Ϊ����˳��洢
	//���ԣ��ҵ����ӵ��±꣬��������±�Խ���ˣ���û�����ӣ�����һ����Ҷ�ӽ��
	while (1)
	{
		int left = 2 * root + 1;
		if (left >= size){				//�����±������󳤶�ҲԽ��
			//��Ҷ�ӽ��
			return;
		}
		//�ҵ����Һ�����С��һ��
		//һ�������ӣ��ж��Ƿ����Һ���
		int right = 2 * root + 2;
		int min = left;
		if (right < size//���Һ���
			&&array[right] > array[left])//�Һ��ӵ�ֵС������
		{
			min = right;
		}
		//�Ƚ�array��min�� array[root]
		if (array[root] >= array[min])
		{
			return;
		}
		//����ֵ
		int t = array[root];
		array[root] = array[min];
		array[min] = t;
		//�������µ�������min��Ϊ���
		root = min;				//��Ҫѭ��
	}
}

void PrintArray(int array[], int size){    //��ӡ����
	for (int i = 0; i < size; i++){
		printf("%d  ", array[i]);
	}
	printf("\n");
}

/*���ϵ���
array  ����
size   ���鳤��
child  Ҫ���ϵ����Ľ���±�

1.�Ȳ���parent
2.�Ѿ��ǻ���
*/
void AdjustUp(int array[], int size, int child){

	while (1){
		if (child == 0){			//�Ѿ��ǻ���
			return;
		}
		int parent = (child - 1) / 2;			//�ҵ������
		if (array[parent] >= array[child]){			//������childС������Ҫ����
			return;
		}
		int t = array[parent];						//���򣬽���
		array[parent] = array[child];
		array[child] = t;

		child = parent;						//��λ���ж���һ��
	}
}


//�����ĵ�һ����Ҷ�ӽڵ��
//���һ����Ҷ�ӽڵ�=���һ��Ҷ�ӽ���˫�׽�㣨��size-1��-1��/2
//������ʼ������һֱ���������ڵ�������Ϳ��Ե����ɶ�
//��ȷ�Ŀ���O��n�������ԵĿ���O��nlogn��
void CreatHeap(int array[], int size){			//����
	for (int i = (size - 2) / 2; i >= 0; i--){		
		AdjustDown(array, size, i);
	}

}

//������
//���򣬽����
void HeapSort(int array[], int size){

	CreatHeap(array, size);

	//i��ʾ�ҳ����������ĸ���
	for (int i = 0; i < size - 1; i++){
		//ÿ��ѭ�������ҳ�����һ�����ŵ����
		//O(1)
		int t = array[0];
		array[0] = array[size - i - 1];
		array[size - i - 1] = t;

		//�������µ���  ���ݹ�ģ��size-1-i			//����֮�󣬵�����һ�α�һ����i+1
		AdjustDown(array, size - i - 1, 0);
	}
}


void	TestAdjustDown(){			//�������µ���

	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int size = sizeof array / sizeof(int);
	PrintArray(array, size);
	AdjustDown(array, size, 0);   //�������������±��0��ʼ
	PrintArray(array, size);
}


void TestCreatHeap(){				//���Խ���
	int array[] = { 15,37,2,45,63,9,18,7,16,13 };
	int size = sizeof array / sizeof(int);
	PrintArray(array, size);
	CreatHeap(array, size);
	PrintArray(array, size);
}

void TestHeapSort(){

	int array[] = { 39, 129, 12, 38, 27, 9, 33, 2, 14 };
	int size = sizeof array / sizeof(int);

	HeapSort(array, size);
	PrintArray(array, size);
}

#define SIZE  50000
void  TestSortSpeed(){
	int array[SIZE];
	for (int i = 0; i < SIZE; i++){
		array[i] = rand() % 10 * 1000;

	}
	
	HeapSort(array, SIZE);


}

void TopK(int array[], int sizem, int k){
	int *heap = (int *)malloc(sizeof(int)*k);
	for (int i = 0; i < k; i++){
		heap[i] = array[i];
	}
	//��С��
	CreatHeap(heap, k);
	for (int j = k; j < size; j++){
		if (array[j]>heap[0]){			//ֱ�Ӹ�ֵ
			heap[0] = array[j];
			AdjustDown(heap, k, 0);
		}
	}

}