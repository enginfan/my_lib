#pragma once
#ifndef STATICSTACK_H
#define STATICSTACK_H

#include"Stack.h"

namespace mylib
{
	template <typename T,int N>
	class StaticStack :public Stack<T>
	{
	protected:
		T m_space[N];
		int m_top;
		int m_size;
	public:
		StaticStack()
		{
			m_top = -1;
			m_size = 0;
		}

		int capcity()const
		{
			return N;
		}

		void push(const T& e)
		{
			if (m_size < N)
			{
				m_space[m_top + 1] = e;//Òì³£°²È«
				m_size++;
				m_top++;
			}
			else
			{

			}
		};

		void pop()
		{
			if (m_size > 0)
			{
				m_size--;
				m_top--;
			}
			else
			{

			}
		}

		T top()const
		{
			return m_space[m_top];
		};

		void clear()
		{
			m_size = 0;
			m_top = -1;
		};

		int size()const
		{
			return m_size;
		};
	};

}

#endif // !STATICSTACK_H
