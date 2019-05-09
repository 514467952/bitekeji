#include<stdio.h>
#include<stdlib.h>
void fun(int n){
	int i = 0;
	int j = 0;
	for (i = 1; i <=n; i++){
		for (j = 1; j <=n-i+1; j++){
			printf(" %d * %d = %d ", i, j, i*j);
		}
			printf("\n");
	}
}
int main(void){
	int n = 0;
	printf("请输入你想实现乘法口诀表的行数:\n");
	scanf_s("%d", &n);
	fun(n);
	system("pause");
}