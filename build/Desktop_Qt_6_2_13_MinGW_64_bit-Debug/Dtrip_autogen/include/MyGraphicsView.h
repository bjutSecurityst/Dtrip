#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#pragma once
#include <QGraphicsView>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsWidget>
class MyGraphicsView:public QGraphicsView{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = nullptr);
signals:
    void sendToMap(QWheelEvent *event);
private slots:
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QGraphicsWidget* m_widget;
    QGraphicsScene* m_scene;
};

#endif // MYGRAPHICSVIEW_H

