#ifndef TICKETWINDOW_H
#define TICKETWINDOW_H

#include <QMainWindow>
#include "Log.h"

namespace Ui {
class ticketWindow;
}

class ticketWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ticketWindow(Log* tlog,int mode,QWidget *parent = nullptr);
    explicit ticketWindow(Log* tlog,int mode,Log* clog,QWidget *parent = nullptr);
    ~ticketWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();

    void on_spinBox_valueChanged(int arg1);

signals:
    //购票信号
    void sendToMainWindow(Log* tlog);
    //退出信号
    void Exit();
    //准备改签信号
    void changeTicket(Log* tlog);
    //改签信号
    void change(Log* tlog);
    //退票信号
    void refund(Log* tlog);
private:
    Ui::ticketWindow *ui;
    Log *tlog,*clog;
    int mode;
};

#endif // TICKETWINDOW_H
