#include <iostream>
#include <cstdlib>
#include "Exception.h"
#include "SmartPointer.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"

using namespace mylib;

int main()
{
	LinkList<int> a;
	for (int i = 0; i < 10; i++)
	{
		a.insert(i+1);
	}
	cout << "a.length=" << a.length() << endl;
	for (int i = 0; i < 10; i++)
	{	
		int v = 0;
		a.get(i, v);
		cout << v << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		a.set(i ,10-i);
	}
	a.remove(3);
	for (int i = 0; i < 10; i++)
	{
		int v = NULL;
		a.get(i, v);
		cout << v << endl;
	}
	cout << "a.length=" << a.length() << endl;
	return 0;
}