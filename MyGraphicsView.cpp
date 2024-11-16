#include "MyGraphicsView.h"
#include "QWheelEvent"
MyGraphicsView::MyGraphicsView(QWidget *parent):QGraphicsView(parent)
{

}
//GraphicsView定制版，以下实现了地图的缩放，以及信号从此传递至主页面的工作
void MyGraphicsView::wheelEvent(QWheelEvent *event)
{
    int wheelValue = event->angleDelta().y();
    double ratio = (double)wheelValue / (double)1200 + 1;
    QPoint p( -100, 100);
    QPoint q( 100, -100);
    if((mapFromScene(p).rx()-mapFromScene(q).rx())>(p.rx()-q.rx()+60)){
        if(ratio<1){}
        else scale(ratio, ratio);
    }
    else scale(ratio, ratio);
    emit sendToMap(event);
}
//鼠标拖动时传递信号
void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    //调用父类该函数
    QGraphicsView::mouseMoveEvent(event);
    QWheelEvent* even = NULL;
    emit sendToMap(even);
}

