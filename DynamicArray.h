#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <iostream>
#include "Array.h"
namespace mylib
{//¶àÎ¬Êý×éDynamicArray<DynamicArray<int>>d;
	template <typename T>
	class DynamicArray :public Array<T>
	{
	protected:
		int m_length;
	public:
		DynamicArray(int length=0)
		{
			this->m_array = new T[length];
			if (this->m_array != NULL)
			{
				this->m_length = length;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "DynamicArray construct failed", "DynamicArray.h", 23);
			}
		}
		DynamicArray(const DynamicArray<T>& dyna)
		{
			this->m_array = new T[dyna.m_length];
			if (this->m_array != NULL)
			{
				this->m_length = dyna.m_length;
				for (int i=0; i < dyna.m_length; i++)
				{
					this->m_array[i] = dyna.m_array[i];
				}
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "DynamicArray construct failed", "DynamicArray.h", 39);
			}
		}
		DynamicArray<T>& operator=(const DynamicArray<T>& dyna)
		{
			if (this != &dyna)
			{
				T* array = new T[dyna.m_length];
				if (array != NULL)
				{
					for (int i = 0; i < dyna.m_length; i++)
					{
						array[i] = dyna.m_array[i];
					}
					T* temp = this->m_array;
					this->m_array = array;
					this->m_length = dyna.m_length;
					delete[] temp;
				}
			}
			return *this;
		}
		int length()const
		{
			return m_length;
		}
		void resize(int len)
		{
			if (len!=m_length)
			{
				T* array = new T[len];
				if (array!=NULL)
				{
					int length = (len > this->m_length ? this->m_length : len );
					for (int i = 0; i < length; i++)
					{
						array[i] = this->m_array[i];
					}
					T* temp = this->m_array;
					this->m_array = array;
					this->m_length = len;
					delete[] temp;
				}
				else
				{
					THROW_EXCEPTION(NoEnoughMemoryException, "resize operation fail", "DynamicArray.h", 84);
				}
			}
		}
		~DynamicArray()
		{
			delete[] this->m_array;
		}
	};
}
#endif 