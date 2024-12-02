#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include "QPushButton"
#include <QGraphicsScene>
#include <QDate>
#include <QLabel>
#include "Log.h"
namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT

public:
    explicit Map(QDate curDate,QWidget *parent = nullptr);
    explicit Map(Log* userLogs,int myticketnum,QWidget *parent = nullptr);
    ~Map();
    QPoint* getcityp();
    QPoint* bj;

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_checkBox_stateChanged(int arg1);

signals:
    void sendToMainWindow(QString a,QString b,QDate curdate);
private:
    Ui::Map *ui;
    QPushButton* buttons[17];
    QString citys[17]={"北京","上海","昆明","广州","台北","西安","乌鲁木齐","哈尔滨","拉萨","西宁","新加坡","马尼拉","曼谷","东京","首尔","新德里"};
    QPoint cityp[17]={QPoint(1115,338),QPoint(1252,649),QPoint(735,828),QPoint(1025,885),QPoint(1245,834),QPoint(900,540),QPoint(310,192),QPoint(1392,139),QPoint(419,674),QPoint(699,459),QPoint(774,1472),QPoint(1230,1117),QPoint(677,1132),QPoint(1739,495),QPoint(1400,440),QPoint(42,721)};
    QGraphicsScene *scene;
    QGraphicsLineItem *itemline;
    //QLabel *kilos=new QLabel();
    Log* userLogs;
    QGraphicsSimpleTextItem *kilos;
    int mode,modeAD=0,modemul=0,myticketnum=0,sortmode=0;
    //覆写滚轮事件
    void wheelEvent(QWheelEvent *event);
    //拖动事件
    void on_MyGraphicsView_rubberBandChanged();
    //按键按下事件
    void on_buttons_clicked();
    //航线绘制函数
    void addcursorline(int x1,int x2,int y1,int y2,int line,int color,QGraphicsScene *scene);
};

#endif // MAP_H
