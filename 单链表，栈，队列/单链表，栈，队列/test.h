#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int elemtype;

#define MAXSIZE  100
//��������ͷ���
typedef struct Node{
	struct Node *next;
	elemtype value;
}Node;

typedef struct {
	Node * first;
}Linklist;

//����ѭ������
typedef struct queue{
	elemtype array[MAXSIZE];
	int front, rear;
	int num;
}Crc_queue;
//����ջ
typedef struct Stack{
	elemtype *array;
	int size;
}Stack;

