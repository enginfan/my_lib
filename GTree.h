#pragma once
#ifndef GTREE_H
#define GTREE_H

#include "Tree.h"
#include "GTreeNode.h"

namespace mylib
{
	template<typename T>
	class GTree :public Tree<T>
	{
	public:
        bool insert(TreeNode<T>* node) ;
        bool insert(const T& value, TreeNode<T>* parent) ;
        SharedPointer< Tree<T> > remove(const T& value) ;
        SharedPointer< Tree<T> > remove(TreeNode<T>* node) ;
        TreeNode<T>* find(const T& value) const ;
        TreeNode<T>* find(TreeNode<T>* node) ;
        TreeNode<T>* root() const;
        int degree() const;
        int count() const;
        int height() const;
        void clear() ;
        bool begin() ;
        bool end() ;
        bool next() ;
        T current() ;
	};
}

#endif // !GTREE_H

