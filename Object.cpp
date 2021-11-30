#include "Object.h"
#include <cstdlib>
namespace mylib
{
	void* Object::operator new(std::size_t size)throw()
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