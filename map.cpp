#include "map.h"
#include "MyGraphicsView.h"
#include "ui_map.h"
#include "QWheelEvent"
#include <QGraphicsItem>
#include <QFile>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <mmSystem.h>
#include <fstream>
using namespace std;
#define pai 3.1415926
void addcursorline(int x1,int x2,int y1,int y2,int line,QGraphicsScene *scene);
//地图选择页
Map::Map(QDate curDate,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Map)
{
    int i,j;
    ui->setupUi(this);
    ui->dateEdit->setDate(curDate);
    scene = new QGraphicsScene;
    QImage img;
    img.load("E:/Qtproject/Dtrip/地图.png");
    scene->addPixmap(QPixmap::fromImage(img));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->label->setNum(100);
    connect(ui->graphicsView,&MyGraphicsView::sendToMap,this,&Map::wheelEvent);
    connect(ui->graphicsView,&MyGraphicsView::sendToMap,this,&Map::on_MyGraphicsView_rubberBandChanged);
    // for(i=0;i<16;i++){
    //     for(j=i+1;j<16;j++){
    //         addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),1,scene);
    //     }
    // }
    for(i=0;i<16;i++){
        buttons[i] = new QPushButton(citys[i]);
        buttons[i]->setParent(this);
        buttons[i]->setObjectName(citys[i]);
        buttons[i]->setIcon(QIcon("E:/Qtproject/Dtrip/机场.png"));
        buttons[i]->setIconSize(QSize(20,30));
        buttons[i]->setFlat(true);
        buttons[i]->setGeometry(2000,2000,70,30);
        connect(buttons[i], &QPushButton::clicked, this, &Map::on_buttons_clicked);
    }
    ui->pushButton->setObjectName("清除");
    ui->pushButton_2->setObjectName("确定");
    ui->pushButton->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px;");
    ui->pushButton_2->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px;");
    connect(ui->pushButton, &QPushButton::clicked, this, &Map::on_buttons_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Map::on_buttons_clicked);
    ui->pushButton_3->setStyleSheet("border-radius: 10px; background-color: #00aef9;");
    ui->pushButton_4->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px;");
    ui->label_2->setVisible(true);
    ui->label_2->move(ui->graphicsView->mapFromScene(QPoint(850,560)).rx(),ui->graphicsView->mapFromScene(QPoint(850,560)).ry());
}

Map::~Map()
{
    delete ui;
}
//实现滚轮缩放以及缩放条的长度设置
void Map::wheelEvent(QWheelEvent *event)
{
    int i;
    QPoint p( -100, 100);
    QPoint q( 100, -100);
    double ratio=(ui->graphicsView->mapFromScene(p).rx()-ui->graphicsView->mapFromScene(q).rx())/(double)(p.rx()-q.rx()+60)*18-16;
    if(ratio>99) ratio=99;
    ui->horizontalSlider->setSliderPosition(ratio);
    ui->label->setNum((int)ratio);
    for(i=0;i<16;i++){
        buttons[i]->move(ui->graphicsView->mapFromScene(cityp[i]).rx(),ui->graphicsView->mapFromScene(cityp[i]).ry());
    }
    ui->label_2->move(ui->graphicsView->mapFromScene(QPoint(850,560)).rx(),ui->graphicsView->mapFromScene(QPoint(850,560)).ry());
    if(ratio<16) {
        for(i=0;i<16;i++){
            buttons[i]->setVisible(false);
        }
        ui->label_2->setVisible(true);
    }
    else {
        for(i=0;i<16;i++){
            buttons[i]->setVisible(true);
        }
        ui->label_2->setVisible(false);
    }
}





void Map::on_horizontalSlider_sliderMoved(int position)
{

}


//实现城市按钮位置的实时更新
void Map::on_MyGraphicsView_rubberBandChanged()
{
    int i;
    QPoint p( -100, 100);
    QPoint q( 100, -100);
    double ratio=(ui->graphicsView->mapFromScene(p).rx()-ui->graphicsView->mapFromScene(q).rx())/(double)(p.rx()-q.rx()+60)*18-16;
    for(i=0;i<16;i++){
        buttons[i]->move(ui->graphicsView->mapFromScene(cityp[i]).rx(),ui->graphicsView->mapFromScene(cityp[i]).ry());
    }
    ui->label_2->move(ui->graphicsView->mapFromScene(QPoint(850,560)).rx(),ui->graphicsView->mapFromScene(QPoint(850,560)).ry());
}

void Map::on_buttons_clicked()
{
    QPushButton *btn=qobject_cast<QPushButton*>(sender());
    if(btn->objectName()=="清除"){
        ui->label_3->setText("始发地：请点击始发地");
        ui->label_4->setText("目的地：请点击目的地");
    }
    else if(btn->objectName()=="确定"){
        this->setAttribute(Qt::WA_DeleteOnClose, true);
        emit sendToMainWindow(ui->label_3->text(),ui->label_4->text(),ui->dateEdit->date());
        this->close();
    }
    else{
        if(ui->label_3->text()=="始发地：请点击始发地") ui->label_3->setText("始发地："+btn->objectName());
        else ui->label_4->setText("目的地："+btn->objectName());
    }
}

void addcursorline(int x1,int x2,int y1,int y2,int line,QGraphicsScene *scene){
    QImage img;
    img.load("E:/Qtproject/Dtrip/icon_airplane.png");
    if(line==2){
        double a=sqrt(pow(abs(x2-x1),2)+pow(abs(y2-y1),2));
        double b=sqrt(a/15);
        double tan=(double)(y1-y2)/(double)(x1-x2);
        double x=(x1+x2)/2.0-a/2.0;
        double y=(y1+y2)/2.0+b/2.0;
        QGraphicsEllipseItem *item1 = new QGraphicsEllipseItem(x,y,a,b);
        item1->setTransformOriginPoint(item1->boundingRect().center().x(), item1->boundingRect().center().y());
        item1->setRotation(atan(tan)*180/pai);
        item1->setBrush(Qt::transparent);
        QGraphicsPixmapItem *item2 = new QGraphicsPixmapItem(QPixmap::fromImage(img));
        QGraphicsPixmapItem *item3 = new QGraphicsPixmapItem(QPixmap::fromImage(img));
        item2->setPos((x1+x2)/2.0,y+3);
        item2->setRotation(atan(tan)*180/pai+45);
        item3->setPos((x1+x2)/2.0+10,y-5);
        item3->setRotation(atan(tan)*180/pai-135);
        QPen pen;  // creates a default pen
        pen.setStyle(Qt::DashDotLine);
        pen.setWidth(1.0);
        pen.setBrush(Qt::blue);
        pen.setCapStyle(Qt::RoundCap);
        pen.setJoinStyle(Qt::RoundJoin);
        item1->setPen(pen);
        scene->addItem(item1);
        scene->addItem(item2);
        scene->addItem(item3);
    }
    else{
        QGraphicsLineItem *item4 = new QGraphicsLineItem(x1,y1,x2,y2);
        QGraphicsPixmapItem *item5 = new QGraphicsPixmapItem(QPixmap::fromImage(img));
        QPen pen;  // creates a default pen
        pen.setStyle(Qt::DashDotLine);
        pen.setWidth(1.0);
        pen.setBrush(Qt::blue);
        pen.setCapStyle(Qt::RoundCap);
        pen.setJoinStyle(Qt::RoundJoin);
        item4->setPen(pen);
        item5->setPos((x1+x2)/2.0,(y1+y2)/2.0-9);
        double tan=(double)(y1-y2)/(double)(x1-x2);
        item5->setRotation(atan(tan)*180/pai+45);
        scene->addItem(item4);
        scene->addItem(item5);
    }
}


void Map::on_pushButton_4_clicked()
{
    if(ui->pushButton_4->text()=="清除航线"){
        QImage img;
        img.load("E:/Qtproject/Dtrip/地图.png");
        scene->addPixmap(QPixmap::fromImage(img));
        ui->graphicsView->setScene(scene);
        ui->pushButton_4->setText("显示航线");
    }
    else{
        int i,j;
        for(i=0;i<16;i++){
            for(j=i+1;j<16;j++){
                addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),1,scene);
            }
        }
        ui->pushButton_4->setText("清除航线");
    }
}


void Map::on_pushButton_5_clicked()
{
    //显示对应日期的航线
    QDate curDate =ui->dateEdit->date();
    QString year,month,day;
    int count0=0,count1=0;
    year= QString::number(curDate.year());
    month= QString::number(curDate.month());
    day= QString::number(curDate.day());
    QImage img;
    QString fname;
    img.load("E:/Qtproject/Dtrip/地图.png");
    scene->addPixmap(QPixmap::fromImage(img));
    ui->graphicsView->setScene(scene);
    int i,j;
    for(i=0;i<16;i++){
        for(j=i+1;j<16;j++){
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[i] + "-" + citys[j] + ".txt";
            QFile fs(fname);
            if(fs.open(QIODeviceBase::ReadOnly)){
                count0=1;
            }
            fs.close();
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[j]+"-"+citys[i]+".txt";
            QFile fs1(fname);
            if(fs1.open(QIODeviceBase::ReadOnly)){
                count1=1;
            }
            fs1.close();
            if((count0+count1)==2) addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),2,scene);
            else if(count0==1) addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),1,scene);
            else if(count1==1) addcursorline(cityp[j].rx(),cityp[i].rx(),cityp[j].ry(),cityp[i].ry(),1,scene);
            else{}
            count0=0;
            count1=0;
        }
    }
    ui->pushButton_4->setText("清除航线");
}

