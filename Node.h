#include <assert.h>
#include "Edge.h"
using namespace std;
#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int data = 0)
    {
        m_cData = data;
        m_bVisited = false;
        m_indegree = 0;
        next = NULL;
    }
    Node(const Node& node)
    {
        if (this == &node)
            return;
        *this = node;
    }


    Node& operator=(const Node& node)
    {
        if (this == &node)
            return *this;
        this->m_cData = node.m_cData;
        this->m_bVisited = node.m_bVisited;
        this->next = node.next;
        return *this;
    }
public:
    int m_cData; //数据
    bool m_bVisited; //是否访问
    int m_indegree;
    Edge* next;
};
#endif // NODE_H
