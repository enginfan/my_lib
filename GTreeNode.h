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
	public:
		LinkList<GTreeNode<T>*> child;

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
/*
GTree<char> t;
	GTreeNode<char>* node = NULL;

	t.insert('A',NULL);

	node = t.find('A');
	t.insert('B', node);
	t.insert('C', node);
	t.insert('D', node);

	node = t.find('B');
	t.insert('E', node);
	t.insert('F', node);

	node = t.find('D');
	t.insert('H', node);
	t.insert('I', node);
	t.insert('J', node);

	node = t.find('E');
	t.insert('K', node);
	t.insert('L', node);

	node = t.find('C');
	t.insert('G', node);

	node = t.find('H');
	t.insert('M', node);

	cout <<"t.degree()=" << t.degree() << endl;
	cout <<"t.height()=" << t.height() << endl;
	cout <<"t.count()=" << t.count() << endl;

	for (t.begin(); !t.end(); t.next())
	{
		cout << t.current() << endl;
	}
	*/
#endif // !GTreeNode_H

