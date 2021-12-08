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
		T* operator-> ()//a->x�ȼ��ڣ�*a��.x//���ʵȼ�Ϊa.operator()->x; ��������Ϊa->x
		{
			return m_pointer;
		}
		T& operator& ()//�˴����������÷���û����.������
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
