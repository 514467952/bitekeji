#include<stdio.h>
#include<stdlib.h>
int main(void){
	long int sn=0;
	int a;
	printf("please input a number:");
	scanf_s("%d", &a);
	for (int i = 0; i < 4; i++){
		sn = sn + a;
		a = a * 10 + a;
	}
	printf("%ld", sn);

	system("pause");
}