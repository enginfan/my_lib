#ifndef STATICLINKLIST_H_
#define STATICLINKLIST_H_
#include "LinkList.h"

namespace mylib
{
	template<typename T,int N>
	class StaticLinkList:public  LinkList<T>
	{
	protected:
		typedef typename LinkList<T>::Node Node;
		struct SNode :public Node
		{
			void* operator new( std::size_t size, void* loc)
			{
				return loc;
			}
		};
		unsigned char m_space[sizeof(SNode) * N];//�����������õ�����������
		int m_used[N];
		SNode* create()
		{
			SNode* re = 0;
			for (int i = 0; i < N; i++)
			{
				if (!m_used[i])
				{
					re = reinterpret_cast<SNode*>(m_space) +i;//���������ڴ棬���������캯���ĵ���
					/*������Ϊnodeָ�������������������=��+-1�����ƶ�node����С��λ��*/
					re = new(re)SNode();//��ret�ռ��ڲ������󲢵��ù������T�Ĺ��캯�� SNode�����ǿռ�����
					m_used[i] = 1;
					return re;
					break;
				}
			}
			cout << "SNode_Create_Error" << endl;
		}
		void destroy(Node* pn)
		{
			SNode* space =reinterpret_cast<SNode*>(m_space);
			SNode* psn = dynamic_cast<SNode*>(pn);
			for (int i = 0; i < N; i++)
			{
				if (psn == (space + i))
				{
					m_used[i] = 0;
					psn->~SNode();
					break;
				}
			}
		}
	public:
		StaticLinkList()
		{
			for (int i = 0; i < N; i++)
			{
				m_used[i] = 0;
			}
		}
		int capcity()
		{
			return N;
		}
		~StaticLinkList()
		{
			this->clear();//����������������ͷž�̬�ռ䱨�������ͬʱ�����ڲ��������������
			//����ֱ���ʹ��LinkList<T>::m_header.next=0;��ʹ���ڲ������޷�����
		}
	};
}

#endif 
