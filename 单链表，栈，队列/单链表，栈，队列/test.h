#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int elemtype;

#define MAXSIZE  100
//单链表不带头结点
typedef struct Node{
	struct Node *next;
	elemtype value;
}Node;

typedef struct {
	Node * first;
}Linklist;

//定义循环队列
typedef struct queue{
	elemtype array[MAXSIZE];
	int front, rear;
	int num;
}Crc_queue;
//定义栈
typedef struct Stack{
	elemtype *array;
	int size;
}Stack;

