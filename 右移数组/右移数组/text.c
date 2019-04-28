#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  N  10
void rightmove(int a[],  int  step);
int main(void)
{
	char *p = "abcdefg";
	int step = 0;
	printf("please  inoput  you 要右移的位数:\n");
	scanf("%d", &step);
	rightmove(p, step);

}
void rightmove(char *pc, int  step)
{
	while (step)
	{	
		int len = sizeof(pc);
		int t = 0;
		t = pc[len-1];
		for (int i = len-1; i >= 1; i--)
		{
			pc[i ] = pc[i-1];
		}
		pc[0] = t;
		step--;
	}
	for (int i = 0; i < N;i++)
	printf("%  d", pc[i]);
	system("pause");
}