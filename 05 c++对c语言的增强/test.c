

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1.ȫ�ֱ���
int a;
int a = 10;
//�������ͨ��

//2.���������ǿ
int  getRect(w, h)
{

}

void test02()
{
	//���θ�����ͬ
	getRect(10, 10, 10);
}

//3.����ת�������ǿ
void test03()
{
	char *p = malloc(sizeof(64));//malloc����ֵ��void *
}
//4.struct ��ǿ
struct Person
{
	int m_Age;
	//void plusAge();//c������struct�����ԼӺ���
};
void test04()
{
	struct Person p1;  //ʹ��ʱ�������struct�ؼ���
	
}

//5.bool������ǿ  c������û��bool����
//bool flag; 

//6.��Ŀ�������ǿ
void test06()
{
	int a = 10;
	int b = 20;
	printf("ret=%d\n", a > b ? a : b);

	//a > b ? a : b = 100;//20=100		//c�з��ص���ֵ

	//c��������ģ��c++д
	*(a > b ? &a : &b) = 100;
	printf("a=%d,b=%d\n", a, b);
}


int main(){
	test06();
	system("pause");
	return 0;
}