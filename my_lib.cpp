#include <iostream>
#include <cstring>
//#include <cstdlib>
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
#include "LinkStack.h"
using namespace mylib;
using namespace std;
class Test :public Object
{
public:
	int value;
	string str;
	Test():value(0),str("null")
	{
		cout <<"Test" << endl;
	}
	Test(string st)
	{
		cout << "Test" << endl;
		str = st;
		cout << "Test" << str <<"creat"<< endl;
	}
	Test(int v):str("null")
	{
		value = v;
		cout << "Test" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
		cout << str << endl;
	}
};


int main()
{

	return 0;
}