#include "Object.h"
#include <cstdlib>
namespace mylib
{
	void* Object::operator new(std::size_t size)throw()//保证如果申请值失败不抛出异常而返回空指针
	{
		return malloc(size);
	}
	void Object::operator delete(void* p)
	{
		free(p);
	}
	void* Object::operator new[](std::size_t size)throw()
	{
		return malloc(size);
	}
	void Object::operator delete[](void* p)
	{
		free(p);
	}
	Object::~Object() {};
}