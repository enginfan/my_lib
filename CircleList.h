#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "LinkList.h"

namespace mylib
{
	template <typename T>
	class CircleList :public LinkList<T>
	{
	protected:
		typedef typename LinkList<T>::Node Node;
		Node* last() const//o(n)
		{
			return this->position(this->m_length-1)->next;
		}
		void last_to_first() const
		{
			last()->next = this->m_header.next;
		}
		int mod(int i) const//O(1)
		{
			return (this->m_length == 0) ? 0 : (i % this->m_length);
		}
	public:
		bool insert(const T& e)
		{
			return insert(this->m_length, e);
		}
		bool insert(int i, const T& e)
		{
			bool ret = true;
			i = i % (this->m_length + 1);
			ret = LinkList<T>::insert(i, e);
			if ((ret) && i == 0)
			{
				last_to_first();
			}
			return ret;
		}
		bool remove(int i)
		{
			bool ret = true;
			if (i == 0)
			{
				Node* toDel = this->m_header.next;
				if (toDel != 0)
				{
					this->m_header.next = toDel->next;
					this->m_length--;
					if (this->m_length > 0)
					{
						last_to_first();
						if (this->m_current == toDel)
						{
							this->m_current = toDel->next;
						}
					}
					else
					{
						this->m_header.next = 0;
						this->m_current = 0;
					}
					this->destroy(toDel);//�쳣��ȫ����//���ຯ��ʱҪʹ��thisָ��
				}
				else
				{
					ret = false;
				}
			}
			else
			{
				ret=LinkList<T>::remove(i);
			}
			return ret;//ע�ⵥһ����ԭ��
		}
		bool set(int i, const T& e)
		{
			return LinkList<T>::set(mod(i), e);
		}
		T get(int i)const
		{
			return LinkList<T>::get(mod(i));
		}
		bool get(int i, T& e) const
		{
			return LinkList<T>::get(mod(i),e);//mod��������Ϊconst����
		}
		int find(const T& e)
		{
			int ret = -1;
			Node* slider = this->m_header.next;
			for (int i = 0; i < this->m_length; i++)
			{
				if (slider->value == e)
				{
					ret = i;
					break;
				}
				slider = slider->next;
			}
			return ret;
		}
		void clear()
		{
			while (this->m_length > 1)
			{
				remove(1);//���Ч�����Բ���Ҫremove��0��
			}
			if (this->m_length == 1)
			{
				Node* toDel = this->m_header.next;
				this->m_header.next = 0;
				this->m_current = 0;
				this->m_length = 0;
				this->destroy(toDel);
			}
		}
		//����ʵ�ֱ�������
		bool move(int i, int step=1)
		{
			return LinkList<T>::move(i, step);
		}
		bool end()
		{
			return ((this->m_length == 0) || (this->m_current->next == 0));
		}

		~CircleList()
		{
			clear();
		}
	};
}
/*ѭ�������Ӧ��
* Լɪ������
* ��֪n���ˣ�0~n-1���ӱ��Ϊk���˿�ʼ����������m���˿�ʼ���У���һ�����ִ�1��ʼ��
* �����ظ�ֱ�������˳���
*/
#endif