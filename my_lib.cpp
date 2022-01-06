#include <iostream>
#include <cstring>
#include <cstdlib>
//#include "Exception.h"
//#include "SmartPointer.h"
//#include "StaticList.h"
//#include "DynamicList.h"
//#include "StaticArray.h"
//#include "DynamicArray.h"
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
		String a[] = { "E","D","C","B","A"};
		String min = a[0];
		for (int i = 0; i < 5; i++)
		{
			if (min > a[i])
			{
				min = a[i];
			}
		}
		cout << "a.length()=" << a->length() << endl;
		cout << "a.str()=" << a->str() << endl;
		cout << "min=" << min.str() << endl;
	}
	/*Test(String st)
	{
		cout << "Test" << endl;
		str = st;
		cout << "Test" << str <<"creat"<< endl;
	}*/
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
	Test t1;

	
	return 0;
}