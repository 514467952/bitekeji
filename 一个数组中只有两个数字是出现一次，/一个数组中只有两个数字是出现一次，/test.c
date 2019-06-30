#include<stdio.h>
#include<stdlib.h>
int main(void){
	int a[10] = { 1, 1, 1, 2, 3, 3, 3, 4, 5, 5 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++){
		for (j = i + 1; j < 10; j++){
			if (a[i] != a[j]){
				
			}
		}
		printf("%5d\n", a[i]);
	}
		
	system("pause");
}