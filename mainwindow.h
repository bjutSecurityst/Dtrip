#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include "map.h"
#include "CMap.h"
#include "Edge.h"
#include "Node.h"
#include "ticketinfo.h"
#include "Log.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_verticalScrollBar_sliderMoved(int position);

    void on_pushButton_0_clicked();

    void on_pushButton_4_clicked();

    void on_verticalScrollBar_2_sliderMoved(int position);

    void on_verticalScrollBar_2_valueChanged(int value);

    void setLog(string s,int mode);

    void on_button_swap_clicked();

    void on_pushButton_5_clicked();

    void on_lineEditdep_textChanged(const QString &arg1);

    void on_lineEditari_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    int myTimerId;
    int picId;
    int ticketnum=0,ticket_checkednum=0,ticket_now=0;
    QTimer *timer;
    Dist *dist;
    bool btvisible=true;
    QPushButton* button_swap;
    QString citys[17]={"北京","上海","昆明","广州","台北","西安","乌鲁木齐","哈尔滨","拉萨","西宁","新加坡","马尼拉","曼谷","东京","首尔","新德里"};
    Log logs[4000];
    void Timerout();
    void getMapMessage(QString a,QString b,QDate curdate);
};
#endif // MAINWINDOW_H
