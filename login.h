#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "Log.h"

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

signals:
    void sendToMainWindow(QString name,Log* logs,int myticketnum);
private:
    Ui::Login *ui;
    QString name;
    int log_mode=0,myticketnum=0;
    Log logs[1000];
};

#endif // LOGIN_H
