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
#include "LinkStack.h"
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
	MatrixGraph<9, char, int> g;
	const char* VD = "ABEDCGFHI";

	for (int i = 0; i < 9; i++)
	{
		g.setVertex(i, VD[i]);
	}

	g.setEdge(0, 1, 0);
	g.setEdge(1, 0, 0);

	g.setEdge(0, 3, 0);
	g.setEdge(3, 0, 0);

	g.setEdge(0, 4, 0);
	g.setEdge(4, 0, 0);

	g.setEdge(1, 2, 0);
	g.setEdge(2, 1, 0);

	g.setEdge(1, 4, 0);
	g.setEdge(4, 1, 0);

	g.setEdge(2, 5, 0);
	g.setEdge(5, 2, 0);

	g.setEdge(3, 6, 0);
	g.setEdge(6, 3, 0);

	g.setEdge(4, 6, 0);
	g.setEdge(6, 4, 0);

	g.setEdge(6, 7, 0);
	g.setEdge(7, 6, 0);

	g.setEdge(7, 8, 0);
	g.setEdge(8, 7, 0);

    SharedPointer< Array<int> > sa = g.DFS(0);

	for (int i = 0; i < sa->length(); i++)
	{
		cout << (*sa)[i] << " ";
	}

	return 0;
}
