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
		T& operator *()//�˴����������÷���û����.������
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
//NULL����ָ����Ե��ó�Ա����
//2��ͨ��������ó�Ա�����������ָ��ᱻ���뺯���У�ָ������Ϊthis
//3��NULL����ָ����ó�Ա����ʱ��ֻҪ�����ʴ˶���ĳ�Ա�������������������
//4��NULL����ָ����ó�Ա����ʱ��һ�����ʴ˶���ĳ�Ա�����������������磺cout<<t1->t<<endl;
//SmartPointer <test>m(new test());
//ex
//m->show();//showΪָ�������ڲ�����
//(*m).show();
#endif // !SMARTPOINTER_H

