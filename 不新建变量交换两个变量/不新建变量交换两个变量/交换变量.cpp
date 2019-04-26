#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i = 10;
	int j = 20;
	j = i + j;
	i = j - i;
	j = j - i;
	printf(" %d   %d\n", i, j);




	system("pause");
}