#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void menu(){
	printf("输入  1   查成绩\n");
	printf("输入  0   退出  \n");
}
void fun(){
	int m;
	do{
		printf("请输入你的成绩:\n");
		scanf("%d", &m);
	} while (m<0 || m>100);
	if (m >= 90){
		printf("你的成绩是A\n");
	}
	else if (m >= 80){
		printf("你的成绩是B\n");
	}
	else if (m >= 60){
		printf("你的成绩是C\n");
	}
	else {
		printf("你的成绩是D\n");
	}

}
int main(){

	int n;
	while (1){
		menu();
		printf("请输入你要操作你要执行的操作\n");
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			printf("退出\n");
			return 0;
		case 1:
			fun();
			break;
		default:
			printf("输入错误\n");
			break;
		}
	}
	system("pause");
	return 0;
}