#include <iostream>
#include <cstring>
#include <cstdlib>
//#include "Exception.h"
//#include "SmartPointer.h"
//#include "StaticList.h"
//#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
//#include "LinkList.h"
//#include "StaticLinkList.h"
//#include "SharedPointer.h"
//#include "CircleList.h"
//#include "DualLinkList.h"
//#include "DualStaticLinkList.h"
//#include "DualCircleList.h"
//#include "StaticStack.h"
//#include "LinkStack.h"
//#include "StaticQueue.h"
//#include "LinkQueue.h"
#include "String.h"
//#include "QueenSolution.h"
#include "Sort.h"

using namespace mylib;
using namespace std;
class Test :public Object
{
public:
	int value;
	String str;
	Test():value(0),str("null")
	{
		cout <<"Test" << endl;
		String a = "    less   ";
		cout << a.length() << endl;
		if (a.trim().insert(4, " is more.").endOf("more.") && a.startWith("less"))
		{
			cout << a.str() << endl;
		}
		cout << a.length() << endl;
		
		
	}

	Test(int v):str("null")
	{
		value = v;
		cout << "Test" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
};



int main()
{
	StaticArray<int, 10> a1;
	DynamicArray<int> a2(10);
	int b[] = { 8,9,5,5,6,7,1,2,10,11 };
	for (int i = 0; i < 10; i++)
	{
		a1.set(i, b[i]);
		a2.set(i, b[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		cout<<a2.get(i)<<endl;
	}

	Sort::Bubble(a2, true);
	
	for (int i = 0; i < 10; i++)
	{
		cout << a2.get(i) << endl;
	}



	return 0;
}