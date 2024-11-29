#include "userinfo.h"
#include "ui_userinfo.h"
#include <QMouseEvent>
#include "QuickSort.h"
#include "ranking.h"
userinfo::userinfo(QString username,int cost,int mileage,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userinfo)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose,false);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->pushButton_4->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px; background-color: white;");
    ui->label_2->setText(username);
    QImage img;
    img.load(pathCreator("/head.png"));
    ui->label->setPixmap(changeImage(QPixmap::fromImage(img),img.height()/2));
    ui->label->setStyleSheet("border: 2px solid #009ef9; border-radius: 38px;");
    ui->pushButton->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px;");
    ui->pushButton_2->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px;");
    ui->pushButton_3->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px;");
    ui->label_3->setText("消费："+QString::number(cost)+"元");
    ui->label_4->setText("里程："+QString::number(mileage)+"公里");
    QImage img1,img2;
    QString levels[6]={"菜鸟","青铜","白银","黄金","铂金","钻石"};
    int i=0,progress=0,distance=0;
    if(cost<500) {
        i=0;
        if(cost!=0) progress=(cost*100)/(double)500;
        distance=500-cost;
    }
    else if(cost<2000) {
        i=1;
        progress=(cost*100)/(double)2000;
        distance=2000-cost;
    }
    else if(cost<10000) {
        i=2;
        progress=(cost*100)/(double)10000;
        distance=10000-cost;
    }
    else if(cost<50000) {
        i=3;
        progress=(cost*100)/(double)50000;
        distance=50000-cost;
    }
    else if(cost<300000){
        i=4;
        progress=(cost*100)/(double)300000;
        distance=300000-cost;
    }
    else {
        i=5;
        progress=100;
    }
    img1.load(pathCreator("/"+levels[i]+".png"));
    if(i!=5) img2.load(pathCreator("/"+levels[i+1]+".png"));
    ui->label_5->setPixmap(QPixmap::fromImage(img1));
    if(i!=5) ui->label_6->setPixmap(QPixmap::fromImage(img2));
    else ui->label_6->setText("满级");
    ui->progressBar->setValue(progress);
    if(i!=5) ui->label_7->setText("当前成长"+QString::number(cost)+"，距离升级"+levels[i+1]+"会员 还需要"+QString::number(distance));
    else ui->label_7->setText("当前成长"+QString::number(cost)+"，已满级");

}

userinfo::~userinfo()
{
    delete ui;
}

void userinfo::on_pushButton_3_clicked()
{
    emit sendToMainWindow();
    this->close();
}


void userinfo::on_pushButton_clicked()
{
    ranking *ranking0=new ranking(ui->label_2->text(),0);
    ranking0->show();
}


void userinfo::on_pushButton_2_clicked()
{
    ranking *ranking0=new ranking(ui->label_2->text(),1);
    ranking0->show();
}

