#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Log.h"
#include <QString>
#include<iostream>
#include <stdio.h>
#include <cstdio>
using namespace std;
#define THRESHOLD 8
void ModQuickSort2(Log* array, int left, int right);
int partition2(Log* array, int left, int right);
void insertSort2(Log* array, int n);
void QuickSort2(Log* array, int n) {
    ModQuickSort2(array, 0, n - 1);
    insertSort2(array, n);
}
void ModQuickSort2(Log* array, int left, int right) {
    if (right - left + 1 > THRESHOLD) {
        int j;
        int pivot = (left+right)/2;
        swap(array[pivot], array[right]);
        pivot = partition2(array, left, right);
        ModQuickSort2(array, left, pivot - 1);
        ModQuickSort2(array, pivot + 1, right);
    }
}
int partition2(Log* array, int left, int right) {
    int l = left, r = right;
    int i;
    Log t = array[r];
    while (l != r) {
        while (r > l) {
            if (array[l].price <= t.price) l++;
            else break;
        }
        if (l < r) {
            array[r] = array[l];
            r--;
        }
        while (r > l) {
            if (array[r].price >= t.price) r--;
            else break;
        }
        if (l < r) {
            array[l] = array[r];
            l++;
        }
    }
    array[l] = t;
    return l;
}
void insertSort2(Log* array, int n) {
    int  i, j;
    Log t;
    for (i = 1; i < n; i++) {
        t = array[i];
        int j = i - 1;
        while (j >= 0 && t.price < array[j].price) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = t;
    }
}
#endif // QUICKSORT_H
