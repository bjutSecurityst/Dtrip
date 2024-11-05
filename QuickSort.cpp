#include "Log.h"
#include <QString>
#include <cstdio>
#include <QObject>
#include <QCoreApplication>
#include <QDir>
#include "Log.h"
using namespace std;
#define THRESHOLD 8
#define sortnum 8
void QuickSort(Log* array, int n,int mode);
void ModQuickSort1(Log* array, int left, int right,int mode);
int partition1(Log* array, int left, int right,int mode);
void insertSort1(Log* array, int n,int mode);
void ModQuickSort2(Log* array, int left, int right,int mode);
int partition2(Log* array, int left, int right,int mode);
void insertSort2(Log* array, int n,int mode);
void ModQuickSort3(Log* array, int left, int right,int mode);
int partition3(Log* array, int left, int right,int mode);
void insertSort3(Log* array, int n,int mode);
void ModQuickSort4(Log* array, int left, int right,int mode);
int partition4(Log* array, int left, int right,int mode);
void insertSort4(Log* array, int n,int mode);
void ModQuickSort5(Log* array, int left, int right,int mode);
int partition5(Log* array, int left, int right,int mode);
void insertSort5(Log* array, int n,int mode);
void ModQuickSort6(Log* array, int left, int right,int mode);
int partition6(Log* array, int left, int right,int mode);
void insertSort6(Log* array, int n,int mode);
void ModQuickSort7(Log* array, int left, int right,int mode);
int partition7(Log* array, int left, int right,int mode);
void insertSort7(Log* array, int n,int mode);
int timediffer(QString time0,QString time1);
void QuickSort_Turn(Log logs,Log* array,int n);
void ModQuickSort_Turn(Log logs,Log* array, int left, int right);
int partition_Turn(Log logs,Log* array, int left, int right);
void insertSort_Turn(Log logs,Log* array, int n);
int modSearch(Log logs0[],QString time1,int a,int b);
QString pathCreator(QString a);
void ModQuickSort1(Log* array, int left, int right,int mode) {
    if (right - left + 1 > THRESHOLD) {
        int j;
        int pivot = (left+right)/2;
        swap(array[pivot], array[right]);
        pivot = partition1(array, left, right,mode);
        ModQuickSort1(array, left, pivot - 1,mode);
        ModQuickSort1(array, pivot + 1, right,mode);
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
void ModQuickSort2(Log* array, int left, int right,int mode) {
    if (right - left + 1 > THRESHOLD) {
        int j;
        int pivot = (left+right)/2;
        swap(array[pivot], array[right]);
        pivot = partition2(array, left, right,mode);
        ModQuickSort2(array, left, pivot - 1,mode);
        ModQuickSort2(array, pivot + 1, right,mode);
    }
}
int partition2(Log* array, int left, int right,int mode) {
    int l = left, r = right;
    int i;
    Log t = array[r];
    if(mode<sortnum){
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
    }
    else{
        while (l != r) {
            while (r > l) {
                if (array[l].price >= t.price) l++;
                else break;
            }
            if (l < r) {
                array[r] = array[l];
                r--;
            }
            while (r > l) {
                if (array[r].price <= t.price) r--;
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
            while (j >= 0 && t.price < array[j].price) {
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
            while (j >= 0 && t.price > array[j].price) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = t;
        }
    }
}
void ModQuickSort3(Log* array, int left, int right,int mode) {
    if (right - left + 1 > THRESHOLD) {
        int j;
        int pivot = (left+right)/2;
        swap(array[pivot], array[right]);
        pivot = partition3(array, left, right,mode);
        ModQuickSort3(array, left, pivot - 1,mode);
        ModQuickSort3(array, pivot + 1, right,mode);
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
void QuickSort(Log* array, int n,int mode) {
    if(mode%(sortnum-1)==1){
        ModQuickSort1(array, 0, n - 1,mode);
        insertSort1(array, n,mode);
    }
    else if(mode%(sortnum-1)==2){
        ModQuickSort2(array, 0, n - 1,mode);
        insertSort2(array, n,mode);
    }
    else if(mode%(sortnum-1)==3){
        ModQuickSort3(array, 0, n - 1,mode);
        insertSort3(array, n,mode);
    }
    else if(mode%(sortnum-1)==4){
        ModQuickSort4(array, 0, n - 1,mode);
        insertSort4(array, n,mode);
    }
    else if(mode%(sortnum-1)==5){
        ModQuickSort5(array, 0, n - 1,mode);
        insertSort5(array, n,mode);
    }
    else if(mode%(sortnum-1)==6){
        ModQuickSort6(array, 0, n - 1,mode);
        insertSort6(array, n,mode);
    }
    else if(mode%(sortnum-1)==0){
        ModQuickSort7(array, 0, n - 1,mode);
        insertSort7(array, n,mode);
    }

}
void ModQuickSort4(Log* array, int left, int right,int mode) {
    if (right - left + 1 > THRESHOLD) {
        int j;
        int pivot = (left+right)/2;
        swap(array[pivot], array[right]);
        pivot = partition4(array, left, right,mode);
        ModQuickSort4(array, left, pivot - 1,mode);
        ModQuickSort4(array, pivot + 1, right,mode);
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
void ModQuickSort5(Log* array, int left, int right,int mode) {
    if (right - left + 1 > THRESHOLD) {
        int j;
        int pivot = (left+right)/2;
        swap(array[pivot], array[right]);
        pivot = partition5(array, left, right,mode);
        ModQuickSort5(array, left, pivot - 1,mode);
        ModQuickSort5(array, pivot + 1, right,mode);
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
void ModQuickSort6(Log* array, int left, int right,int mode) {
    if (right - left + 1 > THRESHOLD) {
        int j;
        int pivot = (left+right)/2;
        swap(array[pivot], array[right]);
        pivot = partition6(array, left, right,mode);
        ModQuickSort6(array, left, pivot - 1,mode);
        ModQuickSort6(array, pivot + 1, right,mode);
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
void ModQuickSort7(Log* array, int left, int right,int mode) {
    if (right - left + 1 > THRESHOLD) {
        int j;
        int pivot = (left+right)/2;
        swap(array[pivot], array[right]);
        pivot = partition7(array, left, right,mode);
        ModQuickSort7(array, left, pivot - 1,mode);
        ModQuickSort7(array, pivot + 1, right,mode);
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
void QuickSort_Turn(Log logs,Log* array,int n){
    ModQuickSort_Turn(logs,array, 0, n - 1);
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
void ModQuickSort_Turn(Log logs, Log* array, int left, int right){
    if (right - left + 1 > THRESHOLD) {
        int j;
        int pivot = (left+right)/2;
        swap(array[pivot], array[right]);
        pivot = partition_Turn(logs, array, left, right);
        ModQuickSort_Turn(logs, array, left, pivot - 1);
        ModQuickSort_Turn(logs, array, pivot + 1, right);
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
int timediffer(QString time0,QString time1){
    int time0h,time0m,time1h,time1m,i=0,j=0,times_h,times_m;
    bool dayplus=false;
    QString time1_withplus;
    int time_D;
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
        case(1):dayplus=true;break;
        }
        i++;
    }
    times_m=time1m-time0m;
    if(dayplus==true) times_h=time1h-time0h+24;
    else times_h=time1h-time0h;
    if(times_m<0) {
        times_m+=60;
        times_h-=1;
    }
    return time_D=times_h*60+times_m;
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
