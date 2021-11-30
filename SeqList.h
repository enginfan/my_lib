#ifndef SEQUEST_H_
#define SEQUEST_H_
#include "List.h"
namespace mylib
{
	template <typename T>
	class Seqlist :public List<T>
	{
	protected:
		T* m_array;
		int m_length;
	public:
		bool insert(const T& e)
		{
			bool ret = (m_length + 1 <= capcity());
			if (ret)
			{
				m_array[m_length] = e;
				m_length++;
			}
			return ret;
		}
		bool insert(int i, const T& e)
		{
			bool ret = ((i >= 0) && (i <=m_length));
			ret = ((ret) && (m_length + 1 <= capcity()));
			if (ret)
			{
				for (int p = m_length - 1; p >= i; p--)
				{
					m_array[p + 1] = m_array[p];
				}
				m_array[i] = e;
				m_length++;
				cout << "m_length=" << m_length << endl;
			}
			return ret;
		}
		bool remove(int i)
		{
			bool ret = ((i >= 0) && (i <=m_length));
			cout << "ret=" << ret << endl;
			if (ret)
			{
				for (int p = i; p < m_length - 1; p++)
				{
					m_array[p] = m_array[p + 1];
				}
				m_length--;
			}
			return ret;
		}
		bool set(int i, const T& e)
		{
			bool ret = ((i >= 0) && (i <m_length));
			if (ret)
			{
				m_array[i] = e;
			}
			return ret;
		}
		bool get(int i, T& e)
		{
			bool ret = ((i <= 0) && (i < m_length));
			if (ret)
			{
				e = m_array[i];
			}
			return ret;
		}
		int length()const
		{
			return m_length;
		}
		void clear()
		{
			m_length = 0;
		}
		//重载数组操作符
		T& operator[](int i)
		{
			return m_array[i];
		}
		T operator[](int i)const
		{
			return m_array[i];
		}
		//数组容量确定
		virtual int capcity() const= 0;
	};
}

#endif
