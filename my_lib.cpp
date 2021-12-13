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
	cout << 8% 7 << endl;
	return 0;
}