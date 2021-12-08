#ifndef POINTER_H_
#define POINTER_H_
#include "Object.h"

namespace mylib
{
	template <typename T>
	class Pointer :public Object
	{
	protected:
		T* m_pointer;
	public:
		Pointer(T* p=0)
		{
			m_pointer = p;
		}
		T* operator-> ()//a->x等价于（*a）.x//本质等价为a.operator()->x; 编译器简化为a->x
		{
			return m_pointer;
		}
		T& operator& ()//此处必须是引用否则没法用.操作符
		{
			return *m_pointer;
		}
		bool isNull()
		{
			return (m_pointer == 0);
		}
		T* get()const
		{
			return m_pointer;
		}
	};
}

#endif
