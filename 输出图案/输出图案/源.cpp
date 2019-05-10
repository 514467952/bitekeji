#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i;
	int j;
	
	for (i = 1; i <=7; i++){
		for (j = 1; j <= 2 * i - 1; j++){
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i < 7; i++){
		for (j = 0; j <13 - 2 * i; j++){
			printf("*");
		}
		printf("\n");
	}
	system("pause");
}