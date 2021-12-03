#include <iostream>
#include <cstdlib>
#include "Exception.h"
#include "SmartPointer.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"

using namespace mylib;

int main()
{
	DynamicArray<int> a(2);
	for (int i=0; i < 1; i++)
	{
		a[i] = i * i;
	}
	/*for (int i=0; i < 10; i++)
	{
		cout<<"a["<<i<<"]=" << a[i] << endl;
	}*/
	cout << "_________________________________________" << endl;
	DynamicArray<int> b = a;
	/*for (int i = 0; i < 1; i++)
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
	}*/
	
	b = a;
	
	return 0;
}