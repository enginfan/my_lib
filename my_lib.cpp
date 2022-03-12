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
#include "Tree_problem.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

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
	ListGraph<char, int>g;
	  
	g.addVertex('A');
	g.addVertex('B');
	g.addVertex('C');
	g.addVertex('D');


	for (int i = 0; i < g.vCount(); i++)
	{
		cout << i << ":" << g.getVertex(i)<<endl;
	}
	cout << g.vCount() << endl;
	cout << g.setEdge(0, 1, 5);
	cout << g.setEdge(0, 3, 5);
	cout << g.setEdge(1, 2, 8);
	cout << g.setEdge(2, 3, 2);
	cout << g.setEdge(3, 1, 9) << endl;

	cout << "W(0,1):" << g.getEdge(0, 1) << endl;
	cout << "W(0,3):" << g.getEdge(0, 3) << endl;
	cout << "W(1,2):" << g.getEdge(1, 2) << endl;
	cout << "W(2,3):" << g.getEdge(2, 3) << endl;
	cout << "W(3,1):" << g.getEdge(3, 1) << endl;

	g.removeEdge(3, 1);

	SharedPointer<Array<int>> aj = g.getAdjacent(0);

	for (int i = 0; i < aj->length(); i++)
	{
		cout << (*aj)[i] << endl;
	}
	return 0;
}