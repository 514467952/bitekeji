#include"test.h"
//��ʼ��
void InitCrc_queue(Crc_queue*q){

	q = (Crc_queue*)malloc(sizeof(Crc_queue));
	if (q == NULL){
		printf("��ʼ��ʧ��\n");
		return;
	}
	//��βָ��Ͷ�ͷָ��ŵ����
	q->front = MAXSIZE;
	q->rear = MAXSIZE;
	q->num = 0;
	printf("��ʼ���ɹ�\n");
}
//��ѭ������   ��β�ƶ�
void IN_Crc_queue(Crc_queue*q){
	if ((q->rear+1)%MAXSIZE==q->front){
		printf("����\n");
		return ;
	}
	else{
		int n;
		printf("��������Ҫ���������\n");
		scanf("%d", &n);
		q->rear = (q->rear + 1) % MAXSIZE;
		q->array[q->rear] = n;
		q->num++;
		printf("��ӳɹ�\n");
		return ;
	}
}
//��ѭ������ʱ����ͷ�ƶ�
void Out_Crc_queue(Crc_queue*q){
	if (q->front==q->rear){
		printf("�ӿգ����ܳ�\n");
		return ;
	}
	else{
		int m = 0;
		elemtype *x=&m;
		q->front = (q->front + 1) % MAXSIZE;
		*x = q->array[q->front];
		printf("%d\n", *x);
		q->num--;
		printf("���ӳɹ�\n");
		return ;
	}
}
//�ж϶����Ƿ�Ϊ��
void Empty_Crc_queue(Crc_queue*q){
	if (q->front==q->rear){
		printf("�ӿ�\n");
		return;
	}
		printf("�Ӳ���\n");
		return;
	
}

int * Back(int *u){
	*u = 0;
	printf("ллʹ��\n");
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
		printf("----1.���-----------\n");
		printf("----2.������------\n");
		printf("----3.�ж��Ƿ�Ϊ��-----------\n");
		printf("----0.�˳�---------------\n");
		printf("-------------------------\n");
		printf("��������Ҫִ�еĲ���\n");
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
			printf("����ʧ��������ѡ��\n");
			break;
		}
	}

	/*IN_Crc_queue(head);
	result=Out_Crc_queue(head,result);*/

}