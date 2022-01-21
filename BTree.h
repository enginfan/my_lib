#pragma once
#ifndef BTREE_H
#define BTREE_H

#include "Tree.h"
#include "BTreeNode.h"
#include "LinkQueue.h"
#include "DynamicArray.h"


namespace mylib
{
    enum BTTraversal
    {
        PreOrder,
        InOrder,
        PostOrder
    };
	template<typename T>
	class BTree :public Tree<T>
	{
    protected:
        LinkQueue<BTreeNode<T>*> m_queue;
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

        virtual void remove(BTreeNode<T>* node, BTree<T>* &ret)
        {
            ret = new BTree<T>();
            if (ret)
            {
                if (node == m_root)
                {
                    this->m_root = NULL;
                }
                else
                {
                    BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);

                    if (parent->left == node)
                    {
                        parent->left = NULL;
                    }
                    if (parent->right == node)
                    {
                        parent->right = NULL;
                    }
                    node->parent = NULL;
                }
            }
            ret->m_root = node;
        }

        virtual void free(BTreeNode<T>* node)
        {
            if (node)
            {
                free(node->left);
                free(node->right);

                if (node->flag() == true)
                {
                    delete node;
                }
            }
        }

        int count(BTreeNode<T>* node)const
        {
            return (node?(count(node->left)+count(node->right)+1):0);
        }

        int height(BTreeNode<T>* node)const
        {
            int ret = 0;
            if (node)
            {
                int hl = height(node->left);
                int hr = height(node->right);
                ret = ((hl > hr) ? hl : hr)+1;
            }
            return ret;
        }

        int degree(BTreeNode<T>* node)const
        {
            int ret = 0;
            if (node != NULL)
            {
                BTreeNode<T>* child[] = { node->left,node->right };
                ret = !!node->left + !!node->right;//!是逻辑操作符只会返回0 OR 1
                for (int i = 0; (i < 2) && (ret < 2); i++)
                {
                    int d = degree(child[i]);
                    if (ret < d)
                    {
                        ret = d;
                    }
                }
            }
            return ret;
        }

        void preOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*> &queue)
        {
            if (node)
            {
                queue.add(node);
                preOrderTraversal(node->left,queue);
                preOrderTraversal(node->right,queue);
            }
        }

        void inOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
        {
            if (node)
            {
                inOrderTraversal(node->left,queue);
                queue.add(node);
                inOrderTraversal(node->right,queue);
            }
        }

        void postOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
        {
            if (node)
            {
                postOrderTraversal(node->left,queue);
                postOrderTraversal(node->right,queue);
                queue.add(node);
            }
        }

        void traversal(BTTraversal order, LinkQueue<BTreeNode<T>*>& queue)
        {
            switch (order)
            {
            case PreOrder:
                preOrderTraversal(root(), queue);
                break;
            case InOrder:
                inOrderTraversal(root(), queue);
                break;
            case PostOrder:
                postOrderTraversal(root(), queue);
                break;
            default:

                break;
            }
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
            BTree<T>* ret = NULL;
            BTreeNode<T>* node = find(value);
            if (node)
            {
                remove(node, ret);
            }
            return ret;
        }

        SharedPointer< Tree<T> > remove(TreeNode<T>* node)
        {
           BTree<T>* ret = NULL;

            node = find(node);

            if (node)
            {
               remove(dynamic_cast<BTreeNode<T>*>(node), ret);
            }
            return ret;
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
            bool ret = (root() != NULL);
            if (ret)
            {
                m_queue.clear();
                m_queue.add(root());
            }
            return ret;
        }

        bool end()
        {
            return (m_queue.length()==0);
        }

        bool next()
        {
            bool ret = (m_queue.length()>0);
            if (ret)
            {
                BTreeNode<T>* parent=m_queue.front();
                if (parent->left)
                {
                    m_queue.add(parent->left);
                }
                if (parent->right)
                {
                    m_queue.add(parent->right);
                }
                m_queue.remove();
            }
            return ret;
        }

        T current()
        {
            if (!end())
            {
                return m_queue.front()->value;
            }
        }

        SharedPointer<Array<T>>traversal(BTTraversal order)
        {
            DynamicArray<T>* ret = NULL;
            LinkQueue<BTreeNode<T>*> queue;
            traversal(order, queue);
            
            ret = new DynamicArray<T>(queue.length());

            if (ret)
            {
                for (int i = 0; i < ret->length(); i++, queue.remove())
                {
                    ret->set(i, queue.front()->value);
                }
            }
            return ret;
        }

        ~BTree()
        {
            clear();
        }
	};
}

#endif // !BTREE_H

