#ifndef DUALCIRCLELIST_H
#define DUALCIRCLELIST_H

#include "LinuxList.h"
#include "DualLinkList.h"

namespace mylib
{
	template <typename T>
	class DualCircleList :public DualLinkList<T>
	{
	protected:
		struct Node :public Object
		{
			list_head head;
			T value;
		};

		list_head m_header;
		list_head m_current;

		list_head* position(int i)const
		{
			list_head* ret = reinterpret_cast<list_head*>(&m_header);
			for (int p = 0; p < i; p++)
			{
				ret = ret->next;
			}
			return ret;
		}

		int mod(int i)
		{
			return (this->m_length == 0) ? 0 : (i % this->m_length);
		}
	public:
		DualCircleList()
		{
			this->m_length = 0;
			this->m_step = 1;

			m_current = NULL;

			INIT_LIST_HEAD(&m_header);
		}

		bool insert(const T& e)
		{
			return insert(this->m_length, e);
		}

		bool insert(int i, const T& e)
		{
			bool ret = ((i>=0)&&(i<=this->m_length));
			Node* node = new Node();
			i = i % (this->m_length + 1);
			if (node!=NULL)
			{
				node->value = e;
				list_add_tail()


			}

		}

	};
}

#endif
