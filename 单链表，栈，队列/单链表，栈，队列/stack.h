#include"test.h"

//��ʼ��
void InitStack(Stack *s){
	s->array = (elemtype*)malloc(sizeof(MAXSIZE*4));
	s->size = 0;
	printf("��ʼ���ɹ�\n");
}
//����
void DestroyStack(Stack*s){
	if (s->array == NULL){
		printf("��ջ���޷�����\n");
	}
	free(s->array);
	s->size = 0;
	printf("���ٳɹ�\n");
}
//ѹջ
void StackPush(Stack *s){
	printf("��������Ҫ�����Ԫ��\n");
	int n = 0;
	scanf("%d", &n);
	s->array[s->size++] =n;
	printf("ѹջ�ɹ�\n");
}
//��ջ��Ԫ��
int StackTop(Stack*s){
	if (s->size==0)
	{
		printf("ջ�գ��޷���Ԫ��\n");
		return -1;
	}
	else{
		printf("ջ��Ԫ��Ϊ%  d\n", s->array[s->size - 1]);
		return s->array[s->size - 1];
	}
}
//����ջ��Ԫ�ظ���
int StackSize(Stack*s){
	printf("��ǰջ��Ԫ�ظ���	%d\n", s->size);
	return s->size;
}
//�ж�ջ��
int EmptyStack(Stack*s){
	if (s->size == 0){
		printf("ջ�ѿ�\n");
	}
	else{
		printf("ջ����\n");
	}
	
	return !s->size;
}
//ɾ������ջ
void StackPop(Stack*s){
	if (s->size == 0){
		printf("�ѿգ�����Ҫ����\n");
	}
	else{
		s->size--;
		printf("�����ɹ�\n");
	}
}

int * Back(int *u){
	*u = 0;
	printf("ллʹ��\n");
	return u;
}

void stackmenu(){
	Stack q;
	Stack *s = &q;
	InitStack(s);
	int u = 1;
	int empt = 0;
	int num = 0;
	int *m1 = NULL;
	while (u)
	{
		printf("-------------------------\n");
		printf("----1.��ջ---------------\n");
		printf("----2.��ջ---------------\n");
		printf("----3.�ж�ջ�Ƿ�Ϊ��-----\n");
		printf("----4.��ջ��Ԫ��---------\n");
		printf("----5.��ʾ��ǰԪ�ظ���---\n");
		printf("----0.�˳�---------------\n");
		printf("-------------------------\n");
		printf("��������Ҫִ�еĲ���\n");
		int n = 0;
		scanf("%d", &n);
		switch (n)
		{
		case 1:StackPush(s);
			break;
		case 2:StackPop(s);
			break;
		case 3:EmptyStack(s);
			break;
		case 4:StackTop(s);
			break;
		case 5:StackSize(s);
			break;
		case 0:Back(&u);
			break;
		default:
			printf("����ʧ��������ѡ��\n");
			break;
		}
	}
}
