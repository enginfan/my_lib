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
	DualLinkList<int> list;

	for (int i = 0; i < 5; i++)
	{
		list.insert(0,i);
		list.insert(0,5);
	}

	for (list.move(list.length()-1, 1); !list.end(); list.pre())
	{
		cout << list.current() << endl;
	}

	for (list.move(0, 1); !list.end(); list.next())
	{
		cout << list.current() << endl;
	}

	list.move(list.length() - 1);

	while (!list.end())
	{
		if (list.current() == 5)
		{
			cout << "current=" << list.current() << endl;

			list.remove(list.find(list.current()));
		}
		else
		{
			list.pre();
		}
	}

	cout << "list.m_length()=" << list.length() << endl;

	for (list.move(0, 1); !list.end(); list.next())
	{
		cout << list.current() << endl;
	}
	return 0;
}