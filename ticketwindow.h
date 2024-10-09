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

private:
    Ui::ticketWindow *ui;
    Log *tlog;
};

#endif // TICKETWINDOW_H
