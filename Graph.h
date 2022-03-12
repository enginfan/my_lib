#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "Object.h"
#include "SharedPointer.h"
#include "Array.h"
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

    };
}

#endif // !GRAPH_H
