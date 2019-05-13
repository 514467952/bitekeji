#include<iostream>
#include<stdlib.h>

using namespace std;
#if 0
int main()
{

	const	int	a = 10;
	int	*pa = (int *)&a;
	*pa = 100;
	cout << a << endl;
	cout << *pa << endl;
	system("pause");
	return 0;
}
#endif


#if 0
//ºêº¯Êı
#define MAX(a,b)((a)>(b)? (a):(b))
int main(){
	int a = 10;
	int b = 20;
	cout << MAX(a, b) << endl;
	cout << MAX(b, a) << endl;
	system("pause");
	return 0;
}
#endif

#if 0
inline int Add(int left, int right){
	return left + right;
}
int main(){
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a, b);
	system("pause");
	return 0;
}
#endif
#if 0
int TestAuto()
{
	return 10;
}

int main() {
	auto a = 10;
	auto b = 3.14;
	auto c = 'a';
	auto d = TestAuto();
	cout << typeid(b).name() << endl;
	//cout << typeid(c).name() << endl; 
	//cout << typeid(d).name() << endl;
	system("pause");
	return 0;
}
#endif
#if 0 
void TestAuto() {
	auto a = 1, b = 2; 
	//auto c = 3, d = 4.0;
}
int  main(){
	int a = 10;
	auto pal = &a;
	auto *pa2 = &a;
	cout << typeid(pal).name() << endl;
	cout << typeid(pa2).name() << endl;
	auto& ra = a;
	ra = 100;
	cout << a << endl;
	system("pause");
	return 0;
}
#endif

int main(){


	/*int array[] = { 1, 2, 3, 4, 5 }; 
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;

	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p) 
		cout << *p << endl;*/
	int array[] = { 1, 2, 3, 4, 5 }; 
	for (auto e : array) 
		e *= 2;

	for (auto e : array)
	cout << e << " ";

	
	system("pause");
	return 0;
}
