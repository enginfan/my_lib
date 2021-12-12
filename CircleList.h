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
	};
}
#endif