#define _CRT_SECURE_NO_WARNINGS 1
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <QPainter>
#include <QFile>
#include <QRegularExpression>
#include "QuickSort.h"
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
    ui->easystay->setStyleSheet("border: none; border-image: url(E:/Qtproject/Dtrip/easy_stay.png);");
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


void MainWindow::on_pushButton_4_clicked()
{
    int nodeNum=16, arcNum=241, begin,end;
    int i,j;
    bool label;
    QDate curDate =ui->dateEdit->date();
    QString year,month,day;
    QString company,ID,sou,des,time0,time1,chi;
    int price=0,price0=0;
    year= QString::number(curDate.year());
    month= QString::number(curDate.month());
    day= QString::number(curDate.day());
    QString fname,info0;
    CMap* pMap = new CMap(nodeNum,arcNum);
    QRegularExpression rxlen( "^(.*)/(.*)/(.*)/(.*)/(.*)/(.*)/(.*)/(.*)$" );
    QRegularExpressionMatch match;
    for (i = 0; i < nodeNum;i++) {
        Node* pNode0 = new Node(i);
        pMap->addNode(pNode0);
    }
    for (i = 0; i < nodeNum;i++) {
        for(j = i+1; j < nodeNum;j++) {
            price=0;
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[i] + "-" + citys[j] + ".txt";
            QFile fs(fname);
            if(fs.open(QIODeviceBase::ReadOnly)){
                QTextStream in(&fs);
                in.setEncoding(QStringConverter::System);
                while (in.atEnd()==false){
                    info0=in.readLine();
                    match = rxlen.match(info0);
                    price0=match.captured(7).toInt();
                    if(price==0) price=price0;
                    else if(price0<price) price=price0;
                }
                label=pMap->setValueToMatrixForDirectedGraph(i, j, price);
            }
            fs.close();
            price=0;
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[j] + "-" + citys[i] + ".txt";
            QFile fs1(fname);
            if(fs1.open(QIODeviceBase::ReadOnly)){
                QTextStream in1(&fs1);
                in1.setEncoding(QStringConverter::System);
                while (in1.atEnd()==false){
                    info0=in1.readLine();
                    match = rxlen.match(info0);
                    price0=match.captured(7).toInt();
                    if(price==0) price=price0;
                    else if(price0<price) price=price0;
                }
                label=pMap->setValueToMatrixForDirectedGraph(j, i, price);
            }
            fs.close();
        }
    }
    for(begin=0;begin<17;begin++){
        if(citys[begin]==ui->lineEditdep->text()) break;
    }
    for(end=0;end<17;end++){
        if(citys[end]==ui->lineEditari->text()) break;
    }
    //ui->label_11->setText(QString::number(end));
    dist = pMap->Dijkstra(begin);
    //获取价格最低路径
    string s = pMap->visit_first(dist,begin,end);
    QString qs=QString::fromStdString(s);
    QStringList qsl=qs.split(' ');
    QRegularExpression numbers( "0|[1-9]\\d{0,1}" );
    QRegularExpressionMatch matchnum;
    QRegularExpression dot( "[,]" );
    qs="";
    QString coc="",ari="";
    QStringList mid[5];
    i=0;
    foreach (QString item, qsl) {
        matchnum = numbers.match(item);
        match = dot.match(item);
        if(matchnum.hasMatch()){
            if(item.toInt()<20){
                qs=qs+citys[item.toInt()];
                if(coc=="") coc=citys[item.toInt()];
                else {
                    mid->append(citys[item.toInt()]);
                    i++;
                }
                ari=citys[item.toInt()];
            }
            else qs=qs+"需要"+item+"￥-";
        }
        else if(match.hasMatch()) qs=qs+"经";
    }
    mid->removeLast();
    i=0;
    j=0;
    fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+ coc + "-" + ari + ".txt";
    QFile fs(fname);
    if(fs.open(QIODeviceBase::ReadOnly)){
        QTextStream in(&fs);
        in.setEncoding(QStringConverter::System);
        while (in.atEnd()==false){
            info0=in.readLine();
            QStringList infos=info0.split('/');
            i=0;
            foreach (QString item, infos) {
                switch(i){
                case(0):company=item;break;
                case(1):ID=item;break;
                case(2):sou=item;break;
                case(3):des=item;break;
                case(4):time0=item;break;
                case(5):time1=item;break;
                case(6):price=item.toInt();break;
                case(7):chi=item;break;
                }
                i++;
            }
            logs[j].setLog(company,ID,sou,des,time0,time1,price,chi);
            j++;
        }
        QuickSort2(logs,j);
        for(i=0;i<j;i++){
            qDebug() <<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
        }
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        for(i=0;i<3;i++){
            ticketInfo* ticket0=new ticketInfo(logs[i].company,logs[i].ID,logs[i].sou,logs[i].des,logs[i].time0,logs[i].time1,logs[i].price,logs[i].chi);
            ui->verticalLayout_2->addWidget(ticket0);
        }
    }
    ticketnum=j;
    fs.close();
    ui->label_11->setText(qs);
    //获取价格次低路径
    s = pMap->visit_second(dist,begin,end);
    qs=QString::fromStdString(s);
    qsl=qs.split(' ');
    qs="";
    foreach (QString item, qsl) {
        matchnum = numbers.match(item);
        match = dot.match(item);
        if(matchnum.hasMatch()){
            if(item.toInt()<20){
                qs=qs+citys[item.toInt()];
            }
            else qs=qs+"需要"+item+"￥-";
        }
        else if(match.hasMatch()) qs=qs+"经";
    }
    ui->label_11->setText(qs);

}


void MainWindow::on_verticalScrollBar_2_sliderMoved(int position)
{
    if(ticketnum!=0){
        int i=0;
        int j=3;
        j=(ticketnum-3)*((double)position/(double)100);
        if(j<3)j=3;
        if(j>ticketnum) j=ticketnum;
        while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();

            if (QSpacerItem* spaerItem = item->spacerItem())
                ui->verticalLayout_2->removeItem(spaerItem);

            delete item;
        }
        ticketInfo* ticket0=new ticketInfo(logs[j-3].company,logs[j-3].ID,logs[j-3].sou,logs[j-3].des,logs[j-3].time0,logs[j-3].time1,logs[j-3].price,logs[j-3].chi);
        ticketInfo* ticket1=new ticketInfo(logs[j-2].company,logs[j-2].ID,logs[j-2].sou,logs[j-2].des,logs[j-2].time0,logs[j-2].time1,logs[j-2].price,logs[j-2].chi);
        ticketInfo* ticket2=new ticketInfo(logs[j-1].company,logs[j-1].ID,logs[j-1].sou,logs[j-1].des,logs[j-1].time0,logs[j-1].time1,logs[j-1].price,logs[j-1].chi);
        ui->verticalLayout_2->addWidget(ticket0);
        ui->verticalLayout_2->addWidget(ticket1);
        ui->verticalLayout_2->addWidget(ticket2);
    }
}


void MainWindow::on_verticalScrollBar_2_valueChanged(int value)
{
    if(ticketnum!=0){
        int i=0;
        int j=3;
        j=(ticketnum-3)*((double)ui->verticalScrollBar_2->sliderPosition()/(double)100);
        if(j<3)j=3;
        if(j>ticketnum) j=ticketnum;
        while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();

            if (QSpacerItem* spaerItem = item->spacerItem())
                ui->verticalLayout_2->removeItem(spaerItem);

            delete item;
        }
        ticketInfo* ticket0=new ticketInfo(logs[j-3].company,logs[j-3].ID,logs[j-3].sou,logs[j-3].des,logs[j-3].time0,logs[j-3].time1,logs[j-3].price,logs[j-3].chi);
        ticketInfo* ticket1=new ticketInfo(logs[j-2].company,logs[j-2].ID,logs[j-2].sou,logs[j-2].des,logs[j-2].time0,logs[j-2].time1,logs[j-2].price,logs[j-2].chi);
        ticketInfo* ticket2=new ticketInfo(logs[j-1].company,logs[j-1].ID,logs[j-1].sou,logs[j-1].des,logs[j-1].time0,logs[j-1].time1,logs[j-1].price,logs[j-1].chi);
        ui->verticalLayout_2->addWidget(ticket0);
        ui->verticalLayout_2->addWidget(ticket1);
        ui->verticalLayout_2->addWidget(ticket2);
    }
}

