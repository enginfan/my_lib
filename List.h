#ifndef _LIST_H_
#define _LIST_H_
#include"Object.h"
namespace mylib
{
	template <typename T>
	class List :public Object
	{
	public:
		virtual bool insert(const T& e) = 0;
		virtual bool insert(int t, const T& e) = 0;
		virtual bool remove(int i) = 0;
		virtual bool set(int i,const T& e) = 0;
		virtual bool get(int i, T& e)const = 0;
		virtual int length()const = 0;
		virtual void clear() = 0;
	};
}
#endif
