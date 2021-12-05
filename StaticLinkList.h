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
		unsigned char m_space[sizeof(SNode) * N];//中括号内设置的是数组数量
		int m_space[N];
		Node* create()
		{
			SNode* ret = 0;
			for (int i = 0; i < N; i++)
			{
				if (!m_space[i])
				{
					ret = reinterpret_cast<SNode*>(m_space) +i;//单纯分配内存，不包括构造函数的调用
					/*把他变为node指针后就是类似与数组操作=》+-1就是移动node个大小的位置*/
					ret = new(ret)SNode();//在ret空间内产生对象？
					break;
				}
				return ret;
			}
		}
	};
}

#endif 
