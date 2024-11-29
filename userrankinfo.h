#ifndef USERRANKINFO_H
#define USERRANKINFO_H

#include <QWidget>

namespace Ui {
class userRankInfo;
}

class userRankInfo : public QWidget
{
    Q_OBJECT

public:
    explicit userRankInfo(QString name,int rank,int number,QWidget *parent = nullptr);
    ~userRankInfo();

private:
    Ui::userRankInfo *ui;
};

#endif // USERRANKINFO_H
