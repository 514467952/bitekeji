#define _CRT_SECURE_NO_WARNINGS
#include"test.h"
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#define elemtype int
//
////��������ͷ���
//typedef struct Node{
//	struct Node *next;
//	elemtype value;
//}Node;
//
//typedef struct {
//	Node * first;
//}Linklist;

//��ʼ��
void InitLinklist(Linklist *head){
	assert(head != NULL);
	head->first = NULL;
	printf("��ʼ���ɹ�\n");
}
//ͷ�������
void HeadInsert(Linklist *head){
	assert(head != NULL);

	Node *node = (Node*)malloc(sizeof(Node));
	printf("��������Ҫ�������\n");
	elemtype value = 0;
	scanf("%d", &value);
	node->value = value;
	node->next = head->first;
	head->first = node;
	printf("ͷ��ɹ�\n");
}

//β�� ÿ��Ҫ�ҵ����һ����㣬����Ҫ��ѭ��
void BackInsert(Linklist *head){
	assert(head != NULL);

	Node *node = (Node *)malloc(sizeof(Node));
	printf("��������Ҫ�������\n");
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
	printf("β��ɹ�\n");
}
//ͷɾ
void HeadFree(Linklist *head){
	assert(head != NULL);
	if (head->first == NULL){
		printf("����Ϊ��,ɾ��ʧ��\n");
		return;
	}
	Node *next = head->first->next;
	
	free(head->first);
	head->first = next;
	printf("ɾ���ɹ�\n");
}
//βɾ
void BackFree(Linklist *head){
	assert(head != NULL);
	if (head->first == NULL){
		printf("����Ϊ��,ɾ��ʧ��\n");
		return;
	}
	Node *cur = head->first;
	while (cur->next->next != NULL){
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
	printf("ɾ���ɹ�\n");
}
//��ѯ�����е�ĳ����
Node * FindValue(Linklist *head){
	assert(head != NULL);

	if (head->first == NULL){
		printf("����Ϊ�գ����ܲ���\n");
		return NULL;
	}
	printf("��������Ҫ��ѯ�����ݣ�\n");
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
		printf("û���ҵ�\n");
	}
	
	//return NULL;
}
int * Back(int *u){
	*u = 0;
	printf("ллʹ��\n");
	return u;
}
void SeeLinklist(Linklist *head){
	assert(head != NULL);
	if (head->first == NULL){
		printf("����Ϊ�գ��޷�����\n");
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
		printf("----1.��������-----------\n");
		printf("----2.��ѯ����-----------\n");
		printf("----3.�鿴��ǰ����-------\n");
		printf("----4.ɾ��������Ԫ��-----\n");
		printf("----0.�˳�---------------\n");
		printf("-------------------------\n");
		printf("��������Ҫִ�еĲ���\n");
		int n = 0;
		scanf("%d", &n);
		switch (n)
		{
		case 1:HeadInsert(head);
			break;
		case 2:result = FindValue(head);
			/*if (result == NULL){
				printf("û���ҵ�\n");
			}
			else if(result->value){
				printf("�ҵ�\n");
			}*/
			break;
		case 3: SeeLinklist(head);
			break;
		case 4:HeadFree(head);
			break;
		case 0:Back(&u);
			break;
		default:
			printf("����ʧ��������ѡ��\n");
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