#pragma once

#include "Object.h"
#include "Array.h"

namespace mylib
{
	class Sort :public Object
	{
	private:
        Sort();
        //���캯�����������캯������ֵ���캯��ȫ��������Ϊ˽�е�
        //��ʱ˵��sort�������ǲ������ж����
		Sort(const Sort&);//һ�㺯����������ֻд�β�����,�����β���//���������У������������β������б���
						 //ͬ�����ں���������, ��������ڲ����õ��˲���ʱ, ����ֻ��������, �����������Բ��ø���
		Sort& operator=(const Sort&);
        template< typename T >
		static void swap(T& a, T& b)
		{
			T c(a) ;
			a = b;
			b = c;
		}

		template <typename T>
		static void Merge(T src[], T helper[], int begin, int mid, int end, bool min2max)
		{
			int i = begin;
			int k = mid + 1;
			int j = begin;
			while((i <= mid) && (k <= end))
			{
				if (min2max ? (src[i]<=src[k]) : (src[i]>=src[k]))
				{
					helper[j++] = src[i++];
				}
				else
				{
					helper[j++] = src[k++];
				}
			}
			while (i <= mid)
			{
				helper[j++] = src[i++];
			}
			while (k <= end)
			{
				helper[j++] = src[k++];
			}
			for (i = begin; i <= end; i++)
			{
				src[i] = helper[i];
			}
		}

		template <typename T>
		static void Merge(T src[], T helper[], int begin, int end, bool min2max)
		{
			if (begin < end)
			{
				int mid = (begin + end) / 2;
				Merge(src, helper, begin, mid, min2max);
				Merge(src, helper, mid + 1, end, min2max);
				Merge(src, helper, begin, mid, end, min2max);
			}
		}


		template <typename T>
		static int partition(T array[], int begin, int end, bool min2max )
		{
			T pv = array[begin];
			while (begin < end)
			{
				while ((begin < end) && (min2max ? (array[end] > pv) : (array[end] < pv)))
				{
					end--;
				}
				swap(array[begin], array[end]);
				while ((begin < end) && (min2max ? (array[begin] <= pv) : (array[begin] >= pv)))
				{
					begin++;
				}
				swap(array[begin], array[end]);
			}
			return begin;
		}

		template<typename T>
		static void Quik(T array[], int begin,int end, bool min2max)
		{
			if (begin < end)
			{
				int pivot = partition(array, begin, end, min2max);
				Quik(array, begin, pivot - 1, min2max);
				Quik(array, pivot + 1, end, min2max);
			}
		}

	public:

		template<typename T>
		static void Select(T array[], int len,bool min2max=true)//����ԭ����ͬ��������˳���ǲ��ȶ�������
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

		//���ò��������ϣ������
		template<typename T>
        static void Shell(T array[], int len, bool min2max = true){
			int d = len;
			do{
                d = d / 3 + 1;
                for(int i=d;i<len;i+=d){
                    int k = i;
                    T e = array[i];

                    for (int j = i - d; (j >= 0) && (min2max ? array[j] > e:array[j] < e);j -= d){
                        array[j + d] = array[j];
                        k = j;
                    }
                    if (k != i){
                        array[k] = e;
                    }
                }

            } while (d > 1);
		}

		//����ð�������ϣ������
		template<typename T>
		static void Shell2(T array[], int len, bool min2max = true)
		{
			int d = len;
			do
			{
				d = d / 3 + 1;
				int u = 0;
				do
				{
					bool exchange = true;
					for (int i = u; (i<len)&&(exchange); i+=d)
					{
						exchange = false;
						int v = (len - u) / d;
						for (int j =(u+v*d<len?u+v*d:u+(v-1)*d); j > i; j -= d)
						{
							if (min2max ? (array[j]<array[j - d]) : (array[j - d]<array[j]))
							{
								swap(array[j], array[j - d]);
								exchange = true;
							}
						}
					}
					u++;
				} while (u<d);
			} while (d > 1);
		}

		//�鲢����
		template <typename T>
		static void Merge(T array[], int len, bool min2max = true)
		{
			T* helper = new T[len];
			if (helper != NULL)
			{
				Merge(array, helper,0, len-1, min2max);
			}
			delete[] helper;
		}

		template<typename T>
		static void Quik(T array[], int len, bool min2max = true)
		{
			Quik(array, 0, len - 1, min2max);
		}

		/*template <typename T>
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
		}*/

		template<typename T>
		static void Select(Array<T>& array, bool min2max=true)
		{
			Select(array.array(), array.length(), min2max);
		}

		template<typename T>
		static void Insert(Array<T>& array, bool min2max = true)
		{
			Insert(array.array(),array.length(),min2max );
		}

		template <typename T>
		static void Bubble(Array<T>& array, bool min2max = true)
		{
			Bubble(array.array(), array.length(), min2max);
		}

		template <typename T>
		static void Shell(Array<T>& array,bool min2max=true)
		{
			Shell(array.array(), array.length(), min2max);
		}

		template <typename T>
		static void Merge(Array<T>& array, bool min2max = true)
		{
			Merge(array.array(), array.length(), min2max);
		}

		template <typename T>
		static void Quik(Array<T>& array, bool min2max = true)
		{
			Quik(array.array(), array.length(), min2max);
		}
	};
}
