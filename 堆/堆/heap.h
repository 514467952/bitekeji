#pragma once
//#include "test.h"
#include<string.h>

//˳���Ļ������в��ֹ���

typedef struct Heap{
	int array[100];
	int size;
}Heap;

void  HeapInit(Heap *heap, int array[], int size){

	memcpy(heap->array, array, size * sizeof(int));
	heap->size = size;
	CreatHeap(heap->array, size);
}

//����
void HeapPush(Heap *heap, int val){
	heap->array[heap->size++] = val;

	AdjustUp(heap->array, heap->size, heap->size - 1);
}

//ɾ��
//ֻ��ɾ���Ѷ�Ԫ�أ�ɾ����λ��û������
void HeapPop(Heap *heap){
	heap->array[0] = heap->array[heap->size - 1];
	AdjustDown(heap->array, heap->size - 1, 0);			//�����ĸ�����һ�ˣ����±��һ��Ԫ�ؿ�ʼɾ
}






//���ضѶ�Ԫ��
int HeapTop(Heap *heap){
	return heap->array[0];
}

void Test(){
	Heap heap;
	int array[] = { 15, 37, 2, 45, 63, 9, 18, 7, 16, 13 };
	int size = sizeof array / sizeof(int);
	HeapInit(&heap, array, size);
	PrintArray(heap.array, heap.size);

	HeapPush(&heap, 1);
	PrintArray(heap.array, heap.size);

}