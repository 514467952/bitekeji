

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1.全局变量
int a;
int a = 10;
//编译可以通过

//2.函数检测增强
int  getRect(w, h)
{

}

void test02()
{
	//传参个数不同
	getRect(10, 10, 10);
}

//3.类型转换检测增强
void test03()
{
	char *p = malloc(sizeof(64));//malloc返回值是void *
}
//4.struct 增强
struct Person
{
	int m_Age;
	//void plusAge();//c语言中struct不可以加函数
};
void test04()
{
	struct Person p1;  //使用时必须加入struct关键字
	
}

//5.bool类型增强  c语言中没有bool类型
//bool flag; 

//6.三目运算符增强
void test06()
{
	int a = 10;
	int b = 20;
	printf("ret=%d\n", a > b ? a : b);

	//a > b ? a : b = 100;//20=100		//c中返回的是值

	//c语言中想模仿c++写
	*(a > b ? &a : &b) = 100;
	printf("a=%d,b=%d\n", a, b);
}


int main(){
	test06();
	system("pause");
	return 0;
}