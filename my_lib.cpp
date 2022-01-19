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
#include "BTree.h"
#include "BTreeNode.h"

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
	
	BTree<int> bt;
	BTreeNode<int>* n=NULL;
	bt.insert(1,NULL);

	n=bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);
	
	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);
	
	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	n = bt.find(6);
	bt.insert(11,n,LEFT);

	int a[] = { 8,9,10,11,7 };

	for (int i = 0; i < 5; i++)
	{
		BTreeNode<int>* node = bt.find(a[i]);
		while (node)
		{
			cout << node->value << " ";
			node = dynamic_cast<BTreeNode<int>*>(node->parent);
		}
		cout << endl;
	}

	return 0;
}