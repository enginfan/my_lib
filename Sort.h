#pragma once

#include "Object.h"

namespace mylib
{
	class Sort :public Object
	{
	private:
		Sort();
		Sort(const Sort&);//一般函数声明可以只写形参类型,而无形参名//函数申明中，编译器不对形参名进行编译
						 //同样的在函数定义里, 如果函数内不会用到此参数时, 可以只给出类型, 而参数名可以不用给出
		Sort& operator=(const Sort&);
		template<typename T>
		static void swap(T& a, T& b)
		{
			T c(a) ;
			a = b;
			b = c;
		}
	public:

		template<typename T>
		static void Select(T array[], int len,bool min2max=true)//打破原有相同数据排列顺序，是不稳定的排序法
		{
			for (int i = 0; i < len; i++)
			{
				int key = i;
				for (int j = i + 1; j < len; j++)
				{
					if (min2max?array[key] > array[j]:array[key]<array[j])
					{
						key = j;
					}
				}
				if (key!=i)
				{
					swap(array[i], array[key]);
				}
			}
		}

		template<typename T> 
		static void Insert(T array[], int len, bool min2max = true)
		{
			for (int i = 1; i < len; i++)
			{
				int k = i;
				T e = array[i];
				for (int j = i - 1; (j >= 0) && (min2max ? array[j] > e:array[j] < e);j--)
				{
					array[j + 1] = array[j];
					k = j;
				}
				if (k != i)
				{
					array[k] = e;
				}
			}
		}

		template<typename T> 
		static void Bubble(T array[], int len, bool min2max = true)
		{
			bool exchange = true;
			for (int i = 0; (i < len && exchange); i++)
			{
				for (int j = len - 1; j > i; j--)
				{
					exchange = false;
					if (min2max ? (array[j]<array[j - 1]) : (array[j]>array[j - 1]))
					{
						swap(array[j], array[j - 1]);
						exchange = true;
					}
				}
			}
		}

		template<typename T>
		static void Shell(T array[], int len, bool min2max = true)
		{
			int d = len;
			do
			{
				d = d / 3 + 1;
				for (int i = d; i < len; i+=d)
				{
					int k = i;
					T e = array[i];
						for (int j = i-d; (j >=0)&&(min2max ? (array[j] > e) : (array[j] < e)); j -= d)
						{
							array[j + d] = array[j];
							k = j;
						};
					if (k != i)
					{
						array[k] = e;
					}
				};
			}while(d > 1);
		}

	};
}
