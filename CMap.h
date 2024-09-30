#include <iostream>
#include <vector>
#include <assert.h>
#include <string.h>
#include <queue>
#include "Node.h"
#include "Edge.h"
#include "MinHeap.h"
#include "mainwindow.h"
using namespace std;
#ifndef CMAP_H
#define CMAP_H

class CMap
{

private:
    int m_iCapacity; //顶点总数
    int m_iNodeCount; //当前顶点数量
    int m_edgesNumber;
    Node* m_pNodeArray; //顶点集合
    int* m_pMatrix; //邻接距阵
    Edge* m_pEdgeArray; //最小生成树边集合
public:
    CMap(int iCapacity,int edgesNumber)
    {
        m_iCapacity = iCapacity;
        m_iNodeCount = 0;
        m_edgesNumber = edgesNumber;
        m_pNodeArray = new Node[m_iCapacity];
        m_pMatrix = new int[m_iCapacity * m_iCapacity];
        memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));
        m_pEdgeArray = new Edge[m_iCapacity - 1];
    }
    CMap(CMap* cmap)
    {
        int i,j;
        m_iCapacity = cmap->m_iCapacity;
        m_iNodeCount = cmap->m_iNodeCount;
        m_edgesNumber = cmap->m_edgesNumber;
        m_pNodeArray = new Node[m_iCapacity];
        for (i = 0; i < m_iCapacity; i++) {
            m_pNodeArray[i].m_cData = cmap->m_pNodeArray[i].m_cData;
            m_pNodeArray[i].m_bVisited = cmap->m_pNodeArray[i].m_bVisited;
            m_pNodeArray[i].m_indegree = cmap->m_pNodeArray[i].m_indegree;
        }
        m_pMatrix = new int[m_iCapacity * m_iCapacity];
        memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));
        for (i = 0; i < m_iCapacity; i++) {
            for (j = 0; j < m_iCapacity; j++) {
                m_pMatrix[i * m_iCapacity + j] = cmap->m_pMatrix[i * m_iCapacity + j];
            }
        }
        m_pEdgeArray = new Edge[m_iCapacity - 1];
    }
    ~CMap(void)
    {
        delete[]m_pNodeArray;
        delete[]m_pMatrix;
        delete[]m_pEdgeArray;
    }

private:
    //广度遍历具体实现
    void breadthFirstTraverseImpl(vector<int> preVec)
    {
        int val = 0;
        vector<int> curVec;
        for (int i = 0; i < (int)preVec.size(); i++)
        {
            for (int j = 0; j < m_iCapacity; j++)
            {
                getValueFromMatrix(preVec[i], j, val);
                if (/*1 == val*/0 != val)
                {
                    if (m_pNodeArray[j].m_bVisited)
                        continue;
                    cout << m_pNodeArray[j].m_cData << " ";
                    m_pNodeArray[j].m_bVisited = true;
                    curVec.push_back(j);
                }
                else
                    continue;
            }
        }

        if (curVec.empty())
            return;
        else
            breadthFirstTraverseImpl(curVec);
    }

    //取最小边
    int getMinEdge(const vector<Edge>& edgeVec)
    {
        int min = 0, minEdge = 0;

        for (int i = 0; i < (int)edgeVec.size(); i++)
        {
            if (edgeVec[i].m_bSelected)
                continue;
            min = edgeVec[i].m_iWeightValue;
            minEdge = i;
        }

        for (int i = 0; i < (int)edgeVec.size(); i++)
        {
            if (edgeVec[i].m_bSelected)
                continue;
            if (min > edgeVec[i].m_iWeightValue)
            {
                min = edgeVec[i].m_iWeightValue;
                minEdge = i;
            }
        }

        if (0 == min)
            return -1;

        return minEdge;
    }

    bool isInSet(const vector<int>& nodeSet, int target)
    {
        for (int i = 0; i < (int)nodeSet.size(); i++)
        {
            if (nodeSet[i] == target)
                return true;
        }

        return false;
    }

    void mergeNodeSet(vector<int>& nodeSetA, const vector<int>& nodeSetB)
    {
        for (size_t i = 0; i < (int)nodeSetB.size(); i++)
        {
            nodeSetA.push_back(nodeSetB[i]);
        }
    }
public:
    int getIndegree(int a) {
        return m_pNodeArray[a].m_indegree;
    }
    int getmCapacity() {
        return m_iCapacity;
    }
    int getmVisited(int a) {
        return m_pNodeArray[a].m_bVisited;
    }
    void deleteNode(int a) {
        m_pNodeArray[a].m_bVisited = true;
        int i;
        for (i = 0; i < m_iCapacity; i++) {
            if (m_pMatrix[a * m_iCapacity + i] == 1) {
                m_pMatrix[a * m_iCapacity + i] = 0;
                m_pNodeArray[i].m_indegree -= 1;
            }
        }
    }
    //添加顶点
    void addNode(Node* node)
    {
        assert(node);
        m_pNodeArray[m_iNodeCount].m_cData = node->m_cData;
        m_iNodeCount++;
    }
    //将顶点访问设置默认
    void resetNode()
    {
        for (int i = 0; i < m_iNodeCount; i++)
            m_pNodeArray[i].m_bVisited = false;
    }
    //设置权重-有向图
    bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1)
    {
        if (row < 0 || row >= m_iCapacity)
            return false;
        if (col < 0 || col >= m_iCapacity)
            return false;
        m_pMatrix[row * m_iCapacity + col] = val;
        if (m_pNodeArray[row].next == NULL) {
            m_pNodeArray[row].next = new Edge(row, col, val);
        }
        else {
            Edge* edge0 = m_pNodeArray[row].next;
            while (edge0->next != NULL) {
                // if (edge0->m_iNodeIndexA == row && edge0->m_iNodeIndexB == col) {
                //     edge0->m_iWeightValue = val;
                //     return false;
                // }
                edge0 = edge0->next;
            }
            edge0->next = new Edge(row, col, val);
        }
        m_pNodeArray[col].m_indegree += 1;
        return true;
    }
    Edge* firstEdge(int v) {
        return m_pNodeArray[v].next;
    }
    Edge* nextEdge(Edge* e) {
        return e->next;
    }
    //设置权重-无向图
    bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1)
    {
        if (row < 0 || row >= m_iCapacity)
            return false;
        if (col < 0 || col >= m_iCapacity)
            return false;
        m_pMatrix[row * m_iCapacity + col] = val;
        m_pMatrix[col * m_iCapacity + row] = val;
        return true;
    }
    //获取权重
    bool getValueFromMatrix(int row, int col, int& val)
    {
        if (row < 0 || row >= m_iCapacity)
            return false;
        if (col < 0 || col >= m_iCapacity)
            return false;
        val = m_pMatrix[row * m_iCapacity + col];
        return true;
    }
    //打印矩阵
    void printMatrix()
    {
        for (int i = 0; i < m_iCapacity; i++)
        {
            for (int j = 0; j < m_iCapacity; j++)
                cout << m_pMatrix[i * m_iCapacity + j] << " ";
            cout << endl;
        }
    }

    //深度遍历
    void depthFirstTraverse(int index)
    {
        int val = 0;
        cout << m_pNodeArray[index].m_cData << " ";
        m_pNodeArray[index].m_bVisited = true;

        for (int i = 0; i < m_iCapacity; i++)
        {
            getValueFromMatrix(index, i, val);
            if (/*1 == val*/0 != val)
            {
                if (m_pNodeArray[i].m_bVisited)
                    continue;
                depthFirstTraverse(i);
            }
            else
                continue;
        }
    }

    //广度遍历
    void breadthFirstTraverse(int index)
    {
        cout << m_pNodeArray[index].m_cData << " ";
        m_pNodeArray[index].m_bVisited = true;

        vector<int> curVec;
        curVec.push_back(index);

        breadthFirstTraverseImpl(curVec);
    }

    //求最小生成树-普里斯算法
    void primTree(int index)
    {
        int val = 0;
        int iEdgeCount = 0;
        vector<Edge> edgeVec;//待选边集合

        //从传入点开始找
        vector<int> nodeIndexVec;
        nodeIndexVec.push_back(index);

        //结束条件：边数=顶点数-1
        while (iEdgeCount < m_iCapacity - 1)
        {
            //查找传入点的符合要求（权重不为0且目的点没有被访问）边
            int row = nodeIndexVec.back();
            cout << m_pNodeArray[row].m_cData << endl;
            m_pNodeArray[row].m_bVisited = true;

            for (int i = 0; i < m_iCapacity; i++)
            {
                getValueFromMatrix(row, i, val);
                if (0 == val)
                    continue;
                if (m_pNodeArray[i].m_bVisited)
                    continue;
                Edge edge(row, i, val);
                edgeVec.push_back(edge);
            }

            //取出最小边
            int retIndex = getMinEdge(edgeVec);
            if (-1 != retIndex)
            {
                //存储选中边
                edgeVec[retIndex].m_bSelected = true;
                m_pEdgeArray[iEdgeCount] = edgeVec[retIndex];
                cout << m_pNodeArray[m_pEdgeArray[iEdgeCount].m_iNodeIndexA].m_cData << " - ";
                cout << m_pNodeArray[m_pEdgeArray[iEdgeCount].m_iNodeIndexB].m_cData << " (";
                cout << m_pEdgeArray[iEdgeCount].m_iWeightValue << ") " << endl;
                iEdgeCount++;

                int iNodeIndex = edgeVec[retIndex].m_iNodeIndexB;
                //设置点被访问
                m_pNodeArray[iNodeIndex].m_bVisited = true;
                //存入目的点递归查找
                nodeIndexVec.push_back(iNodeIndex);
            }
        }

    }

    bool loopfind() {
        resetNode();
        int i,n=0;
        queue<int> que;
        for (i = 0; i < m_iCapacity; i++) {
            if (m_pNodeArray[i].m_indegree == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            i = que.front();
            que.pop();
            n = n + 1;
            m_pNodeArray[i].m_bVisited = true;
            Edge* edge0;
            edge0 = m_pNodeArray[i].next;
            while (edge0 != NULL) {
                m_pNodeArray[edge0->m_iNodeIndexB].m_indegree -= 1;
                if (m_pNodeArray[edge0->m_iNodeIndexB].m_indegree == 0) {
                    que.push(edge0->m_iNodeIndexB);
                }
                edge0 = edge0->next;
            }
        }
        if (n != m_iCapacity) {
            return false;
        }
        return true;
    }

    Dist* Dijkstra(int begin) {
        Dist* dist = new Dist[m_iCapacity];
        DNODE *p,*q;
        int i;
        resetNode();
        for (i = 0; i < m_iCapacity; i++) {
            dist[i].m_vertex = i;
            dist[i].m_length = INT_MAX;
            dist[i].m_pre_vertex = begin;
            dist[i].m_second_length = INT_MAX;
            dist[i].m_second_pre_vertex = begin;
        }
        dist[begin].m_length = 0;
        MinHeap mh=MinHeap(m_edgesNumber);
        mh.Insert(&dist[begin]);
        for (i = 0; i < m_iCapacity; i++) {
            bool found = false;
            Dist tempdist;
            while (!mh.isempty()) {
                tempdist = *mh.RemoveMin();
                if (getmVisited(tempdist.m_vertex) == false) {
                    found = true;
                    break;
                }
            }
            if (!found) break;
            int v = tempdist.m_vertex;
            m_pNodeArray[v].m_bVisited = true;
            for (Edge* e = firstEdge(v); e != NULL; e = nextEdge(e)) {
                if (dist[e->m_iNodeIndexB].m_length > dist[v].m_length + e->m_iWeightValue) {
                    dist[e->m_iNodeIndexB].m_length = dist[v].m_length + e->m_iWeightValue;
                    dist[e->m_iNodeIndexB].m_pre_vertex = v;
                    mh.Insert(&dist[e->m_iNodeIndexB]);
                }
                if ((dist[e->m_iNodeIndexB].m_length < dist[v].m_length + e->m_iWeightValue)&&(dist[e->m_iNodeIndexB].m_second_length > dist[v].m_length + e->m_iWeightValue)) {
                    dist[e->m_iNodeIndexB].m_second_length = dist[v].m_length + e->m_iWeightValue;
                    dist[e->m_iNodeIndexB].m_second_pre_vertex = v;
                    //mh.Insert(&dist[e->m_iNodeIndexB]);
                }
            }
        }
        return dist;
    }
    Dist* DijkstraPlus(int begin) {
        Dist* dist = new Dist[m_iCapacity];
        DNODE *p,*q;
        int i,j,k;
        resetNode();
        for (i = 0; i < m_iCapacity; i++) {
            dist[i].m_vertex = i;
            for(j=0;j<6;j++){
                if(i==begin) {
                    dist[i].m_length_list[j] = 0;
                }
                else {
                    dist[i].m_length_list[j] = INT_MAX;
                }
                dist[i].m_pre_vertex_list[j] = begin;
            }
            dist[i].m_pre_vertex = begin;
            if(i==begin) dist[i].m_length=0;
            else dist[i].m_length = INT_MAX;
        }
        MinHeap mh=MinHeap(m_edgesNumber);
        mh.Insert(&dist[begin]);
        j=0,k=0;
        for (i = 0; i < m_iCapacity; i++) {
            bool found = false;
            Dist tempdist;
            while (!mh.isempty()) {
                tempdist = *mh.RemoveMin();
                if (getmVisited(tempdist.m_vertex) == false) {
                    found = true;
                    break;
                }
            }
            if (!found) break;
            int v = tempdist.m_vertex;
            m_pNodeArray[v].m_bVisited = true;
            for (Edge* e = firstEdge(v); e != NULL; e = nextEdge(e)) {
                if (dist[e->m_iNodeIndexB].m_length > dist[v].m_length + e->m_iWeightValue) {
                    dist[e->m_iNodeIndexB].m_length = dist[v].m_length + e->m_iWeightValue;
                    dist[e->m_iNodeIndexB].m_pre_vertex = v;
                    dist[e->m_iNodeIndexB].m_length_list[0] = dist[v].m_length + e->m_iWeightValue;
                    dist[e->m_iNodeIndexB].m_pre_vertex_list[0] = v;
                    mh.Insert(&dist[e->m_iNodeIndexB]);
                    continue;
                }
                for(j=0;j<6;j++){
                    if ((dist[e->m_iNodeIndexB].m_length_list[j] < dist[v].m_length + e->m_iWeightValue)&&(dist[e->m_iNodeIndexB].m_length_list[j+1] > dist[v].m_length + e->m_iWeightValue)) {
                        dist[e->m_iNodeIndexB].m_length_list[j+1] = dist[v].m_length + e->m_iWeightValue;
                        dist[e->m_iNodeIndexB].m_pre_vertex_list[j+1] = v;
                        mh.Insert(&dist[e->m_iNodeIndexB]);
                        break;
                    }
                }
            }
        }
        return dist;
    }
    string visit_first(Dist* tempdist, int dep,int ari) {
        int a=ari;
        string s;
        if (tempdist[ari].m_length == INT_MAX) {
            cout << "< " << dep << " , " << "INF" << " " << tempdist[ari].m_vertex << " >" << endl;
            s="不可达";
        }
        else{
            while(tempdist[a].m_pre_vertex!=dep){
                s = " , " + to_string(tempdist[a].m_pre_vertex) + s;
                a = tempdist[a].m_pre_vertex;
            }
            cout << "< " << dep << s << " : " << tempdist[ari].m_length << " " << tempdist[ari].m_vertex << " >" << endl;
            s="< " + to_string(dep) + s + " : " + to_string(tempdist[ari].m_length) + " " + to_string(tempdist[ari].m_vertex) + " >";
        }
        return s;
    }
    string visit_second(Dist* tempdist, int dep,int ari) {
        int a=ari;
        string s;
        if (tempdist[ari].m_second_length == INT_MAX) {
            cout << "< " << dep << " " << "INF" << " " << tempdist[ari].m_vertex << " >" << endl;
            s="不可达";
        }
        else {
            if(tempdist[a].m_second_pre_vertex!=dep){
                s = " " + to_string(tempdist[a].m_second_pre_vertex) + s;
                a = tempdist[a].m_second_pre_vertex;
            }
            while(tempdist[a].m_pre_vertex!=dep){
                s = " " + to_string(tempdist[a].m_pre_vertex) + s;
                a = tempdist[a].m_pre_vertex;
            }
            cout << "< " << dep << s << " : " << tempdist[ari].m_second_length << " " << tempdist[ari].m_vertex << " >" << endl;
            s= "< " + to_string(dep) + s + " : " + to_string(tempdist[ari].m_second_length) + " " + to_string(tempdist[ari].m_vertex) + " >";
        }
        return s;
    }
    QStringList visit_plus(Dist* tempdist, int dep,int ari ,int Ari,bool* blist) {
        int a=ari,i,j;
        bool same;
        QString s;
        QStringList list,list0;
        blist[ari]=true;
        bool blist0[16];
        for(i=0;i<16;i++){
            blist0[i]=blist[i];
        }
        if(tempdist[ari].m_pre_vertex_list[0]==dep && Ari!=ari){
            if(ari==dep) s="< " + QString::number(dep);
            else s="< " + QString::number(dep)+" "+QString::number(ari);
            list.append(s);
            return list;
        }
        for(i=0;i<6;i++){
            if (tempdist[ari].m_length_list[i] != INT_MAX && blist[tempdist[ari].m_pre_vertex_list[i]]!=true) {
                list0 = visit_plus(tempdist, dep, tempdist[ari].m_pre_vertex_list[i], Ari,blist0);
                while (!list0.empty()) {
                    if (Ari != ari) s = list0[0] + " " + QString::number(ari);
                    else s = list0[0] + " : " + QString::number(tempdist[ari].m_length_list[i]) + " " + QString::number(tempdist[ari].m_vertex) + " >";
                    list.append(s);
                    list0.removeFirst();
                }
            }
        }
        return list;
    }
    //最小生成树-克鲁斯卡尔算法
    void kruskalTree()
    {
        int val = 0;
        int edgeCount = 0;

        //定义存放节点集合数组
        vector<vector<int> > nodeSets;

        //第一步、取出所有边
        vector<Edge> edgeVec;
        for (int i = 0; i < m_iCapacity; i++)
        {
            for (int j = i + 1; j < m_iCapacity; j++)
            {
                getValueFromMatrix(i, j, val);
                if (0 == val)
                    continue;
                if (m_pNodeArray[i].m_bVisited)
                    continue;
                Edge edge(i, j, val);
                edgeVec.push_back(edge);
            }
        }

        //第二步、从所有边中取出组成最小生成树的边
        //1、算法结束条件：边数=顶点数-1
        while (edgeCount < m_iCapacity - 1)
        {
            //2、从边集合中找出最小边
            int retIndex = getMinEdge(edgeVec);
            if (-1 != retIndex)
            {
                edgeVec[retIndex].m_bSelected = true;

                //3、找出最小边连接点
                int nodeAIndex = edgeVec[retIndex].m_iNodeIndexA;
                int nodeBIndex = edgeVec[retIndex].m_iNodeIndexB;

                //4、找出点所在集合
                bool nodeAInSet = false;
                bool nodeBInSet = false;
                int nodeAInSetLabel = -1;
                int nodeBInSetLabel = -1;

                for (int i = 0; i < (int)nodeSets.size(); i++)
                {
                    nodeAInSet = isInSet(nodeSets[i], nodeAIndex);
                    if (nodeAInSet)
                        nodeAInSetLabel = i;
                }

                for (int i = 0; i < (int)nodeSets.size(); i++)
                {
                    nodeBInSet = isInSet(nodeSets[i], nodeBIndex);
                    if (nodeBInSet)
                        nodeBInSetLabel = i;
                }

                //5、根据点集合的不同做不同处理
                if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1)
                {
                    vector<int> vec;
                    vec.push_back(nodeAIndex);
                    vec.push_back(nodeBIndex);
                    nodeSets.push_back(vec);
                }
                else if (nodeAInSetLabel == -1 && nodeBInSetLabel != -1)
                {
                    nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
                }
                else if (nodeAInSetLabel != -1 && nodeBInSetLabel == -1)
                {
                    nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
                }
                else if (-1 != nodeAInSetLabel && -1 != nodeBInSetLabel && nodeAInSetLabel != nodeBInSetLabel)
                {
                    //mergeNodeSet(nodeSets[nodeAInSetLabel], nodeSets[nodeBInSetLabel]);
                    nodeSets[nodeAInSetLabel].insert(nodeSets[nodeAInSetLabel].end(),
                                                     nodeSets[nodeBInSetLabel].begin(),
                                                     nodeSets[nodeBInSetLabel].end());
                    for (int k = nodeBInSetLabel; k < (int)nodeSets.size() - 1; k++)
                    {
                        nodeSets[k] = nodeSets[k + 1];
                    }
                }
                else if (nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel)
                {
                    continue;
                }

                m_pEdgeArray[edgeCount] = edgeVec[retIndex];
                edgeCount++;

                cout << m_pNodeArray[edgeVec[retIndex].m_iNodeIndexA].m_cData << " - ";
                cout << m_pNodeArray[edgeVec[retIndex].m_iNodeIndexB].m_cData << " (";
                cout << edgeVec[retIndex].m_iWeightValue << ") " << endl;
            }
        }
    }
};
#endif // CMAP_H
