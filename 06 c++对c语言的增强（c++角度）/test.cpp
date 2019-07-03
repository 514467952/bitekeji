

#include<iostream>

using namespace std;

//1.全局变量检测增强
//int a;
//int a = 10;
//编译通过不了

//2.函数检测增强,参数类型增强，返回值检测曾强,函数调用参数个数检测增强
int  getRect(int w, int h)
{
	return w*h;
}

void test02()
{
	//传参个数不同
	//getRect(10, 10, 10);
	getRect(10, 10);
}
//3.类型转换检测增强
void test03()
{
	//char *p = malloc(sizeof(64));//malloc返回值是void *
	//c++中malloc必须要强制类型转换
}


//4.struct 增强
struct Person
{
	int m_Age;
	void plusAge(){ m_Age++; };//c++语言中struct可以加函数

};

void test04()
{
	Person p1;  //使用时可以不加入struct关键字
	p1.m_Age = 10;
	p1.plusAge();
	cout << p1.m_Age << endl;
	
}

//5.bool类型增强  c语言中没有bool类型
bool flag=true;  //只有真或假true 代表真  false代表假
void test05()
{
	cout << sizeof(bool) << endl;
	//只有1个字节的大小

	flag = 100;
	//bool的类型非0的值转换为1，0就是0
	cout << flag << endl;
}

//6.三目运算符增强
void test06()
{
	int a = 10;
	int b = 20;
	cout << "ret=" <<( a > b ? a : b)<<endl;
	//printf("ret=%d\n", a > b ? a : b);

	(a > b ? a : b) = 100;//返回的是b=100  c++中返回的是变量

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	/*
	cout << "ret1=" << (a < b ? a : b)<<endl;
	(a < b ? a : b )= 100;	//返回的是a1=100，
	cout << "a1=" << a << endl;
	cout << "b1=" << b << endl;
	*/
}

int main(){

	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}

