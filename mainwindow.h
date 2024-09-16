#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include "map.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_verticalScrollBar_sliderMoved(int position);

    void on_pushButton_0_clicked();

private:
    Ui::MainWindow *ui;
    int myTimerId;
    int picId;
    QTimer *timer;
    bool btvisible=true;
    void Timerout();
    void getMapMessage(QString a,QString b,QDate curdate);
};
#endif // MAINWINDOW_H
