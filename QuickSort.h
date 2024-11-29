#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Log.h"
#include <QString>
#include <cstdio>
#include <QObject>
#include <QCoreApplication>
#include <QDir>
#include "Log.h"
#include "CMap.h"
#include <QFile>
#include <QRegularExpression>
// 1：飞行时间 2：价格 3：起飞时间 4：降落时间
void QuickSort(Log* array, int n,int mode,int opt);
void ModQuickSort1(Log* array, int left, int right,int mode,int opt);
int partition1(Log* array, int left, int right,int mode);
void insertSort1(Log* array, int n,int mode);
void ModQuickSort2(Log* array, int left, int right,int mode,int opt);
int partition2(Log* array, int left, int right,int mode);
void insertSort2(Log* array, int n,int mode);
void ModQuickSort3(Log* array, int left, int right,int mode,int opt);
int partition3(Log* array, int left, int right,int mode);
void insertSort3(Log* array, int n,int mode);
void ModQuickSort4(Log* array, int left, int right,int mode,int opt);
int partition4(Log* array, int left, int right,int mode);
void insertSort4(Log* array, int n,int mode);
void ModQuickSort5(Log* array, int left, int right,int mode,int opt);
int partition5(Log* array, int left, int right,int mode);
void insertSort5(Log* array, int n,int mode);
int timediffer(QString time0,QString time1);
void QuickSort_Turn(Log logs,Log* array,int n,int opt);
void ModQuickSort_Turn(Log logs,Log* array, int left, int right,int opt);
int partition_Turn(Log logs,Log* array, int left, int right);
void insertSort_Turn(Log logs,Log* array, int n);
int modSearch(Log logs0[],QString time1,int a,int b);
void invert(Log* array,int n);
QString pathCreator(QString a);
QPixmap changeImage(QPixmap img_in,int radius);
int calDistance(QPoint city0,QPoint city1);
void setLog(string s,int mode,QDate curdate,int &ticketnum,int &ticket_checkednum,Log *logs);
void CMapSet(QDate curDate,QString* citys,CMap* pMap,int mode);
template <typename T>
void QuickSortcommon(T* array, int n,int mode,int opt);
template <typename T>
void ModQuickSortcommon(T* array, int left, int right,int mode,int opt);
template <typename T>
int partitioncommon(T* array, int left, int right,int mode);
template <typename T>
void insertSortcommon(T* array, int n,int mode);
#endif // QUICKSORT_H
