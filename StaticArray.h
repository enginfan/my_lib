#ifndef SATATICARRAY_H_
#define SATATICARRAY_H_
#include "Array.h"
#include "SmartPointer.h"
namespace mylib
{
	template <typename T,int N>
	class StaticArray :public Array<T>
	{
	protected:
		T m_space[N];
	public:
		StaticArray()
		{
			this->m_array = m_space;
		}
		StaticArray(const StaticArray<T, N>& obj)
		{
			this->m_array = m_space;
			for (int i = 0; i < N; i++)
			{
				this->m_array[i] = obj.m_array[i];//space
			}
		}
		StaticArray<T, N>& operator=(const StaticArray<T, N>* obj)
		{
			if (*this != obj)
			{
				for (int i = 0; i < N; i++)
				{
					this->m_space[i] = obj.m_space[i];
				}
			}
			return *this;
		}
		int length()const
		{
			return N;
		}
	};
}
#endif