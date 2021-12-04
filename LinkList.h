#ifndef LINKLIST_H_
#define LINKLIST_H_
#include "List.h"
namespace mylib
{
	template <typename T>
	class LinkList :public List <T>
	{
	protected:
		struct Node :public Object
		{
			T value;
			Node* next;
		};
		mutable Node m_header;
		int m_length;
	public:
		LinkList()
		{
			m_header.next = 0;
			m_length = 0;
		}
		bool insert(int i,const T& e)
		{
			bool ret = ((i >= 0) && (i <= m_length));
			if (ret)
			{
				Node* node = new Node();
				if (node != 0)
				{
					Node* current = &m_header;
					for (int p = 0; p < i; p++)
					{
						current = current->next;//此处只是复制一个指向下个node的指针
					}
					node->value = e;
					node->next = current->next;
					current->next = node;//通过指针操作更改节点的指向m
					m_length++;
				}
				else
				{
					cout << "Insert_Error" << endl;
				}
			}
			return ret;
		}
		bool insert(const T& e)
		{
			return insert(m_length, e);
		}
		bool remove(int i)
		{
			bool ret((i >= 0) && (i < m_length));
			if (ret)
			{
				Node* current = &m_header;
				for (int p = 0; p<i; p++)
				{
					current = current->next;
				}
				Node* ToDel = current->next;
				current->next = ToDel->next;
				delete ToDel;
				m_length--;
			}
			return ret;
		}
		bool set (int i,const T& e)
		{
			bool ret = ((i >= 0) && (i < m_length));
			if(ret)
			{
				Node* current = &m_header;
				for (int p = 0; p < i; p++)
				{
					current = current->next;
				}
				Node* v = current->next;
				v->value = e;
			}
			return ret;
		}
		bool get(int i, T& e)
		{
			bool ret = ((i >= 0) && (i < m_length));
			if (ret)
			{
				Node* current = &m_header;
				for (int p = 0; p < i; p++)
				{
					current = current->next;
				}
				Node* v = current->next;
				e=v->value;
			}
			return ret;
		}
		int length()const
		{
			return m_length;
		}
		void clear()
		{
			while (m_header.next)
			{
				Node* ToDel = m_header.next;
				m_header.next =ToDel->next;
				delete ToDel;
			}
			m_length = 0;
		}
		~LinkList()
		{
			clear();
		}
	};
}

#endif
