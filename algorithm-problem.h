#pragma once
#include "Object.h"

/*�����ô�ָ�������
	   ����ͬ�㣺

	   ���ǵ�ַ�ĸ��

	   ָ��ָ��һ���ڴ棬������������ָ�ڴ�ĵ�ַ������������ĳ���ڴ�ı�����

	   �ﲻͬ�㣺

	   ��ָ����һ��ʵ�壬�����ý��Ǹ�������

	   ������ֻ���ڶ���ʱ����ʼ��һ�Σ�֮�󲻿ɱ䣻ָ��ɱ䣻���á���һ���ա���ָ����ԡ�����˼Ǩ����

	   ������û��const��ָ����const��const��ָ�벻�ɱ䣻������ָû��int& const a������ʽ����const int& a���еģ� 
	   ǰ��ָ���ñ������������Ըı䣬���ǵ�Ȼ�ģ����Բ���Ҫ������ʽ������ָ������ָ��ֵ�����Ըı䣩

	   �����ò���Ϊ�գ�ָ�����Ϊ�գ�

	   ��sizeof ���á��õ�������ָ��ı���(����)�Ĵ�С������sizeof ָ�롱�õ�����ָ�뱾��Ĵ�С��

	   ��ָ������õ�����(++)�������岻һ����

	   �����������Ͱ�ȫ�ģ���ָ�벻�� (���ñ�ָ��������ͼ��


	   */

//ʹ�����ò�������Ҫԭ����������
//1. ����Ա�ܹ��޸ĵ��ú����е����ݶ���
//2. ͨ���������ö������������ݶ��󣬿�����߳���������ٶȡ�

//������Щ����������ֻʹ�ô��ݹ�����ֵ��������ֵ�����޸ġ�
//
//
//
//��1��������ݶ����С���������������ͻ�С�ͽṹ��ʹ�ð�ֵ���ݡ�
//��2��������ݶ��������飬��ʹ��ָ��const��ָ�롣
//��3��������ݶ����ǽϴ�Ľṹ����ʹ��constָ�����const���ã�����߳����Ч�ʡ�
//��4��������ݶ������������ʹ��const���á���ˣ��������������ı�׼��ʽ�ǰ����ô��ݡ�
//
//������Щ������������Ҫ�޸Ĵ��ݹ�����ֵ��
//
//
//
//��1��������ݶ����������������ͣ���ʹ��ָ�롣
//��2��������ݶ���ʦ���棬��ֻ��ʹ��ָ�롣
//��3��������ݶ����ǽṹ����ʹ��ָ��������á�
//��4��������ݶ������������ʹ�����á�
//��������������������������������
//��Ȩ����������ΪCSDN������������������ԭ�����£���ѭCC 4.0 BY - SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https ://blog.csdn.net/hbtj_1216/article/details/56843014

//ֻʹ�ô��ݹ�����ֵ��������ֵ�����޸�	��Ҫ�޸Ĵ��ݹ�����ֵ
//������������	��ֵ���ݣ�С�ͽṹ��         	ָ�봫��
//����	               ָ�봫��              	ָ�봫��
//�ṹ	         ָ������ã��ϴ�Ľṹ��    	ָ�������
//�ࡢ����	           ���ô���	                ���ô���
 

namespace mylib
{
	unsigned int sum(unsigned int n)
	{
		if (n > 1)
		{
			return n + sum(n - 1);
		}
		else
		{
			return 1;
		}
	}

	unsigned int fac(unsigned int n)
	{
		if (n > 2)
		{
			return fac(n - 2) + fac(n - 1);
		}
		if ((n == 1) || (n == 2))
		{
			return 1;
		}

		return 0;
	}

	struct Node
	{
		int value;
		Node* next;
	};

	Node* create_list(int v, int len)
	{
		Node* ret = NULL;
		Node* slider = NULL;
		for (int i = v; i < (v + len); i++)
		{
			Node* n = new Node();
			n->value = i;
			if (slider == NULL)
			{
				slider = n;
				ret = n;
			}
			else
			{
				slider->next = n;
				slider = n;
			}
		}
		return ret;
	}

	void destory(Node* list)
	{
		while (list)
		{
			Node* del = list;
			list = list->next;
			delete del;
		}
	}

	void print_Node(Node* list)
	{
		while (list)
		{
			cout << list->value << "->";
			list = list->next;
		}
		if (list == NULL)
		{
			cout << "NULL" << endl;
		}
	}


	//��ת����
	Node* reverse(Node* list)
	{

		if ((list->next == NULL) || (list == NULL))
		{
			return list;
		}
		if (list->next)
		{
			Node* guard = list->next;
			Node* ret = reverse(list->next);
			guard->next = list;
			list->next = NULL;
			return ret;
		}
	}

	//�ϲ���������
	Node* merge(Node* list1, Node* list2)
	{
		if (list1 == NULL)
		{
			return list2;
		}
		else if (list2 == NULL)
		{
			return list1;
		}
		else if (list1->value < list2->value)
		{
			Node* list1_ = list1->next;
			Node* list = merge(list1_, list2);

			list1->next = list;

			return list1;//���ﷵ�ص��������ͷ��㣡���������Ƿ���merge//�ú����ȼ���return (list->next=merge(list->next,list2),list1)//ʹ�ö��ű��ʽ
		}
		else
		{
			Node* list2_ = list2->next;
			Node* list = merge(list1, list2->next);

			list2->next = list;

			return list2;
		}
	}


	//��ŵ������
	void HanoiTower(int n, char a, char b, char c)//a==��ʼ��b==��ת��c==Ŀ��
	{
		if (n == 1)
		{
			cout << a << "-->" << c << endl;
		}
		else
		{
			HanoiTower(n - 1, a, c, b);
			HanoiTower(1, a, b, c);
			HanoiTower(n - 1, b, a, c);
		}
	}

	//ȫ��������
	void permutation(char* s, char* e)
	{
		if (*s == '\0')
		{
			cout << e << endl;
		}
		else
		{
			int len = strlen(s);
			for (int i = 0; i < len; i++)
			{
				if ((s[0] != s[i]) || (i == 0))//�ַ��ظ������
				{
					swap(s[0], s[i]);
					permutation(s + 1, e);
					swap(s[0], s[i]);
				}
			}
		}
	}

	//�����ӡ�������е�ż���ڵ�//��ӡ�Ĺ��̾��ǻ��ݵĹ��̣�����
	//�൱��ȥ�Թ���ѡ�����±���ٷ���ʱ��·���ص����ջ������
	void r_ptint_even(Node* list)
	{
		if (list != NULL)
		{
			r_ptint_even(list->next);
			if (list->value % 2 == 0)
			{
				cout << list->value;
			}
		}
	}

}
