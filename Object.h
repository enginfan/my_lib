#ifndef _OBJECT_H_
#define _OBJECT_H_
using namespace std;
//#define NULL 0
#define TRUE 1
#define FALSE 0
#include <cstdlib>
namespace mylib
{
class Object
{
	public:
        void* operator new (std::size_t)throw();
		void operator delete(void* p);
        void* operator new[](std::size_t)throw();
		void operator delete[](void* p);
		bool operator ==(const Object& Obj)
		{
			return(this == &Obj);//�����þ���ĳһ������Ŀ�꣩��һ�������������õĲ�����Ա���ֱ�Ӳ�����ȫһ��''
		}
		bool operator !=(const Object& Obj)
		{
			return(this != &Obj);
		}
		virtual ~Object();
};
}
#endif
