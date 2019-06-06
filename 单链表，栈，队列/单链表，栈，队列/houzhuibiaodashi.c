#include"test.h"
#include"stack.h"
typedef char datetype;

double Calcul_exp(char *A){
	Stack s;
	
	char ch = *A++;

	InitStack(&s);
	while (ch != '#'){
		if (ch != '+'&&'/'&&'*'&&'-'){
			StackPush(&s);
		}
		else{
			int c = 0;
			int b=StackTop(&s);
			StackPop(&s);
			int a = StackTop(&s);
			StackPop(&s);
			switch (ch)
			{
			case '+':c = a + b;
				break;
			case '-':c = a - b;
				break;
			case '*':c = a*b;
				break;
			case '/':c = a%b;
				break;
			default:
				printf("ÓÐ´íÎó\n");
				break;
			}
			printf("% c\n", &c);
			StackPush(&s);

		}
	}

}