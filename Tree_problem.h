#pragma once
#ifndef TREE_PROBLEM_H
#define TREE_PROBLEM_H
#include "BTree.h"
namespace mylib
{
    //����һ�����Ƚڵ�ɾ��(�������ڵ�)
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
    
    //��׼��1(�������ڵ�)
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
                BTreeNode<T>* node_child = (node->left != NULL) ? node->left : node->right;//Ҫʹ��if�ж���������ǿ��Կ���ʹ����Ŀ�����
                if (parent != NULL)
                {
                    BTreeNode<T>*& parent_child = (parent->left == node) ? parent->left : parent->right;
                    //����֪����C++��ָ��Ҳ��һ�ֱ������ͣ����д洢���ǵ�ַ��
                    //����֪��C++�к��������Ĵ���Ĭ����ֵ���ݣ����������һ���������޸ı�����ֵ��
                    // ���˳�������ʱ������Ӱ�챣���Ļ�������Ҫʹ�ñ�����ָ�����Ӧ����Ϊ������
                    //ͬ��ָ����Ϊһ�ֱ������ڴ��ݲ�����ʱ��ָ��Ҳ�ǰ���ֵ���ݵģ�
                    // �����ͻᵼ��һ�����⣬������ʹ��ֵ���ݵ�ʱ��
                    // ��������ں������޸���ָ�������ָ��(Ҳ���Ǵ���ĵ�ֵַ�����仯)��
                    // �������˳�ʱ����Ӱ�첻�ᱣ���������������һ���������޸�ָ���ָ��
                    // �������˳�����������Ӱ�챣��������Ҫʹ��ָ�������ָ��������ô��ݲ�����
                    //����ָ���ָ����Բο����ͣ�C++��ָ��ָ���ָ�������https://blog.csdn.net/liuweiyuxiang/article/details/84769438
                    //��ʵָ�����ò�������⣬�����ͨ������������⼴�ɡ�
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
        BTreeNode<T>* re = node;//�˴���ֵ�������ڲ���ַ�Ĵ��ݣ�������ָ��ָ��ָ��
        //֮���Է���������Ϊǿ������ת������������ʱ�������ܽ���ȡֵ����
        BTreeNode<T>** ret = &(re);//�˴���ָ��ָ��ָ��
        delOdd2(ret);
    }
    //����һ��(���������ڵ�)
    //BTreeNode<T>*p 
    // p��ָ��BTreeNode<T>���͵�ָ�루BTreeNode<T>���ͣ�,
    //BTreeNode<T>** p
    // p��ָ��BTreeNode<T>* ���͵�ָ��(Ϊָ������)����ָ��Ķ�����BTreeNode<T>*
    //���������BTreeNode<T>*& ��ָ��BTreeNode<T>* ���͵�ָ������ָ��Ķ���Ҳ��BTreeNode<T>*������ָ�뱾��
    //**���ʹ���
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
                //�˴���ɾ��node�ڵ���ָ���һƬ�ռ䵫��node����Ŀռ���û�б�ɾ���ģ�����
                //��ô��node�������ĵ�ֵַ�����ظ�ֵ(�������õ�ԭ��)��ô�ı����nodeָ��ĵ�ַ�ռ䡣
                delOdd2(node);
            }
            else
            {
                delOdd2(&((*node)->left));
                delOdd2(&((*node)->right));

            }
        }

    }
    //*&����
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
                //�˴���ɾ��node�ڵ���ָ���һƬ�ռ䵫��node����Ŀռ���û�б�ɾ���ģ�����
                //��ô��node�������ĵ�ֵַ�����ظ�ֵ(�������õ�ԭ��)��ô�ı����nodeָ��ĵ�ַ�ռ䡣
                delOdd22(node);
            }
            else
            {
                delOdd22(node->left);
                delOdd22(node->right);

            }
        }
    }
    //���Զ���
    //����������������
    //��дһ������������������
    //Ҫ�������������ݽṹ
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
    //�÷����ᵼ������ʱ���޵ݹ�ʹ��ջ���
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


