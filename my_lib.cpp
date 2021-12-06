#include <iostream>
#include <cstdlib>
#include "Exception.h"
#include "SmartPointer.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "StaticLinkList.h"
using namespace mylib;

int main()
{
	StaticLinkList<int, 10> sta;
	for (int i = 0; i < sta.capcity(); i++)
	{
		sta.insert(i);
	}
	for (int i = 0; i < sta.capcity(); i++)
	{
		int v = 0;
		sta.get(i,v);
		cout << "v=" << v << endl;
	}
	cout << "sta.length=" << sta.length() << endl;
	cout << "sta.find(9)=" << sta.find(9) << endl;
	sta.remove(sta.find(4));
	for (int i = 0; i < sta.capcity(); i++)
	{
		int v = 0;
		sta.get(i, v);
		cout << "v=" << v << endl;
	}
	cout << "down" << endl;
	return 0;
}