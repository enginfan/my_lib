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
	StaticLinkList<int,5>list;
	for (int i = 0; i < 5; i++)
	{
		list.insert(i);
	}
	for (list.move(0, 1); !list.end(); list.next())
	{
		if (list.current() == 3)
		{
			list.remove(3);
			cout << list.current() << endl;
		}
	}
	for(int i=0;i<list.length();i++)
	{
		cout << list.get(i) << endl;
	}
	
	return 0;
}