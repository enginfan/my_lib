#pragma once
#ifndef BTREE_H
#define BTREE_H

#include "Tree.h"
#include "BTreeNode.h"
#include "LinkQueue.h"
#include "DynamicArray.h"

namespace mylib
{
	template<typename T>
	class BTree :public Tree<T>
	{
    protected:
       virtual BTreeNode<T>* find(BTreeNode<T>* node, const T& value)const//const T& value const是限制value值不变
        {
            BTreeNode<T>* ret = NULL;
            if (node != NULL)
            {
                if (node->value == value)
                {
                    ret = node;
                }
                else
                {
                    if (ret == NULL)
                    {
                        ret = find(node->left, value);
                    }
                    if (ret == NULL)
                    {
                        ret = find(node->right, value);
                    }
                }
            }
            return ret;
        }

        virtual BTreeNode<T>* find(BTreeNode<T>* node, BTreeNode<T>* obj)const
        {
            BTreeNode<T>* ret = NULL;
            if (node == obj)
            {
                ret = node;
            }
            else
            {
                if (node != NULL)
                {
                    if (ret == NULL)
                    {
                        ret = find(node->left, obj);
                    }
                    if (ret == NULL)
                    {
                        ret = find(node->right, obj);
                    }
                }
            }
            return ret;
        }

        virtual bool insert(BTreeNode<T>* n, BTreeNode<T>* np, BTNodePos pos)
        {
            bool ret = true;

            if (pos==ANY)
            {
                if (np->left == NULL)
                {
                    np->left = n;
                }
                else if(np->right==NULL)
                {
                    np->right = n;
                }
                else
                {
                    ret = false;
                }
            }
            else if (pos == LEFT)
            {
                if (np->left==NULL)
                {
                    np->left = n;
                }
                else
                {
                    ret = false;
                }
            }
            else if (pos == RIGHT)
            {
                if (np->right == NULL)
                {
                    np->right = n;
                }
                else
                {
                    ret = false;
                }
            }
            else
            {
                ret = false;
            }
            return ret;
        }

	public:
        bool insert(TreeNode<T>* node)
        {
            return insert(node,ANY);
        }

        bool insert(TreeNode<T>* node,BTNodePos pos)
        {
            bool ret = true;

            if (node != NULL)
            {
                if (root() == NULL)
                {
                    m_root = node;
                    node->parent = NULL;
                }
                else
                {
                    BTreeNode<T>* np = find(node->parent);
                    if (np != NULL)
                    {
                        ret = insert(dynamic_cast<BTreeNode<T>*>(node),np, pos);
                    }
                    else
                    {
                        ret = false;
                    }
                }
            }
            else
            {
                ret = false;
            }
            return ret;
        }

        bool insert(const T& value, TreeNode<T>* parent)
        {
            return insert(value, parent, ANY);
        }

        bool insert(const T& value, TreeNode<T>* parent, BTNodePos pos)
        {
            bool ret = true;

            BTreeNode<T>* node = BTreeNode<T>::NewNode();
            if (node != NULL)
            {
                node->value = value;
                node->parent = parent;
                ret = insert(node, pos);
                if (!ret)
                {
                    delete node;
                }
            }
            else
            {
                ret = false;
            }


            return ret;
        }

        SharedPointer< Tree<T> > remove(const T& value)
        {
            return NULL;
        }

        SharedPointer< Tree<T> > remove(TreeNode<T>* node)
        {
            return NULL;
        }

        BTreeNode<T>* find(const T& value) const
        {
            return find(root(),value);
        }

        BTreeNode<T>* find(TreeNode<T>* node) const
        {
            return find(root(),dynamic_cast<BTreeNode<T>*>(node));
        }

        BTreeNode<T>* find(BTreeNode<T>* node) const
        {
            return find(root(), node);
        }

        BTreeNode<T>* root() const
        {
            return dynamic_cast<BTreeNode<T>*>(this->m_root);
        }

        int degree() const
        {
            return 0;
        }
        int count() const
        {
            return 0;
        }

        int height() const
        {
            return 0;
        }

        void clear()
        {

        }

        bool begin()
        {
            bool ret = true;

            return ret;
        }

        bool end()
        {
            bool ret = true;

            return ret;
        }

        bool next()
        {
            bool ret = true;

            return ret;
        }

        T current()
        {
            return NULL;
        }

        ~BTree()
        {
            clear();
        }
	};
}

#endif // !BTREE_H

