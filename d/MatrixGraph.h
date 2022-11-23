#pragma once
#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include "Graph.h"
#include "DynamicArray.h"
namespace mylib
{
    template < int N, typename V, typename E >
    class MatrixGraph : public Graph<V, E>
    {
    protected:
        V* m_vertexes[N];
        E* m_edges[N][N];
        int m_eCount;
    public:
        MatrixGraph()
        {
            for (int i = 0; i < N; i++)
            {
                m_vertexes[i] = NULL;
                for (int j = 0; j < N; j++)
                {
                    m_edges[i][j] = NULL;
                }
            }
            m_eCount = 0;
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
            bool ret = ((0 <= i) && (i < vCount()));
            if (ret)
            {
                if (m_vertexes[i] != NULL)
                {
                    value = *(m_vertexes[i]);
                }
                else
                {
                    ret = false;
                }
            }
            return ret;
        }
        bool setVertex(int i, const V& value)
        {
            bool ret = ((i >= 0) && (i <= vCount()));

            if (ret)
            {
                V* data = m_vertexes[i];//为了异常安全当抛异常时，不会对图本身的结构产生损坏
                if (data == NULL)
                {
                    data = new V();
                }
                if (data != NULL)
                {
                    *data = value;//主要是防止此处赋值异常
                    m_vertexes[i] = data;
                }
                else
                {
                    ret = false;
                }
            }
            return ret;
        }
        SharedPointer< Array<int> > getAdjacent(int i)
        {
            SharedPointer< Array<int> > ret = NULL;
            if ((i >= 0) && (i < vCount()))
            {
                int n = 0;
                for (int j = 0; j < vCount(); j++)
                {
                    if (m_edges[i][j] != NULL)//这里的不为空是不是指0的情况FALSE才是0
                    {
                        n++;
                    }
                }
                ret = new DynamicArray<int>(n);
                if (!ret.isNull())
                {
                    for (int j = 0, k = 0; j < vCount(); j++)
                    {
                        if (m_edges[i][j] != NULL)
                        {
                            ret->set(k++, j);
                        }
                    }
                }
                else
                {

                }
            }
            else
            {

            }
            return ret;
        }

        bool isAdjacent(int i, int j)
        {
            return (i >= 0) && (i < vCount()) && (j >= 0) && (j < vCount()) && (m_edges[i][j] != NULL);
        }

        E getEdge(int i, int j)
        {
            E ret;
            if (!getEdge(i, j, ret))
            {

            }
            return ret;
        }

        bool getEdge(int i, int j, E& value)
        {
            bool ret = (i >= 0) && (i < vCount()) && (j >= 0) && (j < vCount());
            if (ret)
            {
                if (m_edges[i][j] != NULL)
                {
                    value = *(m_edges[i][j]);
                }
            }
            return ret;
        }

        bool setEdge(int i, int j, const E& value)
        {
            bool ret = ((i >= 0) && (i < vCount()) && (j >= 0) && (j < vCount()));
            if (ret)
            {
                E* ne = m_edges[i][j];
                if (ne == NULL)
                {
                    ne = new E();
                    if (ne != NULL)
                    {
                        *ne = value;
                        m_edges[i][j] = ne;
                        m_eCount++;
                    }
                }
                else
                {
                    *ne = value;
                }
            }
            return ret;
        }

        bool removeEdge(int i, int j)
        {
            bool ret = ((i >= 0) && (i < vCount()) && (j >= 0) && (j < vCount()));
            if (ret)
            {
                E* toDel = m_edges[i][j];
                m_edges[i][j] = NULL;
                if (toDel != NULL)
                {
                    m_eCount--;
                    delete toDel;
                }
            }
            return ret;
        }
        int vCount()
        {
            return N;
        }
        int eCount()
        {
            return m_eCount;
        }
        int OD(int i)
        {
            int ret = 0;
            if ((i >= 0) && (i < vCount()))
            {
                for (int j = 0; j < vCount(); j++)
                {
                    if (m_edges[i][j] != NULL)
                    {
                        ret++;
                    }
                }
            }
            else
            {
                ret = -1;
            }
            return ret;
        }
        int ID(int i)
        {
            int ret = 0;
            if ((i >= 0) && (i < vCount()))
            {
                for (int j = 0; j < vCount(); j++)
                {
                    if (m_edges[j][i] != NULL)
                    {
                        ret++;
                    }
                }
            }
            else
            {
                ret = -1;
            }
            return ret;
        }

        ~MatrixGraph()
        {
            for (int i = 0; i < N; i++)
            {
                delete m_vertexes[i];
                for (int j = 0; j < N; j++)
                {
                   delete m_edges[i][j];
                }
            }
        }
    };
}
//示例代码
/*
MatrixGraph<3, int, int> g;

g.setEdge(0, 1, 1);
g.setEdge(1, 0, 2);
g.setEdge(1, 2, 3);
//g.setEdge(2, 1, 3);

cout << "eCount:" << g.eCount() << endl;
cout << "vCount:" << g.vCount() << endl;
cout << "ID(1):" << g.ID(1) << endl;
cout << "OD(1):" << g.OD(1) << endl;
cout << "TD(1):" << g.TD(1) << endl;
cout << g.getEdge(1, 0) << endl;
cout << g.getEdge(1, 2) << endl;
cout << g.getEdge(0, 1) << endl;

SharedPointer<Array<int>>aj = g.getAdjacent(2);

for (int i = 0; i < aj->length(); i++)
{
    cout << (*aj)[i] << endl;
}

cout << g.eCount() << endl;
g.removeEdge(0, 1);

cout << g.eCount() << endl;

g.setVertex(0, 100);
cout << g.getVertex(0) << endl;
*/


#endif 
