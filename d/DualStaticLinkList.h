#pragma once 
#ifndef	DUALSTATICLINKLIST_H
#define DUALSTATICLINKLIST_H

#include "DualLinkList.h"
#include <iostream>
namespace mylib
{
	template <typename T,int N> 
	class DualStaticLinkList :public DualLinkList<T>
	{
	protected:
		typedef typename DualLinkList<T>::Node Node;
		struct SNode :public Node
		{
			void* operator new(size_t size, void* loc)
			{
				return loc;
			}
		};
		unsigned char m_space[sizeof(T) * N];
		int m_used[N];
		SNode* create()//使用const修饰可以防止内部成员指针包括this发生莫名其妙的错误//m_used[]内部数列也会变化！！
		{
			SNode* re = 0;
			for (int i = 0; i < N; i++)
			{
				if (!m_used[i])
				{
					re = reinterpret_cast<SNode*>(m_space)+i;
					re = new(re)SNode();
					m_used[i] = 1;
					cout << "creat()" << endl;
					return re;
					break;
				}
				else
				{
					
				}
			}
		}
		void destroy(Node* pn)
		{
			SNode* psn = dynamic_cast<SNode*>(pn);
			SNode* space = reinterpret_cast<SNode*>(m_space);
			for (int i=0; i < N; i++)
			{
				if (psn == (space+i))
				{
					m_used[i] = 0;
					psn->~SNode();
					break;
				}
			}
		}
	public:
		DualStaticLinkList()
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
		~DualStaticLinkList()
		{
			this->clear();
		}
	};
}

#endif