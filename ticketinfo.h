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
    explicit ticketInfo(QString company,
                        QString ID,
                        QString sou,
                        QString des,
                        QString time0,
                        QString time1,
                        int price,
                        QString chi,
                        Log* next,
                        Log* my,
                        QWidget *parent = nullptr);
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
