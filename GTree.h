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
    protected:
        GTreeNode<T>* find(GTreeNode<T>* node, const T& value)const
        {
            GTreeNode<T>* ret = NULL;
            if (node != NULL)
            {
                if (node->value == value)
                {
                    return node;
                }
                else
                {
                    for (node->child.move(0, 1); !node->child.end()&&(ret==NULL); node->child.next())
                    {
                        ret=find(node->child.current(), value);
                    }
                }
            }
            return ret;
        }

        GTreeNode<T>* find(GTreeNode<T>* node, GTreeNode<T>* obj)const
        {
            GTreeNode<T>* ret = NULL;
            if (node == obj)
            {
                return node;
            }
            else
            {
                if (node != NULL)
                {
                    for (node->child.move(0, 1); !node->child.end() && (ret == NULL); node->child.next())
                    {
                        ret = find(node->child.current(), obj);
                    }
                }
            }
            return ret;
        }

        void free(GTreeNode<T>* node)
        {
            if (node == NULL)
            {

            }
            else
            {
                for (node->child.move(0, 1); !node->child.end(); node->child.next())
                {
                    free(node->child.current());
                }
                if (node->flag())
                {
                    delete node;
                }
            }
        }

        void remove(GTreeNode<T>* node, GTree<T>*& ret)
        {
            ret = new GTree<T>();
            
            if (ret == NULL)
            {

            }
            else
            {
                if (root() == node)
                {
                    this->m_root == NULL;
                }
                else
                {
                    LinkList<GTreeNode<T>*>& child = dynamic_cast<GTreeNode<T>*>(node->parent)->child;
                    child.remove(child.find(node));
                    node->parent = NULL;
                }
                ret->m_root = node;
            }
        }

        int count(GTreeNode<T>* node)const
        {
            int ret = 0;
            if (node != NULL)
            {
                ret = 1;
                for (node->child.move(0, 1); !node->child.end(); node->child.next())
                {
                    ret += count(node->child.current());
                }
            }
            return ret;
        }

        int height(GTreeNode<T>* node)const
        {
            int ret = 0;
            if (node != NULL)
            {
                for (node->child.move(0); !node->child.end(); node->child.next())
                {
                    int h = height(node->child.current());
                    if (ret < h)
                    {
                        ret = h;
                    }
                }
            }
            return ret=ret+1;
        }

        int degree(GTreeNode<T>* node)const
        {
            int ret = 0;
            if (node != NULL)
            {
                ret= node->child.length();
                for (node->child.move(0); !node->child.end(); node->child.next())
                {
                    int d = degree(node->child.current());
                    if (ret < d)
                    {
                        ret = d;
                    }
                }
            }
            return ret;
        }

	public:
        bool insert(TreeNode<T>* node)
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
                    GTreeNode<T>* np = find(node->parent);
                    if (np != NULL)
                    {
                        GTreeNode<T>* n = dynamic_cast<GTreeNode<T>*>(node);
                        if (np->child.find(n) < 0)
                        {
                            np->child.insert(n);
                        }
                        else
                        {
                            ret = false;
                        }
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
            bool ret = true;
            GTreeNode<T>* node = GTreeNode<T>::NewNode();
            if (node != NULL)
            {
                node->value = value;
                node->parent = parent;
                if (m_root == NULL)
                {
                    m_root = parent;
                }
                insert(node);
            }
            else
            {
                ret = false;
            }
            return ret;
        }

        SharedPointer<Tree<T>> remove(const T& value)//通过智能指针访问堆空间中的数据
        {
            GTree<T>* ret = NULL;
            GTreeNode<T>* node = find(value);
            if (value == NULL)
            {

            }
            else
            {
                remove(node, ret);

            }
            return ret;
        }
        SharedPointer<Tree<T>> remove(TreeNode<T>* node)
        {
            GTree<T>* ret = NULL;
            node = find(node);//父类指针可以指向子类指针

            if (node == NULL)
            {

            }
            else
            {
                remove(dynamic_cast<GTreeNode<T>*>(node), ret);
            }
            return ret;
        }
        GTreeNode<T>* find(const T& value) const
        {
            return find(root(), value);
        }
        GTreeNode<T>* find(TreeNode<T>* node)const
        {
            return find(root(), dynamic_cast<GTreeNode<T>*>(node));
        }
        GTreeNode<T>* root() const
        {
            return (dynamic_cast<GTreeNode<T>*>(this->m_root));
        }
        int degree() const
        {
            return degree(root());
        }
        int count() const
        {
            return count(root());
        }
        int height() const
        {
            return height(root());
        }
        void clear()
        {
            free(root());
            m_root = NULL;
        }
        bool begin()
        {
            return 0;
        }
        bool end()
        {
            return 0;
        }
        bool next()
        {
            return 0;
        }
        T current()
        {
            return 0;
        }
	};
}

#endif // !GTREE_H

