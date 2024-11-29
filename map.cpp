#include "map.h"
#include "MyGraphicsView.h"
#include "ui_map.h"
#include "QWheelEvent"
#include <QGraphicsItem>
#include <QFile>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <mmSystem.h>
#include "QuickSort.h"
#include "Log.h"
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
    ui->checkBox->setVisible(false);
    ui->widget->setVisible(false);
    ui->pushButton_7->setVisible(false);
    mode=0;
    scene = new QGraphicsScene;
    QImage img;
    img.load("E:/Qtproject/Dtrip/地图.png");
    scene->addPixmap(QPixmap::fromImage(img));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->label->setNum(10);
    connect(ui->graphicsView,&MyGraphicsView::sendToMap,this,&Map::wheelEvent);
    connect(ui->graphicsView,&MyGraphicsView::sendToMap,this,&Map::on_MyGraphicsView_rubberBandChanged);
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
    float ratioreal=2.815478;
    float leftx=ui->graphicsView->mapToScene(QPoint(60,660)).rx(),lefty=ui->graphicsView->mapToScene(QPoint(60,660)).ry();
    float kilox=ui->graphicsView->mapToScene(QPoint(140,140)).rx()-ui->graphicsView->mapToScene(QPoint(0,140)).rx(),kiloy=ui->graphicsView->mapToScene(QPoint(20,20)).ry()-ui->graphicsView->mapToScene(QPoint(20,0)).ry();
    itemline = new QGraphicsLineItem(leftx,lefty,ui->graphicsView->mapToScene(QPoint(60+200/ratioreal,660)).rx(),lefty);
    kilos->setText("200公里");
    kilos->setGeometry(ui->graphicsView->mapToScene(QPoint(60+200/ratioreal/2,635)).rx(),ui->graphicsView->mapToScene(QPoint(60+200/ratioreal/2,635)).ry(),kilox,kiloy);
    scene->addItem(itemline);
    scene->addWidget(kilos);
    kilos->setStyleSheet("background-color: transparent;");
}
Map::Map(Log* userLogs,int myticketnum,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Map)
{
    int i,j;
    setAttribute(Qt::WA_QuitOnClose,false);
    ui->setupUi(this);
    mode=1;
    this->userLogs=userLogs;
    this->myticketnum=myticketnum;
    ui->dateEdit->setVisible(false);
    ui->checkBox->setVisible(true);
    ui->pushButton_7->setVisible(true);
    ui->checkBox->move(95,22);
    ui->widget->setVisible(true);
    scene = new QGraphicsScene;
    QImage img;
    img.load("E:/Qtproject/Dtrip/地图.png");
    scene->addPixmap(QPixmap::fromImage(img));
    ui->graphicsView->resize(780,586);
    ui->centralwidget->resize(780,586);
    ui->horizontalSlider->resize(250,32);
    ui->horizontalSlider->move(450,13);
    ui->label->move(430,13);
    ui->pushButton_6->setStyleSheet("border-radius: 10px; background-color: #00aef9;");
    ui->pushButton_7->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px;");
    ui->pushButton_5->setVisible(false);
    ui->pushButton_4->resize(70,40);
    ui->pushButton_4->move(10,10);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
    ui->label->setNum(10);
    connect(ui->graphicsView,&MyGraphicsView::sendToMap,this,&Map::wheelEvent);
    connect(ui->graphicsView,&MyGraphicsView::sendToMap,this,&Map::on_MyGraphicsView_rubberBandChanged);
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
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_2->move(ui->graphicsView->mapFromScene(QPoint(850,560)).rx(),ui->graphicsView->mapFromScene(QPoint(850,560)).ry());
    float ratioreal=2.815478;
    int posy1=490,posy2;
    posy2=posy1-25;
    float leftx=ui->graphicsView->mapToScene(QPoint(60,posy1)).rx(),lefty=ui->graphicsView->mapToScene(QPoint(60,posy1)).ry();
    float kilox=ui->graphicsView->mapToScene(QPoint(140,140)).rx()-ui->graphicsView->mapToScene(QPoint(0,140)).rx(),kiloy=ui->graphicsView->mapToScene(QPoint(20,20)).ry()-ui->graphicsView->mapToScene(QPoint(20,0)).ry();
    itemline = new QGraphicsLineItem(leftx,lefty,ui->graphicsView->mapToScene(QPoint(60+200/ratioreal,posy1)).rx(),lefty);
    kilos->setText("200公里");
    kilos->setGeometry(ui->graphicsView->mapToScene(QPoint(60+200/ratioreal/2,posy2)).rx(),ui->graphicsView->mapToScene(QPoint(60+200/ratioreal/2,posy2)).ry(),kilox,kiloy);
    scene->addItem(itemline);
    scene->addWidget(kilos);
    kilos->setStyleSheet("background-color: transparent;");
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
    float ratioreal=(ui->graphicsView->mapFromScene(p).rx()-ui->graphicsView->mapFromScene(q).rx())/(double)(p.rx()-q.rx());
    ratioreal=2.815478/ratioreal;
    int posy1,posy2;
    if(mode==0){
        posy1=660;
    }
    else{
        posy1=490;
    }
    posy2=posy1-25;
    float leftx=ui->graphicsView->mapToScene(QPoint(60,posy1)).rx(),lefty=ui->graphicsView->mapToScene(QPoint(60,posy1)).ry();
    float kilox=ui->graphicsView->mapToScene(QPoint(140,140)).rx()-ui->graphicsView->mapToScene(QPoint(0,140)).rx(),kiloy=ui->graphicsView->mapToScene(QPoint(20,20)).ry()-ui->graphicsView->mapToScene(QPoint(20,0)).ry();
    QFont ft;
    if(kilos->isVisible()) scene->removeItem(itemline);
    if(ratioreal>2) {
        itemline = new QGraphicsLineItem(leftx,lefty,ui->graphicsView->mapToScene(QPoint(60+200/ratioreal,posy1)).rx(),lefty);
        kilos->setText("200公里");
        kilos->setGeometry(ui->graphicsView->mapToScene(QPoint(60+200/ratioreal/3,posy2)).rx(),ui->graphicsView->mapToScene(QPoint(0,posy2)).ry(),kilox,kiloy);
    }
    else if(ratioreal>=1) {
        itemline=new QGraphicsLineItem(leftx,lefty,ui->graphicsView->mapToScene(QPoint(60+100/ratioreal,posy1)).rx(),lefty);
        kilos->setText("100公里");
        kilos->setGeometry(ui->graphicsView->mapToScene(QPoint(60+100/ratioreal/3,posy2)).rx(),ui->graphicsView->mapToScene(QPoint(0,posy2)).ry(),kilox,kiloy);
    }
    else if(ratioreal>=0.5) {
        itemline=new QGraphicsLineItem(leftx,lefty,ui->graphicsView->mapToScene(QPoint(60+50/ratioreal,posy1)).rx(),lefty);
        kilos->setText("50公里");
        kilos->setGeometry(ui->graphicsView->mapToScene(QPoint(60+50/ratioreal/3,posy2)).rx(),ui->graphicsView->mapToScene(QPoint(0,posy2)).ry(),kilox,kiloy);
    }
    if(ratioreal<0.5){
        kilos->setVisible(false);
        return;
    }
    kilos->setVisible(true);
    QPen pen;  // creates a default pen
    if(1.5*ratioreal<1.0) pen.setWidth(1.0);
    else pen.setWidth(1.5*ratioreal);
    pen.setBrush(Qt::black);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    itemline->setPen(pen);
    scene->addItem(itemline);
    if(ratioreal>0.5) ft.setPointSize((int)4*ratioreal);
    else ft.setPointSize(2);
    kilos->setFont(ft);
    kilos->show();
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
        int i,times=0,datetimes=0,dateall=0,timenoon[6]={0,0,0,0,0,0},max=0,maxtime=0;
        QDate datepre,datenow;
        QStringList st;
        QString maxcompany="";
        int companytime[100];
        if(sortmode!=7 && myticketnum!=0) {
            QuickSort(userLogs,myticketnum,7,0);
            sortmode=7;
        }
        if(mode==1 && modeAD==0){
            ui->label_7->setText("城市：\n"+btn->objectName());
            for(i=0;i<myticketnum;i++){
                if(userLogs[i].sou.mid(0,btn->objectName().length()).contains(btn->objectName())) {
                    times++;
                    if(times==1) datenow=QDate::fromString(userLogs[i].curdate);
                    else{
                        datepre=datenow;
                        datenow=QDate::fromString(userLogs[i].curdate);
                        dateall+=abs(datepre.daysTo(datenow));
                        datetimes++;
                    }
                    if(timediffer("22:00",userLogs[i].time0)>0 || timediffer("02:00",userLogs[i].time0)<=0) timenoon[0]++;
                    else if(timediffer("02:00",userLogs[i].time0)>0 && timediffer("06:00",userLogs[i].time0)<=0) timenoon[1]++;
                    else if(timediffer("06:00",userLogs[i].time0)>0 && timediffer("10:00",userLogs[i].time0)<=0) timenoon[2]++;
                    else if(timediffer("10:00",userLogs[i].time0)>0 && timediffer("14:00",userLogs[i].time0)<=0) timenoon[3]++;
                    else if(timediffer("14:00",userLogs[i].time0)>0 && timediffer("18:00",userLogs[i].time0)<=0) timenoon[4]++;
                    else if(timediffer("18:00",userLogs[i].time0)>0 && timediffer("22:00",userLogs[i].time0)<=0) timenoon[5]++;
                    int j=0;
                    bool find=false;
                    foreach (QString company,st){
                        if(company==userLogs[i].company) {
                            find=true;
                            break;
                        }
                        j++;
                    }
                    if(find){
                        companytime[j]++;
                    }
                    else{
                        st.append(userLogs[i].company);
                        companytime[j]=1;
                    }
                }
            }
            ui->label_10->setText("始发次数：\n"+QString::number(times));
            if(!datenow.isNull()) ui->label_9->setText("最近出发日期：\n"+datenow.toString());
            else ui->label_9->setText("最近出发日期：\n未知");
            if(dateall!=0) ui->label_11->setText("平均出发间隔：\n"+QString::number(dateall/datetimes)+"天");
            else ui->label_11->setText("平均出发间隔：\n未知");
            for(i=0;i<6;i++){
                if(timenoon[i]>max){
                    max=timenoon[i];
                    maxtime=i;
                }
            }
            i=0;
            max=0;
            foreach(QString company,st){
                if(companytime[i]>max){
                    max=companytime[i];
                    maxcompany=company;
                }
                i++;
            }
            ui->label_12->setText("常乘航司：\n"+maxcompany);
            QString timenoons[6]={"半夜","凌晨","早上","中午","下午","晚上"};
            ui->label_13->setText("常选出发时间：\n"+timenoons[maxtime]);
        }
        else if(mode==1 && modeAD==1){
            ui->label_7->setText("城市：\n"+btn->objectName());
            for(i=0;i<myticketnum;i++){
                if(userLogs[i].des.mid(0,btn->objectName().length()).contains(btn->objectName())) {
                    times++;
                    if(times==1) datenow=QDate::fromString(userLogs[i].curdate);
                    else{
                        datepre=datenow;
                        datenow=QDate::fromString(userLogs[i].curdate);
                        dateall+=abs(datepre.daysTo(datenow));
                        datetimes++;
                    }
                    if(timediffer("22:00",userLogs[i].time1)>0 || timediffer("02:00",userLogs[i].time1)<=0) timenoon[0]++;
                    else if(timediffer("02:00",userLogs[i].time1)>0 && timediffer("06:00",userLogs[i].time1)<=0) timenoon[1]++;
                    else if(timediffer("06:00",userLogs[i].time1)>0 && timediffer("10:00",userLogs[i].time1)<=0) timenoon[2]++;
                    else if(timediffer("10:00",userLogs[i].time1)>0 && timediffer("14:00",userLogs[i].time1)<=0) timenoon[3]++;
                    else if(timediffer("14:00",userLogs[i].time1)>0 && timediffer("18:00",userLogs[i].time1)<=0) timenoon[4]++;
                    else if(timediffer("18:00",userLogs[i].time1)>0 && timediffer("22:00",userLogs[i].time1)<=0) timenoon[5]++;
                    int j=0;
                    bool find=false;
                    foreach (QString company,st){
                        if(company==userLogs[i].company) {
                            find=true;
                            break;
                        }
                        j++;
                    }
                    if(find){
                        companytime[j]++;
                    }
                    else{
                        st.append(userLogs[i].company);
                        companytime[j]=1;
                    }
                }
            }
            ui->label_10->setText("到达次数：\n"+QString::number(times));
            if(!datenow.isNull()) ui->label_9->setText("最近到达日期：\n"+datenow.toString());
            else ui->label_9->setText("最近到达日期：\n未知");
            if(dateall!=0) ui->label_11->setText("平均到达间隔：\n"+QString::number(dateall/datetimes)+"天");
            else ui->label_11->setText("平均到达间隔：\n未知");
            for(i=0;i<6;i++){
                if(timenoon[i]>max){
                    max=timenoon[i];
                    maxtime=i;
                }
            }
            i=0;
            max=0;
            foreach(QString company,st){
                if(companytime[i]>max){
                    max=companytime[i];
                    maxcompany=company;
                }
                i++;
            }
            ui->label_12->setText("常乘航司：\n"+maxcompany);
            QString timenoons[6]={"半夜","凌晨","早上","中午","下午","晚上"};
            ui->label_13->setText("常选到达时间：\n"+timenoons[maxtime]);
        }
        else{
            if(ui->label_3->text()=="始发地：请点击始发地") ui->label_3->setText("始发地："+btn->objectName());
            else ui->label_4->setText("目的地："+btn->objectName());
        }
    }
}

void addcursorline(int x1,int x2,int y1,int y2,int line,int color,QGraphicsScene *scene){
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
        if(color==0) pen.setBrush(QColor(0,109,49,100));
        else if(color==1) pen.setBrush(Qt::blue);
        else pen.setBrush(Qt::red);
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
        if(color==0) pen.setBrush(QColor(0,109,49,100));
        else if(color==1) pen.setBrush(Qt::blue);
        else pen.setBrush(Qt::red);
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
        if(mode==1 && modemul==0){
            int i,j,begin,end;
            int souToDes[16][16];
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
                    souToDes[i][j]=0;
                }
            }
            for(i=0;i<myticketnum;i++){
                for(begin=0;begin<16;begin++){
                    if(userLogs[i].sou.mid(0,citys[begin].length()).contains(citys[begin])) break;
                }
                for(end=0;end<16;end++){
                    if(userLogs[i].des.mid(0,citys[end].length()).contains(citys[end])) break;
                }
                souToDes[begin][end]++;
                //addcursorline(cityp[begin].rx(),cityp[end].rx(),cityp[begin].ry(),cityp[end].ry(),1,1,scene);
            }
            for(i=0;i<16;i++){
                for(j=0;j<i;j++){
                    bool from=false,to=false;
                    int max;
                    if(souToDes[i][j]>0) from=true;
                    if(souToDes[j][i]>0) to=true;
                    if(from){
                        if(souToDes[i][j]>4) max=0;
                        else if(souToDes[i][j]>1) max=1;
                        else max=2;
                        addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),1,max,scene);
                    }
                    if(to){
                        if(souToDes[j][i]>4) max=0;
                        else if(souToDes[j][i]>1) max=1;
                        else max=2;
                        addcursorline(cityp[j].rx(),cityp[i].rx(),cityp[j].ry(),cityp[i].ry(),1,max,scene);
                    }
                }
            }
            ui->pushButton_4->setText("清除航线");
        }
        else if(mode==1 && modemul==1){
            int i,j,begin,end;
            int souToDes[16][16];
            for(i=0;i<16;i++){
                for(j=0;j<16;j++){
                    souToDes[i][j]=0;
                }
            }
            for(i=0;i<myticketnum;i++){
                if(userLogs[i].next==NULL){
                    for(begin=0;begin<16;begin++){
                        if(userLogs[i].sou.mid(0,citys[begin].length()).contains(citys[begin])) break;
                    }
                    for(end=0;end<16;end++){
                        if(userLogs[i].des.mid(0,citys[end].length()).contains(citys[end])) break;
                    }
                    souToDes[begin][end]++;
                }
                else{
                    Log *p=&userLogs[i];
                    while(p->next!=NULL){
                        p=p->next;
                        for(begin=0;begin<16;begin++){
                            if(p->sou.mid(0,citys[begin].length()).contains(citys[begin])) break;
                        }
                        for(end=0;end<16;end++){
                            if(p->des.mid(0,citys[end].length()).contains(citys[end])) break;
                        }
                        souToDes[begin][end]++;
                    }
                }
            }
            for(i=0;i<16;i++){
                for(j=0;j<i;j++){
                    bool from=false,to=false;
                    int max;
                    if(souToDes[i][j]>0) from=true;
                    if(souToDes[j][i]>0) to=true;
                    if(souToDes[i][j]>souToDes[j][i]) max=souToDes[i][j];
                    else max=souToDes[j][i];
                    if(to && from) {
                        if(max>4) max=0;
                        else if(max>1) max=1;
                        else max=2;
                        addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),2,max,scene);
                    }
                    else if(from){
                        if(souToDes[i][j]>4) max=0;
                        else if(souToDes[i][j]>1) max=1;
                        else max=2;
                        addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),1,max,scene);
                    }
                    else if(to){
                        if(souToDes[j][i]>4) max=0;
                        else if(souToDes[j][i]>1) max=1;
                        else max=2;
                        addcursorline(cityp[j].rx(),cityp[i].rx(),cityp[j].ry(),cityp[i].ry(),1,max,scene);
                    }
                }
            }
            ui->pushButton_4->setText("清除航线");
        }
        else{
            int i,j;
            for(i=0;i<16;i++){
                for(j=i+1;j<16;j++){
                    addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),1,0,scene);
                }
            }
            ui->pushButton_4->setText("清除航线");
        }
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
    int i,j,num0=0,num1=0;
    for(i=0;i<16;i++){
        for(j=i+1;j<16;j++){
            count0=0;
            count1=0;
            num0=0;
            num1=0;
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[i] + "-" + citys[j] + ".txt";
            QFile fs(fname);
            if(fs.open(QIODeviceBase::ReadOnly)){
                count0=1;
                QTextStream in(&fs);
                in.setEncoding(QStringConverter::System);
                while (in.atEnd()==false){
                    QString info0=in.readLine();
                    num0++;
                }
            }
            fs.close();
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[j]+"-"+citys[i]+".txt";
            QFile fs1(fname);
            if(fs1.open(QIODeviceBase::ReadOnly)){
                count1=1;
                QTextStream in(&fs1);
                in.setEncoding(QStringConverter::System);
                while (in.atEnd()==false){
                    QString info0=in.readLine();
                    num1++;
                }
            }
            fs1.close();
            if(num0>num1) num0=num1;
            if(num0>10) num0=0;
            else if(num0>6) num0=1;
            else num0=2;
            if((count0+count1)==2) addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),2,num0,scene);
            else if(count0==1) addcursorline(cityp[i].rx(),cityp[j].rx(),cityp[i].ry(),cityp[j].ry(),1,num0,scene);
            else if(count1==1) addcursorline(cityp[j].rx(),cityp[i].rx(),cityp[j].ry(),cityp[i].ry(),1,num0,scene);
            else{}
        }
    }
    ui->pushButton_4->setText("清除航线");
}
QPoint* Map::getcityp(){
    return cityp;
}

void Map::on_pushButton_7_clicked()
{
    if(modeAD==0){
        modeAD=1;
        ui->pushButton_7->setText("始发模式");
    }
    else{
        modeAD=0;
        ui->pushButton_7->setText("到达模式");
    }
}

void Map::on_checkBox_stateChanged(int arg1)
{
    if(arg1) {
        modemul=1;
        ui->pushButton_4->setText("清除航线");
        on_pushButton_4_clicked();
    }
    else {
        modemul=0;
        ui->pushButton_4->setText("清除航线");
        on_pushButton_4_clicked();
    }
}

