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
        PostOrder,
        LevelOrder
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
                if (node == this->m_root)
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
            if (node!=NULL)
            {
                free(node->left);
                free(node->right);

                if (node->flag())
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

        void LevelOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
        {
            if (node)
            {
                LinkQueue<BTreeNode<T>*> tmp;
                tmp.add(node);
                while (tmp.length() > 0)
                {
                    BTreeNode<T>* n = tmp.front();
                    if (n->left)
                    {
                        tmp.add(n->left);
                    }
                    if (n->right)
                    {
                        tmp.add(n->right);
                    }
                    tmp.remove();
                    queue.add(n);
                }
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
            case LevelOrder:
                LevelOrderTraversal(root(), queue);
                break;
            default:

                break;
            }
        }

        BTreeNode<T>* clone(BTreeNode<T>* node)const
        {
            BTreeNode<T>* ret = NULL;
            if (node)
            {
                ret= BTreeNode<T>::NewNode();
                if (ret)
                {
                    ret->value = node->value;
                    ret->left = clone(node->left);
                    ret->right = clone(node->right);
                    if (ret->left)
                    {
                        ret->left->parent = ret;
                    }
                    if (ret->right)
                    {
                        ret->right->parent = ret;
                    }
                }
            }
            return ret;
        }

        bool equal(BTreeNode<T>* lh, BTreeNode<T>* rh)
        {
            if (lh == rh)//比较地址，判断是否是和自身比较
            {
                return true;
            }
            else if ((lh != NULL) && (rh != NULL))
            {
                return (lh->value == rh->value) && equal(lh->left, rh->left) && equal(lh->right, rh->right);
            }
            else
            {
                return false;
            }
        }

        BTreeNode<T>* add(BTreeNode<T>* lh, BTreeNode<T>* rh)
        {
            BTreeNode<T>* ret = NULL;
            if ((lh == NULL) && (rh != NULL))
            {
                ret = clone(rh);
            }
            else if ((lh != NULL) && (rh == NULL))
            {
                ret = clone(lh);
            }
            else if ((lh != NULL) && (rh != NULL))
            {
                ret = BTreeNode<T>::NewNode();
                ret->value = lh->value + rh->value;
                ret->left = add(lh->left, rh->left);
                ret->right = add(lh->right, rh->right);
                if (ret->left)
                {
                    ret->left->parent = ret;
                }
                if (ret->right)
                {
                    ret->right->parent = ret;
                }
            }
            return ret;
        }

        BTreeNode<T>* connect(LinkQueue<BTreeNode<T>*>& queue)
        {
            BTreeNode<T>* ret = NULL;
            if (queue.length() > 0)
            {
                ret = queue.front();
                BTreeNode<T>* slider = queue.front();
                slider->left = NULL;
                queue.remove();
                while (queue.length() > 0)
                {
                    slider->right = queue.front();
                    queue.front()->left = slider;
                    slider = queue.front();
                    queue.remove();
                }
                slider->right = NULL;
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
                    this->m_root = node;
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

        SharedPointer< Array<T> >traversal(BTTraversal order)
        {
            DynamicArray<T>* ret = NULL;
            LinkQueue<BTreeNode<T>*> queue;//queue 只是完成数据排列的手段完成后可以销毁
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

        BTreeNode<T>* thread(BTTraversal order)
        {
            BTreeNode<T>* ret = NULL;
            LinkQueue<BTreeNode<T>*> queue;

            traversal(order, queue);

            ret=connect(queue);

            this->m_root = NULL;

            m_queue.clear();

            return ret;
        }

        SharedPointer< BTree<T> >clone()const
        {
            BTree<T>* ret = new BTree<T>();

            if (ret)
            {
                ret->m_root = clone(root());
            }
            return ret;
        }

        bool operator==(const BTree<T>& btree)
        {
            return equal(root(),btree.root());
        }

        bool operator!=(const BTree<T>& btree)
        {
            return !(*this == btree);
        }

        SharedPointer< BTree<T> >add(const BTree<T>& btree)
        {
            BTree<T>* ret = new BTree<T>();
            if (ret)
            {
                ret->m_root = add(root(), btree.root());
            }
            return ret;
        }

     
       



        ~BTree()
        {
            clear();
        }
	};
}
//BTree<int> bt;
//BTreeNode<int>* n = NULL;
//
//BTree<int>* btd = NULL;
//
//bt.insert(1, NULL);
//
//n = bt.find(1);
//bt.insert(2, n);
//bt.insert(3, n);
//
//n = bt.find(2);
//bt.insert(4, n);
//bt.insert(5, n);
//
//n = bt.find(4);
//bt.insert(8, n);
//bt.insert(9, n);
//
//n = bt.find(5);
//bt.insert(10, n);
//
//n = bt.find(3);
//bt.insert(6, n);
//bt.insert(7, n);
//
//n = bt.find(6);
//bt.insert(11, n, LEFT);
//
//
//
//BTreeNode<int>* lbt = bt.thread(LevelOrder);
//
//while (lbt->right)
//{
//    lbt = lbt->right;
//}
//
//while (lbt)
//{
//    cout << lbt->value << endl;
//    lbt = lbt->left;
//}

/*BTree<int> nbt;

nbt.insert(0, NULL);

n = nbt.find(0);
nbt.insert(6, n, LEFT);
nbt.insert(2, n, RIGHT);

n = nbt.find(2);
nbt.insert(7, n, LEFT);
nbt.insert(8, n, RIGHT);

SharedPointer<BTree<int>>sbt=nbt.add(bt);

for ((*sbt).begin(); !(*sbt).end(); (*sbt).next())
{
    cout << (*sbt).current() << endl;
}*/
//SharedPointer<BTree<int>> btclone = bt.clone();



/*int a[] = { 8,9,10,11,7 };

for (int i = 0; i < 5; i++)
{
    BTreeNode<int>* node = (*btclone).find(a[i]);
    while (node)
    {
        cout << node->value << " ";
        node = dynamic_cast<BTreeNode<int>*>(node->parent);
    }
    cout << endl;
}*/

//cout << "bt==btclone:" << (bt == (*btclone)) << endl;

/*for (bt.begin(); !bt.end(); bt.next())
{
    cout << bt.current() << endl;
}
SharedPointer<Array<int>> sp = NULL;

sp = bt.traversal(PostOrder);
cout << (*sp).length() << endl;
for (int i = 0; i < (*sp).length(); i++)
{
    cout << (*sp)[i] << " ";
}*/
#endif // !BTREE_H

