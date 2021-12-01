#ifndef DYNAMICLIST_H_
#define DYNAMICLIST_H_
#include "SeqList.h"
#include<iostream>

namespace mylib
{
	template <typename T>
	class DynamicList :public Seqlist<T>
	{
	protected:
		int m_capcity;
	public:
		DynamicList(int cap)
		{
			this->m_array = new T[cap];
			if (this->m_array != NULL)
			{
				this->m_capcity = cap;
				this->m_length = 0;
			}
			else
			{
				cout << "MemoryError" << endl;
			}
		}
		int capcity()const
		{
			return m_capcity;
		}
		void resize(int cap)
		{
			if (capcity != cap)
			{
				T* array = new T[cap];
				if (array != NULL)
				{
					int length = (this->m_length < cap ? this->m_length : cap);
					for (int i = 0; i < length; i++)
					{
						array[i] = this->m_array[i];
					}
					T* temp = this->m_array;
					this->m_array = array;
					this->m_length = length;
					this->m_capcity = cap;
					delete[] temp;
				}
				else 
				{
					cout << "ResizeError" << endl;
				}
			}
		}
		~DynamicList()
		{
			delete[] this->m_array;
		}
	};
}
//��C++�����������ģ���ֱ࣬�ӵ��ø����Ա�Ļ����ᱨ���Ҳ����ñ����������ԭ������Ϊģ��Ķ��α�����Ƶ��µġ�
//ģ�嶨��׶Σ���һ�׶Σ���
//ֻ��ģ���к�ģ������޹ص����ֽ��в��ң�������Щ��ģ������Ĳ��֣���������ģ���࣬�ڵ�һ�α����ʱ��ᱻ���ӵ���
//for instance��
//�����ϱߵ����ӣ�
//StaticList�̳���SeqList���ڵ�һ�α����ʱ�����������Ե�SeqList����װû�п�������
// ���SeqList�еĳ�Աm_array��length��˳����µر������ˡ�
// ��StaticList��û���ٴζ���m_array��length����˱������ڵ�һ�α����ʱ���޷��ҵ�m_array��lengthֱ�ӱ����ˡ�
//
//ģ��ʵ�����׶Σ��ڶ��׶Σ�
//�ڵڶ��׶α�������Ҫ�����ģ������Ĳ��֣����к�ģ����صĲ������ڸý׶���ɡ�
//����һ�����ӣ�Ҳ�����ϱ�����Ľ��������
//����������У���ÿ����Ա����֮ǰ������Base::����thisָ�룬ͨ��Base::����thisָ�룬
//����Ա�����ϵ��ڶ��׶ν��б��롣thisָ���ߵ����ݶ��ǳ�Ա���������ڳ�Ա���������������
//��һ�־����ڵ�ǰ���ж���ı��������ڵ�һ�׶ε�ʱ����м�顣����һ�׶��޷����ҵ��ó�Ա��ʱ��
//�ͻῼ���ǲ��Ǹ���ĳ�Ա�����������һ��ģ���࣬��ô��Ҫ�ڵڶ��׶ν��б��룬��˱��������¼�������Ա��
//�ȵ��ڶ��׶�ȥ�����жԸó�Ա���в���
#endif 
