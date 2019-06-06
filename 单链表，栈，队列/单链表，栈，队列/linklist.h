#define _CRT_SECURE_NO_WARNINGS
#include"test.h"
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#define elemtype int
//
////单链表不带头结点
//typedef struct Node{
//	struct Node *next;
//	elemtype value;
//}Node;
//
//typedef struct {
//	Node * first;
//}Linklist;

//初始化
void InitLinklist(Linklist *head){
	assert(head != NULL);
	head->first = NULL;
	printf("初始化成功\n");
}
//头插入操作
void HeadInsert(Linklist *head){
	assert(head != NULL);

	Node *node = (Node*)malloc(sizeof(Node));
	printf("请输入你要插入的数\n");
	elemtype value = 0;
	scanf("%d", &value);
	node->value = value;
	node->next = head->first;
	head->first = node;
	printf("头插成功\n");
}

//尾插 每次要找到最后一个结点，所以要有循环
void BackInsert(Linklist *head){
	assert(head != NULL);

	Node *node = (Node *)malloc(sizeof(Node));
	printf("请输入你要插入的数\n");
	elemtype value = 0;
	scanf("%d", &value);
	node->value = value;
	node->next = NULL;
	Node *cur = head->first;
	while (cur->next!=NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
	printf("尾插成功\n");
}
//头删
void HeadFree(Linklist *head){
	assert(head != NULL);
	if (head->first == NULL){
		printf("链表为空,删除失败\n");
		return;
	}
	Node *next = head->first->next;
	
	free(head->first);
	head->first = next;
	printf("删除成功\n");
}
//尾删
void BackFree(Linklist *head){
	assert(head != NULL);
	if (head->first == NULL){
		printf("链表为空,删除失败\n");
		return;
	}
	Node *cur = head->first;
	while (cur->next->next != NULL){
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
	printf("删除成功\n");
}
//查询链表中的某个数
Node * FindValue(Linklist *head){
	assert(head != NULL);

	if (head->first == NULL){
		printf("链表为空，不能查找\n");
		return NULL;
	}
	printf("请输入你要查询的数据：\n");
	elemtype value = 0;
	scanf("%d", &value);
	Node* cur = head->first;

	while(cur != NULL&&cur->value != value ){
		if (cur->value == value){
			return cur;
		}
		else{
			cur = cur->next;
		}
		if (cur==NULL)
		printf("没有找到\n");
	}
	
	//return NULL;
}
int * Back(int *u){
	*u = 0;
	printf("谢谢使用\n");
	return u;
}
void SeeLinklist(Linklist *head){
	assert(head != NULL);
	if (head->first == NULL){
		printf("链表为空，无法遍历\n");
		return;
	}
	Node *cur = head->first;
	for (; cur != NULL; cur = cur->next){

		printf("%  d", cur->value);
	}
	printf("\n");

}


void menu(){
	Linklist *head = (Linklist *)malloc(sizeof(Node));
	InitLinklist(head);
	int u = 1;
	Node *result = NULL;
	while (u)
	{
		printf("-------------------------\n");
		printf("----1.插入数据-----------\n");
		printf("----2.查询数据-----------\n");
		printf("----3.查看当前链表-------\n");
		printf("----4.删除链表中元素-----\n");
		printf("----0.退出---------------\n");
		printf("-------------------------\n");
		printf("请输入你要执行的操作\n");
		int n = 0;
		scanf("%d", &n);
		switch (n)
		{
		case 1:HeadInsert(head);
			break;
		case 2:result = FindValue(head);
			/*if (result == NULL){
				printf("没有找到\n");
			}
			else if(result->value){
				printf("找到\n");
			}*/
			break;
		case 3: SeeLinklist(head);
			break;
		case 4:HeadFree(head);
			break;
		case 0:Back(&u);
			break;
		default:
			printf("操作失误，请重新选择\n");
			break;
		}
	}
}



//int main(){
//	menu();
//
//	system("pause");
//	return 0;
//}