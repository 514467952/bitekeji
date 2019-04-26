#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i; 
	int j;
	int cnt = 0;
	int n;
	for (i = 1; i <= 100; i++){
		if (i / 10 == 0){
			if (i + '0' == 57)
				cnt++;
		}
		else{
			n = i/ 10;
			j = i % 10;
			if (n + '0' == 57)
				cnt++;
			if (j + '0' == 57)
				cnt++;
		}
	}
	printf("9出现了%d次\n", cnt);



	system("pause");
}