#ifndef STATICLINKLIST_H_
#define STATICLINKLIST_H_
#include "LinkList.h"

namespace mylib
{
	template<typename T,int N>
	class StaticLinkList :public LinkList<T>
	{
	protected:
		typedef typename LinkList<T>::Node Node;
		struct SNode :public Node
		{
			void* operator new(unsigned int size, void* loc)
			{
				return loc;
			}
		};
		unsigned char m_space[sizeof(SNode) * N];//�����������õ�����������
		int m_space[N];
		Node* create()
		{
			SNode* ret = 0;
			for (int i = 0; i < N; i++)
			{
				if (!m_space[i])
				{
					ret = reinterpret_cast<SNode*>(m_space) +i;//���������ڴ棬���������캯���ĵ���
					/*������Ϊnodeָ�������������������=��+-1�����ƶ�node����С��λ��*/
					ret = new(ret)SNode();//��ret�ռ��ڲ�������
					break;
				}
				return ret;
			}
		}
	};
}

#endif 
