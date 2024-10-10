#include "ticketwindow.h"
#include "ui_ticketwindow.h"
#include "QuickSort.h"
#include "ticketinfo.h"

ticketWindow::ticketWindow(Log* tlog,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ticketWindow)
{
    ui->setupUi(this);
    this->tlog=tlog;
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
    this->close();
}


void ticketWindow::on_pushButton_2_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    emit sendToMainWindow(tlog);
    this->close();
}

