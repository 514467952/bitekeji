#include"test.h"
//初始化
void InitCrc_queue(Crc_queue*q){

	q = (Crc_queue*)malloc(sizeof(Crc_queue));
	if (q == NULL){
		printf("初始化失败\n");
		return;
	}
	//队尾指针和队头指针放到最大处
	q->front = MAXSIZE;
	q->rear = MAXSIZE;
	q->num = 0;
	printf("初始化成功\n");
}
//入循环队列   队尾移动
void IN_Crc_queue(Crc_queue*q){
	if ((q->rear+1)%MAXSIZE==q->front){
		printf("队满\n");
		return ;
	}
	else{
		int n;
		printf("请输入你要插入的数据\n");
		scanf("%d", &n);
		q->rear = (q->rear + 1) % MAXSIZE;
		q->array[q->rear] = n;
		q->num++;
		printf("入队成功\n");
		return ;
	}
}
//出循环队列时，队头移动
void Out_Crc_queue(Crc_queue*q){
	if (q->front==q->rear){
		printf("队空，不能出\n");
		return ;
	}
	else{
		int m = 0;
		elemtype *x=&m;
		q->front = (q->front + 1) % MAXSIZE;
		*x = q->array[q->front];
		printf("%d\n", *x);
		q->num--;
		printf("出队成功\n");
		return ;
	}
}
//判断队列是否为空
void Empty_Crc_queue(Crc_queue*q){
	if (q->front==q->rear){
		printf("队空\n");
		return;
	}
		printf("队不空\n");
		return;
	
}

int * Back(int *u){
	*u = 0;
	printf("谢谢使用\n");
	return u;
}

void queuemenu(){
	
	Crc_queue *head = (Crc_queue*)malloc(sizeof(Crc_queue));
	InitCrc_queue(head);
	int m = 0;
	int *result = &m;
	int u = 1;
	//int *result = NULL;
	int *m1 = NULL;
	while (u)
	{
		printf("-------------------------\n");
		printf("----1.入队-----------\n");
		printf("----2.出队列------\n");
		printf("----3.判断是否为空-----------\n");
		printf("----0.退出---------------\n");
		printf("-------------------------\n");
		printf("请输入你要执行的操作\n");
		int n = 0;
		scanf("%d", &n);
		switch (n)
		{
		case 1:IN_Crc_queue(head);
			break;
		case 2:Out_Crc_queue(head);
			
			break;
		case 3:Empty_Crc_queue(head);
			break;
		case 0:Back(&u);
			break;
		default:
			printf("操作失误，请重新选择\n");
			break;
		}
	}

	/*IN_Crc_queue(head);
	result=Out_Crc_queue(head,result);*/

}