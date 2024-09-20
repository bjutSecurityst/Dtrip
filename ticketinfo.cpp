#include "ticketinfo.h"
#include "ui_ticketinfo.h"

ticketInfo::ticketInfo(QString company,QString ID,QString sou,QString des,QString time0,QString time1,int price,QString chi,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ticketInfo)
{
    ui->setupUi(this);
    int time0h,time0m,time1h,time1m,i=0,j=0,times_h,times_m;
    bool dayplus=false;
    QString time1_withplus;
    QString time_split;
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    QStringList time0l=time0.split(':');
    QStringList time1l=time1.split(':');
    foreach (QString item, time0l) {
        switch(i){
        case(0):time0h=item.toInt();break;
        case(1):time0m=item.toInt();break;
        }
        i++;
    }
    i=0;
    foreach (QString item, time1l) {
        switch(i){
        case(0):time1h=item.toInt();break;
        case(1):time1_withplus=item;break;
        }
        i++;
    }
    i=0;
    QStringList time1ml=time1_withplus.split('+');
    foreach (QString item, time1ml) {
        switch(i){
        case(0):time1m=item.toInt();break;
        case(1):dayplus=true;break;
        }
        i++;
    }
    times_m=time1m-time0m;
    if(dayplus==true) times_h=time1h-time0h+24;
    else times_h=time1h-time0h;
    if(times_m<0) {
        times_m+=60;
        times_h-=1;
    }
    time_split=QString::number(times_h)+"小时"+QString::number(times_m)+ "分";
    QImage img;
    if(company=="中国国航"||company=="春秋航空") img.load("E:/Qtproject/Dtrip/CA.png");
    else if(company=="山东航空"||company=="南方航空") img.load("E:/Qtproject/Dtrip/CZ.png");
    else img.load("E:/Qtproject/Dtrip/MU.png");
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label_2->setText(company);
    ui->label_3->setText(ID);
    ui->label_7->setText(time0);
    ui->label_8->setText(sou);
    ui->label_9->setText(time1);
    ui->label_10->setText(des);
    ui->label_5->setText(time_split);
    ui->label_6->setText(QString::number(price));
    ui->pushButton->setText("订票");
}

ticketInfo::~ticketInfo()
{
    delete ui;
}
