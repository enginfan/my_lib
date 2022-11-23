#pragma once
#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include "Graph.h"
#include "LinkList.h"
#include "Exception.h"
#include "DynamicArray.h"

namespace mylib
{
	template<typename V,typename E>
	class ListGraph :public Graph<V, E>
	{
	protected:
		struct Vertex :public Object
		{
			V* data;
            LinkList< Edge<E> > edge;

			Vertex()
			{
				data = NULL;
			}

		};
		LinkList<Vertex*> m_list;
	public:
		ListGraph(unsigned int n = 0)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				addVertex();
			}
		}

		int addVertex()
		{
			int ret = -1;
			Vertex* v = new Vertex();

			if (v != NULL)
			{
				m_list.insert(v);
				ret = m_list.length() - 1;
			}
			return ret;
		}

		int addVertex(const V& value)
		{
			int ret = addVertex();
			if (ret >= 0)
			{
				setVertex(ret, value);
			}
			return ret;
		}

		bool setVertex(int i,const V& value)
		{
			int ret = ((i >= 0) && (i < vCount()));
			if (ret)
			{
				Vertex* vertex = m_list.get(i);
				V* data = vertex->data;
				if (data != NULL)
				{
					*data = value;
				}
				else
				{
					data = new V();
					*data = value;
					vertex->data = data;
				}
			}
			return ret;
		}
		V getVertex(int i)
		{
			V ret;
			if (!getVertex(i, ret))
			{

			}
			return ret;
		}

		bool getVertex(int i, V& value)
		{
			bool ret = ((i >= 0) && (i < vCount()));
			if (ret)
			{
				Vertex* vertex = m_list.get(i);
				V* data = vertex->data;
				if (data != NULL)
				{
					value = *data;
				} 
				else
				{
					ret = false;
				}
			}
			return ret;
		}

		void removeVertex()
		{
			if (m_list.length() > 0)
			{
				int index = m_list.length() - 1;
				Vertex* v = m_list.get(index);
				if (m_list.remove(index))
				{
					for (int i=(m_list.move(0),0); !m_list.end(); m_list.next(),i++)
					{
						int pos=m_list.current()->edge.find(Edge<E>(i, index));
						if (pos >= 0)
						{
							m_list.current()->edge.remove(pos);
						}
					}
					delete v->data;
					delete v;
				}
			}
		}

        SharedPointer< Array<int> > getAdjacent(int i)
		{
			DynamicArray<int>* ret = NULL;
			if ((i >= 0) && (i < vCount()))
			{
				Vertex* vertex = m_list.get(i);
				ret = new DynamicArray<int>(vertex->edge.length());
				if (ret != NULL)
				{
					for (int k = (vertex->edge.move(0), 0); !vertex->edge.end(); vertex->edge.next(), k++)
					{
						ret->set(k, vertex->edge.current().e);
					}
				}
			}
			return ret;
		}

		bool isAdjacent(int i, int j)
		{
			return (0 <= i) && (i < vCount()) && (0 <= j) && (j < vCount()) && (m_list.get(i)->edge.find(Edge<E>(i, j)) >= 0);
		}


		E getEdge(int i, int j)
		{
			E ret;
			
			if (!getEdge(i, j, ret))
			{

			}
		
			return ret;
		}

		bool getEdge(int i, int j, E& value)   // O(n)
		{
			bool ret = ((0 <= i) && (i < vCount()) &&
				(0 <= j) && (j < vCount()));

			if (ret)
			{
				Vertex* vertex = m_list.get(i);
				int pos = vertex->edge.find(Edge<E>(i, j));
				if (pos >= 0)
				{
					value = vertex->edge.get(pos).data;
				}
				else
				{
					
				}
			}

			return ret;
		}

		bool setEdge(int i, int j, const E& value)   // O(n)
		{
			bool ret = ((0 <= i) && (i < vCount()) &&
				(0 <= j) && (j < vCount()));

			if (ret)
			{
				Vertex* vertex = m_list.get(i);
				int pos = vertex->edge.find(Edge<E>(i, j));

				if (pos >= 0)
				{
					ret = vertex->edge.set(pos, Edge<E>(i, j, value));
				}
				else
				{
					ret = vertex->edge.insert(0, Edge<E>(i, j, value));
				}
			}

			return ret;
		}

		bool removeEdge(int i, int j)  // O(n)
		{
			int ret = ((0 <= i) && (i < vCount()) &&
				(0 <= j) && (j < vCount()));

			if (ret)
			{
				Vertex* vertex = m_list.get(i);
				int pos = vertex->edge.find(Edge<E>(i, j));

				if (pos >= 0)
				{
					ret = vertex->edge.remove(pos);
				}
			}

			return ret;
		}

		int vCount() 
		{
			return m_list.length();
		}

		int eCount()
		{
			int ret = 0;

			for (m_list.move(0); !m_list.end(); m_list.next())
			{
				ret += m_list.current()->edge.length();
			}
			return ret;
		}

		int ID(int i)
		{
			int ret = 0;
			if ((i >= 0) && (i < vCount()))
			{
				for (m_list.move(0); !m_list.end(); m_list.next())
				{
                    LinkList< Edge<E> >& edge = m_list.current()->edge;
                    for (edge.move(0); !edge.end(); edge.next())
					{
						if (edge.current().e == i)
						{
							ret++;
							break;
						}
					}
				}
			}
			return ret;
		}

		int OD(int i)
		{
			int ret = 0;
			if ((i >= 0) && (i < vCount()))
			{
				Vertex* vertex = m_list.get(i);
				ret = vertex->edge.length();
			}
			return ret;
		}

		~ListGraph()
		{
			while (m_list.length() > 0)
			{
				Vertex* toDel = m_list.get(0);
				
				m_list.remove(0);
				
				delete toDel->data;
				delete toDel;
			}
		}
	};
}
/*
ListGraph<char, int>g;

	g.addVertex('A');
	g.addVertex('B');
	g.addVertex('C');
	g.addVertex('D');


	for (int i = 0; i < g.vCount(); i++)
	{
		cout << i << ":" << g.getVertex(i)<<endl;
	}
	cout << g.vCount() << endl;
	cout << g.setEdge(0, 1, 5);
	cout << g.setEdge(0, 3, 5);
	cout << g.setEdge(1, 2, 8);
	cout << g.setEdge(2, 3, 2);
	cout << g.setEdge(3, 1, 9) << endl;

	cout << "W(0,1):" << g.getEdge(0, 1) << endl;
	cout << "W(0,3):" << g.getEdge(0, 3) << endl;
	cout << "W(1,2):" << g.getEdge(1, 2) << endl;
	cout << "W(2,3):" << g.getEdge(2, 3) << endl;
	cout << "W(3,1):" << g.getEdge(3, 1) << endl;

	g.removeEdge(3, 1);

	SharedPointer<Array<int>> aj = g.getAdjacent(0);

	for (int i = 0; i < aj->length(); i++)
	{
		cout << (*aj)[i] << endl;
	}

	cout << "ID(1) :" << g.ID(1) << endl;
	cout << "OD(1) :" << g.OD(1) << endl;
	cout << "TD(1) :" << g.TD(1) << endl;

	g.removeVertex();
	cout << "eCount:" << g.eCount() << endl;
	cout << "W(0,1):" << g.getEdge(0, 1) << endl;
	cout << "W(1,2):" << g.getEdge(1, 2) << endl;
	cout << "W(2,3):" << g.getEdge(2, 3) << endl;

*/

#endif
