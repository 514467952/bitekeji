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
//void heapInsert(int arr[], int value, int index) {		//向堆中插入元素
//	arr[index] = value;									//赋值
//	while (index != 0) {								//下标不为0时，也就是堆中不止一个元素时，进行调整
//		int parent = (index - 1) / 2;					//找到父结点，
//		if (arr[parent] < arr[index]) {					//如果父结点的值比传进来的值小进行交换
//			swap(arr, parent, index);
//			index = parent;								//下表移到当前子树父结点的下标，准备下一次交换
//		}
//		else {
//			break;										//如果当前父结点的值大于传进来的值，不用调整，跳出循环
//		}
//	}
//
//void  heapify(int arr[], int index， int heapSize)	{			//创建大根堆，传进来0，也就是数组的第一个下标就可以
//
//		int left = index * 2 + 1;			//当前的左孩子等于当前下标*2+1
//		int right = index * 2 + 2;			//当前的右孩子等于当前下标*2+2          
//		int largest = index;				//假设当前最大的数的下标为index
//
//
//		while (left < heapSize) {			//当左孩子下标小于堆的最大长度
//			if (arr[left] > arr[largest]) {		//作比较，当前左孩子的值大于父结点
//				largest = left;					//最大的数的下标变为left
//			}
//			if (right < heapSize && arr[right] > arr[largest]) {	//如果小于，就要看右孩子是不是大于
//				largest = right;									//如果是，下标置为右孩子的下标
//			}
//			if (largest != index) {							//最大的数的下标如果变了
//				swap(arr, largest, index);					//则进行交换
//			}
//			else {											//没变，则跳出循环
//				break;
//			}
//			index = largest;							//当前的下标置为最大的数的下标
//			left = index * 2 + 1;						//当前的左孩子等于当前下标*2+1
//			right = index * 2 + 2;						//当前的右孩子等于当前下标*2+2
//		}
//	}


/*
小堆
向下调整
array 数组的开始位置
size 数组的长度
root 要调整的下标
*/


void  AdjustDown(int array[], int size, int root)		//向下调整
{
	//判断root是否是叶子结点
	//因为堆是完全二叉 数，所以没有左孩子一定没有右孩子，所以没左孩子一定是叶子结点
	//又因为堆是顺序存储
	//所以，找到左孩子的下标，如果左孩子下标越界了，则没有左孩子，所以一定是叶子结点
	while (1)
	{
		int left = 2 * root + 1;
		if (left >= size){				//数组下标等于最大长度也越界
			//是叶子结点
			return;
		}
		//找到左右孩子最小的一个
		//一定又左孩子，判断是否有右孩子
		int right = 2 * root + 2;
		int min = left;
		if (right < size//有右孩子
			&&array[right] > array[left])//右孩子的值小于左孩子
		{
			min = right;
		}
		//比较array【min】 array[root]
		if (array[root] >= array[min])
		{
			return;
		}
		//交换值
		int t = array[root];
		array[root] = array[min];
		array[min] = t;
		//继续向下调整，以min作为结点
		root = min;				//需要循环
	}
}

void PrintArray(int array[], int size){    //打印函数
	for (int i = 0; i < size; i++){
		printf("%d  ", array[i]);
	}
	printf("\n");
}

/*向上调整
array  数组
size   数组长度
child  要向上调整的结点下标

1.比不过parent
2.已经登基了
*/
void AdjustUp(int array[], int size, int child){

	while (1){
		if (child == 0){			//已经登基了
			return;
		}
		int parent = (child - 1) / 2;			//找到父结点
		if (array[parent] >= array[child]){			//父结点比child小，则不需要调整
			return;
		}
		int t = array[parent];						//否则，交换
		array[parent] = array[child];
		array[child] = t;

		child = parent;						//移位，判断下一个
	}
}


//倒数的第一个非叶子节点的
//最后一个非叶子节点=最后一个叶子结点的双亲结点（（size-1）-1）/2
//子树开始调整，一直调整到根节点的树，就可以调整成堆
//精确的看成O（n），粗略的看成O（nlogn）
void CreatHeap(int array[], int size){			//建堆
	for (int i = (size - 2) / 2; i >= 0; i--){		
		AdjustDown(array, size, i);
	}

}

//堆排序
//升序，建大堆
void HeapSort(int array[], int size){

	CreatHeap(array, size);

	//i表示找出的最大的数的个数
	for (int i = 0; i < size - 1; i++){
		//每次循环，会找出最大的一个数放到最后
		//O(1)
		int t = array[0];
		array[0] = array[size - i - 1];
		array[size - i - 1] = t;

		//进行向下调整  数据规模是size-1-i			//换完之后，调整，一次比一次少i+1
		AdjustDown(array, size - i - 1, 0);
	}
}


void	TestAdjustDown(){			//测试向下调整

	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int size = sizeof array / sizeof(int);
	PrintArray(array, size);
	AdjustDown(array, size, 0);   //调整根，数组下标从0开始
	PrintArray(array, size);
}


void TestCreatHeap(){				//测试建堆
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
	//建小堆
	CreatHeap(heap, k);
	for (int j = k; j < size; j++){
		if (array[j]>heap[0]){			//直接赋值
			heap[0] = array[j];
			AdjustDown(heap, k, 0);
		}
	}

}