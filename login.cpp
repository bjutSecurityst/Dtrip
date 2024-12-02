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
#include <QRegularExpressionValidator>
#include "passwordfix.h"
#pragma comment(lib,"sqlcipher.LIB")
//登录界面
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    //设置登录界面背景色为透明，并设置主界面关闭时一起退出
    setAttribute(Qt::WA_QuitOnClose,false);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置超链接文本
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
    //设置按钮的样式表
    ui->pushButton_4->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px; background-color: white;");
    ui->pushButton_2->setStyleSheet("border-radius: 5px; background-color: #FFCF4C; selection-background-color: #F0CF5C");
    ui->pushButton_3->setStyleSheet("text-align:left;");
    ui->pushButton_5->setStyleSheet("text-align:right;");
    //设置部分按钮在一般模式下隐藏
    ui->label_2->setVisible(false);
    ui->label_7->setVisible(false);
    ui->checkBox_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->lineEdit_4->setVisible(false);
    QFile file(pathCreator("qss/登录.qss"));
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    ui->pushButton_2->setStyleSheet(styleSheet);
    ui->verticalSpacer->changeSize(20,150);
    //设置输入栏的正则表达式过滤器（剔除一些会影响数据库创建的符号）
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" ' < > : / %]*$")));
    ui->lineEdit_2->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" ' < > : / %]*$")));
    ui->lineEdit_3->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" ' < > : / %]*$")));
    ui->lineEdit_4->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" ' < > : / %]*$")));
}

Login::~Login()
{
    delete ui;
}
//登录界面退出按钮
void Login::on_pushButton_5_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    emit sendToMainWindow("",NULL,NULL,myticketnum,mypreticketnum,0,0,0,0,0,0,0,NULL,NULL,0,0);
    this->close();
}

/*
登录按钮槽函数即登录功能的实现
    func：
    1.对用户的输入进行检查，如果未勾选同意协议，用户名为空，密码为空，密码长度过短，密码错误，则输出相应的提示
    2.如果未找到用户的数据库，则判断其为新用户，开启新用户模式，并调整控件。
    3.如果找到用户，并且密码正确，则开始读取用户数据，并将数据发送给主函数
    4.如果是新用户模式，再次对输入进行检查，如果用户已存在，如果密码为空，如果密码长度过短，确认密码与密码不一致，未输入密保问题，则输出相应的提示
    5.如果是新用户模式，并且输入正确，则创建新用户的数据库，初始化用户数据并发送给主函数
    write args：
        log_mode：登陆模式 0普通模式 1新用户模式
        myticketnum：用户票据数量
        name：用户名
        logs：用户正常票据数组
        prelogs：用户过往票据数组
        mypreticketnum：用户过往票据数量
        home：用户住所预测值
        probability：用户住所预测概率
        common：用户票据常去地预测值
        pco：用户票据常去地预测概率
        time_money,time_time,time_straight：用户搜索权重 费用最少，时间最短，直飞
        citytimesfrom：用户搜索始发地权重数组
        citytimesto：用户搜索目的地权重数组
        cost：用户累销
        mileage：用户里程
*/
void Login::on_pushButton_2_clicked()
{
    //对用户的输入进行检查，如果未勾选同意协议，用户名为空，密码为空，密码长度过短，密码错误，则输出相应的提示
    if(!ui->checkBox->isChecked()){
        ui->label_2->setVisible(true);
        ui->label_2->setText("请勾选我已阅读并同意Dtrip的服务政策和个人隐私保护政策");
        ui->verticalSpacer->changeSize(20,112);
        return;
    }
    else ui->verticalSpacer->changeSize(20,150);
    if(ui->lineEdit->text()==""){
        ui->lineEdit->setPlaceholderText("用户名不能为空");
        ui->lineEdit->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
        return;
    }
    ui->lineEdit->setPlaceholderText("账号(英文数字)");
    ui->lineEdit->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
    //建立与用户的数据库之间的连接
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("SQLITECIPHER","read_connection");
    qDebug() << QSqlDatabase::drivers();
    bool dbExist = QFile::exists(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
    //如果用户存在
    if (dbExist && log_mode==0)
    {
        if(ui->lineEdit_2->text()==""){
            ui->lineEdit_2->setPlaceholderText("密码不能为空");
            ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
            return;
        }
        else if(ui->lineEdit_2->text().length()<6){
            ui->lineEdit_2->setText("");
            ui->lineEdit_2->setPlaceholderText("登陆密码 (长度>=6)");
            ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
            return;
        }
        ui->lineEdit_2->setPlaceholderText("登陆密码 (长度>=6)");
        ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        //建立与主数据库的连接
        QSqlDatabase database2;
        database2 = QSqlDatabase::addDatabase("QSQLITE","read_connection_2");
        database2.setDatabaseName(pathCreator("dbs/users.db"));
        database2.setUserName("root");
        database2.setPassword("123456");
        float time_money,time_time,time_straight;
        int cost,mileage;
        float *citytimesfrom=new float[16],*citytimesto=new float[16];
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
            QSqlQuery queryuser(database2);
            queryuser.exec(last_log);
            queryuser.next();
            //获取用户搜索权重
            time_money = queryuser.value(4).toFloat();
            time_time = queryuser.value(5).toFloat();
            time_straight = queryuser.value(6).toFloat();
            //用户累销，用户里程
            cost=queryuser.value(7).toInt();
            mileage=queryuser.value(8).toInt();
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
                QString company,ID,sou,des,time0,time1,chi,date,PID;
                bool business;
                Log *p,*q;
                int price=0,j=0,next,i=1,num;
                //获取有效票根数据
                query.exec("SELECT * FROM ticket");
                while(query.next())
                {
                    PID= query.value(0).toString();
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
                    business = query.value(11).toBool();
                    num = query.value(12).toInt();
                    logs[j].setLog(company,ID,sou,des,time0,time1,price,chi,date);
                    logs[j].setPID(PID);
                    logs[j].setBus(business);
                    logs[j].setnum(num);
                    logs[j].next=NULL;
                    p=&logs[j];
                    j++;
                    //如果有子票，则从subticket表中获取子票
                    if(next!=-1){
                        i=1;
                        QSqlQuery querysub(database);
                        for(i=1;i<=next;i++){
                            querysub.exec(QString("select * from subticket where PID = '%1' AND next = '%2'").arg(PID).arg(i));
                            Log* log0=new Log();
                            querysub.next();
                            company = querysub.value(1).toString();
                            ID = querysub.value(2).toString();
                            sou = querysub.value(3).toString();
                            des = querysub.value(4).toString();
                            time0 = querysub.value(5).toString();
                            time1 = querysub.value(6).toString();
                            price = querysub.value(7).toInt();
                            chi = querysub.value(8).toString();
                            date = querysub.value(10).toString();
                            log0->setLog(company,ID,sou,des,time0,time1,price,chi,date);
                            log0->next=NULL;
                            p->next=log0;
                            p=p->next;
                        }
                    }
                }
                //更新用户有效票据数
                myticketnum=j;
                //获取过去票据数据
                query.exec("SELECT * FROM preticket");
                QString status;
                j=0;
                while(query.next())
                {
                    PID= query.value(0).toString();
                    company = query.value(1).toString();
                    ID = query.value(2).toString();
                    sou = query.value(3).toString();
                    des = query.value(4).toString();
                    time0 = query.value(5).toString();
                    time1 = query.value(6).toString();
                    price = query.value(7).toInt();
                    chi = query.value(8).toString();
                    status = query.value(9).toString();
                    date = query.value(10).toString();
                    business = query.value(11).toBool();
                    num = query.value(12).toInt();
                    prelogs[j].setLog(company,ID,sou,des,time0,time1,price,chi,date);
                    prelogs[j].setPID(PID);
                    prelogs[j].setBus(business);
                    prelogs[j].setnum(num);
                    prelogs[j].setstatus(status);
                    prelogs[j].next=NULL;
                    j++;
                }
                //更新用户过去票据数
                mypreticketnum=j;
                //获取用户搜索始发地权重数组，用户搜索目的地权重数组
                query.exec("SELECT * FROM searchtimes");
                if(query.next())
                {
                    for(i=1;i<17;i++){
                        citytimesfrom[i-1]=query.value(i).toFloat();
                    }
                }
                else{
                    qDebug() << "fault!";
                }
                if(query.next())
                {
                    for(i=1;i<17;i++){
                        citytimesto[i-1]=query.value(i).toFloat();
                    }
                }
                else{
                    qDebug() << "fault!";
                }
                database.close();
            }
            qDebug() << "success!";
        }
        //数据获取完毕，关闭与数据库的连接
        database2.close();
        name=ui->lineEdit->text();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        QSqlDatabase::removeDatabase("read_connection");
        QSqlDatabase::removeDatabase("read_connection_2");
        int home,common;
        double probability,pco;
        //通过用户票据信息分析用户的住所以及常去地
        userHomeAnalyse(&home,&probability,&common,&pco);
        //向主界面发送用户数据
        emit sendToMainWindow(name,logs,prelogs,myticketnum,mypreticketnum,home,probability,common,pco,time_money,time_time,time_straight,citytimesfrom,citytimesto,cost,mileage);
        this->close();
    }
    else
    {
        //如果未找到用户，并且是普通模式
        if(log_mode==0) {
            //切换为新用户模式
            log_mode=1;
            //显示新控件
            ui->label_2->setVisible(true);
            ui->label_7->setVisible(true);
            ui->checkBox_2->setVisible(true);
            ui->lineEdit_3->setVisible(true);
            ui->lineEdit_4->setVisible(true);
            ui->pushButton_2->setDisabled(true);
            ui->label_2->setText("检测到您为新用户，请再次确认您的账号密码：");
            ui->verticalSpacer->changeSize(20,20);
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            return;
        }
        //以下为新用户模式的代码
        //判断用户是否已经存在
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
        else if(ui->lineEdit_2->text().length()<6){
            ui->lineEdit_2->setText("");
            ui->lineEdit_2->setPlaceholderText("登陆密码 (长度>=6)");
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
        //创建新用户数据库
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
            QString create_sql = "create table ticket (PID varchar(30), name varchar(30), id varchar(30), sou varchar(30), des varchar(30), time0 varchar(30), time1 varchar(30), price int, chi varchar(30), next int, date varchar(30), business bool, num int, PRIMARY KEY(PID))";
            sql_query.prepare(create_sql);
            if(!sql_query.exec())
            {
                qDebug() << "Error: Fail to create table." << sql_query.lastError();
            }
            else
            {
                qDebug() << "Table created!";
            }
            create_sql = "create table subticket (PID varchar(30), name varchar(30), id varchar(30), sou varchar(30), des varchar(30), time0 varchar(30), time1 varchar(30), price int, chi varchar(30), next int, date varchar(30))";
            sql_query.prepare(create_sql);
            if(!sql_query.exec())
            {
                qDebug() << "Error: Fail to create table." << sql_query.lastError();
            }
            else
            {
                qDebug() << "Table created!";
            }
            create_sql = "create table searchtimes (LABEL int primary key,北京 float, 上海 float, 昆明 float, 广州 float, 台北 float, 西安 float, 乌鲁木齐 float, 哈尔滨 float, 拉萨 float, 西宁 float, 新加坡 float, 马尼拉 float, 曼谷 float, 东京 float, 首尔 float, 新德里 float)";
            sql_query.prepare(create_sql);
            if(!sql_query.exec())
            {
                qDebug() << "Error: Fail to create table." << sql_query.lastError();
            }
            else
            {
                qDebug() << "Table created!";
            }
            create_sql ="CREATE TABLE preticket (PID varchar(30),name varchar(30),id varchar(30),sou varchar(30),des varchar(30),time0 archar(30),time1 varchar(30),price int,chi varchar(30),status varchar(30),date varchar(30),business bool,num int, sequence INTEGER,PRIMARY KEY(sequence AUTOINCREMENT))";
            sql_query.prepare(create_sql);
            if(!sql_query.exec())
            {
                qDebug() << "Error: Fail to create table." << sql_query.lastError();
            }
            else
            {
                qDebug() << "Table created!";
            }
            QString insert_sql = QString("insert into searchtimes (LABEL, 北京, 上海, 昆明, 广州, 台北, 西安, 乌鲁木齐, 哈尔滨, 拉萨, 西宁, 新加坡, 马尼拉, 曼谷, 东京, 首尔, 新德里) values('0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0') ");
            if(!sql_query.exec(insert_sql))
            {
                qDebug() << sql_query.lastError();
            }
            else
            {
                qDebug() << "inserted searchtime0!";
            }
            insert_sql = QString("insert into searchtimes (LABEL, 北京, 上海, 昆明, 广州, 台北, 西安, 乌鲁木齐, 哈尔滨, 拉萨, 西宁, 新加坡, 马尼拉, 曼谷, 东京, 首尔, 新德里) values('1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0') ");
            if(!sql_query.exec(insert_sql))
            {
                qDebug() << sql_query.lastError();
            }
            else
            {
                qDebug() << "inserted searchtime1!";
            }
            database.close();
            //向主数据库中写入新用户信息
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
                QString insert_sql = QString("insert into users(uid, name, password, question, timemoney, timetime, timestraight, cost, mileage) values('%1','%2','%3','%4','0','0','0','0','0') ").arg(max_number+1).arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_4->text());
                if(!sql_query2.exec(insert_sql))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "inserted users!";
                }
                database2.close();
            }
        }
        log_mode=0;
        name=ui->lineEdit->text();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        //初始化用户数据
        float *citytimesfrom=new float[16],*citytimesto=new float[16];
        for(int i=0;i<16;i++){
            citytimesfrom[i]=0;
            citytimesto[i]=0;
        }
        //向主界面发送用户数据
        emit sendToMainWindow(name,logs,prelogs,myticketnum,mypreticketnum,-1,0,-1,0,0,0,0,citytimesfrom,citytimesto,0,0);
        this->close();
    }
}
//我已确认勾选框的槽函数，用于控制是否启用登录按钮
void Login::on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1)
{
    if(log_mode==1 && ui->checkBox_2->isChecked()) ui->pushButton_2->setDisabled(false);
    else if(log_mode==1) ui->pushButton_2->setDisabled(true);
}

//我已确认勾选框的槽函数，用于控制是否启用登录按钮
void Login::on_checkBox_2_stateChanged(int arg1)
{
    if(log_mode==1 && ui->checkBox_2->isChecked()) ui->pushButton_2->setDisabled(false);
    else if(log_mode==1) ui->pushButton_2->setDisabled(true);
}

//更改密码槽函数，用于转到更改密码页面
void Login::on_pushButton_clicked()
{
    if(fix==NULL){
        fix=new Passwordfix(ui->lineEdit->text(),"",0);
        connect(fix,&Passwordfix::sendToLogin,this,&Login::getpasswordfixMessage);
        fix->show();
    }
    else if(fix->getMode()==1){
        fix->setAttribute(Qt::WA_DeleteOnClose, true);
        fix->close();
        fix=new Passwordfix(ui->lineEdit->text(),"",0);
        connect(fix,&Passwordfix::sendToLogin,this,&Login::getpasswordfixMessage);
        fix->show();
    }
    else fix->raise();
}

//忘记密码槽函数，用于转到忘记密码页面
void Login::on_pushButton_3_clicked()
{
    if(fix==NULL){
        fix=new Passwordfix(ui->lineEdit->text(),ui->lineEdit_2->text(),1);
        connect(fix,&Passwordfix::sendToLogin,this,&Login::getpasswordfixMessage);
        fix->show();
    }
    else if(fix->getMode()==0){
        fix->setAttribute(Qt::WA_DeleteOnClose, true);
        fix->close();
        fix=new Passwordfix(ui->lineEdit->text(),ui->lineEdit_2->text(),1);
        connect(fix,&Passwordfix::sendToLogin,this,&Login::getpasswordfixMessage);
        fix->show();
    }
    else fix->raise();
}
//登录界面获取修改或忘记密码界面信号的接收函数
void Login::getpasswordfixMessage(){
    fix=NULL;
}
/*
用户住所以及票务常去目的地分析函数：userHomeAnalyse
    input args：
        home：用户住所预测值（数字编码）
        probability：用户住所预测概率
        common：用户票据常去地预测值
        pco：用户票据常去地预测概率

*/
void Login::userHomeAnalyse(int* home,double* probability,int* common,double* pco){
    int cityTimes[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    *home=-1;
    *common=-1;
    *probability=0;
    *pco=0;
    int i,j,begin,end,pre=-1;
    float max=0,premax=0;
    //从用户票据中收集始发地权重
    for(i=0;i<myticketnum;i++){
        //将文字翻译为数字编码
        for(begin=0;begin<16;begin++){
            if(logs[i].sou.mid(0,citys[begin].length()).contains(citys[begin])) break;
            if(begin==4){
                if(logs[i].sou.mid(0,4).contains("中国台北")) break;
            }
        }
        cityTimes[begin]++;
    }
    //获取权重最大，次大的城市，及其权重
    for (i = 0; i < 16; i++) {
        if(max<cityTimes[i]) {
            premax=max;
            pre=*home;
            max=cityTimes[i];
            *home=i;
        }
        if(premax<cityTimes[i] && cityTimes[i]<max){
            pre=i;
            premax=cityTimes[i];
        }
    }
    //计算用户住所预估概率
    if(max!=0) *probability=max/(double)(max+premax);
    for(i=0;i<16;i++){
        cityTimes[i]=0;
    }
    max=0;pre=-1;premax=0;
    //从用户票据中收集目的地权重
    for(i=0;i<myticketnum;i++){
        //将文字翻译为数字编码
        for(end=0;end<16;end++){
            if(logs[i].des.mid(0,citys[end].length()).contains(citys[end])) break;
            if(end==4){
                if(logs[i].des.mid(0,4).contains("中国台北")) break;
            }
        }
        cityTimes[end]++;
    }
    //获取权重最大，次大的城市，及其权重
    for (i = 0; i < 16; i++) {
        if(max<cityTimes[i]) {
            premax=max;
            pre=*common;
            max=cityTimes[i];
            *common=i;
        }
        if(premax<cityTimes[i] && max>cityTimes[i]){
            pre=i;
            premax=cityTimes[i];
        }
    }
    //如果用户常去地等于用户住所，则去次大的城市作为用户常去地，并计算用户常去地预估概率
    if(*home==*common){
        *common=pre;
        if(max!=0) *pco=premax/(double)(max+premax);
    }
    else if(max!=0) *pco=max/(double)(max+premax);
}
//密码显示功能的实现，按下后即可切换密码显示模式
void Login::on_pushButton_6_clicked()
{
    if(ui->lineEdit_2->echoMode()==QLineEdit::Password) ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    else ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

