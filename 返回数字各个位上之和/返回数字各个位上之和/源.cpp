#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n){
	int cnt = n%10;
	if (n == 0)
		return cnt;
	else
	return cnt + DigitSum(n / 10 );
}
int main(void){
	int n=-1;
	while (n < 0){
	printf("������һ���Ǹ�����:\n");
	scanf("%d", &n);
		if (n < 0){
			printf("����������:\n");
		}
	}
	printf("% d\n",DigitSum(n));
	system("pause");
}