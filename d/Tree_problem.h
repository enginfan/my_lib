#pragma once
#ifndef TREE_PROBLEM_H
#define TREE_PROBLEM_H
#include "BTree.h"
namespace mylib
{
    //面试一、单度节点删除(包含父节点)
    template<typename T>
    void delOdd1(BTreeNode<T>* node)
    {
        if (node != NULL)
        {
            int ret = !!node->right + !!node->left;
            if (ret == 1)
            {
                BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
                BTreeNode<T>* child = NULL;
                if (node->left != NULL)
                {
                    child = node->left;
                }
                else
                {
                    child = node->right;
                }
                if (parent == NULL)
                {
                    child->parent = NULL;
                }
                else
                {
                    child->parent = parent;
                    if (parent->left == node)
                    {
                        parent->left = child;
                    }
                    else
                    {
                        parent->right = child;
                    }
                }
                if (node->flag())
                {
                    delete node;
                }

                delOdd1(child);
            }
            else
            {
                delOdd1(node->left);
                delOdd1(node->right);
            }
        }

    }
    
    //标准答案1(包含父节点)
    template<typename T>
    BTreeNode<T>* delOdd1B(BTreeNode<T>* node)
    {
        BTreeNode<T>* ret = NULL;
        if (node != NULL)
        {
            if (((node->left != NULL) && (node->right == NULL)) ||
                ((node->left == NULL) && (node->right != NULL)))
            {
                BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
                BTreeNode<T>* node_child = (node->left != NULL) ? node->left : node->right;//要使用if判断两种情况是可以考虑使用三目运算符
                if (parent != NULL)
                {
                    BTreeNode<T>*& parent_child = (parent->left == node) ? parent->left : parent->right;
                    //我们知道在C++中指针也是一种变量类型，其中存储的是地址。
                    //我们知道C++中函数参数的传递默认是值传递，如果我想在一个函数中修改变量的值，
                    // 当退出函数的时候这种影响保留的话，就需要使用变量的指针或者应用作为参数。
                    //同样指针作为一种变量，在传递参数的时候，指针也是按照值传递的，
                    // 这样就会导致一个问题，当我们使用值传递的时候，
                    // 如果我们在函数中修改了指针变量的指向(也就是储存的地址值发生变化)，
                    // 当函数退出时这种影响不会保留。如果我们想在一个函数中修改指针的指向，
                    // 并且在退出函数后这种影响保留，就需要使用指针变量的指针或者引用传递参数。
                    //关于指针的指针可以参考博客：C++中指向指针的指针的作用https://blog.csdn.net/liuweiyuxiang/article/details/84769438
                    //其实指针引用并不难理解，类比普通变量的引用理解即可。
                    parent_child = node_child;
                    node_child->parent = parent;
                }
                else
                {
                    node_child->parent = NULL;
                }

                if (node->flag())
                {
                    delete node;
                }

                ret = delOdd1B(node_child);
            }
            else
            {
                delOdd1B(node->left);
                delOdd1B(node->right);
                ret = node;
            }
        }
        return ret;
    }

    template<typename T>
    void delOdd2(BTreeNode<T>* node)
    {
        BTreeNode<T>* re = node;//此处赋值仅仅是内部地址的传递，并不是指针指向指针
        //之所以分两步是因为强制类型转换产生的是临时变量不能进行取值操作
        BTreeNode<T>** ret = &(re);//此处是指针指向指针
        delOdd2(ret);
    }
    //面试一、(不包含父节点)
    //BTreeNode<T>*p 
    // p是指向BTreeNode<T>类型的指针（BTreeNode<T>类型）,
    //BTreeNode<T>** p
    // p是指向BTreeNode<T>* 类型的指针(为指针类型)他所指向的对象是BTreeNode<T>*
    //如果是引用BTreeNode<T>*& 是指向BTreeNode<T>* 类型的指针他所指向的对象也是BTreeNode<T>*但是是指针本身
    //**类型传入
    template<typename T>
    void delOdd2(BTreeNode<T>** node)
    {

        if ((*node) != NULL)
        {
            if ((((*node)->left != NULL) && ((*node)->right == NULL)) ||
                (((*node)->left == NULL) && ((*node)->right != NULL)))
            {
                BTreeNode<T>* node_child = ((*node)->left != NULL) ? (*node)->left : (*node)->right;

                if ((*node)->flag())
                {
                    delete (*node);
                }
                (*node) = node_child;
                //此处是删除node节点所指向的一片空间但是node本身的空间是没有被删除的！！！
                //那么对node所包含的地址值进行重赋值(采用引用的原因)那么改变的是node指向的地址空间。
                delOdd2(node);
            }
            else
            {
                delOdd2(&((*node)->left));
                delOdd2(&((*node)->right));

            }
        }

    }
    //*&传入
    template<typename T>
    void delOdd22(BTreeNode<T>*& node)
    {

        if (node != NULL)
        {
            if (((node->left != NULL) && (node->right == NULL)) ||
                ((node->left == NULL) && (node->right != NULL)))
            {
                BTreeNode<T>* node_child = (node->left != NULL) ? node->left : node->right;

                if (node->flag())
                {
                    delete node;
                }
                node = node_child;
                //此处是删除node节点所指向的一片空间但是node本身的空间是没有被删除的！！！
                //那么对node所包含的地址值进行重赋值(采用引用的原因)那么改变的是node指向的地址空间。
                delOdd22(node);
            }
            else
            {
                delOdd22(node->left);
                delOdd22(node->right);

            }
        }
    }
    //面试二、
    //中序线索化二叉树
    //编写一个中序线索化二叉树
    //要求不适用其他数据结构
    template<typename T>
    void InOrderThread(BTreeNode<T>* node, BTreeNode<T>*& pre)
    {
        if (node != NULL)
        {
            InOrderThread(node->left, pre);
            node->left = pre;
            if (pre != NULL)
            {
                pre->right = node;
            }
            pre = node;
            InOrderThread(node->right, pre);
        }
    }
    //该方法会导致析构时无限递归使得栈溢出
    template<typename T>
    BTreeNode<T>* InOrderThread1(BTreeNode<T>* node)
    {
        BTreeNode<T>* ret = NULL;
        InOrderThread(node, ret);
        while ((ret != NULL) && (ret->left != NULL))
        {
            ret = ret->left;
        }
        return ret;
    }
}

#endif // !TREE_PROBLEM_H


