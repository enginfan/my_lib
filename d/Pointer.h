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
		Pointer(T* p = NULL)
		{
			m_pointer = p;
		}

		T* operator-> ()//a->x�ȼ��ڣ�*a��.x//���ʵȼ�Ϊa.operator()->x; ��������Ϊa->x
		{
			return m_pointer;
		}

		const T& operator* () const//�˴����������÷���û����.������
		{
			return *m_pointer;
		}

		const T* operator-> () const
		{
			return m_pointer;
		}

		T& operator* ()
		{
			return *m_pointer;
		}

		bool isNull() const
		{
			return (m_pointer == NULL);
		}

		T* get() const
		{
			return m_pointer;
		}
	};
}

#endif
