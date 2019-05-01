

#include<stdio.h>


/*

int Add(int left, int right);

double Add(double left, double right);

//double Add(int left, double right);

int main(){

	Add(1, 2);
	Add(1.0, 2.0);
	//Add(1, 2.0);
	return 0;
}

*/
/*
//传值
//优点：函数的副作用不会影响外部的实参
//缺点：不同通过修改形参来改变外部的实参
//		传参的效率低
void Swap(int left, int right){

	int temp = left;
	left = right;
	right = temp;
}


//传地址
//优点：可以通过形参的改变外部的实参，传参效率高
//缺点：函数的副作用会影响外部的实参
//		可定性差
void Swap(int *pleft, int *pright){

	int temp = *pleft;
	*pleft = *pright;
	*pright = temp;
}
*/

//
//void TestRef() {
//	int a = 10; 
//	 int& ra;   
//	int& ra = a; 
//	int& rra = a; 
//	printf("%p  %p  %p\n", &a, &ra, &rra);
//}





//
//int main(){
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	return 0;
//}

//void TestConstRef() {
//	
//	
//	
//	double d = 12.34; 
//	int& rd = d;  // 该语句编译时会出错，类型不同 
//	const int& rd = d; 
//}


#include <time.h> struct A {  int a[10000];};




void TestFunc1(A a) {}

void TestFunc2(A& a) {}

void TestRefAndValue() {
	A a;

	// 以值作为函数参数    
	size_t begin1 = clock();    for (size_t i = 0; i < 10000; ++i)        TestFunc1(a);    size_t end1 = clock();

	// 以引用作为函数参数   
	size_t begin2 = clock();    for (size_t i = 0; i < 10000; ++i)        TestFunc2(a);    size_t end2 = clock();

	// 分别计算两个函数运行结束后的时间
	
		//6.5.2 值和引用的作为返回值类型的性能比较
		cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;   
		cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}

// 运行多次，检测值和引用在传参方面的效率区别 
int main() 
{    
	for (int i = 0; i < 10; ++i)    
{        
	TestRefAndValue();   

}            
	return 0; 
}
