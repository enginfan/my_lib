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
				//delete m_pointer;���������쳣��ȫ
				/*�쳣��ȫ����˼���ǣ����������쳣������ʱ�򣬳�����Ի��˵ĺܸɾ���
				ʲô�ǻ��˵ĺܸɾ��أ���ʵ���Ǻ����ڷ����쳣��ʱ�򲻻�й¶��Դ
				���߲��ᷢ���κ����ݽṹ���ƻ������˵һ���������쳣��ȫ��,
				��ô���������������ᵽ������������*/
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
//NULL����ָ����Ե��ó�Ա����
//2��ͨ��������ó�Ա�����������ָ��ᱻ���뺯���У�ָ������Ϊthis
//3��NULL����ָ����ó�Ա����ʱ��ֻҪ�����ʴ˶���ĳ�Ա�������������������
//4��NULL����ָ����ó�Ա����ʱ��һ�����ʴ˶���ĳ�Ա�����������������磺cout<<t1->t<<endl;
//SmartPointer <test>m(new test());
//ex
//m->show();//showΪָ�������ڲ�����
//(*m).show();
#endif // !SMARTPOINTER_H

