#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
using namespace std;
namespace mylib
{ 
	template <typename T>
	class SmartPointer
	{
	protected:
		T* m_pointer;
	public:
		SmartPointer(T* p = 0)
		{
		m_pointer = p;
		}
		T* operator ->()const
		{
			return m_pointer;
		}
		T& operator *()//此处必须是引用否则没法用.操作符
		{
			return *m_pointer;
		}
		bool isnull()
		{
			return (m_pointer == 0);
		}
		T* get()const
		{
			return m_pointer;
		}
		SmartPointer(const SmartPointer<T>& p)
		{
			m_pointer = p.m_pointer;
			const_cast<SmartPointer<T>&>(p).m_pointer = 0;
		}
		SmartPointer<T>& operator=(const SmartPointer<T>& p)
		{
			if (*this != p)
			{
				delete m_pointer;
				m_pointer = p.m_pointer;
				const_cast<SmartPointer<T>&>(p).m_pointer = 0;
			}
			return *this;
		}
		~SmartPointer()
		{
			delete m_pointer;
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

