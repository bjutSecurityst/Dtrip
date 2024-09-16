#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include "QPushButton"
#include <QGraphicsScene>
#include <QDate>

namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT

public:
    explicit Map(QDate curDate,QWidget *parent = nullptr);
    ~Map();
    QPoint* bj;

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

signals:
    void sendToMainWindow(QString a,QString b,QDate curdate);
private:
    Ui::Map *ui;
    QPushButton* buttons[40];
    QString citys[40]={"北京","上海","昆明","广州","台北","西安","乌鲁木齐","哈尔滨","拉萨","西宁","新加坡","马尼拉","曼谷","东京","首尔","新德里"};
    QPoint cityp[40]={QPoint(1115,338),QPoint(1252,649),QPoint(735,828),QPoint(1025,885),QPoint(1245,834),QPoint(900,540),QPoint(310,192),QPoint(1392,139),QPoint(419,674),QPoint(699,459),QPoint(774,1472),QPoint(1230,1117),QPoint(677,1132),QPoint(1739,495),QPoint(1400,440),QPoint(42,721)};
    QGraphicsScene *scene;
    void wheelEvent(QWheelEvent *event);
    void on_MyGraphicsView_rubberBandChanged();
    void on_buttons_clicked();
};

#endif // MAP_H
