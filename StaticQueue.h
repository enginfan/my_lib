#pragma once
#ifndef STATICQUEUE_H
#define STATICQUEUE_H
#include "Exception.h"
#include "Queue.h"

namespace mylib
{
	template<typename T,int N>
	class StaticQueue :public Queue<T>
	{
	protected:
		T m_space[N];
		int m_front;
		int m_rear;
		int m_length;
	public:
		StaticQueue()
		{
			m_front = 0;
			m_rear = 0;
			m_length = 0;
		}

		void add(const T& e)
		{
			if (m_length < N)
			{
				m_space[m_rear] = e;
				m_rear = (m_rear + 1) % N;//此处使用循环计数法
				m_length++;
			}
			else
			{
				THROW_EXCEPTION(IndexOutOfBoundsException, "indexOutOfMemory", "StaticQueue", "35");
			}
		}

		void remove()
		{
			if (m_length > 0)
			{
				m_front = (m_front + 1) % N;
				m_length--;
			}
			else
			{
				THROW_EXCEPTION(IndexOutOfBoundsException, "indexOutOfMemory", "StaticQueue", "48");
			}
		}

		T front()const 
		{
			return m_space[m_front];
		}

		void clear()
		{
			m_front = 0;
			m_rear = 0;
			m_length = 0;
		}

		int length()const
		{
			return m_length;
		}

		int capcicty()const
		{
			return N;
		}
	};
}

#endif