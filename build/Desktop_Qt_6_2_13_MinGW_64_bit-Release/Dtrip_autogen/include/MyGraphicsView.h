#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMainWindow>

class MyGraphicsView:public QGraphicsView{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = nullptr);
private slots:
    void wheelEvent(QWheelEvent *event);
};

#endif // MYGRAPHICSVIEW_H
