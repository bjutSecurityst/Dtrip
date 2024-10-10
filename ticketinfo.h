#ifndef TICKETINFO_H
#define TICKETINFO_H
#include "Log.h"
#include <QWidget>
namespace Ui {
class ticketInfo;
}

class ticketInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ticketInfo(Log* my,int mode,QWidget *parent = nullptr);
    ~ticketInfo();

private slots:
    void on_pushButton_clicked();

signals:
    void sendToMainWindow(Log* tlog);
private:
    Ui::ticketInfo *ui;
    Log* tlog;
};

#endif // TICKETINFO_H
