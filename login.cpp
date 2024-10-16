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
#include "passwordfix.h"
#pragma comment(lib,"sqlcipher.LIB")

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose,false);
    setAttribute(Qt::WA_TranslucentBackground, true);
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
    ui->checkBox_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->lineEdit_4->setVisible(false);
    QFile file(pathCreator("qss/登录.qss"));
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
    if(!ui->checkBox->isChecked()){
        ui->label_2->setVisible(true);
        ui->label_2->setText("请勾选我已阅读并同意Dtrip的服务政策和个人隐私保护政策");
        return;
    }
    else if(log_mode==0) {
        ui->label_2->setVisible(false);
        ui->label_2->setText("检测到您为新用户，请再次确认您的账号密码：");
    }
    if(ui->lineEdit->text()==""){
        ui->lineEdit->setPlaceholderText("用户名不能为空");
        ui->lineEdit->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
        return;
    }
    ui->lineEdit->setPlaceholderText("账号(英文数字)");
    ui->lineEdit->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("SQLITECIPHER","read_connection");
    qDebug() << QSqlDatabase::drivers();
    bool dbExist = QFile::exists(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
    if (dbExist && log_mode==0)
    {
        if(ui->lineEdit_2->text()==""){
            ui->lineEdit_2->setPlaceholderText("密码不能为空");
            ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
            return;
        }
        ui->lineEdit_2->setPlaceholderText("登陆密码 (长度>=6)");
        ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
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
            QSqlQuery query(database);
            database.setDatabaseName(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
            database.setUserName(ui->lineEdit->text());
            database.setPassword(ui->lineEdit_2->text());
            database.setConnectOptions("QSQLITE_USE_CIPHER=sqlcipher; SQLCIPHER_LEGACY=1; SQLCIPHER_LEGACY_PAGE_SIZE=4096");
            if (!database.open())
            {
                qDebug() << "Error: Failed to connect database." << database.lastError();
                database.close();
                QSqlDatabase::removeDatabase("read_connection");
                QSqlDatabase::removeDatabase("read_connection_2");
                ui->lineEdit_2->setText("");
                ui->lineEdit_2->setPlaceholderText("密码错误");
                ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
                return;
            }
            else
            {
                ui->lineEdit_2->setPlaceholderText("登陆密码 (长度>=6)");
                ui->lineEdit_2->setStyleSheet("color:rgb(0,0,0);");
                QString company,ID,sou,des,time0,time1,chi,date;
                Log *p,*q;
                int price=0,j=0,next;
                query.exec("SELECT * FROM ticket");
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
                    date = query.value(10).toString();
                    if(next==1 || next==2){
                        logs[j].setLog(company,ID,sou,des,time0,time1,price,chi,date);
                        logs[j].next=NULL;
                        p=&logs[j];
                        j++;
                    }
                    else{
                        Log* log0=new Log();
                        log0->setLog(company,ID,sou,des,time0,time1,price,chi,date);
                        log0->next=NULL;
                        p->next=log0;
                        p=p->next;
                    }
                }
                myticketnum=j;
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
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
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
            ui->checkBox_2->setVisible(true);
            ui->lineEdit_3->setVisible(true);
            ui->lineEdit_4->setVisible(true);
            ui->pushButton_2->setDisabled(true);
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            return;
        }
        dbExist = QFile::exists(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
        if (dbExist){
            ui->lineEdit->setText("");
            ui->lineEdit->setPlaceholderText("该用户已存在！");
            ui->lineEdit->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
            return;
        }
        ui->lineEdit->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        ui->lineEdit->setPlaceholderText("账号(英文数字)");
        if(ui->lineEdit_2->text()==""){
            ui->lineEdit_2->setPlaceholderText("密码不能为空");
            ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
            return;
        }
        ui->lineEdit_2->setPlaceholderText("登陆密码 (长度>=6)");
        ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        if(ui->lineEdit_2->text()!=ui->lineEdit_3->text()){
            ui->label_2->setText("密码不一致，请再次确认您的密码");
            ui->label_2->setStyleSheet("color:rgb(255,0,0);");
            ui->lineEdit_3->setText("");
            return;
        }
        ui->label_2->setStyleSheet("color:rgb(0,0,0);");
        if(ui->lineEdit_4->text()==""){
            ui->label_7->setText("以下为密保问题，请回答所在城市：");
            ui->label_7->setStyleSheet("color:rgb(255,0,0);");
            ui->lineEdit_3->setStyleSheet("font-size:12pt; color:rgb(255,0,0);");
            ui->lineEdit_3->setPlaceholderText("请回答");
            return;
        }
        ui->lineEdit_3->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        ui->lineEdit_3->setPlaceholderText("请输入(找回密码用)");
        if(ui->lineEdit_2->text().length()<6){
            ui->label_2->setText("密码不安全，请确保密码长度>=6");
            ui->label_2->setStyleSheet("color:rgb(255,0,0);");
            ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");
            return;
        }
        ui->label_2->setStyleSheet("color:rgb(0,0,0);");
        qDebug() << pathCreator("dbs/"+ui->lineEdit->text()+".db");
        database.setDatabaseName(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
        database.setUserName(ui->lineEdit->text());
        database.setPassword(ui->lineEdit_2->text());
        database.setConnectOptions("QSQLITE_USE_CIPHER=sqlcipher; SQLCIPHER_LEGACY=1; SQLCIPHER_LEGACY_PAGE_SIZE=4096; QSQLITE_CREATE_KEY");
        if (!database.open())
        {
            qDebug() << "Error: Failed to connect database." << database.lastError();
        }
        else
        {
            //创建表格
            QSqlQuery sql_query(database);
            QString create_sql = "create table ticket (uid int primary key, name varchar(30), id varchar(30), sou varchar(30), des varchar(30), time0 varchar(30), time1 varchar(30), price int, chi varchar(30), next int, date varchar(30))";
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

void Login::on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1)
{
    if(log_mode==1 && ui->checkBox_2->isChecked()) ui->pushButton_2->setDisabled(false);
    else if(log_mode==1) ui->pushButton_2->setDisabled(true);
}



void Login::on_checkBox_2_stateChanged(int arg1)
{
    if(log_mode==1 && ui->checkBox_2->isChecked()) ui->pushButton_2->setDisabled(false);
    else if(log_mode==1) ui->pushButton_2->setDisabled(true);
}


void Login::on_pushButton_clicked()
{
    Passwordfix* fix=new Passwordfix(ui->lineEdit->text(),"",0);
    fix->show();
}


void Login::on_pushButton_3_clicked()
{
    Passwordfix* fix=new Passwordfix(ui->lineEdit->text(),ui->lineEdit_2->text(),1);
    fix->show();
}

