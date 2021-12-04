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
	int v = 0;
	LinkList<int> a;
	for (int i = 0; i < 10; i++)
	{
		cout<<a.insert(i)<<endl;
	}
	cout << "a.length=" << a.length() << endl;
	/*for (int i = 0; i < 10; i++)
	{
		a.get(i, v);
		cout << v << endl;
	}*/
	return 0;
}