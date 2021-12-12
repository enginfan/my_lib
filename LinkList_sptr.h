#ifndef LINKLIST_H_
#define LINKLIST_H_
#include "List.h"
#include "SharedPointer.h"
namespace mylib
{
	template <typename T>
	class LinkList :public List <T>
	{
	protected:
		struct Node :public Object
		{
			T value;
			//Node* next;
			SharedPointer<Node> next;
		};
		mutable struct :public Object
		{
			char reserved[sizeof(T)];
			SharedPointer<Node> next;
		}m_header;
		int m_length;
		//Node* m_current;
		SharedPointer<Node> m_current;
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
		const SharedPointer<Node> header;
	public:
		LinkList():header(reinterpret_cast<Node*> (&m_header))//const 修饰的成员常量要在初始化列表中设置
			/*话说有几个地方必须在构造函数的初始化列表中(详见)：
			类的const常量
			类的引用类型成员
			没有默认构造函数的类类型成员
			如果类存在继承关系，派生类必须在其初始化列表中调用基类的构造函数*/
		{
			//header= reinterpret_cast<Node*> (&m_header);
			m_header.next = 0;
			m_length = 0;
		}
		bool insert(int i,const T& e)
		{
			bool ret = ((i >= 0) && (i <= m_length));
			if (ret)
			{
				SharedPointer<Node> node =0;
				node = create();
				if (!node.isNull())
				{
					//for (int p = 0; p < i; p++)
					//{
					//	current = current->next;//此处只是复制一个指向下个node的指针
					//}
					node->value = e;
					node->next = (*position(i)).next;//必须使用这个形式否则会发生删除节点的情况
					(*position(i)).next = node;//通过指针操作更改节点的指向m
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
				SharedPointer<Node> ToDel = (*position(i)).next;//current是指向前一位数
				(*position(i)).next = ToDel->next;
				if (m_current == ToDel)//当current指向Todel时在删除后会报错
				{
					next();
				}
				m_length--;//为了抛异常的安全
				//destroy(ToDel);
			}
			return ret;
		}
		bool set (int i,const T& e)
		{
			bool ret = ((i >= 0) && (i < m_length));
			if(ret)
			{
				SharedPointer<Node> current = position(i);
				SharedPointer<Node> v = current->next;
				v->value = e;
			}
			return ret;
		}
		bool get(int i, T& e)
		{
			bool ret = ((i >= 0) && (i < m_length));
			if (ret)
			{
				SharedPointer<Node> current = position(i);
				SharedPointer<Node> v = current->next;
				e=v->value;
			}
			return ret;
		}
		T get(int i)
		{
			bool ret = ((i >= 0) && (i < m_length));
			if (ret)
			{
				SharedPointer<Node> current = position(i);
				SharedPointer<Node> v = current->next;
				return v->value;
			}
			return 0;
		}
		int length()const
		{
			return m_length;
		}
		void clear()
		{
			
			while (m_header.next.isNull())
			{
				SharedPointer<Node> ToDel = m_header.next;
				m_header.next = ToDel->next;
				//destroy (ToDel);
			}
			m_length = 0;
		}
		~LinkList()
		{
			clear();
		}
		Node* position(int i)const//定位代码
		{
			SharedPointer<Node> ret = header;
			for(int p = 0; p < i; p++)
			{
				ret = ret->next;
			}
			return ret.get();
		}
		int find(const T& e)const
		{
			int ret = -1;
			int i = 0;
			SharedPointer<Node> node = m_header.next;
			while (node.isNull())
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
		//例如可通过如下过程遍历
		//for(list.move(0, 1); !list.end(); list.next())
		bool move(int i, int step = 1)
		{
			bool ret((i >= 0) && (i < m_length) && (step > 0));
			if (ret)
			{
				m_current = position(i)->next;
				m_step = step;
			}
			return ret;
		}
		bool end()
		{
			return(m_current.isNull());
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
