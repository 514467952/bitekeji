#include<iostream>

using namespace std;
#if 0
//�����������Σ�������������ת��Ϊ��Ԫ�ص�ַ��
//��ת������int*���͵�ָ�룬��֪�����ָ����ָ������ݾ����Ƕ���
//�����ò��˷�Χfor
void PrintArray(int array[]){
	for (auto e : array){
		cout << e << " ";
	}
	cout << endl;
}

int main(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7 };
	for (auto& e : array){
		e *= 2;
	}
	//Ҫ�ı������е�Ԫ�أ�����Ҫ����صĵ�ַ����������ӡ��ֻ��Ҫ���ʼ��ɣ������൱��ָ�룬����������
	for (auto e : array){
		cout << e << "  ";
	}



	system("pause");
	return 0;
}
#endif

void TestFunc(int)
{
	cout << "TestFunc(int)" << endl;
}
void TestFunc(int*)
{
	cout << "TestFunc(int*)" << endl;
}
int main(){
	int a = 10;
	int *pa = &a;

	int *pb = NULL;

	TestFunc(pb);
	TestFunc(NULL);//��Ӧ�õ��õڶ������صĺ������������˵�һ����
					//��Ϊ��������NULL����0������
	TestFunc(nullptr);
	return 0;
}