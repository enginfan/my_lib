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
		unsigned char m_space[sizeof(SNode) * N];//中括号内设置的是数组数量
		int m_used[N];
		SNode* create()
		{
			SNode* re = 0;
			for (int i = 0; i < N; i++)
			{
				if (!m_used[i])
				{
					re = reinterpret_cast<SNode*>(m_space) +i;//单纯分配内存，不包括构造函数的调用
					/*把他变为node指针后就是类似与数组操作=》+-1就是移动node个大小的位置*/
					re = new(re)SNode();//在ret空间内产生对象并调用构造对象T的构造函数 SNode（）是空间类型
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
			this->clear();//解决父类析构函数释放静态空间报错的问题同时链表内部对象的析构问题
			//如果粗暴的使用LinkList<T>::m_header.next=0;会使得内部对象无法析构
		}
	};
}

#endif 
