#ifndef _OBJECT_H_
#define _OBJECT_H_
namespace mylib
{
class Object
{
	public:
		void* operator new (size_t size)throw();
		void operator delete(void* p);
		void* operator new[](size_t size)throw();
		void operator delete[](void* p);
		virtual ~Object();
};
}
#endif
