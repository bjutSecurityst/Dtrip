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
    explicit ticketWindow(Log* tlog,QWidget *parent = nullptr);
    ~ticketWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
signals:
    void sendToMainWindow(Log* tlog);
private:
    Ui::ticketWindow *ui;
    Log *tlog;
};

#endif // TICKETWINDOW_H
