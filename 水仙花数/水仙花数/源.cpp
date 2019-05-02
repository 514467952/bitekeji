#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i;
	int t1;
	int t2;
	int t3;
	for (i = 100; i < 1000; i++){
		t1 = i % 10;
		t2 = i / 10 % 10;
		t3 = i / 100;
		if (t1*t1*t1 + t2*t2*t2 + t3*t3*t3 == i){
			printf("%d", i);
			printf("\n");
		}
	}
	system("pause");
}