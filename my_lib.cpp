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
int main()
{
	LinkList<int> list;
	for (int i = 0; i < 5; i++)
	{
		list.insert(i);
	}
	for (list.move(0, 1); !list.end(); list.next())
	{
		cout<<list.current()<<endl;
	}
	list.remove(1);
	for (list.move(0, 1); !list.end(); list.next())
	{
		cout << list.current() << endl;
	}
	return 0;
}