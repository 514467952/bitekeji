

#include<iostream>

using namespace std;

//1.ȫ�ֱ��������ǿ
//int a;
//int a = 10;
//����ͨ������

//2.���������ǿ,����������ǿ������ֵ�����ǿ,�������ò������������ǿ
int  getRect(int w, int h)
{
	return w*h;
}

void test02()
{
	//���θ�����ͬ
	//getRect(10, 10, 10);
	getRect(10, 10);
}
//3.����ת�������ǿ
void test03()
{
	//char *p = malloc(sizeof(64));//malloc����ֵ��void *
	//c++��malloc����Ҫǿ������ת��
}


//4.struct ��ǿ
struct Person
{
	int m_Age;
	void plusAge(){ m_Age++; };//c++������struct���ԼӺ���

};

void test04()
{
	Person p1;  //ʹ��ʱ���Բ�����struct�ؼ���
	p1.m_Age = 10;
	p1.plusAge();
	cout << p1.m_Age << endl;
	
}

//5.bool������ǿ  c������û��bool����
bool flag=true;  //ֻ������true ������  false�����
void test05()
{
	cout << sizeof(bool) << endl;
	//ֻ��1���ֽڵĴ�С

	flag = 100;
	//bool�����ͷ�0��ֵת��Ϊ1��0����0
	cout << flag << endl;
}

//6.��Ŀ�������ǿ
void test06()
{
	int a = 10;
	int b = 20;
	cout << "ret=" <<( a > b ? a : b)<<endl;
	//printf("ret=%d\n", a > b ? a : b);

	(a > b ? a : b) = 100;//���ص���b=100  c++�з��ص��Ǳ���

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	/*
	cout << "ret1=" << (a < b ? a : b)<<endl;
	(a < b ? a : b )= 100;	//���ص���a1=100��
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

