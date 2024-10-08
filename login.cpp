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
#include "sqlite3.h"
#pragma comment(lib,"sqlcipher.LIB")

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
    ui->label_2->setVisible(false);
    ui->label_7->setVisible(false);
    ui->radioButton_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->lineEdit_4->setVisible(false);
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


void Login::on_pushButton_2_clicked()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("SQLITECIPHER","read_connection");
    qDebug() << QSqlDatabase::drivers();
    bool dbExist = QFile::exists(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
    if (dbExist)
    {
        QSqlDatabase database2;
        database2 = QSqlDatabase::addDatabase("QSQLITE","read_connection_2");
        database2.setDatabaseName(pathCreator("dbs/users.db"));
        database2.setUserName("root");
        database2.setPassword("123456");
        //database.setConnectOptions("QSQLITE_USE_CIPHER=aes128cbc;");
        if (!database2.open())
        {
            qDebug() << "Error: Failed to connect database." << database2.lastError();
            ui->lineEdit->setText("查询失败");
        }
        else
        {
            //获取数据
            QString last_log = QString("select * from users where name = '%1'").arg(ui->lineEdit->text());
            QString password,question;
            QSqlQuery query;
            database.setDatabaseName(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
            database.setUserName(ui->lineEdit->text());
            database.setPassword(ui->lineEdit_2->text());
            database.setConnectOptions("QSQLITE_USE_CIPHER=aes128cbc");
            if (!database.open())
            {
                qDebug() << "Error: Failed to connect database." << database.lastError();
                database.close();
                QSqlDatabase::removeDatabase("read_connection");
                QSqlDatabase::removeDatabase("read_connection_2");
                return;
            }
            else
            {
                QString company,ID,sou,des,time0,time1,chi;
                Log *p,*q;
                int price=0,j=0,next;
                query.exec("SELECT * FROM users");
                if(!query.exec())
                {
                    qDebug() << "Error: Fail to query table. " << query.lastError();
                }
                else
                {
                    while(query.next())
                    {
                        company = query.value(1).toString();
                        ID = query.value(2).toString();
                        sou = query.value(3).toString();
                        des = query.value(4).toString();
                        time0 = query.value(5).toString();
                        time1 = query.value(6).toString();
                        price = query.value(7).toInt();
                        chi = query.value(8).toString();
                        next = query.value(9).toInt();
                        if(next==1){
                            logs[j].setLog(company,ID,sou,des,time0,time1,price,chi);
                            logs[j].next=NULL;
                            p=&logs[j];
                            j++;
                        }
                        else{
                            Log* log0=new Log();
                            log0->setLog(company,ID,sou,des,time0,time1,price,chi);
                            log0->next=NULL;
                            p->next=log0;
                            p=p->next;
                        }
                    }
                    myticketnum=j;
                }
                database.close();
            }
            query.exec(last_log);
            qDebug() << "success!";
            while(query.next()){
                password = query.value("password").toString();
                question = query.value("question").toString();
            }
            qDebug() << password << question;
        }
        database2.close();
        name=ui->lineEdit->text();
        QSqlDatabase::removeDatabase("read_connection");
        QSqlDatabase::removeDatabase("read_connection_2");
        emit sendToMainWindow(name,logs,myticketnum);
        this->close();
    }
    else
    {
        if(log_mode==0) {
            log_mode=1;
            ui->label_2->setVisible(true);
            ui->label_7->setVisible(true);
            ui->radioButton_2->setVisible(true);
            ui->lineEdit_3->setVisible(true);
            ui->lineEdit_4->setVisible(true);
            ui->pushButton_2->setDisabled(true);
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            return;
        }
        qDebug() << pathCreator("dbs/"+ui->lineEdit->text()+".db");
        database.setDatabaseName(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
        database.setUserName(ui->lineEdit->text());
        database.setPassword(ui->lineEdit_2->text());
        database.setConnectOptions("QSQLITE_USE_CIPHER=aes128cbc");
        if (!database.open())
        {
            qDebug() << "Error: Failed to connect database." << database.lastError();
        }
        else
        {
            //创建表格
            QSqlQuery sql_query(database);
            QString create_sql = "create table ticket (uid int primary key, name varchar(30), id varchar(30), sou varchar(30), des varchar(30), time0 varchar(30), time1 varchar(30), price int, chi varchar(30), next int)";
            sql_query.prepare(create_sql);
            if(!sql_query.exec())
            {
                qDebug() << "Error: Fail to create table." << sql_query.lastError();
            }
            else
            {
                qDebug() << "Table created!";
            }
            database.close();
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            QSqlDatabase database2;
            database2 = QSqlDatabase::addDatabase("QSQLITE","read_connection");
            database2.setDatabaseName(pathCreator("dbs/users.db"));
            database2.setUserName("root");
            database2.setPassword("123456");
            if (!database2.open())
            {
                qDebug() << "Error: Failed to connect database." << database2.lastError();
            }
            else
            {
                //插入数据
                QSqlQuery sql_query2(database2);
                sql_query2.exec("SELECT uid FROM users ORDER BY uid DESC LIMIT 1");
                int max_number;
                if(!sql_query2.next()){
                    qDebug() << "Error: Fail to read." << sql_query2.lastError();
                    max_number=0;
                }
                else
                {
                    qDebug() << "success!";
                    max_number = sql_query2.value(0).toInt();
                }
                QString insert_sql = QString("insert into users(uid, name, password, question) values('%1','%2','%3','%4') ").arg(max_number+1).arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_4->text());
                if(!sql_query2.exec(insert_sql))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "inserted Wang!";
                }
                database2.close();
            }
        }
        log_mode=0;
        name=ui->lineEdit->text();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        emit sendToMainWindow(name,logs,myticketnum);
        this->close();
    }
}


void Login::on_radioButton_2_clicked()
{
    if(log_mode==1 && ui->radioButton_2->isChecked()) ui->pushButton_2->setDisabled(false);
    else if(log_mode==1) ui->pushButton_2->setDisabled(true);
}

