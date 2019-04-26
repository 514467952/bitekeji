#include<stdio.h>
#include<stdlib.h>
int main(){
	int t1 = 0;
	int t2 = 0;
	int t3 = 0;
	int i = 0;
	for (i = 100; i < 1000; i++){
		t1 = i % 10;
		t2 = i / 10 % 10;
		t3 = i / 100;
		if ((t1*t1*t1 + t2*t2*t2 + t3*t3*t3) == i){
			printf("  %d \n", i);
		}
	}
	system("pause");
	return 0;

}