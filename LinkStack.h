#pragma once
#ifndef LINKSTACK_H

#include "LinkList.h"
#include "Stack.h"

namespace mylib
{
	template <typename T>
	class LinkStack : public Stack<T>
	{
	protected:
		LinkList<T> m_list;//封装LinkList类不需要设置构造和析构函数
	public:
		void push(const T& e)
		{
			m_list.insert(0, e);
		}

		void pop() 
		{
			if (m_list.length() > 0)
			{
				m_list.remove(0);
			}
			else
			{

			}
		}

		T top()const
		{
			if (m_list.length() > 0)
			{
				return m_list.get(0);
			}
			else
			{

			}
		}

		void clear()
		{
			m_list.clear();
		}

		int size()const
		{
			return m_list.length();
		}

	};
}
/*
//左右操作符匹配算法
bool is_left(const char* l)
{
	return (((char)l == '<') || ((char)l == '(') || ((char)l == '[') || ((char)l == '{'));
}

bool is_right(const char* r)
{
	return (((char)r == '>') || ((char)r == ')') || ((char)r == ']') || ((char)r == '}'));
}

bool is_match(const char* l, const char* r)
{
	return ((((char)l== '<')&&((char)r== '>')) ||
		(((char)l == '(') && ((char)r == ')'))||
		(((char)l == '[') && ((char)r == ']'))||
		(((char)l == '{') && ((char)r == '}'))||
		(((char)l == '\'') && ((char)r == '\''))||
		(((char)l== '\"') && ((char)r== '\"'))
		);
}

bool is_quot(const char* q)
{
	return (((char)q == '\"') || ((char)q == '\''));
}

bool scan(const char* code)
{
	int i = 0;
	bool ret = TRUE;
	code= (code == NULL) ? "" : code;
	LinkStack<char> stack;

	while (ret && (code[i] != '\0'))
	{
		if (is_left((char*)code[i]))
		{
			stack.push(code[i]);
			cout << "match" << endl;
		}
		else if(is_right((char*)code[i]))
		{
			if ((stack.size() != 0)&&(is_match((char*)stack.top(),(char*)code[i])))
			{
				stack.pop();
			}
			else
			{
				ret = FALSE;
			}
		}
		else if (is_quot((char*)code[i]))
		{
			if (stack.size() == 0 || !is_match((char*)stack.top(), (char*)code[i]))
			{
				stack.push(code[i]);
			}
			else if(is_match((char*)stack.top(), (char*)code[i]))
			{
				stack.pop();
			}
		}
		i++;
		cout << i << endl;
	}
	return ret&&(stack.size()==0);
}
*/

#endif
