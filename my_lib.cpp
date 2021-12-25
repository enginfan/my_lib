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
	DualStaticLinkList<int, 10> list;
	
	list.DualStaticLinkList::insert(1);
	list.insert(2);
	list.insert(3);
	return 0;
}