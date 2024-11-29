#include "userrankinfo.h"
#include "ui_userrankinfo.h"

userRankInfo::userRankInfo(QString name,int rank,int number,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userRankInfo)
{
    ui->setupUi(this);
    ui->label->setText(QString::number(rank));
    ui->label_2->setText(name);
    ui->label_3->setText(QString::number(number));
}

userRankInfo::~userRankInfo()
{
    delete ui;
}
