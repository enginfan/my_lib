#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include"Queue.h"
#include"LinuxList.h"
#include<iostream>

namespace mylib
{
	template<typename T>
	class LinkQueue :public Queue<T>
	{
	protected:
		struct Node: public Object
		{
			list_head head;
			T value;
		};
		list_head m_header;
		int m_length;
	public:
		LinkQueue()
		{
			m_length = 0;
			INIT_LIST_HEAD(&m_header);
		}

		void add(const T& e)
		{
			Node* node = new Node();
			if (node != NULL)
			{
				node->value = e;
				list_add_tail(&node->head, &m_header);
				
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
				list_head* toDel = m_header.next;
				list_del(toDel);
				m_length--;
				delete list_entry(toDel, Node, head);
			}
			else
			{

			}
		}

		T front()const
		{
			if (m_length > 0)
			{
				return list_entry(m_header.next, Node, head)->value;
			}
			else
			{

			}
		}

		void clear()
		{
			while (m_length > 0)
			{
				remove();
			}
		}

		int length()const
		{
			return m_length;
		}

		~LinkQueue()
		{
			clear();
		}
	};
}
//队列实现栈

//template <typename T>
//class QueuetoStack :public Stack<T>
//{
//protected:
//	LinkQueue<T> queue_1;
//	LinkQueue<T> queue_2;
//	LinkQueue<T>* q_in;
//	LinkQueue<T>* q_out;
//
//	void move()const
//	{
//		int n = q_in->length() - 1;
//
//		for (int i = 0; i < n; i++)
//		{
//			q_out->add(q_in->front());
//			q_in->remove();
//		}
//	}
//
//	void swap()
//	{
//		LinkQueue<T>* temp = q_in;
//		q_in = q_out;
//		q_out = temp;
//	}
//
//public:
//	QueuetoStack()
//	{
//		q_in = &queue_1;
//		q_out = &queue_2;
//	}
//
//	void push(const T& e)
//	{
//		q_in->add(e);
//	}
//
//	void pop()
//	{
//		if (q_in->length() > 0)
//		{
//			move();
//			q_in->remove();
//			swap();
//		}
//		else
//		{
//			cout << "POP_ERROR" << endl;
//		}
//	}
//
//	T top()const
//	{
//		if (q_in->length() > 0)
//		{
//			move();
//			return q_in->front();
//		}
//		else
//		{
//			cout << "TOP_ERROR" << endl;
//		}
//	}
//
//	void clear()
//	{
//		q_in->clear();
//		q_out->clear();
//	}
//
//	int size()const
//	{
//		return q_in->length() + q_out->length();
//	}
//
//	~QueuetoStack()
//	{
//		clear();
//	}
//};

#endif
