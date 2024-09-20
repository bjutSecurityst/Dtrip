#ifndef TICKETINFO_H
#define TICKETINFO_H

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
                        QWidget *parent = nullptr);
    ~ticketInfo();

private:
    Ui::ticketInfo *ui;
};

#endif // TICKETINFO_H
