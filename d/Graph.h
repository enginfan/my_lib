#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "Object.h"
#include "SharedPointer.h"
#include "Array.h"
#include "DynamicArray.h"
#include "LinkStack.h"
namespace mylib
{
    template<typename E>
    struct Edge:public Object
    {
        int b; //begin
        int e; //end
        E data;

        Edge(int i = -1, int j = -1)
        {
            b = i;
            e = j;
        }

        Edge(int i, int j, const E& value)
        {
            b = i;
            e = j;
            data = value;
        }

        bool operator==(Edge<E>& obj)
        {
            return (b == obj.b) && (e == obj.e);
        }
        
        bool operator!=(Edge<E>&obj)
        {
            return !(*this == obj);
        }
    };
    template < typename V, typename E >
    class Graph : public Object//抽象类不可以定义对象，但可以定义指针（父类指针）
    {
    protected:
        template<typename T>
        DynamicArray<T>* toArray(LinkQueue<T>& queue)
        {
            DynamicArray<T>* ret = new DynamicArray<T>(queue.length());
            if (ret != NULL)
            {
                for (int i = 0; i < ret->length(); i++, queue.remove())
                {
                    ret->set(i,queue.front());
                }
            }
            return ret;
        }
    public:
        virtual V getVertex(int i) = 0;
        virtual bool getVertex(int i, V& value) = 0;
        virtual bool setVertex(int i, const V& value) = 0;
        virtual SharedPointer< Array<int> > getAdjacent(int i) = 0;
        virtual bool isAdjacent(int i, int j) = 0;
        virtual E getEdge(int i, int j) = 0;
        virtual bool getEdge(int i, int j, E& value) = 0;
        virtual bool setEdge(int i, int j, const E& value) = 0;
        virtual bool removeEdge(int i, int j) = 0;
        virtual int vCount() = 0;
        virtual int eCount() = 0;
        virtual int OD(int i) = 0;
        virtual int ID(int i) = 0;

        virtual int TD(int i)
        {
            return OD(i) + ID(i);
        }

        SharedPointer< Array<int> > BFS(int i)
        {
            DynamicArray<int>* ret = NULL;
            if ((i >= 0) && (i < vCount()))
            {
                LinkQueue<int> q;
                LinkQueue<int> r;
                DynamicArray<bool> visited(vCount());
                for (int i = 0; i < vCount(); i++)
                {
                    visited[i] = FALSE;
                }
                q.add(i);

                while (q.length() > 0)
                {
                    int v = q.front();
                    q.remove();
                    if (!visited[v])
                    {
                        SharedPointer< Array<int> > aj = getAdjacent(v);
                        for (int j = 0; j < (*aj).length(); j++)
                        {
                            q.add((*aj)[j]);
                        }
                        r.add(v);

                        visited[v] = TRUE;
                    }
                }
                ret = toArray(r);
            }
            return ret;
        }
    /*
    MatrixGraph<9, char, int> g;
	const char* VD = "ABEDCGFHI";

	for (int i = 0; i < 9; i++)
	{
		g.setVertex(i, VD[i]);
	}

	g.setEdge(0, 1, 0);
	g.setEdge(1, 0, 0);

	g.setEdge(0, 3, 0);
	g.setEdge(3, 0, 0);

	g.setEdge(0, 4, 0);
	g.setEdge(4, 0, 0);

	g.setEdge(1, 2, 0);
	g.setEdge(2, 1, 0);

	g.setEdge(1, 4, 0);
	g.setEdge(4, 1, 0);

	g.setEdge(2, 5, 0);
	g.setEdge(5, 2, 0);

	g.setEdge(3, 6, 0);
	g.setEdge(6, 3, 0);

	g.setEdge(4, 6, 0);
	g.setEdge(6, 4, 0);

	g.setEdge(6, 7, 0);
	g.setEdge(7, 6, 0);

	g.setEdge(7, 8, 0);
	g.setEdge(8, 7, 0);

	SharedPointer<Array<int>> sa = g.BFS(0);

	for (int i = 0; i < sa->length(); i++)
	{
		cout << (*sa)[i] << " ";
	}
    */

        SharedPointer< Array<int> > DFS(int i)
        {
            SharedPointer< Array<int> > ret = NULL;
            if ((i >= 0) && (i < vCount()))
            {
                LinkStack<int> s;
                LinkQueue<int> r;
                DynamicArray<bool> visited(vCount());
                for (int j = 0; j < visited.length(); j++)
                {
                    visited[j] = FALSE;
                }
                s.push(i);
                while (s.size() > 0)
                {
                    int v = s.top();
                    s.pop();
                    if (!visited[v])
                    {
                        SharedPointer< Array<int> > aj = getAdjacent(v);
                        for (int j = aj->length()-1; j >=0; j--)
                        {
                            s.push((*aj)[j]);
                        }
                        r.add(v);
                        visited[v] = TRUE;
                    }
                }
                ret = toArray(r);
            }
            return ret;
        }
    };
}

#endif // !GRAPH_H
