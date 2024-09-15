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
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"MSIMG32.LIB")
#define TIMEOUT 4000
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
    ui->pushButton->setStyleSheet("border-radius: 10px; background-color: #009ef9;");
    ui->pushButton_4->setStyleSheet("border-radius: 10px; background-color: #009ef9;");
    ui->pushButton_4->setIcon(QIcon("E:/Qtproject/Dtrip/search.png"));
    //设置应用图标
    QPixmap icon0("E:/Qtproject/Dtrip/旅行.png");
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
    ui->label_8->setPixmap(changeImage(QPixmap::fromImage(img),15));
    ui->label_8->setScaledContents(true);
    connect(timer,&QTimer::timeout,this,&MainWindow::Timerout);
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
    ui->label_8->setPixmap(changeImage(QPixmap::fromImage(img),15));
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
