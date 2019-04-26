#include<stdio.h>
#include<stdlib.h>
void swap(int * a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
	return;
}
int main(void){
	int a = 10;
	int b = 20;
	printf("a=%d,b=%d\n", a, b);
	swap(&a, &b);
	printf("½»»»ºó:\n");
	printf("a=%d,b=%d\n", a, b);
	system("pause");
}