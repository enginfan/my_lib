#ifndef _OBJECT_H_
#define _OBJECT_H_
using namespace std;
//#define NULL 0
#define TRUE 1
#define FALSE 0
#include <cstdlib>
//创建顶层父类的意义
//规范动态内存申请的行为（对于不同编译器，申请失败的行为是不同的）此处保证堆中创建的子类对象在是失败时返回null值
//保证数据结构库具有单一继承的结构
//object作为纯虚父类，能够对所有子类进行动态类型识别

//该数据结构类库的开发方式是
//迭代开发
//采用单一继承树
//只抛异常不处理异常，进而提高可移植性（对于老版本的C++编译器，移植时把宏后的throw注释掉即可）
//弱耦合 尽量不使用标准库中的类和函数，提高可移植性
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
			return(this == &Obj);//“引用就是某一变量（目标）的一个别名，对引用的操作与对变量直接操作完全一样''
		}
		bool operator !=(const Object& Obj)
		{
			return(this != &Obj);
		}
		virtual ~Object()=0;
};
}
#endif
