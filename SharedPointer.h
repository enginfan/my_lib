#ifndef SHAREDPOINTER_H_
#define SHAREDPOINTER_H_
#include"Pointer.h"
#include<cstdlib>
using namespace mylib;
namespace mylib
{
	template <typename T>
	class SharedPointer :public Pointer<T>
	{
	protected:
		int* m_ref;
		void assign(const SharedPointer<T>& obj)
		{
			this->m_pointer = obj.m_pointer;
			this->m_ref = obj.m_ref;
			if (this->m_ref)
			{
				*(this->m_ref) = *(this->m_ref) + 1;
			}
		}
	public:
		SharedPointer(T* p = 0) :m_ref(0), Pointer<T>(p)//�ڸ���û���޲ι��캯��ʱ������ʽ���ø��๹�캯������p=NULL����pointerָ���޷���ʼ��
		{
			if (p)
			{
				this->m_ref = static_cast<int*>(malloc(sizeof(int)));
				if (this->m_ref)
				{
					*(this->m_ref) = 1;
				}
				else
				{
					cout << "Sharepointer_error" << endl;
				}
			}
		}
		SharedPointer(const SharedPointer<T>& obj) :Pointer<T>(obj.m_pointer)
		{
			assign(obj);
		}
		SharedPointer& operator=(const SharedPointer<T>& obj)
		{
			if (this != &obj)
			{
				assign(obj);
			}
			return *this;
		}
		void clear()
		{
			int* ref = this->m_ref;
			T* ToDel = this->m_pointer;//thisָ��һ��ָ��̬��Ա
			this->m_ref = 0;
			this->m_pointer = 0;
			if (ref)
			{
				(*ref)--;
				if (*ref == 0)
				{
					delete ToDel;
					free(ref);
				}
			}
		}
		~SharedPointer()
		{
			clear();
		}
	};
};
//��ȫ�����رȽϲ�����
template<typename T>
bool operator==(const SharedPointer<T>& ob1, const SharedPointer<T>& ob2)
{
	return (ob1.get() == ob2.get());
}
template<typename T>
bool operator!= (const SharedPointer<T>& ob1, const SharedPointer<T>& ob2)
{
	return !(ob1 == ob2);
}
#endif
