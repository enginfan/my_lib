#ifndef _OBJECT_H_
#define _OBJECT_H_
using namespace std;
#define NULL 0
namespace mylib
{
class Object
{
	public:
		void* operator new (size_t size)throw();
		void operator delete(void* p);
		void* operator new[](size_t size)throw();
		void operator delete[](void* p);
		bool operator ==(const Object& Obj)
		{
			return(this == &Obj);//“引用就是某一变量（目标）的一个别名，对引用的操作与对变量直接操作完全一样''
		}
		bool operator !=(const Object& Obj)
		{
			return(this != &Obj);
		}
		virtual ~Object();
};
}
#endif
