#ifndef LINKLIST_H_
#define LINKLIST_H_
#include "List.h"
namespace mylib
{
	template <typename T>
	class LinkList :public List <T>
	{
	protected:
		int val;//判断析构
		struct Node :public Object
		{
			T value;
			Node* next;
		};
		mutable Node m_header;
		int m_length;
		Node* m_current;
		int m_step;
		//封装申请空间函数语句
		virtual Node* create()
		{
			return new Node();
		}
		virtual void destroy(Node* pn)
		{
			delete pn;
		}
	public:
		LinkList()
		{
			m_header.next = 0;
			m_length = 0;
			val = 1;
		}
		bool insert(int i,const T& e)
		{
			bool ret = ((i >= 0) && (i <= m_length));
			if (ret)
			{
				Node* node =0;
				node = create();
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
				Node* current = posion(i);
				Node* ToDel = current->next;
				current->next = ToDel->next;
				destroy(ToDel);
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
				m_header.next = ToDel->next;
				delete ToDel;
			}
			m_length = 0;
			
			
		}
		~LinkList()
		{
			clear();
		}
		Node* posion(int i)const//定位代码
		{
			Node* ret = reinterpret_cast<Node*> (&m_header);
			for(int p = 0; p < i; p++)
			{
				ret = ret->next;
			}
			return ret;
		}
		int find(const T& e)const
		{
			int ret = -1;
			int i = 0;
			Node* node = m_header.next;
			while (node)
			{
				if (node->value==e)
				{
					ret = i;
					break;
				}
				else
				{
					node = node->next;
				}
				i++;
			}
			return ret;
		}
		//设置游标优化遍历方法
		bool move(int i, int step = 1)
		{
			bool ret((i >= 0) && (i < m_length) && (step > 0));
			if (ret)
			{
				m_current = posion(i)->next;
				m_step = step;
			}
			return ret;
		}
		bool end()
		{
			return(m_current==NULL);
		}
		T current()
		{
			if (!end())
			{
				return m_current->value;
			}
			else
			{
				cout << "AT_THE_END_OF_THE_LIST" << endl;
			}
		}
		bool next()
		{
			int i = 0;
			while ((i < m_step) && (!end()))
			{
				m_current = m_current->next;
				i++;
			}
			return (i == m_step);
		}

	};
}

#endif
