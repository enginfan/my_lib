#ifndef DYNAMICLIST_H_
#define DYNAMICLIST_H_
#include "SeqList.h"
#include<iostream>

namespace mylib
{
	template <typename T>
	class DynamicList :public Seqlist<T>
	{
	protected:
		int m_capcity;
	public:
		DynamicList(int cap)
		{
			this->m_array = new T[cap];
			if (this->m_array != NULL)
			{
				this->m_capcity = cap;
				this->m_length = 0;
			}
			else
			{
				cout << "MemoryError" << endl;
			}
		}
		int capcity()const
		{
			return m_capcity;
		}
		void resize(int cap)
		{
			if (capcity != cap)
			{
				T* array = new T[cap];
				if (array != NULL)
				{
					int length = (this->m_length < cap ? this->m_length : cap);
					for (int i = 0; i < length; i++)
					{
						array[i] = this->m_array[i];
					}
					T* temp = this->m_array;
					this->m_array = array;
					this->m_length = length;
					this->m_capcity = cap;
					delete[] temp;
				}
				else 
				{
					cout << "ResizeError" << endl;
				}
			}
		}
		~DynamicList()
		{
			delete[] this->m_array;
		}
	};
}
//在C++中如果父类是模板类，直接调用父类成员的话，会报错找不到该变量，其根本原因是因为模板的二次编译机制导致的。
//模板定义阶段（第一阶段）：
//只对模板中和模板参数无关的名字进行查找（无视那些有模板参数的部分）。父类是模板类，在第一次编译的时候会被无视掉。
//for instance：
//对于上边的例子：
//StaticList继承自SeqList，在第一次编译的时候编译器会忽略掉SeqList，假装没有看到它，
// 因此SeqList中的成员m_array和length就顺理成章地被忽略了。
// 在StaticList中没有再次定义m_array和length，因此编译器在第一次编译的时候无法找到m_array和length直接报错了。
//
//模板实例化阶段（第二阶段）
//在第二阶段编译器主要处理带模板参数的部分，所有和模板相关的操作都在该阶段完成。
//给出一个例子，也就是上边问题的解决方法。
//在这个子类中，在每个成员变量之前加入了Base::或者this指针，通过Base::或者this指针，
//将成员变量拖到第二阶段进行编译。this指针后边的内容都是成员变量，对于成员变量有两种情况，
//第一种就是在当前类中定义的变量，会在第一阶段的时候进行检查。当第一阶段无法查找到该成员的时候，
//就会考虑是不是父类的成员，如果父类是一个模板类，那么需要在第二阶段进行编译，因此编译器会记录下这个成员，
//等到第二阶段去父类中对该成员进行查找
#endif 
