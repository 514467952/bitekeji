#include<iostream>

using namespace std;
#if 0
//按数组名传参，编译器把数组转化为首元素地址，
//就转化成了int*类型的指针，不知道这个指针所指向的内容具体是多少
//所以用不了范围for
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
	//要改变数组中的元素，必须要有相关的地址操作，而打印，只需要访问即可，引用相当于指针，给别名即可
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
	TestFunc(NULL);//本应该调用第二个重载的函数，但调用了第一个，
					//因为编译器把NULL当成0来处理
	TestFunc(nullptr);
	return 0;
}