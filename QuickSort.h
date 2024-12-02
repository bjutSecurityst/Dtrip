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
// mode 1：飞行时间-升序 2：价格-升序 3：起飞时间-升序 4：降落时间-升序 5：准点率-升序 6：PID-升序 7：日期-升序
// 8-14为降序 快排n为数组数量+1 归并n为数组数量 opt为是否采用随机轴值优化
//快排主函数
void QuickSort(Log* array, int n,int mode,int opt);
//按价格排序
void ModQuickSort1(Log* array, int left, int right,int mode,int opt);
int partition1(Log* array, int left, int right,int mode);
void insertSort1(Log* array, int n,int mode);
//按飞行时间排序
void ModQuickSort2(Log* array, int left, int right,int mode,int opt);
int partition2(Log* array, int left, int right,int mode);
void insertSort2(Log* array, int n,int mode);
//按起飞时间排序
void ModQuickSort3(Log* array, int left, int right,int mode,int opt);
int partition3(Log* array, int left, int right,int mode);
void insertSort3(Log* array, int n,int mode);
//按降落时间排序
void ModQuickSort4(Log* array, int left, int right,int mode,int opt);
int partition4(Log* array, int left, int right,int mode);
void insertSort4(Log* array, int n,int mode);
//按准点率排序
void ModQuickSort5(Log* array, int left, int right,int mode,int opt);
int partition5(Log* array, int left, int right,int mode);
void insertSort5(Log* array, int n,int mode);
//按PID排序
void ModQuickSort6(Log* array, int left, int right,int mode,int opt);
int partition6(Log* array, int left, int right,int mode);
void insertSort6(Log* array, int n,int mode);
//按日期排序
void ModQuickSort7(Log* array, int left, int right,int mode,int opt);
int partition7(Log* array, int left, int right,int mode);
void insertSort7(Log* array, int n,int mode);
//时间差计算函数
int timediffer(QString time0,QString time1);
//按转机时间+飞行时间排序
void QuickSort_Turn(Log logs,Log* array,int n,int opt);
void ModQuickSort_Turn(Log logs,Log* array, int left, int right,int opt);
int partition_Turn(Log logs,Log* array, int left, int right);
void insertSort_Turn(Log logs,Log* array, int n);
//按价格归并排序
void mergeSort(Log* array, Log* temparray,int left, int right);
void merge(Log* array, Log* temparray, int left, int right, int middle);
//废弃函数
void mergeSortTurn(Log logs,Log* array, Log* temparray,int left, int right);
void mergeTurn(Log logs,Log* array, Log* temparray, int left, int right, int middle);
//二分法查找函数
int modSearch(Log logs0[],QString time1,int a,int b);
//相对路径转绝对路径
QString pathCreator(QString a);
//通用快排函数
template <typename T>
void QuickSortcommon(T* array, int n,int mode,int opt);
template <typename T>
void ModQuickSortcommon(T* array, int left, int right,int mode,int opt);
template <typename T>
int partitioncommon(T* array, int left, int right,int mode);
template <typename T>
void insertSortcommon(T* array, int n,int mode);
//查找第二日票据
void findSecondDay(Log *logs,Log *logs0,int &ticketnum,int &ticket_checkednum,int i,int mode,int j,int &l,QDate curdate,string s);
//城市字符串编码为数字
void findCityNum(Log mylog,int &begin,int &end);
//调换函数，用于优化排序
void invert(Log* array,int n);
//图片圆角化函数
QPixmap changeImage(QPixmap img_in,int radius);
//城市之间距离计算函数
int calDistance(QPoint city0,QPoint city1);
//设置迪杰斯特拉算法输出路径的票据的函数
void setLog(string s,int mode,QDate curdate,int &ticketnum,int &ticket_checkednum,Log *logs);
//设置图的函数
void CMapSet(QDate curDate,QString* citys,CMap* pMap,int mode);
#endif // QUICKSORT_H
