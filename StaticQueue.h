#pragma once
#ifndef STATICQUEUE_H
#define STATICQUEUE_H

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
				m_rear = (m_rear + 1) % N;
				m_length++;
			}
			else
			{

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