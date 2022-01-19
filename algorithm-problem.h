#pragma once
#include "Object.h"

/*传引用传指针的区别
	   ★相同点：

	   ●都是地址的概念；

	   指针指向一块内存，它的内容是所指内存的地址；而引用则是某块内存的别名。

	   ★不同点：

	   ●指针是一个实体，而引用仅是个别名；

	   ●引用只能在定义时被初始化一次，之后不可变；指针可变；引用“从一而终”，指针可以“见异思迁”；

	   ●引用没有const，指针有const，const的指针不可变；（具体指没有int& const a这种形式，而const int& a是有的， 
	   前者指引用本身即别名不可以改变，这是当然的，所以不需要这种形式，后者指引用所指的值不可以改变）

	   ●引用不能为空，指针可以为空；

	   ●“sizeof 引用”得到的是所指向的变量(对象)的大小，而“sizeof 指针”得到的是指针本身的大小；

	   ●指针和引用的自增(++)运算意义不一样；

	   ●引用是类型安全的，而指针不是 (引用比指针多了类型检查


	   */








namespace mylib
{
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
		for (int i = v; i < (v + len); i++)
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
			list = list->next;
		}
		if (list == NULL)
		{
			cout << "NULL" << endl;
		}
	}


	//反转链表
	Node* reverse(Node* list)
	{

		if ((list->next == NULL) || (list == NULL))
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

	//合并两个链表
	Node* merge(Node* list1, Node* list2)
	{
		if (list1 == NULL)
		{
			return list2;
		}
		else if (list2 == NULL)
		{
			return list1;
		}
		else if (list1->value < list2->value)
		{
			Node* list1_ = list1->next;
			Node* list = merge(list1_, list2);

			list1->next = list;

			return list1;//这里返回的是最外侧头结点！！！并不是返回merge//该函数等价于return (list->next=merge(list->next,list2),list1)//使用逗号表达式
		}
		else
		{
			Node* list2_ = list2->next;
			Node* list = merge(list1, list2->next);

			list2->next = list;

			return list2;
		}
	}


	//汉诺塔问题
	void HanoiTower(int n, char a, char b, char c)//a==起始，b==中转，c==目的
	{
		if (n == 1)
		{
			cout << a << "-->" << c << endl;
		}
		else
		{
			HanoiTower(n - 1, a, c, b);
			HanoiTower(1, a, b, c);
			HanoiTower(n - 1, b, a, c);
		}
	}

	//全排列问题
	void permutation(char* s, char* e)
	{
		if (*s == '\0')
		{
			cout << e << endl;
		}
		else
		{
			int len = strlen(s);
			for (int i = 0; i < len; i++)
			{
				if ((s[0] != s[i]) || (i == 0))//字符重复的情况
				{
					swap(s[0], s[i]);
					permutation(s + 1, e);
					swap(s[0], s[i]);
				}
			}
		}
	}

	//逆序打印单链表中的偶数节点//打印的过程就是回溯的过程！！！
	//相当于去迷宫在选择处留下标记再返回时找路；重点理解栈的作用
	void r_ptint_even(Node* list)
	{
		if (list != NULL)
		{
			r_ptint_even(list->next);
			if (list->value % 2 == 0)
			{
				cout << list->value;
			}
		}
	}

}
