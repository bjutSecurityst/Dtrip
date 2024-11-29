#include "ranking.h"
#include "ui_ranking.h"
#include "myopenglwidget.h"
#include "mysqlite.h"
#include "userrankinfo.h"
#include <QCheckBox>
ranking::ranking(QString username,int mode,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ranking)
{
    ui->setupUi(this);
    this->mode=mode;
    this->username=username;
    userRank(mode);
    if(myrank==1) m=new MyOpenGLWidget(1,nullptr);
    else m=new MyOpenGLWidget(0,nullptr);
    ui->verticalLayout_2->addWidget(m);
    m->setGeometry(10,10,300,200);
    m->show();
    QWidget *wid=new QWidget();
    QVBoxLayout *l=new QVBoxLayout();
    for(int i=0;i<names->size();i++){
        userRankInfo *info0=new userRankInfo(names->at(i),i+1,costs[i]);
        l->addWidget(info0);
    }
    wid->setLayout(l);
    ui->scrollArea_2->setWidget(wid);
    QPalette pa = ui->scrollArea_2->palette();

    pa.setBrush(QPalette::Window, Qt::transparent);

    ui->scrollArea_2->setPalette(pa);
    ui->label_9->setText(username);
    if(myrank!=0) ui->label_10->setText("我的排名：第"+QString::number(myrank));
    if(mode==0) ui->label_11->setText("累销："+QString::number(mycosts)+"￥");
    else ui->label_11->setText("里程："+QString::number(mycosts)+"km");
    if(myrank!=0) ui->label_12->setText("第"+QString::number(myrank));
    else ui->label_12->setText("第∞");
    if(myrank<=10 && myrank!=1){
        ui->label_13->setText("第"+QString::number(myrank-1));
        if(costs[myrank-2]!=0 && mycosts!=0) ui->progressBar_2->setValue(mycosts/(float)costs[myrank-2]*100);
        else ui->progressBar_2->setValue(0);
        ui->label_14->setText(QString("当前积分%1，距离第%2名 还需要%3").arg(mycosts).arg(myrank-1).arg(costs[myrank-2]-mycosts));
    }
    else if(myrank==1){
        ui->label_13->setText("登顶");
        ui->progressBar_2->setValue(100);
        ui->label_14->setVisible(false);
    }
    else {
        ui->label_13->setText("第十");
        if(costs[9]!=0 && mycosts!=0) ui->progressBar_2->setValue(mycosts/(float)costs[9]*100);
        else ui->progressBar_2->setValue(0);
        ui->label_14->setText(QString("当前积分%1，距离第十名 还需要%3").arg(mycosts).arg(costs[9]-mycosts));
    }
    champion=new QLabel("champion\n "+names->at(0));
    champion->setParent(this);
    champion->setGeometry(80,55,200,80);
    r=100,g=160,b=230;
    champion->setStyleSheet("font: 28pt 'Mistral'; color:rgb(100,160,230)");
    timer=new QTimer;
    timer->start(50);
    connect(timer,&QTimer::timeout,this,&ranking::Timerout);
}

ranking::~ranking()
{
    delete ui;
}

void ranking::userRank(int mode){
    if(mode==1){
        names->clear();
        for(int i=0;i<10;i++){
            costs[i]=0;
        }
        mycosts=0;
        myrank=0;
        getuserinfokilo(names,costs,username,mycosts,myrank);
    }
    else{
        names->clear();
        for(int i=0;i<10;i++){
            costs[i]=0;
        }
        mycosts=0;
        myrank=0;
        getuserinfocost(names,costs,username,mycosts,myrank);
    }
}

void ranking::on_pushButton_2_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    this->close();
}
void ranking::Timerout(){
    r=(r+3)%256;
    g=(g+3)%256;
    b=(b+3)%256;
    champion->setStyleSheet(QString("font: 28pt 'Mistral'; color:rgb(%1,%2,%3)").arg(r).arg(g).arg(b));
}
