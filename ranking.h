#ifndef RANKING_H
#define RANKING_H

#include <QWidget>
#include "myopenglwidget.h"
#include <QLabel>
#include <QTimer>
namespace Ui {
class ranking;
}

class ranking : public QWidget
{
    Q_OBJECT

public:
    explicit ranking(QString username,int mode,QWidget *parent = nullptr);
    ~ranking();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::ranking *ui;
    MyOpenGLWidget * m;
    QStringList names[10];
    int costs[10];
    QString username;
    int mycosts=0,myrank=0,mode;
    void userRank(int mode);
    QLabel *champion;
    QTimer *timer;
    int r,g,b;
    void Timerout();
};

#endif // RANKING_H
