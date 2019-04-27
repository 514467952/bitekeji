#include<stdio.h>
int main()
{
	double a,b,x;
	double f1(double x,int n);
	double f2(int n);
	a=f1(x,20);
	b=f2(20);
	printf("%lf\n",a/b);
	return 0;
}
double f1(double x,int n)
{
	if(n==0)
		return 1;
	else
		return x*f1(x,n-1);
	
}
double f2(int n)
{
	if(n==0)
		return 1;
	else
		return n*f2(n-1);
}