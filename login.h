#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "Log.h"
#include "passwordfix.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

signals:
    void sendToMainWindow(QString name,Log* logs,Log* prelogs,int myticketnum,int allmyticektnum,int home,double probability,int common,double pco,float time_money,float time_time,float time_straight,float *citytimesfrom,float *citytimesto,int cost,int mile);
private:
    Ui::Login *ui;
    //用户名
    QString name;
    //登录界面模式，用户票数，用户过往票数
    int log_mode=0,myticketnum=0,mypreticketnum=0;
    QString citys[17]={"北京","上海","昆明","广州","台北","西安","乌鲁木齐","哈尔滨","拉萨","西宁","新加坡","马尼拉","曼谷","东京","首尔","新德里"};
    //用户正常票数组，用户过往票数组
    Log logs[1000],prelogs[200];
    //修改子窗口指针
    Passwordfix* fix=NULL;
    //登录界面获取修改或忘记密码界面信号的接收函数
    void getpasswordfixMessage();
    //用户住所以及票务常去目的地分析函数：userHomeAnalyse
    void userHomeAnalyse(int *home,double *probability,int *common,double *pco);
};

#endif // LOGIN_H
