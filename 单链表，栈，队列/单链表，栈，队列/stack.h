#include"test.h"

//初始化
void InitStack(Stack *s){
	s->array = (elemtype*)malloc(sizeof(MAXSIZE*4));
	s->size = 0;
	printf("初始化成功\n");
}
//销毁
void DestroyStack(Stack*s){
	if (s->array == NULL){
		printf("无栈，无法销毁\n");
	}
	free(s->array);
	s->size = 0;
	printf("销毁成功\n");
}
//压栈
void StackPush(Stack *s){
	printf("请输入你要插入的元素\n");
	int n = 0;
	scanf("%d", &n);
	s->array[s->size++] =n;
	printf("压栈成功\n");
}
//读栈顶元素
int StackTop(Stack*s){
	if (s->size==0)
	{
		printf("栈空，无法读元素\n");
		return -1;
	}
	else{
		printf("栈顶元素为%  d\n", s->array[s->size - 1]);
		return s->array[s->size - 1];
	}
}
//返回栈中元素个数
int StackSize(Stack*s){
	printf("当前栈中元素个数	%d\n", s->size);
	return s->size;
}
//判断栈空
int EmptyStack(Stack*s){
	if (s->size == 0){
		printf("栈已空\n");
	}
	else{
		printf("栈不空\n");
	}
	
	return !s->size;
}
//删除，弹栈
void StackPop(Stack*s){
	if (s->size == 0){
		printf("已空，不需要弹出\n");
	}
	else{
		s->size--;
		printf("弹出成功\n");
	}
}

int * Back(int *u){
	*u = 0;
	printf("谢谢使用\n");
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
		printf("----1.入栈---------------\n");
		printf("----2.出栈---------------\n");
		printf("----3.判断栈是否为空-----\n");
		printf("----4.读栈顶元素---------\n");
		printf("----5.显示当前元素个数---\n");
		printf("----0.退出---------------\n");
		printf("-------------------------\n");
		printf("请输入你要执行的操作\n");
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
			printf("操作失误，请重新选择\n");
			break;
		}
	}
}
