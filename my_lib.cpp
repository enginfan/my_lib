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

unsigned int sum(unsigned int n)
{
	if (n > 1)
	{
		return n + sum(n - 1);
	}
	else
	{
		return 1;
	}
}

unsigned int fac(unsigned int n)
{
	if (n > 2)
	{
		return fac(n - 2) + fac(n - 1);
	}
	if ((n == 1) || (n == 2))
	{
		return 1;
	}

	return 0;
}

struct Node
{
	int value;
	Node* next;
};

Node* create_list(int v, int len)
{
	Node* ret = NULL;
	Node* slider = NULL;
	for (int i = 0; i < len; i++)
	{
		Node* n = new Node();
		n->value = i;
		if (slider == NULL)
		{
			slider = n;
			ret = n;
		}
		else
		{
			slider->next = n;
			slider = n;
		}
	}
	return ret;
}

void destory(Node* list)
{
	while (list)
	{
		Node* del = list;
		list = list->next;
		delete del;
	}
}

void print_Node(Node* list)
{
	while (list)
	{
		cout << list->value << "->";
		list=list->next;
	}
	if (list == NULL)
	{
		cout << "NULL" << endl;
	}
}

Node* reverse(Node* list)
{

	if ((list->next == NULL)||(list==NULL))
	{
		return list;
	}
	if (list->next)
	{
		Node* guard = list->next;
		Node* ret = reverse(list->next);
		guard->next = list;
		list->next = NULL;
		return ret;
	}
}

int main()
{
	Node* list=create_list(0, 10);
	print_Node(list);
	print_Node(reverse(list));
	
	return 0;
}