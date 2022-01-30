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

	BTree<int>* btd=NULL;

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

	

	BTreeNode<int>* lbt = bt.thread(PostOrder);

	while (lbt)
	{
		cout << lbt->value << endl;
		lbt = lbt->right;
	}

	/*BTree<int> nbt;

	nbt.insert(0, NULL);

	n = nbt.find(0);
	nbt.insert(6, n, LEFT);
	nbt.insert(2, n, RIGHT);

	n = nbt.find(2);
	nbt.insert(7, n, LEFT);
	nbt.insert(8, n, RIGHT);

	SharedPointer<BTree<int>>sbt=nbt.add(bt);

	for ((*sbt).begin(); !(*sbt).end(); (*sbt).next())
	{
		cout << (*sbt).current() << endl;
	}*/
	//SharedPointer<BTree<int>> btclone = bt.clone();
	
	

	/*int a[] = { 8,9,10,11,7 };

	for (int i = 0; i < 5; i++)
	{
		BTreeNode<int>* node = (*btclone).find(a[i]);
		while (node)
		{
			cout << node->value << " ";
			node = dynamic_cast<BTreeNode<int>*>(node->parent);
		}
		cout << endl;
	}*/

	//cout << "bt==btclone:" << (bt == (*btclone)) << endl;

	/*for (bt.begin(); !bt.end(); bt.next())
	{
		cout << bt.current() << endl;
	}
	SharedPointer<Array<int>> sp = NULL;

	sp = bt.traversal(PostOrder);
	cout << (*sp).length() << endl;
	for (int i = 0; i < (*sp).length(); i++)
	{
		cout << (*sp)[i] << " ";
	}*/

	return 0;
}