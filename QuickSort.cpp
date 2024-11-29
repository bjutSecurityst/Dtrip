#include "Log.h"
#include <QString>
#include <cstdio>
#include <QObject>
#include <QCoreApplication>
#include <QDir>
#include "Log.h"
#include "QWindow"
#include "mainwindow.h"
#include <QPixmap>
#include <QPainter>
#include <random>
using namespace std;
#define THRESHOLD 8
#define sortnum 8
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
void ModQuickSort6(Log* array, int left, int right,int mode,int opt);
int partition6(Log* array, int left, int right,int mode);
void insertSort6(Log* array, int n,int mode);
void ModQuickSort7(Log* array, int left, int right,int mode,int opt);
int partition7(Log* array, int left, int right,int mode);
void insertSort7(Log* array, int n,int mode);
int timediffer(QString time0,QString time1);
void QuickSort_Turn(Log logs,Log* array,int n,int opt);
void ModQuickSort_Turn(Log logs,Log* array, int left, int right,int opt);
int partition_Turn(Log logs,Log* array, int left, int right);
void insertSort_Turn(Log logs,Log* array, int n);
int modSearch(Log logs0[],QString time1,int a,int b);
QString pathCreator(QString a);
template <typename T>
void QuickSortcommon(T* array, int n,int mode,int opt);
template <typename T>
void ModQuickSortcommon(T* array, int left, int right,int mode,int opt);
template <typename T>
int partitioncommon(T* array, int left, int right,int mode);
template <typename T>
void insertSortcommon(T* array, int n,int mode);
void ModQuickSort1(Log* array, int left, int right,int mode,int opt) {
    if (right - left + 1 > THRESHOLD) {
        int j,pivot;
        if(opt==0) pivot = (left+right)/2;
        else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(left,right); // 指定范围
            pivot=distrib(gen);
        }
        swap(array[pivot], array[right]);
        pivot = partition1(array, left, right,mode);
        ModQuickSort1(array, left, pivot - 1,mode,opt);
        ModQuickSort1(array, pivot + 1, right,mode,opt);
    }
}
int partition1(Log* array, int left, int right,int mode) {
    int l = left, r = right;
    int i;
    Log t = array[r];
    if(mode<sortnum){
        while (l != r) {
            while (r > l) {
                if (timediffer(array[l].time0,array[l].time1) <= timediffer(t.time0,t.time1)) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (timediffer(array[r].time0,array[r].time1) >= timediffer(t.time0,t.time1)) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    else{
        while (l != r) {
            while (r > l) {
                if (timediffer(array[l].time0,array[l].time1) >= timediffer(t.time0,t.time1)) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (timediffer(array[r].time0,array[r].time1) <= timediffer(t.time0,t.time1)) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    array[l] = t;
    return l;
}
void insertSort1(Log* array, int n,int mode) {
    int  i, j;
    Log t;
    if(mode<sortnum){
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && timediffer(t.time0,t.time1) < timediffer(array[j].time0,array[j].time1)) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
    else{
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && timediffer(t.time0,t.time1) > timediffer(array[j].time0,array[j].time1)) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
}
void ModQuickSort2(Log* array, int left, int right,int mode,int opt) {
    if (right - left + 1 > THRESHOLD) {
        int j,pivot;
        if(opt==0) pivot = (left+right)/2;
        else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(left,right); // 指定范围
            pivot=distrib(gen);
        }
        swap(array[pivot], array[right]);
        pivot = partition2(array, left, right,mode);
        ModQuickSort2(array, left, pivot - 1,mode,opt);
        ModQuickSort2(array, pivot + 1, right,mode,opt);
    }
}
int partition2(Log* array, int left, int right,int mode) {
    int l = left, r = right;
    int i;
    Log t = array[r];
    if(mode<sortnum){
        while (l != r) {
            while (r > l) {
                if (array[l].price*(array[l].business+1) <= t.price*(t.business+1)) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (array[r].price*(array[r].business+1) >= t.price*(t.business+1)) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    else{
        while (l != r) {
            while (r > l) {
                if (array[l].price*(array[l].business+1) >= t.price*(t.business+1)) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (array[r].price*(array[r].business+1) <= t.price*(t.business+1)) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    array[l] = t;
    return l;
}
void insertSort2(Log* array, int n,int mode) {
    int  i, j;
    Log t;
    if(mode<sortnum){
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && t.price*(t.business+1) < array[j].price*(array[j].business+1)) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
    else{
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && t.price*(t.business+1) > array[j].price*(array[j].business+1)) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
}
void ModQuickSort3(Log* array, int left, int right,int mode,int opt) {
    if (right - left + 1 > THRESHOLD) {
        int j,pivot;
        if(opt==0) pivot = (left+right)/2;
        else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(left,right); // 指定范围
            pivot=distrib(gen);
        }
        swap(array[pivot], array[right]);
        pivot = partition3(array, left, right,mode);
        ModQuickSort3(array, left, pivot - 1,mode,opt);
        ModQuickSort3(array, pivot + 1, right,mode,opt);
    }
}
int partition3(Log* array, int left, int right,int mode) {
    int l = left, r = right;
    int i;
    Log t = array[r];
    if(mode<sortnum){
        while (l != r) {
            while (r > l) {
                if (timediffer("00:00",array[l].time0) <= timediffer("00:00",t.time0)) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (timediffer("00:00",array[r].time0) >= timediffer("00:00",t.time0)) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    else{
        while (l != r) {
            while (r > l) {
                if (timediffer("00:00",array[l].time0) >= timediffer("00:00",t.time0)) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (timediffer("00:00",array[r].time0) <= timediffer("00:00",t.time0)) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    array[l] = t;
    return l;
}
void insertSort3(Log* array, int n,int mode) {
    int  i, j;
    Log t;
    if(mode<sortnum){
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && timediffer("00:00",t.time0) < timediffer("00:00",array[j].time0)) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
    else{
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && timediffer("00:00",t.time0) > timediffer("00:00",array[j].time0)) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
}
void QuickSort(Log* array, int n,int mode,int opt) {
    if(mode%(sortnum-1)==1){
        ModQuickSort1(array, 0, n - 1,mode,opt);
        insertSort1(array, n,mode);
    }
    else if(mode%(sortnum-1)==2){
        ModQuickSort2(array, 0, n - 1,mode,opt);
        insertSort2(array, n,mode);
    }
    else if(mode%(sortnum-1)==3){
        ModQuickSort3(array, 0, n - 1,mode,opt);
        insertSort3(array, n,mode);
    }
    else if(mode%(sortnum-1)==4){
        ModQuickSort4(array, 0, n - 1,mode,opt);
        insertSort4(array, n,mode);
    }
    else if(mode%(sortnum-1)==5){
        ModQuickSort5(array, 0, n - 1,mode,opt);
        insertSort5(array, n,mode);
    }
    else if(mode%(sortnum-1)==6){
        ModQuickSort6(array, 0, n - 1,mode,opt);
        insertSort6(array, n,mode);
    }
    else if(mode%(sortnum-1)==0){
        ModQuickSort7(array, 0, n - 1,mode,opt);
        insertSort7(array, n,mode);
    }

}
void ModQuickSort4(Log* array, int left, int right,int mode,int opt) {
    if (right - left + 1 > THRESHOLD) {
        int j,pivot;
        if(opt==0) pivot = (left+right)/2;
        else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(left,right); // 指定范围
            pivot=distrib(gen);
        }
        swap(array[pivot], array[right]);
        pivot = partition4(array, left, right,mode);
        ModQuickSort4(array, left, pivot - 1,mode,opt);
        ModQuickSort4(array, pivot + 1, right,mode,opt);
    }
}
int partition4(Log* array, int left, int right,int mode) {
    int l = left, r = right;
    int i;
    Log t = array[r];
    if(mode<sortnum){
        while (l != r) {
            while (r > l) {
                if (timediffer("00:00",array[l].time1) <= timediffer("00:00",t.time1)) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (timediffer("00:00",array[r].time1) >= timediffer("00:00",t.time1)) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    else{
        while (l != r) {
            while (r > l) {
                if (timediffer("00:00",array[l].time1) >= timediffer("00:00",t.time1)) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (timediffer("00:00",array[r].time1) <= timediffer("00:00",t.time1)) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    array[l] = t;
    return l;
}
void insertSort4(Log* array, int n,int mode) {
    int  i, j;
    Log t;
    if(mode<sortnum){
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && timediffer("00:00",t.time1) < timediffer("00:00",array[j].time1)) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
    else{
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && timediffer("00:00",t.time1) > timediffer("00:00",array[j].time1)) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
}
void ModQuickSort5(Log* array, int left, int right,int mode,int opt) {
    if (right - left + 1 > THRESHOLD) {
        int j,pivot;
        if(opt==0) pivot = (left+right)/2;
        else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(left,right); // 指定范围
            pivot=distrib(gen);
        }
        swap(array[pivot], array[right]);
        pivot = partition5(array, left, right,mode);
        ModQuickSort5(array, left, pivot - 1,mode,opt);
        ModQuickSort5(array, pivot + 1, right,mode,opt);
    }
}
int partition5(Log* array, int left, int right,int mode) {
    int l = left, r = right;
    int i;
    Log t = array[r];
    if(mode<sortnum){
        while (l != r) {
            while (r > l) {
                if (array[l].chi.left(array[l].chi.size()-1).toDouble() <= t.chi.left(t.chi.size()-1).toDouble()) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (array[r].chi.left(array[r].chi.size()-1).toDouble() >= t.chi.left(t.chi.size()-1).toDouble()) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    else{
        while (l != r) {
            while (r > l) {
                if (array[l].chi.left(array[l].chi.size()-1).toDouble() >= t.chi.left(t.chi.size()-1).toDouble()) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (array[r].chi.left(array[r].chi.size()-1).toDouble() <= t.chi.left(t.chi.size()-1).toDouble()) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    array[l] = t;
    return l;
}
void insertSort5(Log* array, int n,int mode) {
    int  i, j;
    Log t;
    if(mode<sortnum){
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && t.chi.left(t.chi.size()-1).toDouble() < array[j].chi.left(array[j].chi.size()-1).toDouble()) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
    else{
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && t.chi.left(t.chi.size()-1).toDouble() > array[j].chi.left(array[j].chi.size()-1).toDouble()) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
}
void ModQuickSort6(Log* array, int left, int right,int mode,int opt) {
    if (right - left + 1 > THRESHOLD) {
        int j,pivot;
        if(opt==0) pivot = (left+right)/2;
        else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(left,right); // 指定范围
            pivot=distrib(gen);
        }
        swap(array[pivot], array[right]);
        pivot = partition6(array, left, right,mode);
        ModQuickSort6(array, left, pivot - 1,mode,opt);
        ModQuickSort6(array, pivot + 1, right,mode,opt);
    }
}
int partition6(Log* array, int left, int right,int mode) {
    int l = left, r = right;
    int i;
    Log t = array[r];
    if(mode<sortnum){
        while (l != r) {
            while (r > l) {
                if (array[l].PID <= t.PID) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (array[r].PID >= t.PID) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    else{
        while (l != r) {
            while (r > l) {
                if (array[l].PID >= t.PID) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (array[r].PID <= t.PID) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    array[l] = t;
    return l;
}
void insertSort6(Log* array, int n,int mode) {
    int  i, j;
    Log t;
    if(mode<sortnum){
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && t.PID < array[j].PID) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
    else{
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && t.PID > array[j].PID) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
}
void ModQuickSort7(Log* array, int left, int right,int mode,int opt) {
    if (right - left + 1 > THRESHOLD) {
        int j,pivot;
        if(opt==0) pivot = (left+right)/2;
        else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(left,right); // 指定范围
            pivot=distrib(gen);
        }
        swap(array[pivot], array[right]);
        pivot = partition7(array, left, right,mode);
        ModQuickSort7(array, left, pivot - 1,mode,opt);
        ModQuickSort7(array, pivot + 1, right,mode,opt);
    }
}
int partition7(Log* array, int left, int right,int mode) {
    int l = left, r = right;
    int i;
    Log t = array[r];
    if(mode<sortnum){
        while (l != r) {
            while (r > l) {
                if (QDate::fromString(array[l].curdate).daysTo(QDate::fromString(t.curdate))>=0) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (QDate::fromString(array[r].curdate).daysTo(QDate::fromString(t.curdate))<=0) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    else{
        while (l != r) {
            while (r > l) {
                if (QDate::fromString(array[l].curdate).daysTo(QDate::fromString(t.curdate))<=0) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (QDate::fromString(array[r].curdate).daysTo(QDate::fromString(t.curdate))>=0) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    array[l] = t;
    return l;
}
void insertSort7(Log* array, int n,int mode) {
    int  i, j;
    Log t;
    if(mode<sortnum){
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && QDate::fromString(array[j].curdate).daysTo(QDate::fromString(t.curdate))<0) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
    else{
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && QDate::fromString(array[j].curdate).daysTo(QDate::fromString(t.curdate))>0) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
}
void QuickSort_Turn(Log logs,Log* array,int n,int opt){
    ModQuickSort_Turn(logs,array, 0, n - 1,opt);
    insertSort_Turn(logs,array, n);
}
int partition_Turn(Log logs,Log* array, int left, int right) {
    int l = left, r = right;
    int i,timeminorl,timeminort,timeminorr;
    Log t = array[r];
    while (l != r) {
        while (r > l) {
            timeminorl=timediffer(logs.time1,array[l].time0);
            if(timeminorl<0) timeminorl=60000;
            timeminort=timediffer(logs.time1,t.time0);
            if(timeminort<0) timeminort=60000;
            if (timediffer(array[l].time0,array[l].time1)+timeminorl <= timediffer(t.time0,t.time1)+timeminort) l++;
            else break;
        }
        if (l < r) {
            array[r] = array[l];
            r--;
        }
        while (r > l) {
            timeminort=timediffer(logs.time1,t.time0);
            if(timeminort<0) timeminort=60000;
            timeminorr=timediffer(logs.time1,array[r].time0);
            if(timeminorr<0) timeminorr=60000;
            if (timediffer(array[r].time0,array[r].time1)+timeminorr >= timediffer(t.time0,t.time1)+timeminort) r--;
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
void ModQuickSort_Turn(Log logs, Log* array, int left, int right,int opt){
    if (right - left + 1 > THRESHOLD) {
        int j,pivot;
        if(opt==0) pivot = (left+right)/2;
        else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(left,right); // 指定范围
            pivot=distrib(gen);
        }
        swap(array[pivot], array[right]);
        pivot = partition_Turn(logs, array, left, right);
        ModQuickSort_Turn(logs, array, left, pivot - 1,opt);
        ModQuickSort_Turn(logs, array, pivot + 1, right,opt);
    }
}
void insertSort_Turn(Log logs,Log* array, int n){
    int  i, j,timeminort,timeminorj;
    Log t;
    for (i = 1; i < n; i++) {
        t = array[i];
        int j = i - 1;
        while (j >= 0) {
            timeminort=timediffer(logs.time1,array[j].time0);
            timeminorj=timediffer(logs.time0,t.time0);
            if(timeminorj<0) timeminorj=60000;
            if(timeminort<0) timeminort=60000;
            if(timediffer(t.time0,t.time1)+timeminorj < timediffer(array[j].time0,array[j].time1)+timeminort){
                array[j + 1] = array[j];
                j = j - 1;
            }
            else break;
        }
        array[j + 1] = t;
    }
}
template <typename T>
void QuickSortcommon(T* array, int n,int mode,int opt) {
    ModQuickSortcommon(array, 0, n - 1,mode,opt);
    insertSortcommon(array, n,mode);
}
template <typename T>
void ModQuickSortcommon(T* array, int left, int right,int mode,int opt) {
    if (right - left + 1 > THRESHOLD) {
        int j,pivot;
        if(opt==0) pivot = (left+right)/2;
        else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(left,right); // 指定范围
            pivot=distrib(gen);
        }
        swap(array[pivot], array[right]);
        pivot = partitioncommon(array, left, right,mode);
        ModQuickSortcommon(array, left, pivot - 1,mode,opt);
        ModQuickSortcommon(array, pivot + 1, right,mode,opt);
    }
}
template <typename T>
int partitioncommon(T* array, int left, int right,int mode) {
    int l = left, r = right;
    int i;
    T t = array[r];
    if(mode<sortnum){
        while (l != r) {
            while (r > l) {
                if (array[l] <= t) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (array[r] >= t) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    else{
        while (l != r) {
            while (r > l) {
                if (array[l] >= t) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (array[r] <= t) r--;
                else break;
            }
            if (l < r) {
                array[l] = array[r];
                l++;
            }
        }
    }
    array[l] = t;
    return l;
}
template <typename T>
void insertSortcommon(T* array, int n,int mode) {
    int  i, j;
    T t;
    if(mode<sortnum){
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && t < array[j]) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
    else{
        for (i = 1; i < n; i++) {
            t = array[i];
            int j = i - 1;
            while (j >= 0 && t > array[j]) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
}
int timediffer(QString time0,QString time1){
    int time0h,time0m,time1h,time1m,i=0,j=0,times_h,times_m;
    int dayplus=0;
    QString time1_withplus;
    QStringList time0l=time0.split(':');
    QStringList time1l=time1.split(':');
    foreach (QString item, time0l) {
        switch(i){
        case(0):time0h=item.toInt();break;
        case(1):time0m=item.toInt();break;
        }
        i++;
    }
    i=0;
    foreach (QString item, time1l) {
        switch(i){
        case(0):time1h=item.toInt();break;
        case(1):time1_withplus=item;break;
        }
        i++;
    }
    i=0;
    QStringList time1ml=time1_withplus.split('+');
    foreach (QString item, time1ml) {
        switch(i){
        case(0):time1m=item.toInt();break;
        case(1): if(item=="1")dayplus=1;else dayplus=2;break;
        }
        i++;
    }
    times_m=time1m-time0m;
    if(dayplus==1) times_h=time1h-time0h+24;
    else if(dayplus==2) times_h=time1h-time0h+48;
    else times_h=time1h-time0h;
    if(times_m<0) {
        times_m+=60;
        times_h-=1;
    }
    return times_h*60+times_m;
}
int modSearch(Log logs0[],QString time1,int a,int b){
    int k=(a+b)/2;
    int k1=0,k2=0;
    if(b==a) return 0;
    if(k==0) return 0;
    if(timediffer(time1,logs0[k].time0)>0 && timediffer(time1,logs0[k-1].time0)<0) return k;
    if(timediffer(time1,logs0[k].time0)>0 && timediffer(time1,logs0[k-1].time0)>0){
        k1=modSearch(logs0,time1,a,k);
    }
    else if(timediffer(time1,logs0[k].time0)<0 && timediffer(time1,logs0[k-1].time0)<0){
        k2=modSearch(logs0,time1,k+1,b);
    }
    return k1+k2;
}
QString pathCreator(QString a){
    return QDir::cleanPath(QCoreApplication::applicationDirPath() + QDir::separator() + a);
}
void invert(Log* array,int n){
    int i;
    for(i=0;i<n-i-1;i++){
        swap(array[i],array[n-i-1]);
    }
}
QPixmap changeImage(QPixmap img_in,int radius){
    //图片圆角化
    QSize size = QSize(img_in.size());
    QBitmap mask = QBitmap(size);
    QPainter painter = QPainter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(mask.rect(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(mask.rect(), radius, radius);
    painter.end();
    img_in.setMask(mask);
    return img_in;
}
int calDistance(QPoint city0,QPoint city1){
    float ratio=2.815478;
    float dis=sqrt((double)pow((city0.rx()-city1.rx()),2)+pow((city0.ry()-city1.ry()),2))*ratio;
    return (int)dis;
}
void setLog(string s,int mode,QDate curdate,int &ticketnum,int &ticket_checkednum,Log *logs){
    QString year,month,day;
    QString company,ID,sou,des,time0,time1,chi;
    int price=0,price0=0,price_max=0;
    // year= QString::number(curDate.year());
    // month= QString::number(curDate.month());
    // day= QString::number(curDate.day());
    year="2024";
    month="9";
    day="20";
    QString fname,info0;
    QString qs=QString::fromStdString(s);
    QStringList qsl=qs.split(' ');
    QRegularExpression numbers( "0|[1-9]\\d{0,1}" );
    QRegularExpressionMatch matchnum;
    QString coc="",ari="",beg="",las="";
    QStringList mid[5];
    Log *p,*q;
    int i=0,j=0,k=0;
    QString citys[17]={"北京","上海","昆明","广州","台北","西安","乌鲁木齐","哈尔滨","拉萨","西宁","新加坡","马尼拉","曼谷","东京","首尔","新德里"};
    foreach (QString item, qsl) {
        matchnum = numbers.match(item);
        if(item=="不可达") return;
        if(matchnum.hasMatch()){
            if(item.toInt()<20){
                if(coc=="") coc=citys[item.toInt()];
                else {
                    mid->append(citys[item.toInt()]);
                    i++;
                }
                ari=citys[item.toInt()];
            }
            else if(price_max<item.toInt()) price_max=item.toInt();
        }
    }
    mid->removeLast();
    beg=coc;
    i=0;
    j=ticket_checkednum;
    if(mid->empty()){
        fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+ coc + "-" + ari + ".txt";
        QFile fs(fname);
        if(fs.open(QIODeviceBase::ReadOnly)){
            QTextStream in(&fs);
            in.setEncoding(QStringConverter::System);
            while (in.atEnd()==false){
                info0=in.readLine();
                QStringList infos=info0.split('/');
                i=0;
                foreach (QString item, infos) {
                    switch(i){
                    case(0):company=item;break;
                    case(1):ID=item;break;
                    case(2):sou=item;break;
                    case(3):des=item;break;
                    case(4):time0=item;break;
                    case(5):time1=item;break;
                    case(6):price=item.toInt();break;
                    case(7):chi=item;break;
                    }
                    i++;
                }
                logs[j].setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                logs[j].setRoute(QString::fromStdString(s));
                logs[j].next=NULL;
                j++;
            }
            //QuickSort2(logs,j);
            // for(i=ticket_checkednum;i<j;i++){
            //     qDebug() <<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
            // }
        }
        ticketnum=j;
        ticket_checkednum=ticketnum;
        fs.close();
        QuickSort(logs,ticketnum,2,1);
    }
    else{
        las=mid->first();
        while(1){
            if(beg==coc){
                fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+ coc + "-" + las + ".txt";
                QFile fs(fname);
                if(fs.open(QIODeviceBase::ReadOnly)){
                    QTextStream in(&fs);
                    in.setEncoding(QStringConverter::System);
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        QStringList infos=info0.split('/');
                        i=0;
                        foreach (QString item, infos) {
                            switch(i){
                            case(0):company=item;break;
                            case(1):ID=item;break;
                            case(2):sou=item;break;
                            case(3):des=item;break;
                            case(4):time0=item;break;
                            case(5):time1=item;break;
                            case(6):price=item.toInt();break;
                            case(7):chi=item;break;
                            }
                            i++;
                        }
                        Log* log0=new Log();
                        log0->setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                        logs[j].next=log0;
                        logs[j].setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                        logs[j].setRoute(QString::fromStdString(s));
                        j++;
                    }
                    //QuickSort4(logs,j);
                    // for(i=ticket_checkednum;i<j;i++){
                    //     qDebug() << "首" <<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
                    // }
                }
                ticketnum=j;
                fs.close();
                beg=mid->first();
                mid->removeFirst();
                if(mid->empty()) las=ari;
                else las=mid->first();
            }
            else{
                j=0;
                Log logs0[1000];
                fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+ beg + "-" + las + ".txt";
                QFile fs(fname);
                if(fs.open(QIODeviceBase::ReadOnly)){
                    QTextStream in(&fs);
                    in.setEncoding(QStringConverter::System);
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        QStringList infos=info0.split('/');
                        i=0;
                        foreach (QString item, infos) {
                            switch(i){
                            case(0):company=item;break;
                            case(1):ID=item;break;
                            case(2):sou=item;break;
                            case(3):des=item;break;
                            case(4):time0=item;break;
                            case(5):time1=item;break;
                            case(6):price=item.toInt();break;
                            case(7):chi=item;break;
                            }
                            i++;
                        }
                        logs0[j].setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                        j++;
                    }
                    if(mode==1 || mode==5) QuickSort(logs0,j,2,1);
                    // for(i=0;i<j;i++){
                    //     qDebug() <<"中"<<logs0[i].company<<logs0[i].ID<<logs0[i].sou<<logs0[i].des<<logs0[i].time0<<logs0[i].time1<<logs0[i].price<<logs0[i].chi<< "\n";
                    // }
                    int log_number=0,l=ticketnum-1;
                    bool repeat=false;
                    if(mode==2 || mode==6) QuickSort_Turn(logs[i],logs0,j,0);
                    for(i=ticket_checkednum;i<ticketnum;i++){
                        if(logs[i].time1.right(2)=="+1"){
                            logs[i].des="不可达";
                            continue;
                        }
                        if(logs[i].des=="不可达") continue;
                        repeat=false;
                        log_number=0;
                        if(mode==1 || mode==5) k=modSearch(logs0,logs[i].time1,0,j+1);
                        else k=0;
                        if(k==0 && timediffer(logs[i].time1,logs0[j-1].time0)<0 && (mode==1 || mode==5)) {
                            logs[i].des="不可达";
                            continue;
                        }
                        QString time_preserve=logs[i].time1;
                        for(; k<=j;k++){
                            if(timediffer(time_preserve,logs0[k].time0)>60 && timediffer(time_preserve,logs0[k].time0)<600){
                                if(!repeat) {
                                    p=&logs[i];
                                    while(p->next!=NULL){
                                        p=p->next;
                                    }
                                    Log* log2=new Log();
                                    p->next=log2;
                                    QString chi0=logs[i].chi.left(logs[i].chi.size()-1),chi1=logs0[k].chi.left(logs0[k].chi.size()-1);
                                    if(chi1.toDouble()<chi0.toDouble()) logs[i].chi=logs0[k].chi;
                                    log2->setLog(logs0[k].company,logs0[k].ID,logs0[k].sou,logs0[k].des,logs0[k].time0,logs0[k].time1,logs0[k].price,logs0[k].chi,curdate.toString());
                                    logs[i].des=logs0[k].des;
                                    logs[i].price=logs[i].price+logs0[k].price;
                                    logs[i].time1=logs0[k].time1;
                                    repeat=true;
                                }
                                else{
                                    int price1=0;
                                    QString chi_min=logs[i].chi;
                                    l++;
                                    p=&logs[i];
                                    q=&logs[l];
                                    while(p->next->next!=NULL){
                                        p=p->next;
                                        price1=price1+p->price;
                                        QString chi0=chi_min.left(chi_min.size()-1),chi1=p->chi.left(p->chi.size()-1);
                                        if(chi1.toDouble()<chi0.toDouble()) chi_min=p->chi;
                                        Log* log1=new Log();
                                        log1->setLog(p->company,p->ID,p->sou,p->des,p->time0,p->time1,p->price,p->chi,curdate.toString());
                                        q->next=log1;
                                        q=q->next;
                                    }
                                    logs[l].setLog(logs[i].company,logs[i].ID,logs[i].sou,logs0[k].des,logs[i].time0,logs0[k].time1,logs0[k].price+price1,chi_min,curdate.toString());
                                    logs[l].setRoute(QString::fromStdString(s));
                                    Log* log2=new Log();
                                    log2->setLog(logs0[k].company,logs0[k].ID,logs0[k].sou,logs0[k].des,logs0[k].time0,logs0[k].time1,logs0[k].price,logs0[k].chi,curdate.toString());
                                    q->next=log2;
                                }
                                log_number++;
                                if(log_number>=3 && mode<4) break;//&&mode<4
                            }
                        }
                        if(log_number==0) logs[i].des="不可达";
                    }

                    ticketnum=l+1;
                    for(i=ticket_checkednum;i<=ticketnum;i++){
                        if(logs[i].des=="不可达"){
                            for(j=i;j<=ticketnum;j++){
                                logs[j]=logs[j+1];
                            }
                            if(ticketnum==1){
                                logs[0].setLog("没有航空公司","123456","不可达","不可达","00:00","25:00",0,"0%","");
                            }
                            logs[ticketnum].clear();
                            i--;
                            ticketnum--;
                        }
                    }
                    // for(i=0;i<ticketnum;i++){
                    //     qDebug() <<"过"<<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
                    // }
                }
                fs.close();
                //如果已经找到终点，退出循环
                if(las==ari) break;
                beg=mid->first();
                mid->removeFirst();
                if(mid->empty()) las=ari;
                else las=mid->first();
            }
        }
        for(i=ticket_checkednum;i<=ticketnum;i++){
            if(logs[i].des=="不可达"){
                for(j=i;j<=ticketnum;j++){
                    logs[j]=logs[j+1];
                }
                if(ticketnum==1){
                    logs[0].setLog("没有航空公司","123456","不可达","不可达","00:00","25:00",0,"0%","");
                }
                i--;
                ticketnum--;
            }
            // else{
            //     qDebug() <<"结"<<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
            // }
        }
        if(ticketnum<0) ticketnum=0;
        if(mode==1 || mode==5) QuickSort(logs,ticketnum,2,1);
        else if(mode==2 || mode==6) QuickSort(logs,ticketnum,1,1);
        ticket_checkednum=ticketnum;
    }
}
void CMapSet(QDate curDate,QString* citys,CMap* pMap,int mode){
    int nodeNum=16, arcNum=241;
    int i,j;
    bool label;
    QString year,month,day;
    QString times0,times1;
    int price=0,price0=0,time,time0;
    // year= QString::number(curDate.year());
    // month= QString::number(curDate.month());
    // day= QString::number(curDate.day());
    year="2024";
    month="9";
    day="20";
    QString fname,info0;
    QRegularExpression rxlen( "^(.*)/(.*)/(.*)/(.*)/(.*)/(.*)/(.*)/(.*)$" );
    QRegularExpressionMatch match;
    for (i = 0; i < nodeNum;i++) {
        Node* pNode0 = new Node(i);
        pMap->addNode(pNode0);
    }
    for (i = 0; i < nodeNum;i++) {
        for(j = i+1; j < nodeNum;j++) {
            price=0;
            time=0;
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[i] + "-" + citys[j] + ".txt";
            QFile fs(fname);
            if(fs.open(QIODeviceBase::ReadOnly)){
                QTextStream in(&fs);
                in.setEncoding(QStringConverter::System);
                if(mode==1){
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        match = rxlen.match(info0);
                        price0=match.captured(7).toInt();
                        if(price==0) price=price0;
                        else if(price0<price) price=price0;
                    }
                    label=pMap->setValueToMatrixForDirectedGraph(i, j, price);
                }
                else if(mode==2){
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        match = rxlen.match(info0);
                        times0 = match.captured(5);
                        times1 = match.captured(6);
                        time0 = timediffer(times0,times1);
                        if(time==0) time=time0;
                        else if(time0<time) time=time0;
                    }
                    label=pMap->setValueToMatrixForDirectedGraph(i, j, time);
                }
                else if(mode==5){
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        match = rxlen.match(info0);
                        price=match.captured(7).toInt();
                        label=pMap->setValueToMatrixForDirectedGraph(i, j, price);
                    }
                }
                else if(mode==6){
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        match = rxlen.match(info0);
                        times0 = match.captured(5);
                        times1 = match.captured(6);
                        time = timediffer(times0,times1);
                        label=pMap->setValueToMatrixForDirectedGraph(i, j, time);
                    }
                }
            }
            fs.close();
            price=0;
            time=0;
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[j] + "-" + citys[i] + ".txt";
            QFile fs1(fname);
            if(fs1.open(QIODeviceBase::ReadOnly)){
                QTextStream in1(&fs1);
                in1.setEncoding(QStringConverter::System);
                if(mode==1){
                    while (in1.atEnd()==false){
                        info0=in1.readLine();
                        match = rxlen.match(info0);
                        price0=match.captured(7).toInt();
                        if(price==0) price=price0;
                        else if(price0<price) price=price0;
                    }
                    label=pMap->setValueToMatrixForDirectedGraph(j, i, price);
                }
                else if(mode==2){
                    while (in1.atEnd()==false){
                        info0=in1.readLine();
                        match = rxlen.match(info0);
                        times0 = match.captured(5);
                        times1 = match.captured(6);
                        time0 = timediffer(times0,times1);
                        if(time==0) time=time0;
                        else if(time0<time) time=time0;
                    }
                    label=pMap->setValueToMatrixForDirectedGraph(j, i, time);
                }
                else if(mode==5){
                    while (in1.atEnd()==false){
                        info0=in1.readLine();
                        match = rxlen.match(info0);
                        price=match.captured(7).toInt();
                        label=pMap->setValueToMatrixForDirectedGraph(j, i, price);
                    }
                }
                else if(mode==6){
                    while (in1.atEnd()==false){
                        info0=in1.readLine();
                        match = rxlen.match(info0);
                        times0 = match.captured(5);
                        times1 = match.captured(6);
                        time = timediffer(times0,times1);
                        label=pMap->setValueToMatrixForDirectedGraph(j, i, time);
                    }
                }
            }
            fs.close();
        }
    }
}
template void QuickSortcommon<int>(int*, int, int, int);
