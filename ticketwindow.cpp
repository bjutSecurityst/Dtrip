#include "ticketwindow.h"
#include "ui_ticketwindow.h"
#include "QuickSort.h"

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
    if(p->next!=NULL) p=p->next;
    while(p!=NULL){
        QLabel* q=new QLabel("航班号："+p->ID);
        q->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        q->wordWrap();
        ui->verticalLayout->addWidget(q);
        p=p->next;
    }
}

ticketWindow::~ticketWindow()
{
    delete ui;
}
