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
#include "mysqlite.h"
#include <QVBoxLayout>
#include "login.h"
#include "MyGraphicsView.h"
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

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_3_clicked();

    void on_verticalScrollBar_3_valueChanged(int value);

    void on_pushButton_9_clicked(bool checked);

    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    // 计时器
    int myTimerId;
    // 图片计数器
    int picId;
    // 票数计数器
    int ticketnum=0,ticket_checkednum=0,ticket_now=0,myticketnum=0;
    // 家所在城市，常去城市
    int home=-1,common=-1;
    // 对应概率
    double probability=0,pco=0;
    float time_money=0,time_time=0,time_straight=0;
    QTimer *timer;
    // 当前日期
    QDate curdate;
    // dijiestela结果
    Dist *dist;
    // 工具栏visible，是否登录
    bool btvisible=true,login=false;
    // 交换按钮
    QPushButton* button_swap;
    QString citys[17]={"北京","上海","昆明","广州","台北","西安","乌鲁木齐","哈尔滨","拉萨","西宁","新加坡","马尼拉","曼谷","东京","首尔","新德里"};
    QPoint cityp[17]={QPoint(1115,338),QPoint(1252,649),QPoint(735,828),QPoint(1025,885),QPoint(1245,834),QPoint(900,540),QPoint(310,192),QPoint(1392,139),QPoint(419,674),QPoint(699,459),QPoint(774,1472),QPoint(1230,1117),QPoint(677,1132),QPoint(1739,495),QPoint(1400,440),QPoint(42,721)};
    Log logs[4000];
    QString username="",userpassword;
    // 用户票据，改签票据
    Log* userLogs=NULL,*clog;
    // 主页模式2 widget
    QWidget* widget0;
    QVBoxLayout* verticalLayout_7;
    // 是否已经弹出登录页
    Login* loginW=NULL;
    // 主页模式3 用户地图
    Map *m=NULL;
    // 改签模式，上次排序模式
    int changemode=0,sortmode=0;
    void Timerout();
    void getMapMessage(QString a,QString b,QDate curdate);
    void getLoginMessage(QString username,Log* mylog,int myticketnum,int home,double probability,int common,double pco,float time_money,float time_time,float time_straight);
    void getticketInfoMessage(Log* tlog,int mode);
    void getticketwindowMessage(Log* tlog);
    void changeTicketMain(Log* tlog);
    void changeTicketSearch(Log* tlog);
    void refundTicketMain(Log* tlog);
};
#endif // MAINWINDOW_H
