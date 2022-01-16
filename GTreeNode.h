#pragma once
#ifndef GTreeNode_H
#define GTreeNode_H

#include "TreeNode.h"
#include "LinkList.h"

namespace mylib
{
	template <typename T>
	class GTreeNode :public TreeNode<T>
	{
    protected:
        bool m_flag;

        void* operator new(size_t size)throw()
        {
            return Object::operator new(size);
        }
	public:
		LinkList<GTreeNode<T>*> child;
        GTreeNode()
        {
            m_flag = false;
        }
        bool flag()
        {
            return m_flag;
        }
        static GTreeNode<T>* NewNode()
        {
            GTreeNode<T>* ret = new GTreeNode<T>();

            if (ret != NULL)
            {
                ret->m_flag = true;
            }

            return ret;
        }
	};
}

#endif // !GTreeNode_H

