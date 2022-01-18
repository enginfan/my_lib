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
#include "SharedPointer.h"
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
#include "GTree.h"
#include "GTreeNode.h"

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
	GTree<char> t;
	GTreeNode<char>* node = NULL;

	t.insert('A',NULL);

	node = t.find('A');
	t.insert('B', node);
	t.insert('C', node);
	t.insert('D', node);

	node = t.find('B');
	t.insert('E', node);
	t.insert('F', node);
	
	node = t.find('D');
	t.insert('H', node);
	t.insert('I', node);
	t.insert('J', node);

	node = t.find('E');
	t.insert('K', node);
	t.insert('L', node);

	node = t.find('C');
	t.insert('G', node);

	node = t.find('H');
	t.insert('M', node);

	cout <<"t.degree()=" << t.degree() << endl;
	cout <<"t.height()=" << t.height() << endl;
	cout <<"t.count()=" << t.count() << endl;

	for (t.begin(); !t.end(); t.next())
	{
		cout << t.current() << endl;
	}
	
	return 0;
}