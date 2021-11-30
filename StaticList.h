#ifndef STATICLIST_H_
#define STATICLIST_H_
#include "SeqList.h"
namespace mylib
{
	template <typename T,int N>
	class StaticList :public Seqlist<T>
	{
	protected:
		T m_space[N];
	public:
		StaticList() 
		{
			this->m_length = 0;
			this->m_array = m_space;
		}
		int capcity()const
		{
			return N;
		}
	};
}
#endif
