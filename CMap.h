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
//图的实现
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
    //经典迪杰斯特拉算法
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
    // DijkstraPlus 函数：改进版 Dijkstra 算法，用于计算从起始节点到其它所有节点的多条最短路径
    Dist* DijkstraPlus(int begin) {
        // 创建一个 Dist 类型的数组，用于存储每个节点的最短路径信息
        Dist* dist = new Dist[m_iCapacity];
        DNODE *p, *q;
        int i, j, k;

        // 重置所有节点的状态
        resetNode();

        // 初始化 dist 数组中的每个节点信息
        for (i = 0; i < m_iCapacity; i++) {
            dist[i].m_vertex = i;  // 节点的编号
            for (j = 0; j < 6; j++) {
                // 如果是起始节点，则初始化其路径长度为 0，否则为无穷大（INT_MAX）
                if (i == begin) {
                    dist[i].m_length_list[j] = 0;
                } else {
                    dist[i].m_length_list[j] = INT_MAX;
                }
                dist[i].m_pre_vertex_list[j] = begin;  // 所有路径的前驱节点初始化为起始节点
            }
            dist[i].m_pre_vertex = begin;  // 默认的前驱节点为起始节点
            if (i == begin) dist[i].m_length = 0;  // 起始节点的最短路径长度为 0
            else dist[i].m_length = INT_MAX;  // 其它节点的最短路径初始化为无穷大
        }

        // 创建一个最小堆，用于优化选择最短路径的节点
        MinHeap mh = MinHeap(m_edgesNumber);
        mh.Insert(&dist[begin]);  // 将起始节点插入到最小堆中

        // 开始主循环，遍历所有节点并更新最短路径信息
        j = 0, k = 0;
        for (i = 0; i < m_iCapacity; i++) {
            bool found = false;   // 标志，检查是否找到一个未访问的节点
            Dist tempdist;

            // 从堆中取出最小路径的节点，直到找到一个未访问的节点
            while (!mh.isempty()) {
                tempdist = *mh.RemoveMin();  // 取出堆中最小的节点
                if (getmVisited(tempdist.m_vertex) == false) {  // 如果该节点还未被访问
                    found = true;
                    break;  // 找到了一个未访问的节点，退出循环
                }
            }

            // 如果所有节点都已经访问过，则结束循环
            if (!found) break;

            // 当前处理的节点
            int v = tempdist.m_vertex;
            m_pNodeArray[v].m_bVisited = true;  // 标记该节点为已访问

            // 遍历当前节点 v 的所有邻接边
            for (Edge* e = firstEdge(v); e != NULL; e = nextEdge(e)) {
                // 如果通过节点 v 到达邻接节点 B 的路径更短，更新最短路径信息
                if (dist[e->m_iNodeIndexB].m_length > dist[v].m_length + e->m_iWeightValue) {
                    dist[e->m_iNodeIndexB].m_length = dist[v].m_length + e->m_iWeightValue;
                    dist[e->m_iNodeIndexB].m_pre_vertex = v;  // 更新前驱节点
                    dist[e->m_iNodeIndexB].m_length_list[0] = dist[v].m_length + e->m_iWeightValue;
                    dist[e->m_iNodeIndexB].m_pre_vertex_list[0] = v;
                    mh.Insert(&dist[e->m_iNodeIndexB]);  // 将更新后的节点重新插入堆中
                    continue;
                }

                // 对于每个邻接节点，如果该路径长度比已存储的路径更短，
                // 或者该路径是次短路径列表中的第一条，更新路径信息
                for (j = 0; j < 6; j++) {
                    if ((dist[e->m_iNodeIndexB].m_length_list[j] < dist[v].m_length + e->m_iWeightValue) &&
                        (dist[e->m_iNodeIndexB].m_length_list[j + 1] > dist[v].m_length + e->m_iWeightValue)) {
                        dist[e->m_iNodeIndexB].m_length_list[j + 1] = dist[v].m_length + e->m_iWeightValue;
                        dist[e->m_iNodeIndexB].m_pre_vertex_list[j + 1] = v;
                        mh.Insert(&dist[e->m_iNodeIndexB]);  // 更新后插入堆中
                        break;  // 找到并更新了次短路径，跳出循环
                    }
                }
            }
        }

        // 返回存储所有节点最短路径信息的 dist 数组
        return dist;
    }
    //求最短路径
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
    //求次短路径
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
    // visit_plus 函数：用于递归地追溯最短路径并生成路径字符串列表
    // 该函数通过深度优先搜索来找出从某个节点到另一个节点的路径，
    // 允许返回多条路径，并根据条件对路径进行过滤
    QStringList visit_plus(Dist* tempdist, int dep, int ari, int Ari, int lastmin,bool blist[]) {
        int a = ari, i, j;
        bool same;
        QString s;
        QStringList list, list0;
        int depth = 0;

        // 如果当前节点 ari 已经被访问过，直接返回空列表
        if (blist[ari]) {
            free(blist);
            return list;
        }

        // 计算当前访问路径的深度
        for (j = 0; j < 16; j++) {
            if (blist[j]) depth++;
        }

        // 如果路径深度超过 4，认为路径过长，直接返回空列表
        if (depth > 4) {
            free(blist);
            return list;
        }

        // 标记当前节点 ari 为已访问
        blist[ari] = true;

        // 如果当前节点的前驱是起始节点 dep 并且 ari != Ari，则记录当前路径
        if (tempdist[ari].m_pre_vertex_list[0] == dep && Ari != ari) {
            // 如果 ari == dep，表示到达起点，构建路径
            if (ari == dep) s = "< " + QString::number(dep);
            else s = "< " + QString::number(dep) + " " + QString::number(ari);
            list.append(s);  // 将路径添加到列表中
            free(blist);
            return list;  // 返回路径
        }

        // 遍历 ari 的所有前驱节点
        for (i = 0; i < 6; i++) {
            // 如果路径长度不为无穷大且前驱节点未访问，并且节点编号小于 16
            if (tempdist[ari].m_length_list[i] != INT_MAX && !blist[tempdist[ari].m_pre_vertex_list[i]] && tempdist[ari].m_pre_vertex_list[i] < 16) {
                // 如果当前路径的长度大于父节点的下一兄弟节点的路径长度，且 ari != Ari，则结束递归
                if (tempdist[ari].m_length_list[i] > lastmin && ari != Ari) {
                    free(blist);  // 释放临时布尔数组
                    return list;  // 结束递归，返回当前路径列表
                }

                // 创建一个新的布尔数组 blist0，复制当前的访问状态
                bool* blist0 = (bool*)malloc(sizeof(bool) * 16);
                for (j = 0; j < 16; j++) {
                    blist0[j] = blist[j];  // 复制访问状态
                }
                // 将次长的路径长度赋给lastmin
                if(i!=5) lastmin=tempdist[ari].m_length_list[i+1];
                else lastmin=INT_MAX;
                // 调试输出，显示当前的前驱节点
                qDebug() << tempdist[ari].m_pre_vertex_list[i] << "\n";

                // 递归调用 visit_plus 查找当前节点的前驱路径
                list0 = visit_plus(tempdist, dep, tempdist[ari].m_pre_vertex_list[i], Ari, lastmin,blist0);

                // 遍历并处理递归返回的路径
                while (!list0.empty()) {
                    // 如果 Ari != ari，则在路径末尾加上当前节点
                    if (Ari != ari)
                        s = list0[0] + " " + QString::number(ari);
                    else
                        s = list0[0] + " : " + QString::number(tempdist[ari].m_length_list[i]) + " " + QString::number(tempdist[ari].m_vertex) + " >";

                    list.append(s);  // 将生成的路径添加到最终的路径列表中
                    list0.removeFirst();  // 移除已处理的路径
                }
            }
        }
        // 返回最终的路径列表
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
