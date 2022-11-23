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
		//��װ����ռ亯�����
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
		LinkList():header(reinterpret_cast<Node*> (&m_header))//const ���εĳ�Ա����Ҫ�ڳ�ʼ���б�������
			/*��˵�м����ط������ڹ��캯���ĳ�ʼ���б���(���)��
			���const����
			����������ͳ�Ա
			û��Ĭ�Ϲ��캯���������ͳ�Ա
			�������ڼ̳й�ϵ����������������ʼ���б��е��û���Ĺ��캯��*/
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
					//	current = current->next;//�˴�ֻ�Ǹ���һ��ָ���¸�node��ָ��
					//}
					node->value = e;
					node->next = (*position(i)).next;//����ʹ�������ʽ����ᷢ��ɾ���ڵ�����
					(*position(i)).next = node;//ͨ��ָ��������Ľڵ��ָ��m
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
				SharedPointer<Node> ToDel = (*position(i)).next;//current��ָ��ǰһλ��
				(*position(i)).next = ToDel->next;
				if (m_current == ToDel)//��currentָ��Todelʱ��ɾ����ᱨ��
				{
					next();
				}
				m_length--;//Ϊ�����쳣�İ�ȫ
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
		Node* position(int i)const//��λ����
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
		//�����α��Ż���������
		//�����ͨ�����¹��̱���
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
