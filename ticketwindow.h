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
    void sendToMainWindow(Log* tlog);
    void Exit();
    void changeTicket(Log* tlog);
    void change(Log* tlog);
    void refund(Log* tlog);
private:
    Ui::ticketWindow *ui;
    Log *tlog,*clog;
    int mode;
};

#endif // TICKETWINDOW_H
