#include "ticketwindow.h"
#include "ui_ticketwindow.h"
#include "QuickSort.h"
#include "ticketinfo.h"

ticketWindow::ticketWindow(Log* tlog,int mode,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ticketWindow)
{
    ui->setupUi(this);
    this->tlog=tlog;
    this->mode=mode;
    QImage img;
    img.load(pathCreator("caC919.png"));
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->pushButton->setStyleSheet("border: 2px solid #009ef9; border-radius: 15px; background-color: white;");
    Log *p=tlog;
    ticketInfo* ticket0=new ticketInfo(p,2);
    ticket0->setParent(this);
    ticket0->setGeometry(435,420,680,100);
    QFile file(pathCreator("qss/登录.qss"));
    //QFile file("登录.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    ui->pushButton_2->setStyleSheet(styleSheet);
    if(mode==1) {
        ui->pushButton_2->setText("退票");
        ui->pushButton_3->setText("改签");
        ui->pushButton_4->setVisible(true);
    }
    else if(mode==2){
        ui->pushButton_2->setText("改签");
        ui->pushButton_3->setText("返回");
        ui->pushButton_4->setVisible(false);
    }
    else ui->pushButton_4->setVisible(false);
    if(p->next!=NULL) p=p->next;
    while(p!=NULL){
        QLabel* q=new QLabel("航班号："+p->ID);
        q->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        q->wordWrap();
        ui->verticalLayout->addWidget(q);
        ticketInfo* ticket=new ticketInfo(p,1);
        QSizePolicy sp = ticket->sizePolicy();
        //修改第一个的水平策略为 Fixed
        sp.setHorizontalPolicy(QSizePolicy::Expanding);
        ticket->setSizePolicy(sp);
        ui->verticalLayout_2->addWidget(ticket);
        p=p->next;
    }
}

ticketWindow::ticketWindow(Log* tlog,int mode,Log* clog,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ticketWindow)
{
    ui->setupUi(this);
    this->tlog=tlog;
    this->clog=clog;
    this->mode=mode;
    QImage img;
    img.load(pathCreator("caC919.png"));
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->pushButton->setStyleSheet("border: 2px solid #009ef9; border-radius: 15px; background-color: white;");
    Log *p=tlog;
    ticketInfo* ticket0=new ticketInfo(p,clog,5);
    ticket0->setParent(this);
    ticket0->setGeometry(435,420,680,100);
    QFile file(pathCreator("qss/登录.qss"));
    //QFile file("登录.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    ui->pushButton_2->setStyleSheet(styleSheet);
    ui->pushButton_2->setText("改签");
    ui->pushButton_3->setText("返回");
    ui->pushButton_4->setVisible(false);
    if(p->next!=NULL) p=p->next;
    while(p!=NULL){
        QLabel* q=new QLabel("航班号："+p->ID);
        q->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        q->wordWrap();
        ui->verticalLayout->addWidget(q);
        ticketInfo* ticket=new ticketInfo(p,1);
        QSizePolicy sp = ticket->sizePolicy();
        //修改第一个的水平策略为 Fixed
        sp.setHorizontalPolicy(QSizePolicy::Expanding);
        ticket->setSizePolicy(sp);
        ui->verticalLayout_2->addWidget(ticket);
        p=p->next;
    }
}

ticketWindow::~ticketWindow()
{
    delete ui;
}

void ticketWindow::on_pushButton_3_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    if(mode==1) emit changeTicket(tlog);
    else emit Exit();
    this->close();
}


void ticketWindow::on_pushButton_2_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    if(mode==0) emit sendToMainWindow(tlog);
    else if(mode==2) emit change(tlog);
    else emit refund(tlog);
    this->close();
}


void ticketWindow::on_pushButton_4_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    emit Exit();
    this->close();
}

