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
	SharedPointer<Test> sp0 = new Test();
	SharedPointer<Test> sp1 = sp0;
	SharedPointer<Test> sp2 = NULL;
	sp2 = sp1;
	cout << sp0->value << endl;
	cout << sp1->value << endl;
	cout << sp2->value << endl;
	cout << (sp0 == sp1) << endl;
	sp2.clear();
	cout << (sp0 != sp2) << endl;
	return 0;
}