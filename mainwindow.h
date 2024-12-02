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
#include <QDateEdit>
#include "mainwindow4.h"
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

    void on_verticalScrollBar_2_valueChanged(int value);
    //通过dijiestra算法的输出生成票据的函数：setLog
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

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_verticalScrollBar_3_sliderReleased();
    //将迪杰斯特拉算法输出的字符串翻译为人能看懂的格式
    QString routeTranslate(QString qs);

    void on_pushButton_12_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_dateEdit_2_userDateChanged(const QDate &date);

    void on_checkBox_3_stateChanged(int arg1);

    void on_pushButton_back_clicked();

private:
    Ui::MainWindow *ui;
    // 计时器
    int myTimerId;
    // 图片计数器
    int picId;
    // 票数计数器
    int ticketnum=0,ticket_checkednum=0,ticket_now=0,myticketnum=0,mypreticketnum=0,copynum=0;
    // 家所在城市，常去城市
    int home=-1,common=-1,commonfrom=-1,commonto=-1;
    // 对应概率
    float profrom,proto;
    // 对应概率
    double probability=0,pco=0;
    // 查询计数器（费用最少，时间最短，直飞，城市计数）
    float time_money=0,time_time=0,time_straight=0,*citytimesfrom,*citytimesto;
    QTimer *timer;
    // 当前日期
    QDate curdate;
    // dijiestela结果
    Dist *dist;
    // 工具栏visible，是否登录,退改是否筛选，搜索是否筛选，是否商业，是否过往模式
    bool btvisible=true,login=false,mode2filter=false,copymode=false,business=false,premode=false;
    // 交换按钮
    QPushButton* button_swap;
    //城市名数组
    QString citys[17]={"北京","上海","昆明","广州","台北","西安","乌鲁木齐","哈尔滨","拉萨","西宁","新加坡","马尼拉","曼谷","东京","首尔","新德里"};
    //城市位置数组
    QPoint cityp[17]={QPoint(1115,338),QPoint(1252,649),QPoint(735,828),QPoint(1025,885),QPoint(1245,834),QPoint(900,540),QPoint(310,192),QPoint(1392,139),QPoint(419,674),QPoint(699,459),QPoint(774,1472),QPoint(1230,1117),QPoint(677,1132),QPoint(1739,495),QPoint(1400,440),QPoint(42,721)};
    Log logs[5000],*copylogs[2000];
    QString username="",userpassword;
    // 用户票据，改签票据，过往票据
    Log *userLogs,*clog,*prelogs;
    // 主页模式2 widget
    QWidget* widget0;
    QVBoxLayout* verticalLayout_7;
    // 是否已经弹出登录页
    Login* loginW=NULL;
    // 主页模式3 用户地图
    Map *m=NULL;
    //后台界面指针
    MainWindow4 *m4=NULL;
    // 改签模式(界面2)，上次查询机票排序模式，我的机票排序模式，筛选模式（界面1）
    int changemode=0,sortmode=0,mysortmode=0;
    // 用户总消费，用户总里程
    int cost=0,mileage=0;
    //定时的图片更新函数，更新内容包括广告图与右侧的风景图
    void Timerout();
    //地图界面信号的主界面接收函数：
    void getMapMessage(QString a,QString b,QDate curdate);
    //登录界面返回信息的接收函数：
    void getLoginMessage(QString username,Log* mylog,Log * prelogs,int myticketnum,int allmyticketnum,int home,double probability,int common,double pco,float time_money,float time_time,float time_straight,float* citytimesfrom,float *citytimesto,int cost,int mileage);
    //小票据界面信号的主界面接收函数：
    void getticketInfoMessage(Log* tlog,int mode);
    //购票主函数-即ticketwindow的接收函数：
    void getticketwindowMessage(Log* tlog);
    //筛选滚动区域的槽函数，用于及时更新筛选结果：
    void getScrollBarMessage();
    //用户展示界面返回的 退出登录信息的接收函数：
    void getuserinfoMessage();
    //改签主函数：
    void changeTicketMain(Log* tlog);
    //改签票查找函数：
    void changeTicketSearch(Log* tlog);
    //退票函数：
    void refundTicketMain(Log* tlog);
    //用户画像分析算法：
    void userImageAnalyse(Log* userLogs,bool *bus,float *probus);
    //用户票务始发地与目的地的分析算法：
    void userSearchAnalyse(int *commonfrom,int * commonto,float *profrom,float *proto);
    //重置工具栏按钮的check状态：
    void resetChecked();
    //设置广告函数：
    void setAD(int bus);
    //用于清除系统无法自动回收的界面：
    void lastWindowCleaner();
    //用于清除layout中的控件
    void layoutCleaner(int num);
};
#endif // MAINWINDOW_H
