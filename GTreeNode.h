#pragma once
#ifndef GTreeNode_H
#define GTreeNode_H

#include "TreeNode.h"
#include "LinkList.h"

namespace mylib
{
	template <typename T>
	class GTreeNode :public TreeNode
	{
	public:
		LinkList<GTreeNode<T>*> child;
	};
}

#endif // !GTreeNode_H

