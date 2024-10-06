#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Log.h"
#include <QString>
#include<iostream>
#include <stdio.h>
#include <cstdio>
#include <QObject>
#include <QCoreApplication>
#include <QDir>
#include "Log.h"
void QuickSort(Log* array, int n,int mode);
void ModQuickSort1(Log* array, int left, int right);
int partition1(Log* array, int left, int right);
void insertSort1(Log* array, int n);
void ModQuickSort2(Log* array, int left, int right);
int partition2(Log* array, int left, int right);
void insertSort2(Log* array, int n);
void ModQuickSort3(Log* array, int left, int right);
int partition3(Log* array, int left, int right);
void insertSort3(Log* array, int n);
void ModQuickSort4(Log* array, int left, int right);
int partition4(Log* array, int left, int right);
void insertSort4(Log* array, int n);
int timediffer(QString time0,QString time1);
void QuickSort_Turn(Log logs,Log* array,int n);
void ModQuickSort_Turn(Log logs,Log* array, int left, int right);
int partition_Turn(Log logs,Log* array, int left, int right);
void insertSort_Turn(Log logs,Log* array, int n);
int modSearch(Log logs0[],QString time1,int a,int b);
QString pathCreator(QString a);
#endif // QUICKSORT_H
