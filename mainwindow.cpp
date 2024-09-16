#define _CRT_SECURE_NO_WARNINGS 1
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <mmSystem.h>
#include <QPainter>
//#pragma comment(lib,"C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64/EasyXw.lib")
//#include <graphics.h>
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"MSIMG32.LIB")
#define TIMEOUT 4000
#define WindowWidth 1280
#define WindowHeight 720
QPixmap changeImage(QPixmap img_in,int radius);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口大小
    this->setMinimumSize(1280,720);
    //设置工具栏为垂直贴顶布局
    ui->verticaltool->setAlignment(Qt::AlignTop);
    //设置工具栏按钮，及其他按钮
    ui->pushButton_1->setMinimumSize(10,10);
    ui->pushButton_1->setCheckable(true);
    ui->pushButton_1->setChecked(true);
    ui->pushButton_2->setCheckable(true);
    ui->pushButton_3->setCheckable(true);
    ui->pushButton_0->setStyleSheet("border:none;");
    ui->pushButton_0->setMaximumSize(100,30);
    ui->pushButton_0->setIcon(QIcon("E:/Qtproject/Dtrip/菜单栏2.png"));
    ui->pushButton->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px; background-color: #88CDF6;");
    ui->pushButton_4->setIcon(QIcon("E:/Qtproject/Dtrip/search.png"));
    ui->pushButton_4->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px; background-color: #88CDF6;");
    //设置应用图标
    QPixmap icon0("E:/Qtproject/Dtrip/trip.png");
    ui->labelicon0->setPixmap(icon0);
    //设置查询窗口中内容
    ui->easystay->setStyleSheet("border: none; border-image: url(E:/Qtproject/Dtrip/easy-stay.png);");
    ui->backgroundsky->setMinimumSize(200,100);
    ui->backgroundsky->setStyleSheet("border: 2px solid lightblue; border-radius: 10px; border-image: url(E:/Qtproject/Dtrip/渐变背景.png);");
    ui->lineEditdep->setMinimumHeight(30);
    ui->lineEditari->setMinimumHeight(30);
    ui->layoutbutton->setStyleSheet("border-radius: 10px; background-color: white;");
    ui->layoutbutton_2->setStyleSheet("border-radius: 10px; background-color: white;");
    ui->home_background->setStyleSheet("border: none; border-image: url(E:/Qtproject/Dtrip/homepage-background.png);");
    ui->comboBox->setCurrentIndex(-1);

    //设置滚动播放的图片
    picId=0;
    timer=new QTimer;
    timer->start(TIMEOUT);
    QImage img;
    img.load("E:/Qtproject/Dtrip/scene0.jpg");
    ui->label_8->setPixmap(changeImage(QPixmap::fromImage(img),30));
    ui->label_8->setScaledContents(true);
    connect(timer,&QTimer::timeout,this,&MainWindow::Timerout);

    QImage imgGg;
    imgGg.load("E:/Qtproject/Dtrip/广告位招租.jpg");
    ui->label_10->setPixmap(changeImage(QPixmap::fromImage(imgGg),40));
    ui->label_10->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Timerout(){
    //定时的图片更新函数
    QString path("E:/Qtproject/Dtrip/scene");
    path+=QString::number(picId);
    path+=".jpg";
    QImage img;
    img.load(path);
    ui->label_8->setPixmap(changeImage(QPixmap::fromImage(img),30));
    picId++;
    picId=picId % 4;
}

QPixmap changeImage(QPixmap img_in,int radius){
    //图片圆角化
    QSize size = QSize(img_in.size());
    QBitmap mask = QBitmap(size);
    QPainter painter = QPainter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(mask.rect(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(mask.rect(), radius, radius);
    painter.end();
    img_in.setMask(mask);
    return img_in;
}

void MainWindow::on_pushButton_clicked()
{
    //转至地图选择页
    this->hide();
    Map *m=new Map(ui->dateEdit->date());
    m->show();
    connect(m,&Map::sendToMainWindow,this,&MainWindow::getMapMessage);
}


void MainWindow::on_verticalScrollBar_sliderMoved(int position)
{
    int y1=30,y2=65,y3=100;
    ui->pushButton_1->move(QPoint(5,y1+ui->verticalScrollBar->sliderPosition()));
    ui->pushButton_2->move(QPoint(5,y2+ui->verticalScrollBar->sliderPosition()));
    ui->pushButton_3->move(QPoint(5,y3+ui->verticalScrollBar->sliderPosition()));
}

void MainWindow::getMapMessage(QString a,QString b,QDate curdate){
    this->show();
    a.remove(0,4);
    b.remove(0,4);
    ui->lineEditdep->setText(a);
    ui->lineEditari->setText(b);
    ui->dateEdit->setDate(curdate);
}



void MainWindow::on_pushButton_0_clicked()
{
    if(btvisible==true){
        ui->pushButton_1->setVisible(0);
        ui->pushButton_2->setVisible(0);
        ui->pushButton_3->setVisible(0);
        btvisible=false;
    }
    else{
        ui->pushButton_1->setVisible(1);
        ui->pushButton_2->setVisible(1);
        ui->pushButton_3->setVisible(1);
        btvisible=true;
    }
}

