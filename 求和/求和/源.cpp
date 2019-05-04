#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i;
	int n = 1;
	double sum=0;


	for (i = 0; i < 101; i++){

		sum = sum + 1.0 / i*n;
		n = n*-1;

	}
	printf("%lf\n", sum);

	system("pause");
}