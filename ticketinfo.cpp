#include "ticketinfo.h"
#include "ui_ticketinfo.h"
#include "QuickSort.h"
QString timeDifferString(QString time0,QString time1,int mode,QString date0,QString date1);
ticketInfo::ticketInfo(Log* my,int mode,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ticketInfo)
{
    ui->setupUi(this);
    int i=0,j;
    tlog=my;
    this->mode=mode;
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    QString company=my->company,ID=my->ID,sou=my->sou,des=my->des,time0=my->time0,time1=my->time1,chi=my->chi;
    int price=my->price;
    Log* next=my->next;
    QString time_split=timeDifferString(time0,time1,1,my->curdate,my->curdate);
    QImage img;
    if(company=="中国国航"||company=="春秋航空") img.load(pathCreator("CA.png"));
    else if(company=="山东航空"||company=="南方航空") img.load(pathCreator("CZ.png"));
    else img.load(pathCreator("MU.png"));
    ui->label->setPixmap(QPixmap::fromImage(img));
    Log* p=next;
    QString a="";
    QString IDS=ID,timeload;
    bool ID_visible=true;
    if(p!=nullptr && p->company!="" && mode!=1){
        timeload=p->time1;
        QString date0=p->curdate;
        i=0;
        while(p->next!=nullptr){
            p=p->next;
            if(p->company!=company) ID_visible=false;
            a=a+"\n"+p->sou+timeDifferString(timeload,p->time0,0,date0,p->curdate);
            timeload=p->time1;
            date0=p->curdate;
            IDS=IDS+"\n"+p->ID;
            i++;
        }
    }
    ui->label_2->setText(company);
    if(ID_visible || mode==1) ui->label_3->setText(IDS);
    else ui->label_3->setText(ID+"\n"+"多个航司，"+QString::number(i+1)+"程航班");
    ui->label_7->setText(time0);
    ui->label_8->setText(sou);
    ui->label_9->setText(time1);
    ui->label_10->setText(des);
    ui->label_5->setText(time_split);
    if(my->business && (mode!=0&&mode!=1)) ui->label_6->setText(QString::number(price*2));
    else ui->label_6->setText(QString::number(price));
    if(i==0 || mode==1) ui->label_11->setText("直飞");
    else ui->label_11->setText("转机"+QString::number(i)+"次,转:"+a);
    ui->pushButton->setText("订票");
    QImage img0;
    img0.load(pathCreator("横杠.png"));
    ui->label_4->setPixmap(QPixmap::fromImage(img0));
    if(mode==1){
        ui->pushButton_2->setStyleSheet("border: 2px solid lightblue; border-radius: 10px; background-color: white;");
        ui->pushButton->setDisabled(true);
        ui->pushButton->setVisible(false);
        ui->label_8->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_7->setAlignment(Qt::AlignTop);
        ui->label_9->setAlignment(Qt::AlignTop);
        ui->horizontalSpacer->changeSize(0, 0);
        if(mode==5) {
            if(tlog->business) ui->label_6->setText("差价："+QString::number(price*2)+"￥");
            else ui->label_6->setText("差价："+QString::number(price)+"￥");
        }
        else ui->label_6->setText("单价："+QString::number(price)+"￥");
        ui->label_6->setMinimumWidth(180);
        ui->label_6->setStyleSheet("font: 14pt Microsoft Sans Serif;color: rgb(255, 160, 8)");
        ui->label_12->setText("准点率："+chi);
        QLabel* a=new QLabel(sou);
        a->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        a->wordWrap();
        ui->horizontalLayout->addWidget(a);
        QVBoxLayout* v=new QVBoxLayout();
        ui->horizontalLayout->addLayout(v);
        QLabel* b=new QLabel(" -------------> ");
        b->setAlignment(Qt::AlignBottom);
        b->setStyleSheet("font-size:12pt; color:rgb(0,60,200);");
        b->wordWrap();
        v->addWidget(b);
        QLabel* ldate=new QLabel(my->curdate);
        ldate->setAlignment(Qt::AlignTop);
        b->setStyleSheet("font-size:10pt; color:rgb(0,60,200);");
        b->wordWrap();
        v->addWidget(ldate);
        v->setStretch(5,3);
        QLabel* c=new QLabel(des);
        c->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        c->wordWrap();
        ui->horizontalLayout->addWidget(c);
        QLabel* d=new QLabel(" 计划起飞：");
        d->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        d->wordWrap();
        ui->verticalLayout_2->insertWidget(0, d);
        QLabel* e=new QLabel(" 计划到达：");
        e->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        e->wordWrap();
        ui->verticalLayout_3->insertWidget(0, e);
    }
    else {
        ui->pushButton_2->setVisible(false);
        ui->horizontalSpacer_2->changeSize(0, 0);
        ui->label_12->setVisible(false);
        ui->line->setVisible(false);
        ui->line_2->setVisible(false);
        ui->line_3->setVisible(false);
    }
    // 0：普通票 1：长票 2：普通隐藏 3：查看票 4：改签票 5：差价隐藏
    if(mode==2 || mode==5) ui->pushButton->setVisible(false);
    else if(mode==3) ui->pushButton->setText("查看");
    else if(mode==4) ui->pushButton->setText("改签");
    if(mode!=3) {
        ui->label_13->setVisible(false);
    }
    else {
        ui->label_13->setVisible("true");
        ui->label_13->setText("PID: "+my->PID);
        ui->label_12->setVisible(true);
        ui->line_3->setVisible(true);
        ui->label_12->setText("准点率："+chi);
        ui->horizontalSpacer->changeSize(0, 0);
        QLabel* ldate=new QLabel(my->curdate);
        ui->horizontalLayout->addWidget(ldate);
        QLabel* business,*num;
        if(my->business) business=new QLabel("商务舱");
        else business=new QLabel("经济舱");
        business->setStyleSheet("font: 700 12pt Microsoft YaHei UI");
        num=new QLabel(QString::number(my->num)+"张");
        ui->verticalLayout_6->addWidget(ldate);
        ui->horizontalLayout->addWidget(business);
        ui->horizontalLayout->addWidget(num);
        QSpacerItem* sp1=new QSpacerItem(20,40,QSizePolicy::Expanding,QSizePolicy::Minimum);
        ui->horizontalLayout->addItem(sp1);
    }
    if(my->status!=""){
        ui->pushButton->setText("已"+my->status);
        ui->pushButton->setFlat(true);
        ui->pushButton->setEnabled(false);
        ui->pushButton->setStyleSheet("font-size:12pt; color:rgb(255,0,0);");
    }
}
ticketInfo::ticketInfo(Log* my,Log* clog,int mode,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ticketInfo)
{
    ui->setupUi(this);
    int i=0,j;
    tlog=my;
    this->mode=mode;
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    QString company=my->company,ID=my->ID,sou=my->sou,des=my->des,time0=my->time0,time1=my->time1,chi=my->chi;
    int price=my->price;
    Log* next=my->next;
    QString time_split=timeDifferString(time0,time1,1,my->curdate,my->curdate);
    QImage img;
    if(company=="中国国航"||company=="春秋航空") img.load(pathCreator("CA.png"));
    else if(company=="山东航空"||company=="南方航空") img.load(pathCreator("CZ.png"));
    else img.load(pathCreator("MU.png"));
    ui->label->setPixmap(QPixmap::fromImage(img));
    Log* p=next;
    QString a="";
    QString IDS=ID,timeload;
    bool ID_visible=true;
    ui->pushButton->setVisible(true);
    if(my->company=="没有航空公司") {
        ui->pushButton->setDisabled(true);
        ui->pushButton->setVisible(false);
    }
    if(p!=nullptr && p->company!="" && mode!=1){
        timeload=p->time1;
        QString date0=p->curdate;
        i=0;
        while(p->next!=nullptr){
            p=p->next;
            if(p->company!=company) ID_visible=false;
            a=a+"\n"+p->sou+timeDifferString(timeload,p->time0,0,date0,p->curdate);
            timeload=p->time1;
            date0=p->curdate;
            IDS=IDS+"\n"+p->ID;
            i++;
        }
    }
    ui->label_2->setText(company);
    if(ID_visible || mode==1) ui->label_3->setText(IDS);
    else ui->label_3->setText(ID+"\n"+"多个航司，"+QString::number(i+1)+"程航班");
    ui->label_7->setText(time0);
    ui->label_8->setText(sou);
    ui->label_9->setText(time1);
    ui->label_10->setText(des);
    ui->label_5->setText(time_split);
    if(mode==4) {
        if(tlog->business) ui->label_6->setText(QString::number((price-clog->price)*2));
        else ui->label_6->setText(QString::number(price-clog->price));
        ui->label_6->setStyleSheet("font: 14pt Microsoft Sans Serif;color: rgb(255, 160, 8)");
    }
    else if(mode==5) {
        if(tlog->business) ui->label_6->setText("差价："+QString::number((price-clog->price)*2)+"￥");
        else ui->label_6->setText("差价："+QString::number(price-clog->price)+"￥");
        ui->label_6->setStyleSheet("font: 14pt Microsoft Sans Serif;color: rgb(255, 160, 8)");
    }
    else ui->label_6->setText(QString::number(price));
    if(i==0 || mode==1) ui->label_11->setText("直飞");
    else ui->label_11->setText("转机"+QString::number(i)+"次,转:"+a);
    ui->pushButton->setText("订票");
    QImage img0;
    img0.load(pathCreator("横杠.png"));
    ui->label_4->setPixmap(QPixmap::fromImage(img0));
    if(mode==1){
        ui->pushButton_2->setStyleSheet("border: 2px solid lightblue; border-radius: 10px; background-color: white;");
        ui->pushButton->setDisabled(true);
        ui->pushButton->setVisible(false);
        ui->label_8->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_7->setAlignment(Qt::AlignTop);
        ui->label_9->setAlignment(Qt::AlignTop);
        ui->horizontalSpacer->changeSize(0, 0);
        ui->label_6->setText("单价："+QString::number(price)+"￥");
        ui->label_6->setMinimumWidth(180);
        ui->label_6->setStyleSheet("font: 14pt Microsoft Sans Serif;color: rgb(255, 160, 8)");
        ui->label_12->setText("准点率："+chi);
        QLabel* a=new QLabel(sou);
        a->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        a->wordWrap();
        ui->horizontalLayout->addWidget(a);
        QVBoxLayout* v=new QVBoxLayout();
        ui->horizontalLayout->addLayout(v);
        QLabel* b=new QLabel(" -------------> ");
        b->setAlignment(Qt::AlignBottom);
        b->setStyleSheet("font-size:12pt; color:rgb(0,60,200);");
        b->wordWrap();
        v->addWidget(b);
        QLabel* ldate=new QLabel(my->curdate);
        ldate->setAlignment(Qt::AlignTop);
        b->setStyleSheet("font-size:10pt; color:rgb(0,60,200);");
        b->wordWrap();
        v->addWidget(ldate);
        v->setStretch(5,3);
        QLabel* c=new QLabel(des);
        c->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        c->wordWrap();
        ui->horizontalLayout->addWidget(c);
        QLabel* d=new QLabel(" 计划起飞：");
        d->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        d->wordWrap();
        ui->verticalLayout_2->insertWidget(0, d);
        QLabel* e=new QLabel(" 计划到达：");
        e->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        e->wordWrap();
        ui->verticalLayout_3->insertWidget(0, e);
    }
    else {
        ui->pushButton_2->setVisible(false);
        ui->horizontalSpacer_2->changeSize(0, 0);
        ui->label_12->setVisible(false);
        ui->line->setVisible(false);
        ui->line_2->setVisible(false);
        ui->line_3->setVisible(false);
    }
    if(mode==2 || mode==5) ui->pushButton->setVisible(false);
    else if(mode==3) ui->pushButton->setText("查看");
    else if(mode==4) ui->pushButton->setText("改签");
    ui->label_13->setVisible(false);
}
ticketInfo::~ticketInfo()
{
    delete ui;
    if(mode==2 && (tlog->company=="没有航空公司"||tlog->company=="您还没有登录"||tlog->company=="您还没有订票"||tlog->company=="没有该日机票")) delete tlog;
}
//字符串计算相差时间函数
QString timeDifferString(QString time0,QString time1,int mode,QString date0,QString date1){
    int time0h,time0m,time1h,time1m,i=0,j=0,times_h,times_m;
    int dayplus0=0,dayplus1=0;
    QString time1_withplus,time0_withplus;
    QString time_split;
    QStringList time0l=time0.split(':');
    QStringList time1l=time1.split(':');
    foreach (QString item, time0l) {
        switch(i){
        case(0):time0h=item.toInt();break;
        case(1):time0_withplus=item;break;
        }
        i++;
    }
    i=0;
    QStringList time0ml=time0_withplus.split('+');
    foreach (QString item, time0ml) {
        switch(i){
        case(0):time0m=item.toInt();break;
        case(1):if(item=="1") dayplus0=1;else dayplus0=2;break;
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
        case(1):if(item=="1") dayplus1=1;else dayplus1=2;break;
        }
        i++;
    }
    times_m=time1m-time0m;
    int dayplus=dayplus1-dayplus0;
    if(dayplus!=0) times_h=time1h-time0h+24*dayplus;
    else times_h=time1h-time0h;
    if(times_m<0) {
        times_m+=60;
        times_h-=1;
    }
    QDate qdate0=QDate::fromString(date0);
    QDate qdate1=QDate::fromString(date1);
    int a=qdate0.daysTo(qdate1);
    if(a!=0) times_h+=24*a;
    if(mode==0) return time_split=QString::number(times_h)+"h"+QString::number(times_m)+ "m";
    else if(time0=="00:00" && time1=="25:00") return time_split="当前查询条件\n下今天内无法完\n成转机";
    else return time_split=QString::number(times_h)+"小时"+QString::number(times_m)+ "分";
}


void ticketInfo::on_pushButton_clicked()
{
    if(mode==0) emit sendToMainWindow(tlog,0);
    else if(mode==3) emit sendToMainWindow(tlog,1);
    else if(mode==4) emit sendToMainWindow(tlog,2);
}

