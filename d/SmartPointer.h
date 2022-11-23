#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include "Pointer.h"

namespace mylib
{ 
	template <typename T>
	class SmartPointer:public Pointer<T>
	{
	public:
        SmartPointer(int p):Pointer<T>(p)
		{

		}
		SmartPointer(const SmartPointer<T>& p)
		{
			this->m_pointer = p.m_pointer;
			const_cast<SmartPointer<T>&>(p).m_pointer = 0;
		}
		SmartPointer<T>& operator=(const SmartPointer<T>& p)
		{
			if (this != &p)
			{
				//delete m_pointer;这样不够异常安全
				/*异常安全的意思就是，当程序在异常发生的时候，程序可以回退的很干净。
				什么是回退的很干净呢？其实就是函数在发生异常的时候不会泄露资源
				或者不会发生任何数据结构的破坏。如果说一个函数是异常安全的,
				那么它必须满足上面提到的两个条件。*/
				T* d = this->m_pointer;
				this->m_pointer = p.m_pointer;
				const_cast<SmartPointer<T>&>(p).m_pointer = 0;
				delete d;
			}
			return *this;
		}
		~SmartPointer()
		{
			delete this->m_pointer;
		}
	};
}
//NULL对象指针可以调用成员函数
//2）通过对象调用成员函数，对象的指针会被传入函数中，指针名称为this
//3）NULL对象指针调用成员函数时，只要不访问此对象的成员变量，则程序正常运行
//4）NULL对象指针调用成员函数时，一旦访问此对象的成员变量，则程序崩溃例如：cout<<t1->t<<endl;
//SmartPointer <test>m(new test());
//ex
//m->show();//show为指向对象的内部函数
//(*m).show();
#endif // !SMARTPOINTER_H

