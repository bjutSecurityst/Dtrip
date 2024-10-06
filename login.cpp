#include "login.h"
#include "ui_login.h"
#include <QUrl>
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include "QuickSort.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose,false);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QString display1="服务政策";
    QString urlStyle1="<a style='color:blue; text-decoration:none;' href=https://contents.ctrip.com/huodong/privacypolicypc/index?type=0>";
    QString display2="个人信息保护政策";
    QString urlStyle2="<a style='color:blue; text-decoration:none;' href=https://contents.ctrip.com/huodong/privacypolicypc/index?type=1>";
    ui->label_5->setText(QString("阅读并同意Dtrip的%1%2").arg(urlStyle1).arg(display1));
    ui->label_6->setText(QString("和%1%2").arg(urlStyle2).arg(display2));
    connect(ui->label_5, &QLabel::linkActivated, [=](QString url){
        QDesktopServices::openUrl(QUrl(url));
    });
    connect(ui->label_6, &QLabel::linkActivated, [=](QString url){
        QDesktopServices::openUrl(QUrl(url));
    });
    ui->pushButton_4->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px; background-color: white;");
    ui->pushButton_2->setStyleSheet("border-radius: 5px; background-color: #FFCF4C; selection-background-color: #F0CF5C");
    ui->pushButton_3->setStyleSheet("text-align:left;");
    ui->pushButton_5->setStyleSheet("text-align:right;");
    QFile file(pathCreator("qss/登录.qss"));
    //QFile file("登录.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    ui->pushButton_2->setStyleSheet(styleSheet);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_5_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    this->close();
}

