#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void menu(){
	printf("����  1   ��ɼ�\n");
	printf("����  0   �˳�  \n");
}
void fun(){
	int m;
	do{
		printf("��������ĳɼ�:\n");
		scanf("%d", &m);
	} while (m<0 || m>100);
	if (m >= 90){
		printf("��ĳɼ���A\n");
	}
	else if (m >= 80){
		printf("��ĳɼ���B\n");
	}
	else if (m >= 60){
		printf("��ĳɼ���C\n");
	}
	else {
		printf("��ĳɼ���D\n");
	}

}
int main(){

	int n;
	while (1){
		menu();
		printf("��������Ҫ������Ҫִ�еĲ���\n");
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			printf("�˳�\n");
			return 0;
		case 1:
			fun();
			break;
		default:
			printf("�������\n");
			break;
		}
	}
	system("pause");
	return 0;
}