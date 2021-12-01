#include <iostream>
#include <cstdlib>
#include "Exception.h"
#include "SmartPointer.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
using namespace std;
using namespace mylib;

int main()
{
	StaticArray<int, 10> a;
	for (int i=0; i < 10; i++)
	{
		a[i] = i * i;
	}
	for (int i=0; i < 10; i++)
	{
		cout<<"a["<<i<<"]=" << a[i] << endl;
	}
	cout << "_________________________________________" << endl;
	StaticArray<int, 10> b = a;
	for (int i = 0; i < 10; i++)
	{
		cout << "b[" << i << "]=" << b[i] << endl;
	}
	cout << "_________________________________________" << endl;
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "a[" << i << "]=" << a[i] << endl;
	}
	b = a;
	for (int i = 0; i < 10; i++)
	{
		cout << "b[" << i << "]=" << b[i] << endl;
	}
	return 0;
}