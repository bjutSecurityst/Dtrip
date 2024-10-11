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
    ~ticketWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();

signals:
    void sendToMainWindow(Log* tlog);
    void Exit();
private:
    Ui::ticketWindow *ui;
    Log *tlog;
    int mode;
};

#endif // TICKETWINDOW_H
