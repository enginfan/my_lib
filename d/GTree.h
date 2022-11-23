#pragma once
#ifndef GTREE_H
#define GTREE_H

#include "Tree.h"
#include "GTreeNode.h"
#include "LinkQueue.h"

namespace mylib
{
	template<typename T>
	class GTree :public Tree<T>
	{
    protected:
        LinkQueue<GTreeNode<T>*> m_queue;



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
                    LinkList< GTreeNode<T>* >& child = dynamic_cast< GTreeNode<T>* >(node->parent)->child;
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

        GTree()
        {

        }

        bool insert(TreeNode<T>* node)
        {
            bool ret = true;
            if (node != NULL)
            {
                if (this->m_root == NULL)
                {
                    this->m_root = node;
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
                if (this->m_root == NULL)
                {
                    this->m_root = parent;
                }
                insert(node);
            }
            else
            {
                ret = false;
            }
            return ret;
        }

        SharedPointer< Tree<T> > remove(const T& value)//通过智能指针访问堆空间中的数据
        {
            GTree<T>* ret = NULL;
            GTreeNode<T>* node = find(value);
            if (node == NULL)
            {

            }
            else
            {
                remove(node, ret);
                m_queue.clear();//队列清空，否则列中数据可能出问题。

            }
            return ret;
        }
        SharedPointer< Tree<T> > remove(TreeNode<T>* node)
        {
            GTree<T>* ret = NULL;
            node = find(node);//父类指针可以指向子类指针

            if (node == NULL)
            {

            }
            else
            {
                remove(dynamic_cast<GTreeNode<T>*>(node), ret);
                m_queue.clear();
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
            this->m_root = NULL;
            m_queue.clear();
        }
        bool begin()
        {
            bool ret = (root()!=NULL);

            if (ret)
            {
                m_queue.clear();
                m_queue.add(root());
            }

            return ret;
        }

        bool end()
        {
            return (m_queue.length() == 0);
        }

        bool next()
        {
            bool ret=(m_queue.length()!=0);

            if (ret)
            {
                GTreeNode<T>* node = m_queue.front();
                m_queue.remove();
                for (node->child.move(0); !node->child.end(); node->child.next())
                {
                    m_queue.add(node->child.current());
                }
            }
            return ret;
        }

        T current()
        {
            if (!end())
            {
                return m_queue.front()->value;
            }
            else
            {

            }
        }
        ~GTree()
        {
            clear();
        }
	};
}
//查找算法
/*char* s = "KLFGMIF";
    for (int i = 0; i < 7; i++)
    {
        TreeNode<char>* node = t.find(s[i]);

        while (node != NULL)
        {
            cout << node->value << " ";
            node = node->parent;
        }
        cout << endl;
    }*/

#endif // !GTREE_H

