#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
int main(void){
	char str1[N] = { '0' };
	char str2[N] = { '1', '2',' 3', '4',' 5', '6', '7', '8', '9', '0' };
	int cnt = 0;
	while (cnt<4){
	printf("���������룺\n");
	gets_s(str1);
	if (strcmp(str1, str2) == 0){
		printf("�ɹ�����\n");
		return 0;
	}
	else{
			printf("��������룬��������\n");
		}
	cnt++;
	}
printf("������Σ����������롣\n");
	system("pause");
}