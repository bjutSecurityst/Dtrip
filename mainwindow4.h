#ifndef MAINWINDOW4_H
#define MAINWINDOW4_H

#include <QMainWindow>
#include "Log.h"
struct Sweight {
    int vertex;
    int weight;
};
namespace Ui {
class MainWindow4;
}

class MainWindow4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow4(QWidget *parent = nullptr);
    ~MainWindow4();

private slots:
    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::MainWindow4 *ui;
    QString citys[17]={"北京","上海","昆明","广州","台北","西安","乌鲁木齐","哈尔滨","拉萨","西宁","新加坡","马尼拉","曼谷","东京","首尔","新德里"};
    QPoint cityp[17]={QPoint(1115,338),QPoint(1252,649),QPoint(735,828),QPoint(1025,885),QPoint(1245,834),QPoint(900,540),QPoint(310,192),QPoint(1392,139),QPoint(419,674),QPoint(699,459),QPoint(774,1472),QPoint(1230,1117),QPoint(677,1132),QPoint(1739,495),QPoint(1400,440),QPoint(42,721)};
    bool createUsers(int num,float *souweight,float *desweight,int searchmode);
    void findticket(QDate curdate,int begin,int end,Log* logs,int mode,int modeuser,int &ticketnum,int &ticket_checkednum);
    template <typename T>
    void weightedRandom(T *array,int n,int &randnum);
    void myRandom(int n,int &randnum);
    void setTicketsToDB(Log* mylogs,int myticketnum,int num);
    void updateMyProgressbar(int usernum);
    void companyFilter(Log *mylogs,int myticketnum,Log *copylogs,int &copynum);
};

#endif // MAINWINDOW4_H
