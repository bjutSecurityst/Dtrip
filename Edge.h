#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include <queue>
using namespace std;
#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:
    Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0) :
        m_iNodeIndexA(nodeIndexA),
        m_iNodeIndexB(nodeIndexB),
        m_iWeightValue(weightValue),
        next(NULL),
        m_bSelected(false) {}
    Edge(const Edge& edge)
    {
        if (this == &edge)
            return;
        *this = edge;
    }

    Edge& operator=(const Edge& edge)
    {
        if (this == &edge)
            return *this;
        this->m_iNodeIndexA = edge.m_iNodeIndexA;
        this->m_iNodeIndexB = edge.m_iNodeIndexB;
        this->m_iWeightValue = edge.m_iWeightValue;
        this->m_bSelected = edge.m_bSelected;
        return *this;
    }

public:
    int m_iNodeIndexA; //头顶点
    int m_iNodeIndexB; //尾顶点
    int m_iWeightValue; //权重
    bool m_bSelected; //是否被选中
    Edge* next;
};
#endif // EDGE_H
