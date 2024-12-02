#include <iostream>
#include <assert.h>
#include "Node.h"
#include "Edge.h"
using namespace std;
#ifndef MINHEAP_H
#define MINHEAP_H
typedef struct dnode{
    int m_second_pre_vertex;
    struct dnode* next;
}DNODE;

struct Dist {
    int m_vertex;
    int m_length;
    int m_pre_vertex;
    //second新增
    int m_second_length;
    int m_second_pre_vertex;
    //plus新增
    int m_length_list[100];
    int m_pre_vertex_list[100];
};

class MinHeap {
private:
    Dist** heapArray;
    int CurrentSize;
    int MaxSize;
    void swap(int pos_x, int pos_y) {
        Dist* temp;
        temp = heapArray[pos_x];
        heapArray[pos_x] = heapArray[pos_y];
        heapArray[pos_y] = temp;
    }
    void BuildHeap() {
        for (int i = CurrentSize / 2 - 1; i >= 0; i--) {
            SiftDown(i);
        }
    }
public:
    MinHeap(const int n) {
        if (n <= 0) {
            return;
        }
        CurrentSize = 0;
        MaxSize = n;
        heapArray = new Dist * [MaxSize];
        BuildHeap();
    }
    virtual ~MinHeap() { delete[]heapArray; }
    int LeftChild(int pos) {
        return 2 * pos + 1;
    }
    int RightChild(int pos) {
        return 2 * pos + 2;
    }
    int Parent(int pos) {
        return (pos - 1) / 2;
    }
    //上筛
    void SiftUp(int position) {
        int temppos = position;
        Dist* temp;
        while ((temppos > 0) && ((heapArray[Parent(temppos)]->m_length) > (heapArray[temppos]->m_length))) {
            temp = heapArray[temppos];
            heapArray[temppos] = heapArray[Parent(temppos)];
            heapArray[Parent(temppos)] = temp;
            temppos = Parent(temppos);
        }
    }
    //下筛
    void SiftDown(int left) {
        int i = left;
        int j = LeftChild(i);
        Dist* temp = heapArray[i];
        while (j < CurrentSize) {
            if ((j < CurrentSize - 1) && (heapArray[j]->m_length > heapArray[j + 1]->m_length)) j++;
            if (temp->m_length > heapArray[j]->m_length) {
                heapArray[i] = heapArray[j];
                i = j;
                j = LeftChild(j);
            }
            else break;
        }
        heapArray[i] = temp;
    }
    //插入
    bool Insert(Dist* newNode) {
        if (CurrentSize == MaxSize) return false;
        heapArray[CurrentSize] = newNode;
        SiftUp(CurrentSize);
        CurrentSize++;
        return true;
    }
    //移出
    Dist* RemoveMin() {
        if (CurrentSize == 0) {
            cout << "Can't Delete";
            exit(1);
        }
        else {
            swap(0, --CurrentSize);
            if (CurrentSize > 1) SiftDown(0);
            return heapArray[CurrentSize];
        }
    }
    bool isempty() {
        if (CurrentSize < 1) return true;
        else return false;
    }
    int getC() {
        return CurrentSize;
    }
    Dist** getH() {
        return heapArray;
    }
};
#endif // MINHEAP_H
