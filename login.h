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
    void sendToMainWindow(QString name,Log* logs,int myticketnum,int home,double probability,int common,double pco,float time_money,float time_time,float time_straight);
private:
    Ui::Login *ui;
    QString name;
    int log_mode=0,myticketnum=0;
    QString citys[17]={"北京","上海","昆明","广州","台北","西安","乌鲁木齐","哈尔滨","拉萨","西宁","新加坡","马尼拉","曼谷","东京","首尔","新德里"};
    Log logs[1000];
    Passwordfix* fix=NULL;
    void getpasswordfixMessage();
    void userHomeAnalyse(int *home,double *probability,int *common,double *pco);
};

#endif // LOGIN_H
