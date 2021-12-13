#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "LinkList.h"

namespace mylib
{
	template <typename T>
	class CircleList :public LinkList<T>
	{
	protected:
		typedef typename LinkList::Node Node;
		Node* last() const
		{
			return this->position(this->m_length-1)->next;
		}
		void last_to_first() const
		{
			last()->next = this->m_header.next;
		}
		int mod(int i)
		{
			return (this->m_length == 0) ? 0 : (i % this->m_length);
		}
	public:
		bool insert(const T& e)
		{
			return insert(this->m_length, e);
		}
		bool insert(int i, const T& e)
		{
			bool ret = true;
			i = i % (this->m_length + 1);
			ret = LinkList<T>::insert(i, e);
			if ((ret) && i == 0)
			{
				last_to_first();
			}
			return ret;
		}
		bool remove(int i)
		{
			bool ret = true;
			if (i == 0)
			{
				Node* toDel = this->m_header.next;
				if (toDel != 0)
				{
					this->m_header.next = toDel->next;
					this->m_length--;
					if (this->m_length > 0)
					{
						last_to_first();
						if (this->m_current == toDel)
						{
							this->m_current = toDel->next;
						}
					}
					else
					{
						this->m_header.next = 0;
						this->m_current = 0;
					}
					this->destroy(toDel);//异常安全调用父类函数时要使用this指针
				}
				else
				{
					ret = false;
				}
			}
			else
			{
				ret=LinkList<T>::remove(i);
			}
			return ret;//注意单一出口原则
		}
		bool set(int i, const T& e)
		{
			return LinkList<T>::set(mod(i), e);
		}
		T get(i)const
		{
			return LinkList<T>::get(mod(i));
		}
		bool get(int i, T& e) const
		{
			return LinkList<T>::get(mod(i),e);
		}
	};
}
#endif