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
#include "SharedPointer.h"
#include "CircleList.h"
#include "DualLinkList.h"
#include "DualStaticLinkList.h"
#include "DualCircleList.h"

using namespace mylib;
using namespace std;
class Test :public Object
{
public:
	int value;
	Test():value(0)
	{
		cout <<"Test" << endl;
	}
	Test(int v)
	{
		value = v;
		cout << "Test" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
};
void func(int n, int s, int m)
{
	CircleList<int> list;
	for (int i = 0; i < m; i++)
	{
		list.insert(i + 1);
	}
	for (list.move(n-1+s-1,s-1); list.length() > 2;list.next())
	{
		cout << list.current() << endl;
		list.remove(list.find(list.current()));
	}
	cout << "————————最终剩余————————" << endl;
	for (int i = 0; i < list.length(); i++)
	{
		cout << list.get(i) << endl;
	}
}
int main()
{
	DualCircleList<int> list;
	
	for (int i = 0; i < 5; i++)
	{
		list.insert(0,1);
		list.insert(0, 5);
	}

	for (int i=0; i<list.length(); i++)
	{
		cout << list.get(i) << endl;
	}
	
	cout << "begin" << endl;

	list.move(list.length() - 1);

	while (list.find(5) != -1)
	{
		if (list.current() == 5)
		{
			cout << "list.current()=" <<list.current()<< endl;
			list.remove(list.find(list.current()));
		}
		else
		{
			list.pre();
		}
	}

	cout << "end" << endl;

	for (int i = 0; i < list.length(); i++)
	{
		cout << list.get(i) << endl;
	}
	return 0;
}