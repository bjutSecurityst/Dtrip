#define _CRT_SECURE_NO_WARNINGS 1
#include "mainwindow.h"
#include "QWindow"
#include "./ui_mainwindow.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <QPainter>
#include <QFile>
#include <QRegularExpression>
#include "QuickSort.h"
#include "login.h"
#include "userinfo.h"
#include "ticketwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <random>
#include "des.h"
#include <ctime>
#include "mainwindow4.h"
//#include "mysqlite.h"
#include <QMessageBox>
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"MSIMG32.LIB")
#pragma comment(lib,"sqlcipher.LIB")
#define TIMEOUT 4000
#define WindowWidth 1280
#define WindowHeight 720
void CMapSet(QDate curDate,QString* citys,CMap* pMap,int mode);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口大小
    this->setMinimumSize(1280,720);
    //设置工具栏为垂直贴顶布局
    ui->verticaltool->setAlignment(Qt::AlignTop);
    //设置工具栏按钮，及其他按钮
    ui->pushButton_1->setMinimumSize(10,10);
    ui->pushButton_1->setCheckable(true);
    ui->pushButton_1->setChecked(true);
    ui->pushButton_2->setCheckable(true);
    ui->pushButton_3->setCheckable(true);
    ui->pushButton_back->setCheckable(true);
    ui->pushButton_0->setStyleSheet("border:none;");
    ui->pushButton_0->setMaximumSize(100,30);
    ui->pushButton_0->setIcon(QIcon(pathCreator("菜单栏2.png")));
    QFile file_search(pathCreator("qss/选择.qss"));
    file_search.open(QFile::ReadOnly);
    QString styleSheet_se = tr(file_search.readAll());
    ui->pushButton->setStyleSheet(styleSheet_se);
    ui->pushButton_4->setIcon(QIcon(pathCreator("search.png")));
    ui->pushButton_4->setStyleSheet(styleSheet_se);
    //设置应用图标
    QPixmap icon0(":/trip.png");
    ui->labelicon0->setPixmap(icon0);
    //设置查询窗口中内容
    ui->easystay->setStyleSheet("border: none; border-image: url(:/easy_stay.png);");
    ui->backgroundsky->setMinimumSize(200,100);
    ui->backgroundsky->setStyleSheet("border: 2px solid lightblue; border-radius: 10px; border-image: url(:/gradbackground.png);");
    ui->lineEditdep->setMinimumHeight(30);
    ui->lineEditari->setMinimumHeight(30);
    ui->layoutbutton->setStyleSheet("border-radius: 10px; background-color: white;");
    ui->layoutbutton_2->setStyleSheet("border-radius: 10px; background-color: white;");
    ui->comboBox_2->setStyleSheet("border-radius: 5px; background-color: white;");
    QFile file(pathCreator("qss/排序.qss"));
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    ui->pushButton_9->setStyleSheet(styleSheet);
    ui->pushButton_11->setStyleSheet("border: 2px solid lightblue; border-radius: 10px; background-color: white;");
    ui->home_background->setStyleSheet("border: none; border-image: url(:/homepage-background.png);");
    ui->comboBox->setCurrentIndex(-1);
    ui->verticalScrollBar_3->setVisible(false);

    button_swap = new QPushButton();
    button_swap->setParent(this);
    button_swap->setObjectName("交换");
    button_swap->setIcon(QIcon(pathCreator("change.png")));
    button_swap->setIconSize(QSize(38,38));
    button_swap->setFlat(true);
    button_swap->setGeometry(680,168,38,38);
    connect(button_swap, &QPushButton::clicked, this, &MainWindow::on_button_swap_clicked);

    //设置滚动播放的图片
    picId=0;
    timer=new QTimer;
    timer->start(TIMEOUT);
    QImage img;
    img.load(pathCreator("/scene0.jpg"));
    ui->label_8->setPixmap(changeImage(QPixmap::fromImage(img),30));
    ui->label_8->setScaledContents(true);
    connect(timer,&QTimer::timeout,this,&MainWindow::Timerout);

    QImage imgGg;
    imgGg.load(pathCreator("北京旅.jpg"));
    ui->label_10->setPixmap(changeImage(QPixmap::fromImage(imgGg),5));
    ui->label_10->setScaledContents(true);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->label_14->setVisible(false);
    ui->pushButton_9->setVisible(false);
    ui->comboBox_2->setVisible(false);
    ui->pushButton_5->setStyleSheet("text-align:right;");

    //设置界面2
    widget0 = new QWidget;
    //将要添加的内容布局设置为 QWidget 对象的布局
    verticalLayout_7=new QVBoxLayout(this);
    verticalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
    widget0->setLayout(verticalLayout_7);
    //将QWidget对象添加到 ui整体布局中
    widget0->setParent(this);
    widget0->hide();
    widget0->move(180,80);
    widget0->resize(1055,610);
    //游离layout需要加到widget上
    ui->widget->setVisible(false);
    ui->pushButton_12->setVisible(false);
    ui->scrollArea->setVisible(false);
    QDateTime time= QDateTime::currentDateTime();//获取系统当前的时间
    ui->dateEdit->setDateTime(time);
    ui->dateEdit_2->setVisible(false);
    ui->checkBox_2->setVisible(false);
    ui->checkBox_3->setVisible(false);
    ui->lineEditari->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" < > : / %]*$")));
    ui->lineEditdep->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" < > : / %]*$")));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//定时的图片更新函数，更新内容包括广告图与右侧的风景图
void MainWindow::Timerout(){
    if(ui->pushButton_1->isChecked()){
        QString path(pathCreator("scene"));
        path+=QString::number(picId);
        path+=".jpg";
        QImage img;
        img.load(path);
        ui->label_8->setPixmap(changeImage(QPixmap::fromImage(img),30));
        picId++;
        picId=picId % 4;
        if(picId%2==1){
            setAD(business);
        }
        else{
            QImage imgGg;
            if(commonto!=-1){
                QString ts=pathCreator("")+citys[this->commonto]+"旅.jpg";
                imgGg.load(ts);
                ui->label_10->setPixmap(changeImage(QPixmap::fromImage(imgGg),imgGg.height()/30));
            }
        }
    }
}
//地图按钮槽函数：用于打开地图
void MainWindow::on_pushButton_clicked()
{
    //转至地图选择页
    this->hide();
    Map *m=new Map(ui->dateEdit->date());
    m->show();
    connect(m,&Map::sendToMainWindow,this,&MainWindow::getMapMessage);
}

//工具栏滚动条槽函数，用于设置工具栏按钮的位置
void MainWindow::on_verticalScrollBar_sliderMoved(int position)
{
    int begin=30,step=35;
    vector<int> y(4);
    for(int i=0;i<4;i++){
        y.at(i)=begin+step*i;
    }
    ui->pushButton_1->move(QPoint(5,y.at(0)+ui->verticalScrollBar->sliderPosition()));
    ui->pushButton_2->move(QPoint(5,y.at(1)+ui->verticalScrollBar->sliderPosition()));
    ui->pushButton_3->move(QPoint(5,y.at(2)+ui->verticalScrollBar->sliderPosition()));
    ui->pushButton_back->move(QPoint(5,y.at(3)+ui->verticalScrollBar->sliderPosition()));
}
//地图界面信号的主界面接收函数：getMapMessage
// input args：a：始发地 b：目的地 curdate：购票日期
void MainWindow::getMapMessage(QString a,QString b,QDate curdate){
    this->show();
    a.remove(0,4);
    b.remove(0,4);
    ui->lineEditdep->setText(a);
    ui->lineEditari->setText(b);
    ui->dateEdit->setDate(curdate);
}
/*
小票据界面信号的主界面接收函数：getticketInfoMessage
    func：
    根据传入的模式来打开对应的ticketwindow来显示票据
    input args：
        tlog：该界面的票据
        mode：打开模式 0，1为一般模式 2为改签模式
*/
void MainWindow::getticketInfoMessage(Log* tlog,int mode){
    if(!login){
        QMessageBox msgBox;
        msgBox.setText("请先登录");
        msgBox.setInformativeText("点击OK返回主界面");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
    }
    else{
        this->hide();
        ticketWindow *t;
        if(mode==2) t=new ticketWindow(tlog,2,clog);
        else t=new ticketWindow(tlog,mode);
        connect(t,&ticketWindow::sendToMainWindow,this,&MainWindow::getticketwindowMessage);
        connect(t,&ticketWindow::changeTicket,this,&MainWindow::changeTicketSearch);
        connect(t,&ticketWindow::Exit,this,&MainWindow::show);
        connect(t,&ticketWindow::change,this,&MainWindow::changeTicketMain);
        connect(t,&ticketWindow::refund,this,&MainWindow::refundTicketMain);
        t->show();
    }
}
/*
购票主函数-即ticketwindow的接收函数：getticketwindowMessage
    func：
    1.生成PID
    2.往用户数据库的ticket和subticket表中写入该票对应的票根与子票
    3.更新主数据库的用户消费与里程信息
    4.弹出窗口告知用户购票成功
    input args：
        tlog：要购买的票
    write args：
        myticketnum：用户正常票数
        myLogs：有效票数组
        cost：用户累计消费
        mileage：用户累计里程
*/
void MainWindow::getticketwindowMessage(Log* tlog){
    QString uid;
    openDatabasegetuid(&uid,username);
    //生成PID：DES（时间戳+UID前四位+4位随机数）
    //获取UID前四位
    if(uid.length()>4) uid=uid.mid(0,4);
    //获取时间戳
    std::time_t t = std::time(0);
    string timeString=std::to_string(t);
    std::random_device rd;
    std::mt19937_64 g2 (rd());
    //生成32位二进制位随机数
    uint32_t u32Random = g2();
    DES *mydes=new DES();
    //将时间戳转换为36进制
    string time_H=mydes->longToA((long)t,36);
    //将随机数转换为36进制后取2~5位
    string s=mydes->uint_32ToA(u32Random,36).substr(1,4);
    //构建PID原文
    string sPID=time_H+uid.toStdString()+s;
    //使用密钥security对PID进行加密，并转换为32进制
    sPID=mydes->des_encrypt_ECB(sPID,"security");
    sPID=mydes->des_H(sPID);
    sPID=mydes->des_2To32(sPID);
    mydes->deleteLater();
    //设置该票的PID
    tlog->setPID(QString::fromStdString(sPID));
    Log *p=tlog;
    Log *q=&userLogs[myticketnum];
    while(p->next!=NULL){
        p=p->next;
        Log* log1=new Log();
        log1->setlogL(p);
        q->next=log1;
        q=q->next;
    }
    userLogs[myticketnum].setlogL(tlog);
    p=tlog;
    QString password;
    bool open=openDatabasegetPassword(&password,username);
    if(!open) return;
    //建立与用户的数据库的连接
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("SQLITECIPHER","read_connection");
    qDebug() << QSqlDatabase::drivers();
    database.setDatabaseName(pathCreator("dbs/"+username+".db"));
    database.setUserName(username);
    database.setPassword(password);
    QString a="QSQLITE_USE_CIPHER=sqlcipher; SQLCIPHER_LEGACY=1; SQLCIPHER_LEGACY_PAGE_SIZE=4096;";
    qDebug() <<a;
    database.setConnectOptions(a);
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
        database.close();
        QSqlDatabase::removeDatabase("read_connection");
        QSqlDatabase::removeDatabase("read_connection_2");
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        return;
    }
    else
    {
        QSqlQuery sql_query2(database);
        QString PID=p->PID;
        //如果这张票没有子票，则只向ticket表中写入该票
        if(p->next==NULL){
            QString insert_sql = QString("insert into ticket(PID, name, id , sou, des, time0, time1, price, chi, next, date, business, num) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13') ").arg(p->PID).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(-1).arg(p->curdate).arg(p->business).arg(p->num);
            if(!sql_query2.exec(insert_sql))
            {
                qDebug() << sql_query2.lastError();
            }
            else
            {
                qDebug() << "inserted Wang!";
                //更新用户消费与里程数据
                cost+=tlog->price*(tlog->business+1);
                int begin,end;
                findCityNum(*p,begin,end);
                mileage+=calDistance(cityp[begin],cityp[end]);
            }
        }
        //如果这张票有子票
        else{
            bool head=true;
            int i=0,subnum=0;
            //先计算子票数
            while(p->next!=NULL){
                p=p->next;
                subnum++;
            }
            p=tlog;
            while(p!=NULL){
                QString insert_sql;
                //首先将票根写入ticket表，并更新用户消费数据
                if(head) {
                    insert_sql = QString("insert into ticket(PID, name, id , sou, des, time0, time1, price, chi, next, date, business, num) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13') ").arg(PID).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(subnum).arg(p->curdate).arg(p->business).arg(p->num);
                    head=false;
                    cost+=tlog->price*(tlog->business+1);
                }
                //如果是子票则写入subticket表
                else insert_sql = QString("insert into subticket(PID, name, id , sou, des, time0, time1, price, chi, next, date) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11') ").arg(PID).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(i).arg(p->curdate);
                if(!sql_query2.exec(insert_sql))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "inserted SUCCESS!";
                    //如果不是票根，则更新用户里程数据
                    if(!head){
                        int begin,end;
                        findCityNum(*p,begin,end);
                        mileage+=calDistance(cityp[begin],cityp[end]);
                    }
                }
                i++;
                p=p->next;
            }
        }
        //关闭数据库
        database.close();
    }
    //断开与数据库的连接
    QString name0 = QSqlDatabase::database().connectionName();
    QSqlDatabase::removeDatabase(name0);
    QSqlDatabase::removeDatabase("read_connection");
    QSqlDatabase::removeDatabase("read_connection_2");
    //弹出窗口告知用户订票成功
    QMessageBox msgBox;
    msgBox.setText("订票成功");
    msgBox.setInformativeText("点击OK返回主界面");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    myticketnum++;
    //更新主数据库的用户消费与里程信息
    updateUserCostandMileage(cost,mileage,username);
    this->show();
}
/*
改签主函数：changeTicketMain
    func：
    1.将被改签票的票写入用户的数据库的preticket表中
    2.从用户数据库的ticket和subticket表中把该票对应的票根与子票更新为新票的数据
    3.更新主数据库的用户消费与里程信息
    4.弹出窗口告知用户改签成功
    5.将票从程序的我的票据数组中复制到失效票数组，并将我的票据被改签的票更新为改签为的票
    6.刷新页面
    input args：
        tlog：要改签为的票
    write args：
        clog：被改签的票
        mypreticketnum：用户失效票数
        myticketnum：用户正常票数
        prelogs：失效票数组
        myLogs：有效票数组
        cost：用户累计消费
        mileage：用户累计里程
*/
void MainWindow::changeTicketMain(Log* tlog){
    Log *t;
    int i=0;
    QString PID;
    Log *p=tlog;
    QString password;
    bool open=openDatabasegetPassword(&password,username);
    if(!open) return;
    //生成新票的PID：DES（时间戳+UID前四位+4位随机数）
    std::time_t ti = std::time(0);
    string timeString=std::to_string(ti);
    std::random_device rd;
    std::mt19937_64 g2 (rd());
    uint32_t u32Random = g2();
    DES *mydes=new DES();
    string time_H=mydes->longToA((long)ti,36);
    string s=mydes->uint_32ToA(u32Random,36).substr(1,4);
    string sPID=time_H+username.mid(0,4).toStdString()+s;
    sPID=mydes->des_encrypt_ECB(sPID,"security");
    sPID=mydes->des_H(sPID);
    sPID=mydes->des_2To32(sPID);
    QString qsPID=QString::fromStdString(sPID);
    //建立与用户的数据库的连接
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("SQLITECIPHER","read_connection");
    qDebug() << QSqlDatabase::drivers();
    database.setDatabaseName(pathCreator("dbs/"+username+".db"));
    database.setUserName(username);
    database.setPassword(password);
    QString a="QSQLITE_USE_CIPHER=sqlcipher; SQLCIPHER_LEGACY=1; SQLCIPHER_LEGACY_PAGE_SIZE=4096;";
    qDebug() <<a;
    database.setConnectOptions(a);
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
        database.close();
        QSqlDatabase::removeDatabase("read_connection");
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        return;
    }
    else
    {   //获取preticket表中票数
        QSqlQuery sql_query2(database);
        QString count_sqllogs="select count(*) from preticket";
        sql_query2.exec(count_sqllogs);
        sql_query2.next();
        int count = sql_query2.value(0).toInt();
        //如果表中票数超过100
        if(count>=100){
            count_sqllogs="SELECT sequence FROM preticket ORDER BY sequence ASC LIMIT 1";
            sql_query2.exec(count_sqllogs);
            sql_query2.next();
            int sequence = sql_query2.value(0).toInt();
            //则删除编号最小的票
            QString delete_sql=QString("DELETE FROM preticket WHERE sequence='%1'").arg(sequence);
            if(!sql_query2.exec(delete_sql))
            {
                qDebug() << sql_query2.lastError();
            }
            else
            {
                qDebug() << "deleted!";
            }
            //如果最小编号以经达到100，则对所有票据从1开始重新编号
            if(sequence==100){
                for(i=1;i<100;i++){
                    QString update_prelog=QString("UPDATE preticket SET sequence='%1' WHERE sequence='%2'").arg(i).arg(sequence+i);
                    if(!sql_query2.exec(update_prelog))
                    {
                        qDebug() << sql_query2.lastError();
                    }
                    else
                    {
                        qDebug() << "prelog sequence updated!";
                    }
                }
                QString update_prelog="UPDATE sqlite_sequence SET seq = 100 WHERE name = 'preticket'";
                if(!sql_query2.exec(update_prelog))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "prelog increment updated!";
                }
            }
        }
        //将被退票的票写入用户的数据库的preticket表中
        QString copy_log=QString("INSERT into preticket(PID,name,id,sou,des,time0,time1,price,chi,date,business,num)  select PID,name,id,sou,des,time0,time1,price,chi,date,business,num from ticket where PID='%1'").arg(clog->PID);
        if(!sql_query2.exec(copy_log)){
            qDebug() << "Error: Fail to copy." << sql_query2.lastError();
        }
        else
        {
            qDebug() << "success!";
        }
        //更新这张票的状态
        QString update_prelog=QString("UPDATE preticket SET status='%1' WHERE PID='%2'").arg("改签").arg(clog->PID);
        if(!sql_query2.exec(update_prelog))
        {
            qDebug() << sql_query2.lastError();
        }
        else
        {
            qDebug() << "prelog updated!";
        }
        QString PID_log = QString("select * from ticket where PID = '%1'").arg(clog->PID);
        sql_query2.exec(PID_log);
        int next;
        if(!sql_query2.next()){
            qDebug() << "Error: Fail to read." << sql_query2.lastError();
        }
        else
        {
            qDebug() << "success!";
            PID= sql_query2.value(0).toString();
            next = sql_query2.value(9).toInt();
        }
        //将被改签的票的票根更新为新票的票根
        QString update_sql=QString("UPDATE ticket SET PID='%1',name='%2', id='%3', sou='%4', des='%5', time0='%6', time1='%7', price='%8', chi='%9' WHERE PID='%10'").arg(qsPID).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(clog->PID);
        if(!sql_query2.exec(update_sql))
        {
            qDebug() << sql_query2.lastError();
        }
        else
        {
            qDebug() << "updated!";
            cost-=clog->price*(clog->business+1);
            cost+=tlog->price*(tlog->business+1);
        }
        //将被改签的票的子票更新为新票的子票
        if(next!=-1){
            i=1;
            while(p->next!=NULL){
                p=p->next;
                QString update_sql=QString("UPDATE subticket SET PID='%1',name='%2', id='%3', sou='%4', des='%5', time0='%6', time1='%7', price='%8', chi='%9' WHERE PID='%10' AND next='%11'").arg(qsPID).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(PID).arg(i);
                if(!sql_query2.exec(update_sql))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "updated!";
                }
                i++;
            }
        }
        //关闭数据库
        database.close();
    }
    //断开与数据库的连接
    QString name0 = QSqlDatabase::database().connectionName();
    QSqlDatabase::removeDatabase(name0);
    QSqlDatabase::removeDatabase("read_connection");
    QMessageBox msgBox;
    //弹出窗口告知用户改签成功
    msgBox.setText("改签成功");
    msgBox.setInformativeText("点击OK返回主界面");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    //将票从程序的我的票据数组中移入失效票数组，并将我的票据被改签的票更新为改签为的票
    prelogs[mypreticketnum].setlogL(clog);
    prelogs[mypreticketnum].setstatus("改签");
    mypreticketnum++;
    tlog->setPID(qsPID);
    for(i=0;i<myticketnum;i++){
        if(userLogs[i].PID==clog->PID) {
            clog->clear();
            Log *p=tlog;
            Log *q=&userLogs[i];
            while(p->next!=NULL){
                p=p->next;
                Log* log1=new Log();
                log1->setlogL(p);
                q->next=log1;
                q=q->next;
            }
            userLogs[i].setlogL(tlog);
            break;
        }
    }
    //更新主数据库的用户消费与里程信息
    updateUserCostandMileage(cost,mileage,username);
    this->show();
    //关闭改签模式
    changemode=0;
    //刷新页面
    on_pushButton_2_clicked();
}
/*
改签票查找函数：changeTicketSearch
    func：
    1.根据改签票的航线与日期查找符合改签要求的机票
    input args：
        tlog：要改签的票
    write args：
        ticketnum：查找到的票数
        ticket_checkednum：已经做过有效性检测的票据数量
        clog：存储要改签的票
        sortmode：前一排序方式
        changemode：表示改签模式是否开始
*/
void MainWindow::changeTicketSearch(Log* tlog){
    Log *p=tlog;
    clog=tlog;
    int begin,end,k=5,i;
    string s="";
    this->show();
    layoutCleaner(7);
    //读取票据信息并拼接出航线
    if(p->next!=NULL) p=p->next;
    while(p!=NULL){
        if(p->next!=NULL){
            for(begin=0;begin<16;begin++){
                if(p->sou.mid(0,citys[begin].length()).contains(citys[begin])) break;
                if(begin==4){
                    if(p->sou.mid(0,4).contains("中国台北")) break;
                }
            }
            if(s=="") s="< "+to_string(begin);
            else s=s+" , "+to_string(begin);
        }
        else{
            findCityNum(*p,begin,end);
            if(s=="") s="< "+to_string(begin)+" : "+"99 "+to_string(end)+" >";
            else s=s+" , "+to_string(begin)+" : "+"99 "+to_string(end)+" >";
        }
        p=p->next;
    }
    for(i=0;i<=ticketnum;i++){
        logs[i].clear();
    }
    ticketnum=0;
    ticket_checkednum=0;
    //使用时间最短方式查找票据
    setLog(s,2);
    if(clog->business){
        for(i=0;i<ticketnum;i++){
            logs[i].setBus(true);
        }
    }
    //设置前一排序方式为飞行时间最短
    sortmode=1;
    qDebug() << QString::fromStdString(s) <<"\n";
    for(i=4;i>=0;i--){
        if(logs[i].ID=="" || logs[i].des=="不可达"){
            k=i;
        }
    }
    //将查到的票据显示到改签票滚动界面中
    if(k==0) {
        k=0;
        Log* logno=new Log();
        logno->setLog("没有航空公司","123456","不可改签","不可改签","00:00","25:00",0,"0%","");
        ticketInfo* ticket0=new ticketInfo(logno,2);
        connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
        verticalLayout_7->addWidget(ticket0);
    }
    else if(k<5){
        for(i=0;i<k;i++){
            ticketInfo* ticket0=new ticketInfo(&logs[i],clog,4);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            verticalLayout_7->addWidget(ticket0);
        }
    }
    else{
        for(i=0;i<5;i++){
            ticketInfo* ticket0=new ticketInfo(&logs[i],clog,4);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            verticalLayout_7->addWidget(ticket0);
        }
    }
    copymode=0;
    //开启改签模式
    changemode=1;
    ticket_now=0;
    ui->pushButton_9->setVisible(true);
    ui->comboBox_2->setVisible(true);
    ui->dateEdit_2->setVisible(false);
    ui->checkBox_2->setVisible(false);
    ui->checkBox_3->setVisible(false);
}
/*
退票函数：refundTicketMain
    func：
    1.将被退票的票写入用户的数据库的preticket表中
    2.从用户数据库的ticket和subticket表中把该票对应的票根与子票删除
    3.更新主数据库的用户消费与里程信息
    4.弹出窗口告知用户退票成功
    5.将票从程序的我的票据数组中删除，并加入失效票数组
    6.刷新页面
    input args：
        tlog：要退的票
    write args：
        mypreticketnum：用户失效票数
        myticketnum：用户正常票数
        prelogs：失效票数组
        myLogs：有效票数组
        cost：用户累计消费
        mileage：用户累计里程
*/
void MainWindow::refundTicketMain(Log* tlog){
    Log *q,*t;
    int i=0,j;
    QString PID;
    Log *p=tlog;
    QString password;
    bool open=openDatabasegetPassword(&password,username);
    if(!open) return;
    //建立与用户的数据库的连接
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("SQLITECIPHER","read_connection");
    qDebug() << QSqlDatabase::drivers();
    database.setDatabaseName(pathCreator("dbs/"+username+".db"));
    database.setUserName(username);
    database.setPassword(password);
    QString a="QSQLITE_USE_CIPHER=sqlcipher; SQLCIPHER_LEGACY=1; SQLCIPHER_LEGACY_PAGE_SIZE=4096;";
    qDebug() <<a;
    database.setConnectOptions(a);
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
        database.close();
        QSqlDatabase::removeDatabase("read_connection");
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        return;
    }
    else
    {
        //获取preticket表中票数
        QSqlQuery sql_query2(database);
        QString count_sqllogs="select count(*) from preticket";
        sql_query2.exec(count_sqllogs);
        sql_query2.next();
        int count = sql_query2.value(0).toInt();
        //如果表中票数超过100
        if(count>=100){
            count_sqllogs="SELECT sequence FROM preticket ORDER BY sequence ASC LIMIT 1";
            sql_query2.exec(count_sqllogs);
            sql_query2.next();
            int sequence = sql_query2.value(0).toInt();
            //则删除编号最小的票
            QString delete_sql=QString("DELETE FROM preticket WHERE sequence='%1'").arg(sequence);
            if(!sql_query2.exec(delete_sql))
            {
                qDebug() << sql_query2.lastError();
            }
            else
            {
                qDebug() << "deleted!";
            }
            //如果最小的票是第100号，则将所有的票重新从1开始编号
            if(sequence==100){
                for(i=1;i<100;i++){
                    QString update_prelog=QString("UPDATE preticket SET sequence='%1' WHERE sequence='%2'").arg(i).arg(sequence+i);
                    if(!sql_query2.exec(update_prelog))
                    {
                        qDebug() << sql_query2.lastError();
                    }
                    else
                    {
                        qDebug() << "prelog sequence updated!";
                    }
                }
                QString update_prelog="UPDATE sqlite_sequence SET seq = 100 WHERE name = 'preticket'";
                if(!sql_query2.exec(update_prelog))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "prelog increment updated!";
                }
            }
        }
        //将被退票的票写入用户的数据库的preticket表中
        QString copy_log=QString("INSERT into preticket(PID,name,id,sou,des,time0,time1,price,chi,date,business,num)  select PID,name,id,sou,des,time0,time1,price,chi,date,business,num from ticket where PID='%1'").arg(tlog->PID);
        sql_query2.exec(copy_log);
        if(!sql_query2.next()){
            qDebug() << "Error: Fail to copy." << sql_query2.lastError();
        }
        else
        {
            qDebug() << "success!";
        }
        //更新这张票的状态
        QString update_prelog=QString("UPDATE preticket SET status='%1' WHERE PID='%2'").arg("退票").arg(tlog->PID);
        if(!sql_query2.exec(update_prelog))
        {
            qDebug() << sql_query2.lastError();
        }
        else
        {
            qDebug() << "prelog updated!";
        }
        //从用户数据库的ticket和subticket表中把该票对应的票根与子票删除
        QString PID_log = QString("select * from ticket where PID = '%1'").arg(tlog->PID);
        sql_query2.exec(PID_log);
        int next;
        if(!sql_query2.next()){
            qDebug() << "Error: Fail to read." << sql_query2.lastError();
        }
        else
        {
            qDebug() << "success!";
            PID= sql_query2.value(0).toString();
            next = sql_query2.value(9).toInt();
        }
        //先删ticket表中的票根
        QString delete_sql=QString("DELETE FROM ticket WHERE PID = '%1'").arg(tlog->PID);
        if(!sql_query2.exec(delete_sql))
        {
            qDebug() << sql_query2.lastError();
        }
        else
        {
            qDebug() << "deleted!";
            cost-=tlog->price;
            int begin,end;
            findCityNum(*tlog,begin,end);
            mileage-=calDistance(cityp[begin],cityp[end]);
        }
        //如果有子票，就把subticket表中的子票都删掉
        if(next!=-1){
            i=1;
            while(p->next!=NULL){
                p=p->next;
                QString delete_sql=QString("DELETE FROM subticket WHERE PID='%1' AND next='%2'").arg(PID).arg(i);
                if(!sql_query2.exec(delete_sql))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "deleted!";
                }
                i++;
            }
        }
        //关闭数据库
        database.close();
    }
    //断开与数据库的连接
    QString name0 = QSqlDatabase::database().connectionName();
    QSqlDatabase::removeDatabase(name0);
    QSqlDatabase::removeDatabase("read_connection");
    QMessageBox msgBox;
    //弹窗告知用户退票成功
    msgBox.setText("退票成功");
    msgBox.setInformativeText("点击OK返回主界面");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    //将票从程序的我的票据数组中删除，并加入失效票数组
    prelogs[mypreticketnum].setlogL(tlog);
    prelogs[mypreticketnum].setstatus("退票");
    mypreticketnum++;
    int ret = msgBox.exec();
    for(i=0;i<myticketnum;i++){
        if(&userLogs[i]==tlog) {
            for(j=i;j<myticketnum-1;j++){
                userLogs[j]=userLogs[j+1];
            }
            myticketnum--;
            tlog->clear();
            break;
        }
    }
    //更新主数据库的用户消费与里程信息
    updateUserCostandMileage(cost,mileage,username);
    this->show();
    //刷新页面
    on_pushButton_2_clicked();
}
//始发地与目的地交换按钮
void MainWindow::on_button_swap_clicked()
{
    QString dep=ui->lineEditdep->text();
    QString ari=ui->lineEditari->text();
    ui->lineEditdep->setText(ari);
    ui->lineEditari->setText(dep);
}
//工具栏控制按钮，用户控制工具栏是否显示
void MainWindow::on_pushButton_0_clicked()
{
    if(btvisible==true){
        ui->pushButton_1->setVisible(0);
        ui->pushButton_2->setVisible(0);
        ui->pushButton_3->setVisible(0);
        ui->pushButton_back->setVisible(0);
        btvisible=false;
    }
    else{
        ui->pushButton_1->setVisible(1);
        ui->pushButton_2->setVisible(1);
        ui->pushButton_3->setVisible(1);
        ui->pushButton_back->setVisible(1);
        btvisible=true;
    }
}

/*
搜索按钮槽函数即搜索功能的实现：
    func：
    1.对搜索输入进行检查，包括目的地，始发地是否为空，是否相同，是否合法。
    2.刷新搜索算法与用户搜索地点权重
    3.根据用户选择的模式进行机票搜索
    4.根据机票特征获取筛选条件
    5.计算搜索用时，并显示机票
    mid args：
        mode：0为智能搜索，1为费用最少，2为时间最短，3为直飞，5为费用最少深度，6为时间最短深度
    write args:
        ui->lineEditdep：始发地输入栏
        ui->lineEditari：目的地输入栏
        time_money：费用最少搜索方式权重
        time_time：时间最短搜索方式权重
        time_straight：直飞搜索方式权重
        citytimesfrom：用户搜索始发地权重
        citytimesto：用户搜索目的地权重
        sortmode：前一排序模式
        logs:搜索票据数组
        ticketnum：搜索票据数组中的票据数量
        ticket_checkednum：已经做过有效性检测的票据数量
*/
void MainWindow::on_pushButton_4_clicked()
{
    int nodeNum=16, arcNum=241, begin,end;
    int i=0,j,k;
    bool label,labeldep=false,labelari=false;
    if(ui->lineEditdep->text()!=ui->lineEditari->text()) {
        for(i=0;i<16;i++){
            if(ui->lineEditdep->text()==citys[i]) labeldep=true;
            if(ui->lineEditari->text()==citys[i]) labelari=true;
        }
    }
    if(labeldep==false && i!=0) {
        if(ui->lineEditdep->text()=="") ui->lineEditdep->setPlaceholderText("请输入始发地");
        else{
            ui->lineEditdep->setText("");
            ui->lineEditdep->setPlaceholderText("请输入正确的始发地");
        }
        ui->lineEditdep->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");

    }
    if(labelari==false && i!=0) {
        if(ui->lineEditari->text()=="") ui->lineEditari->setPlaceholderText("请输入目的地");
        else{
            ui->lineEditari->setText("");
            ui->lineEditari->setPlaceholderText("请输入正确的目的地");
        }
        ui->lineEditari->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
    }
    if(i==0){
        if(ui->lineEditdep->text()==""){
            ui->lineEditdep->setPlaceholderText("请输入始发地");
            ui->lineEditari->setPlaceholderText("请输入目的地");
            ui->lineEditdep->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
            ui->lineEditari->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
        }
        else{
            ui->lineEditari->setText("");
            ui->lineEditari->setPlaceholderText("目的地不能等于始发地");
            ui->lineEditari->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
        }
    }
    if(labeldep==false || labelari==false) return;
    ui->lineEditdep->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
    ui->lineEditari->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
    layoutCleaner(2);
    for(i=0;i<=ticketnum;i++){
        logs[i].clear();
    }
    ticketnum=0;
    ticket_checkednum=0;
    QDate curDate =ui->dateEdit->date();
    QString year,month,day;
    int price=0,price0=0,mode,time_min,time_min0;
    year= QString::number(curDate.year());
    month= QString::number(curDate.month());
    day= QString::number(curDate.day());
    //根据下拉条目设置检索模式,如果未选择则直接返回
    if(ui->comboBox->currentIndex()<4 && ui->comboBox->currentIndex()>=0) mode=ui->comboBox->currentIndex();
    else return;
    //判断是否勾选深度搜索
    bool deepmode=ui->checkBox->checkState();
    //设置程序计时，并开始计时
    clock_t c_start, c_end;
    c_start = clock();
    //根据搜索方式改变权重，并进行权重衰减
    if(time_money!=0) time_money-=time_money/10;
    if(time_time!=0) time_time-=time_time/10;
    if(time_straight!=0) time_straight-=time_straight/10;
    if(mode==1) time_money++;
    else if(mode==2) time_time++;
    else if(mode==3) time_straight++;
    //将城市名称编码为序号
    for(begin=0;begin<17;begin++){
        if(citys[begin]==ui->lineEditdep->text()) break;
    }
    for(end=0;end<17;end++){
        if(citys[end]==ui->lineEditari->text()) break;
    }
    //如果用户已经登录，则根据搜索始发地与目的地改变权重，并进行权重衰减
    if(username!=""){
        for(i=0;i<16;i++){
            if(citytimesfrom[i]!=0) citytimesfrom[i]-=citytimesfrom[i]/16;
            if(citytimesto[i]!=0) citytimesto[i]-=citytimesto[i]/16;
            if(i==begin) citytimesfrom[i]++;
            if(i==end) citytimesto[i]++;
        }
    }
    //如果是时间最短搜索，则设置上一个排序方式为时间最短升序（为了后续进行排序算法优化），否则为价格排序升序
    if(mode==2) sortmode=1;
    else sortmode=2;
    //如果是费用最少和时间最短的深度搜索
    if(deepmode && mode!=3 && mode!=0){
        mode=mode+4;
        //新建图
        CMap* pMap = new CMap(nodeNum,10000);
        //按照搜索模式设置图的边及其权重
        CMapSet(curDate,citys,pMap,mode-4);
        Dist* dist,*dist0;
        //以begin为起点进行深度dijkstra搜索
        dist = pMap->DijkstraPlus(begin);
        //删除图
        delete pMap;
        for(i=0;i<16;i++) {
            qDebug() << dist[i].m_vertex;
            for(j=0;j<6;j++){
                qDebug() << dist[i].m_pre_vertex_list[j];
                qDebug() << dist[i].m_length_list[j];
            }
            qDebug() << "\n";
        }
        //获取最短路径，并设置访问数组（防止出现环路）
        bool blist[16];
        for(i=0;i<16;i++) {
            blist[i]=false;
        }
        //list保存了所有求出的最短及次短路径
        QStringList list = pMap->visit_plus(dist,begin,end,end,blist);
        for(i=0;i<list.size();i++) {
            qDebug() << list[i] << "\n";
        }
        //逐路径获取对应的机票，当票数大于400时停止
        while (!list.empty()) {
            setLog(list[0].toStdString(),mode);
            list.removeFirst();
            if(ticketnum>=400) break;
        }
    }
    else{
        //新建图
        CMap* pMap = new CMap(nodeNum,arcNum);
        int modeuser;
        //如果是费用最少或时间最短
        if(mode==1 || mode==2) CMapSet(curDate,citys,pMap,mode);
        //如果是智能搜索
        else if(mode==0){
            //根据用户搜索习惯设定智能搜索的基本模式（费用最少||时间最短）
            if(time_time>=time_straight && time_time>time_money){
                modeuser=2;
            }
            else modeuser=1;
            CMapSet(curDate,citys,pMap,modeuser);
        }
        //如果是智能搜索或直飞
        if(mode==3 || mode==0) {
            //首先搜索直飞航线
            string s="< "+to_string(begin)+" : 999 "+to_string(end)+" >";
            //获取直飞航线的机票
            setLog(s,mode);
            //如果是智能搜索并且票数过少
            if(mode==0 && ticketnum<10){
                //进行进一步搜索
                dist = pMap->Dijkstra(begin);
                //获取最低路径
                string s = pMap->visit_first(dist,begin,end);
                setLog(s,modeuser);
                //如果票数还是少
                if(ticketnum<10){
                    //获取次低路径
                    string s1 = pMap->visit_second(dist,begin,end);
                    setLog(s1,modeuser);
                    //如果还是少，转为进行深度搜索
                    if(ticketnum<3){
                        layoutCleaner(2);
                        for(i=0;i<=ticketnum;i++){
                            logs[i].clear();
                        }
                        ticketnum=0;
                        ticket_checkednum=0;
                        delete pMap;
                        pMap = new CMap(nodeNum,10000);
                        CMapSet(curDate,citys,pMap,modeuser);
                        dist = pMap->DijkstraPlus(begin);
                        for(i=0;i<16;i++) {
                            qDebug() << dist[i].m_vertex;
                            for(j=0;j<6;j++){
                                qDebug() << dist[i].m_pre_vertex_list[j];
                            }
                            qDebug() << "\n";
                        }
                        //获取最短路径，并设置访问数组（防止出现环路）
                        bool blist[16];
                        for(i=0;i<16;i++) {
                            blist[i]=false;
                        }
                        QStringList list = pMap->visit_plus(dist,begin,end,end,blist);
                        for(i=0;i<list.size();i++) {
                            qDebug() << list[i] << "\n";
                        }
                        while (!list.empty()) {
                            setLog(list[0].toStdString(),modeuser);
                            list.removeFirst();
                            if(ticketnum>=400) break;
                        }
                    }
                }
            }
            delete pMap;
        }
        //如果是普通的费用最少或时间最短模式
        else {
            dist = pMap->Dijkstra(begin);
            //获取最低路径
            string s = pMap->visit_first(dist,begin,end);
            setLog(s,mode);
            //获取次低路径
            string s1 = pMap->visit_second(dist,begin,end);
            setLog(s1,mode);
        }
    }
    //显示部分新增控件
    ui->label_10->setVisible(false);
    ui->label_11->setVisible(false);
    ui->label_14->setVisible(true);
    ui->pushButton_6->setVisible(true);
    ui->pushButton_7->setVisible(true);
    ui->pushButton_9->setVisible(true);
    ui->comboBox_2->setVisible(true);
    //开始获取筛选指标 st为航空公司指标list，sroute为路线指标list
    QStringList st,sroute;
    int pricemin[200];
    for(i=0;i<200;i++){
        pricemin[i]=INT_MAX;
    }
    if(ticketnum!=0){
        //获取航空公司指标
        for(i=0;i<ticketnum;i++){
            bool find=false;
            j=0;
            foreach (QString company,st){
                if(company==logs[i].company) {
                    find=true;
                    if(pricemin[j]>logs[i].price) pricemin[j]=logs[i].price;
                    break;
                }
                j++;
            }
            if(!find){
                st.append(logs[i].company);
                pricemin[j]=logs[i].price;
            }
        }
        //获取路线指标
        for(i=0;i<ticketnum;i++){
            bool find=false;
            foreach (QString route,sroute){
                if(route==logs[i].route) {
                    find=true;
                    break;
                }
                j++;
            }
            if(!find){
                sroute.append(logs[i].route);
            }
        }
        //将迪杰斯特拉路线翻译为人能看懂的格式
        for(i=0;i<sroute.count();i++){
            sroute[i]=routeTranslate(sroute[i]);
        }
        //规范化航空公司指标
        for(i=0;i<st.count();i++){
            st[i]=st[i]+" ￥"+QString::number(pricemin[i]);
        }
        //向筛选滚动区域内添加指标控件
        QWidget *wid=new QWidget();
        QVBoxLayout *l=new QVBoxLayout();
        foreach (QString var, st) {
            QCheckBox *b=new QCheckBox();
            b->setText(var);
            b->setObjectName(var);
            connect(b,&QCheckBox::stateChanged,this,&MainWindow::getScrollBarMessage);
            l->addWidget(b);
        }
        foreach (QString var, sroute) {
            QCheckBox *b=new QCheckBox();
            b->setText(var);
            b->setObjectName(var);
            connect(b,&QCheckBox::stateChanged,this,&MainWindow::getScrollBarMessage);
            l->addWidget(b);
        }
        wid->setLayout(l);
        ui->scrollArea->setWidget(wid);
        ui->pushButton_12->setVisible(true);
    }
    //向机票滚动区域内放置机票
    if(logs[2].ID=="" || logs[2].des=="不可达"){
        k=2;
        if(logs[1].ID=="" || logs[1].des=="不可达") k=1;
        if(logs[0].ID=="" || logs[0].des=="不可达") {
            k=0;
            Log* logno=new Log();
            logno->setLog("没有航空公司","123456","不可达","不可达","00:00","25:00",0,"0%","");
            ticketInfo* ticket0=new ticketInfo(logno,2);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            ui->verticalLayout_2->addWidget(ticket0);
        }
        for(i=0;i<k;i++){
            ticketInfo* ticket0=new ticketInfo(&logs[i],0);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            ui->verticalLayout_2->addWidget(ticket0);
        }
    }
    else{
        for(i=0;i<3;i++){
            ticketInfo* ticket0=new ticketInfo(&logs[i],0);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            ui->verticalLayout_2->addWidget(ticket0);
        }
    }
    //停止计时，并显示搜索时间
    c_end = clock();
    ui->label_14->setText("查询用时："+QString::number((double)(c_end - c_start) / CLOCKS_PER_SEC)+"s");
    printf("time=%f\n", (double)(c_end - c_start) / CLOCKS_PER_SEC);
    copymode=0;
    ticket_now=0;
}

//搜索页面滚动条
void MainWindow::on_verticalScrollBar_2_valueChanged(int value)
{
    Log* scrollLogs;
    int scrollTicketnum;
    int position=ui->verticalScrollBar_2->sliderPosition();
    //如果是普通模式
    if(copymode==0){
        scrollLogs=logs;
        scrollTicketnum=ticketnum;
        if(scrollTicketnum>2){
            int i=0;
            int j=3;
            j=(scrollTicketnum+1)*((double)position/(double)999);
            if(j<3)j=3;
            if(j>scrollTicketnum) j=scrollTicketnum;
            layoutCleaner(2);
            ticket_now=j-3;
            ticketInfo* ticket0=new ticketInfo(&scrollLogs[j-3],0);
            ticketInfo* ticket1=new ticketInfo(&scrollLogs[j-2],0);
            ticketInfo* ticket2=new ticketInfo(&scrollLogs[j-1],0);
            ui->verticalLayout_2->addWidget(ticket0);
            ui->verticalLayout_2->addWidget(ticket1);
            ui->verticalLayout_2->addWidget(ticket2);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            connect(ticket1,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            connect(ticket2,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
        }
    }
    //如果是筛选模式
    else if(copymode==1 && copynum>2){
        scrollTicketnum=copynum;
        int i=0;
        int j=3;
        j=(scrollTicketnum+1)*((double)position/(double)999);
        if(j<3)j=3;
        if(j>scrollTicketnum) j=scrollTicketnum;
        layoutCleaner(2);
        ticket_now=j-3;
        ticketInfo* ticket0=new ticketInfo(copylogs[j-3],0);
        ticketInfo* ticket1=new ticketInfo(copylogs[j-2],0);
        ticketInfo* ticket2=new ticketInfo(copylogs[j-1],0);
        ui->verticalLayout_2->addWidget(ticket0);
        ui->verticalLayout_2->addWidget(ticket1);
        ui->verticalLayout_2->addWidget(ticket2);
        connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
        connect(ticket1,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
        connect(ticket2,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
    }
}
/*
通过dijiestra算法的输出生成票据的函数：setLog
    func：根据输入的dijiestra算法路径字符串与搜索模式从航班数据中搜索符合要求的票据，并将其放入logs数组中，并展示前3个票据到滚动区域中。
    input args：
        s:dijiestra算法路径字符串
        mode:搜索模式
    write args:
        logs:搜索票据数组
        ticketnum：搜索票据数组中的票据数量
        ticket_checkednum：已经做过有效性检测的票据数量
*/
void MainWindow::setLog(string s,int mode){
    QDate curDate =ui->dateEdit->date();
    curdate=curDate;
    QString year,month,day;
    QString company,ID,sou,des,time0,time1,chi;
    int price=0,price0=0,price_max=0;
    // year= QString::number(curDate.year());
    // month= QString::number(curDate.month());
    // day= QString::number(curDate.day());
    year="2024";
    month="9";
    day="20";
    QString fname,info0;
    QString qs=QString::fromStdString(s);
    QStringList qsl=qs.split(' ');
    QRegularExpression numbers( "0|[1-9]\\d{0,1}" );
    QRegularExpressionMatch matchnum;
    QString coc="",ari="",beg="",las="";
    QStringList mid[5];
    Log *p,*q;
    int i=0,j=0,k=0;
    //解析dijiestra算法路径字符串
    foreach (QString item, qsl) {
        //使用数字正则表达式匹配字符串
        matchnum = numbers.match(item);
        if(item=="不可达") return;
        //如果匹配成功
        if(matchnum.hasMatch()){
            //如果小于20，则为城市信息
            if(item.toInt()<20){
                //如果始发地为空，则设置始发地
                if(coc=="") coc=citys[item.toInt()];
                //否则加入中转数组
                else {
                    mid->append(citys[item.toInt()]);
                    i++;
                }
                //设置目的地
                ari=citys[item.toInt()];
            }
            //否则认为是路径长度信息，赋值给路径长度
            else if(price_max<item.toInt()) price_max=item.toInt();
        }
    }
    //将中转城市的最后一个去除（将目的地去除）
    mid->removeLast();
    beg=coc;
    i=0;
    j=ticket_checkednum;
    //如果是直飞
    if(mid->empty()){
        fname=pathCreator("")+year+"."+month+"."+day+"/"+ coc + "-" + ari + ".txt";
        //读取当日航班
        QFile fs(fname);
        if(fs.open(QIODeviceBase::ReadOnly)){
            QTextStream in(&fs);
            in.setEncoding(QStringConverter::System);
            //获取每行航班信息
            while (in.atEnd()==false){
                info0=in.readLine();
                QStringList infos=info0.split('/');
                i=0;
                /*
                    获取该行每个部分的信息
                        company：航空公司
                        ID：航班号
                        sou：始发地
                        des：目的地
                        time0：始发时间
                        time1：到达时间
                        price：价格
                        chi：准点率
                 */
                foreach (QString item, infos) {
                    switch(i){
                    case(0):company=item;break;
                    case(1):ID=item;break;
                    case(2):sou=item;break;
                    case(3):des=item;break;
                    case(4):time0=item;break;
                    case(5):time1=item;break;
                    case(6):price=item.toInt();break;
                    case(7):chi=item;break;
                    }
                    i++;
                }
                //将信息设置到票据中
                logs[j].setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                //设置路径信息
                logs[j].setRoute(QString::fromStdString(s));
                //表示该票没有子票（直飞）
                logs[j].next=NULL;
                j++;
            }
            //QuickSort2(logs,j);
            // for(i=ticket_checkednum;i<j;i++){
            //     qDebug() <<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
            // }
        }
        //更新当前票据数量
        ticketnum=j;
        //更新已检查票据数量
        ticket_checkednum=ticketnum;
        fs.close();
        //按价格排序（随机轴值）
        QuickSort(logs,ticketnum,2,1);
    }
    //如果有中转
    else{
        //获取中转地
        las=mid->first();
        while(1){
            //如果是从始发地出发的
            if(beg==coc){
                //读取当日航班
                fname=pathCreator("")+year+"."+month+"."+day+"/"+ coc + "-" + las + ".txt";
                QFile fs(fname);
                if(fs.open(QIODeviceBase::ReadOnly)){
                    //获取每行航班信息
                    QTextStream in(&fs);
                    in.setEncoding(QStringConverter::System);
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        QStringList infos=info0.split('/');
                        i=0;
                        /*
                            获取该行每个部分的信息
                                company：航空公司
                                ID：航班号
                                sou：始发地
                                des：目的地
                                time0：始发时间
                                time1：到达时间
                                price：价格
                                chi：准点率
                        */
                        foreach (QString item, infos) {
                            switch(i){
                            case(0):company=item;break;
                            case(1):ID=item;break;
                            case(2):sou=item;break;
                            case(3):des=item;break;
                            case(4):time0=item;break;
                            case(5):time1=item;break;
                            case(6):price=item.toInt();break;
                            case(7):chi=item;break;
                            }
                            i++;
                        }
                        //将信息设置到一个新的票据中
                        Log* log0=new Log();
                        log0->setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                        //并将票根的子票指针指向新的票据
                        logs[j].next=log0;
                        //将信息设置到票根中
                        logs[j].setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                        //设置路径
                        logs[j].setRoute(QString::fromStdString(s));
                        j++;
                    }
                    //QuickSort4(logs,j);
                    // for(i=ticket_checkednum;i<j;i++){
                    //     qDebug() << "首" <<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
                    // }
                }
                //更新当前票据数量
                ticketnum=j;
                fs.close();
                //将中转地设为下一次始发地
                beg=mid->first();
                mid->removeFirst();
                //如果中转数组为空，则将下一个目的地设为最终目的地
                if(mid->empty()) las=ari;
                //否则从中转数组中获取下一个中转地
                else las=mid->first();
            }
            else{
                j=0;
                //Log logs0[1000];
                //新建转机子票据数据
                fname=pathCreator("")+year+"."+month+"."+day+"/"+ beg + "-" + las + ".txt";
                QFile fs(fname);
                if(fs.open(QIODeviceBase::ReadOnly)){
                    QTextStream in(&fs);
                    in.setEncoding(QStringConverter::System);
                    int linenum=0;
                    while (in.atEnd()==false){
                        in.readLine();
                        linenum++;
                    }
                    Log logs0[linenum];
                    in.seek(0);
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        QStringList infos=info0.split('/');
                        i=0;
                        foreach (QString item, infos) {
                            switch(i){
                            case(0):company=item;break;
                            case(1):ID=item;break;
                            case(2):sou=item;break;
                            case(3):des=item;break;
                            case(4):time0=item;break;
                            case(5):time1=item;break;
                            case(6):price=item.toInt();break;
                            case(7):chi=item;break;
                            }
                            i++;
                        }
                        logs0[j].setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                        j++;
                    }
                    //如果搜索模式为费用最少（普通或深度搜索），对子票据进行起飞时间排序（快排随机轴值），并进行归并价格排序
                    if(mode==1 || mode==5) {
                        QuickSort(logs0,j,3,1);
                        Log logs0merge[1000];
                        mergeSort(logs0,logs0merge,0,j-1);
                    }
                    // for(i=0;i<j;i++){
                    //     qDebug() <<"中"<<logs0[i].company<<logs0[i].ID<<logs0[i].sou<<logs0[i].des<<logs0[i].time0<<logs0[i].time1<<logs0[i].price<<logs0[i].chi<< "\n";
                    // }
                    int log_number=0,l=ticketnum-1;
                    bool repeat=false;
                    //以前面的票据为票根，开始搜索哪一个票据符合转机要求，并将其添加到其中
                    for(i=ticket_checkednum;i<ticketnum;i++){
                        //如果时间跨度以经超过两天，不继续进行搜索
                        if(logs[i].time1.right(2)=="+2"){
                            logs[i].des="不可达";
                            continue;
                        }
                        //如果该票被废弃，不继续进行搜索
                        if(logs[i].des=="不可达") continue;
                        //如果时间跨度未超过一天
                        if(logs[i].time1.right(2)!="+1"){
                            if(mode==2 || mode==6) QuickSort_Turn(logs[i],logs0,j,1);
                            // //如果是时间最短算法并且没找到则不继续进行搜索
                            if(timediffer(logs[i].time1,logs0[0].time0)<0 && (mode==2 || mode==6)) {
                                logs[i].des="不可达";
                                continue;
                            }
                            repeat=false;
                            log_number=0;
                            QString time_preserve=logs[i].time1;
                            //开始查找符合转机条件的机票
                            for(k=0; k<j;k++){
                                //如果转机时间在1到10个小时内，就将其添加进来
                                if(timediffer(time_preserve,logs0[k].time0)>60 && timediffer(time_preserve,logs0[k].time0)<600){
                                    //如果是本轮第一次添加，则直接加到本体上面
                                    if(!repeat) {
                                        p=&logs[i];
                                        while(p->next!=NULL){
                                            p=p->next;
                                        }
                                        Log* log2=new Log();
                                        p->next=log2;
                                        QString chi0=logs[i].chi.left(logs[i].chi.size()-1),chi1=logs0[k].chi.left(logs0[k].chi.size()-1);
                                        if(chi1.toDouble()<chi0.toDouble()) logs[i].chi=logs0[k].chi;
                                        log2->setLog(logs0[k].company,logs0[k].ID,logs0[k].sou,logs0[k].des,logs0[k].time0,logs0[k].time1,logs0[k].price,logs0[k].chi,curdate.toString());
                                        logs[i].des=logs0[k].des;
                                        logs[i].price=logs[i].price+logs0[k].price;
                                        logs[i].time1=logs0[k].time1;
                                        repeat=true;
                                    }
                                    //否则在数组尾部创建一个新的，并深复制所有数据过去
                                    else{
                                        int price1=0;
                                        QString chi_min=logs[i].chi;
                                        l++;
                                        p=&logs[i];
                                        q=&logs[l];
                                        while(p->next->next!=NULL){
                                            p=p->next;
                                            price1=price1+p->price;
                                            QString chi0=chi_min.left(chi_min.size()-1),chi1=p->chi.left(p->chi.size()-1);
                                            if(chi1.toDouble()<chi0.toDouble()) chi_min=p->chi;
                                            Log* log1=new Log();
                                            log1->setLog(p->company,p->ID,p->sou,p->des,p->time0,p->time1,p->price,p->chi,curdate.toString());
                                            q->next=log1;
                                            q=q->next;
                                        }
                                        logs[l].setLog(logs[i].company,logs[i].ID,logs[i].sou,logs0[k].des,logs[i].time0,logs0[k].time1,logs0[k].price+price1,chi_min,curdate.toString());
                                        logs[l].setRoute(QString::fromStdString(s));
                                        Log* log2=new Log();
                                        log2->setLog(logs0[k].company,logs0[k].ID,logs0[k].sou,logs0[k].des,logs0[k].time0,logs0[k].time1,logs0[k].price,logs0[k].chi,curdate.toString());
                                        q->next=log2;
                                    }
                                    log_number++;
                                    //如果本轮获取了三或六个子票以后直接结束查找
                                    if(log_number>=3 && mode<4) break;//&&mode<4
                                    else if(log_number>=6) break;
                                }
                            }
                            //如果当天没有找到机票，则去第二天查找
                            if(log_number==0) findSecondDay(logs,logs0,ticketnum,ticket_checkednum,i,mode,j,l,curdate,s);
                        }
                        //如果时间跨度超过一天，搜索第二天的航班数据并进行匹配
                        else{
                            QString pretime1=logs[i].time1.left(logs[i].time1.size()-2);
                            //如果搜索模式为时间最短（普通或深度搜索），对子票据进行快排起飞时间排序（随机轴值），并进行归并转机时间排序
                            if(mode==2 || mode==6) {
                                Log *log1=new Log();
                                log1->time1=pretime1;
                                QuickSort_Turn(*log1,logs0,j,1);
                                delete log1;
                            }
                            //如果搜索模式为最短时间，如果未找到合适的航班，就跳过这次循环
                            if(timediffer(pretime1,logs0[0].time0)<0 && (mode==2 || mode==6)) {
                                logs[i].des="不可达";
                                continue;
                            }
                            repeat=false;
                            log_number=0;
                            for(k=0; k<j;k++){
                                if(timediffer(pretime1,logs0[k].time0)>60 && timediffer(pretime1,logs0[k].time0)<600){
                                    if(!repeat) {
                                        p=&logs[i];
                                        while(p->next!=NULL){
                                            p=p->next;
                                        }
                                        Log* log2=new Log();
                                        p->next=log2;
                                        QString chi0=logs[i].chi.left(logs[i].chi.size()-1),chi1=logs0[k].chi.left(logs0[k].chi.size()-1);
                                        if(chi1.toDouble()<chi0.toDouble()) logs[i].chi=logs0[k].chi;
                                        log2->setLog(logs0[k].company,logs0[k].ID,logs0[k].sou,logs0[k].des,logs0[k].time0,logs0[k].time1,logs0[k].price,logs0[k].chi,curdate.addDays(1).toString());
                                        logs[i].des=logs0[k].des;
                                        logs[i].price=logs[i].price+logs0[k].price;
                                        QString ssss=logs0[k].time1;
                                        if(logs0[k].time1.right(2)=="+1"){
                                            ssss=logs0[k].time1.left(logs0[k].time1.size()-2)+"+2";
                                        }
                                        else ssss=logs0[k].time1+"+1";
                                        //将票根的目的时间设为子票的目的时间并调整日期
                                        logs[i].time1=ssss;
                                        repeat=true;
                                    }
                                    else{
                                        int price1=0;
                                        QString chi_min=logs[i].chi;
                                        l++;
                                        p=&logs[i];
                                        q=&logs[l];
                                        while(p->next->next!=NULL){
                                            p=p->next;
                                            price1=price1+p->price;
                                            QString chi0=chi_min.left(chi_min.size()-1),chi1=p->chi.left(p->chi.size()-1);
                                            if(chi1.toDouble()<chi0.toDouble()) chi_min=p->chi;
                                            Log* log1=new Log();
                                            log1->setLog(p->company,p->ID,p->sou,p->des,p->time0,p->time1,p->price,p->chi,p->curdate);
                                            q->next=log1;
                                            q=q->next;
                                        }
                                        Log* log2=new Log();
                                        log2->setLog(logs0[k].company,logs0[k].ID,logs0[k].sou,logs0[k].des,logs0[k].time0,logs0[k].time1,logs0[k].price,logs0[k].chi,curdate.addDays(1).toString());
                                        QString ssss=logs0[k].time1;
                                        //将票根的目的时间设为子票的目的时间并调整日期
                                        if(logs0[k].time1.right(2)=="+1"){
                                            ssss=logs0[k].time1.left(logs0[k].time1.size()-2)+"+2";
                                        }
                                        else ssss=logs0[k].time1+"+1";
                                        logs[l].setLog(logs[i].company,logs[i].ID,logs[i].sou,logs0[k].des,logs[i].time0,ssss,logs0[k].price+price1,chi_min,curdate.toString());
                                        logs[l].setRoute(QString::fromStdString(s));
                                        q->next=log2;
                                    }
                                    log_number++;
                                    if(log_number>=3 && mode<4) break;//&&mode<4
                                    else if(log_number>=6) break;
                                }
                            }
                            if(log_number==0) logs[i].des="不可达";
                        }
                    }
                    //删除所有无效票据
                    ticketnum=l+1;
                    for(i=ticket_checkednum;i<=ticketnum;i++){
                        if(logs[i].des=="不可达"){
                            for(j=i;j<=ticketnum;j++){
                                logs[j]=logs[j+1];
                            }
                            if(ticketnum==1){
                                logs[0].setLog("没有航空公司","123456","不可达","不可达","00:00","25:00",0,"0%","");
                            }
                            logs[ticketnum].clear();
                            i--;
                            ticketnum--;
                        }
                    }
                    // for(i=0;i<ticketnum;i++){
                    //     qDebug() <<"过"<<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
                    // }
                }
                fs.close();
                //如果已经找到终点，退出循环
                if(las==ari) break;
                beg=mid->first();
                mid->removeFirst();
                if(mid->empty()) las=ari;
                else las=mid->first();
            }
        }
        //删除所有无效票据
        for(i=ticket_checkednum;i<=ticketnum;i++){
            if(logs[i].des=="不可达"){
                for(j=i;j<=ticketnum;j++){
                    logs[j]=logs[j+1];
                }
                if(ticketnum==1){
                    logs[0].setLog("没有航空公司","123456","不可达","不可达","00:00","25:00",0,"0%","");
                }
                i--;
                ticketnum--;
            }
            // else{
            //     qDebug() <<"结"<<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
            // }
        }
        //如果票数过多，仅保留500张
        if(ticketnum<0) ticketnum=0;
        if(ticketnum>500) {
            for(i=500;i<=ticketnum;i++){
                logs[i].clear();
            }
            ticketnum=500;
        }
        //如果是费用最少算法，进行价格排序
        if(mode==1 || mode==5) QuickSort(logs,ticketnum,2,1);
        //如果是时间最短算法，进行飞行时间排序
        else if(mode==2 || mode==6) QuickSort(logs,ticketnum,1,1);
        //更新已检查票据数量
        ticket_checkednum=ticketnum;
    }
}
//登录按钮槽函数
void MainWindow::on_pushButton_5_clicked()
{
    //如果还没登录则弹出登录界面
    if(!login){
        if(loginW==NULL){
            loginW=new Login();
            loginW->show();
            connect(loginW,&Login::sendToMainWindow,this,&MainWindow::getLoginMessage);
        }
        else loginW->raise();
    }
    //否则弹出用户展示界面
    else{
        userinfo *userui=new userinfo(username,cost,mileage);
        userui->show();
        connect(userui,&userinfo::sendToMainWindow,this,&MainWindow::getuserinfoMessage);
    }
}

//始发地输入栏的提示词生成函数
void MainWindow::on_lineEditdep_textChanged(const QString &arg1)
{
    int i,j,k;
    bool label,labeldep=false,labelari=false;
    if(ui->lineEditdep->text()!=""){
        for(i=0;i<16;i++){
            if(citys[i].mid(0,ui->lineEditdep->text().length()).contains(ui->lineEditdep->text())) {
                if(labeldep) {
                    ui->label_12->setText(ui->label_12->text()+"/"+citys[i].last(citys[i].length()-1));
                    ui->label_12->setMinimumWidth(90);
                }
                else {
                    ui->label_12->setText(citys[i]);
                    if(citys[i].length()==4) ui->label_12->setMinimumWidth(70);
                    else ui->label_12->setMinimumWidth(0);
                }
                labeldep=true;
            }
        }
    }
    else {
        ui->label_12->setText("");
        ui->label_12->setMinimumWidth(0);
    }
}

//目的地输入栏的提示词生成函数
void MainWindow::on_lineEditari_textChanged(const QString &arg1)
{
    int i;
    bool label,labelari=false;
    if(ui->lineEditari->text()!=""){
        for(i=0;i<16;i++){
            if(citys[i].mid(0,ui->lineEditari->text().length()).contains(ui->lineEditari->text())) {
                if(labelari) {
                    ui->label_13->setText(ui->label_13->text()+"/"+citys[i].last(citys[i].length()-1));
                    ui->label_13->setMinimumWidth(90);
                }
                else {
                    ui->label_13->setText(citys[i]);
                    if(citys[i].length()==4) ui->label_13->setMinimumWidth(70);
                    else ui->label_13->setMinimumWidth(0);
                }
                labelari=true;
            }
        }
    }
    else {
        ui->label_13->setText("");
        ui->label_13->setMinimumWidth(0);
    }
}

/*
向下移动按钮槽函数：
    注：一次一个票据，仅在票据数量大于滚动区域单次能显示的数量时才管用。
    搜索界面与退改签界面公用
    func：
        搜索界面普通模式
        搜索界面筛选模式
        退改签界面普通模式
        退改签界面改签模式
        退改签界面筛选模式
        退改签界面过往票据模式
*/
void MainWindow::on_pushButton_7_clicked()
{
    if(ui->pushButton_1->isChecked()){
        //搜索界面普通模式
        if(copymode==0 && ticketnum>3 && ticket_now<ticketnum-3){
            int i=0,j;
            layoutCleaner(2);
            ticket_now=ticket_now+1;
            j=ticket_now+3;
            for(i=j-3;i<j;i++){
                ticketInfo* ticket0=new ticketInfo(&logs[i],0);
                ui->verticalLayout_2->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
            //ui->verticalScrollBar_2->setValue(ticket_now/(double)(ticketnum-3)*999);
        }
        //搜索界面筛选模式
        else if(copymode==1 && copynum>3 && ticket_now<copynum-3){
            int i=0,j;
            layoutCleaner(2);
            ticket_now=ticket_now+1;
            j=ticket_now+3;
            for(i=j-3;i<j;i++){
                ticketInfo* ticket0=new ticketInfo(copylogs[i],0);
                ui->verticalLayout_2->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
        }
    }
    else if(ui->pushButton_2->isChecked()){
        //退改签界面改签模式
        if(changemode==1){
            if(ticketnum>5 && ticket_now<ticketnum-5){
                int i=0,j;
                layoutCleaner(7);
                ticket_now=ticket_now+1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(&logs[i],clog,4);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
                //ui->verticalScrollBar_3->setValue(ticket_now/(double)(ticketnum-5)*999);
            }
        }
        else{
            //退改签界面过往票据模式
            if(copymode==0 && premode==1 && myticketnum+mypreticketnum>5 && ticket_now<myticketnum+mypreticketnum-5){
                int i=0,j;
                layoutCleaner(7);
                ticket_now=ticket_now+1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0;
                    if(i>=myticketnum){
                        ticket0=new ticketInfo(&prelogs[i-myticketnum],3);
                    }
                    else ticket0=new ticketInfo(&userLogs[i],3);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
            }
            //退改签界面普通模式
            else if(copymode==0 && myticketnum>5 && ticket_now<myticketnum-5){
                int i=0,j;
                layoutCleaner(7);
                ticket_now=ticket_now+1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
                //ui->verticalScrollBar_3->setValue((ticket_now/(double)(myticketnum-5))*999);
            }
            //退改签界面筛选模式
            else if(copymode==1 && copynum>5 && ticket_now<copynum-5){
                int i=0,j;
                layoutCleaner(7);
                ticket_now=ticket_now+1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(copylogs[i],3);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
            }
        }
    }
}

/*
向上移动按钮槽函数：
    注：一次一个票据，仅在票据数量大于滚动区域单次能显示的数量时才管用。
    搜索界面与退改签界面公用
    func：
        搜索界面普通模式
        搜索界面筛选模式
        退改签界面普通模式
        退改签界面改签模式
        退改签界面筛选模式
        退改签界面过往票据模式
*/
void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_1->isChecked()){
        //搜索界面普通模式
        if(copymode==0 && ticketnum>3 && ticket_now>0){
            int i=0,j;
            layoutCleaner(2);
            ticket_now=ticket_now-1;
            j=ticket_now+3;
            for(i=j-3;i<j;i++){
                ticketInfo* ticket0=new ticketInfo(&logs[i],0);
                ui->verticalLayout_2->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
            //ui->verticalScrollBar_2->setValue(ticket_now/(double)(ticketnum-3)*999);
        }
        //搜索界面筛选模式
        else if(copymode==1 && copynum>3 && ticket_now>0){
            int i=0,j;
            layoutCleaner(2);
            ticket_now=ticket_now-1;
            j=ticket_now+3;
            for(i=j-3;i<j;i++){
                ticketInfo* ticket0=new ticketInfo(copylogs[i],0);
                ui->verticalLayout_2->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
        }
    }
    else if(ui->pushButton_2->isChecked()){
        //退改签界面改签模式
        if(changemode==1){
            if(ticketnum>5 && ticket_now>0){
                int i=0,j;
                layoutCleaner(7);
                ticket_now=ticket_now-1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(&logs[i],clog,4);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
                //ui->verticalScrollBar_3->setValue(ticket_now/(double)(ticketnum-5)*999);
            }
        }
        else{
            //退改签界面过往票据模式
            if(copymode==0 && premode==1 && myticketnum+mypreticketnum>5 && ticket_now>0){
                int i=0,j;
                layoutCleaner(7);
                ticket_now=ticket_now-1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0;
                    if(i>=myticketnum) ticket0=new ticketInfo(&prelogs[i-myticketnum],3);
                    else ticket0=new ticketInfo(&userLogs[i],3);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
            }
            //退改签界面普通模式
            if(copymode==0 && myticketnum>5 && ticket_now>0){
                int i=0,j;
                layoutCleaner(7);
                ticket_now=ticket_now-1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
                //ui->verticalScrollBar_3->setValue(ticket_now/(double)(myticketnum-5)*999);
            }
            //退改签界面筛选模式
            else if(copymode==1 && copynum>5 && ticket_now>0){
                int i=0,j;
                layoutCleaner(7);
                ticket_now=ticket_now-1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(copylogs[i],3);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
            }
        }
    }
}
/*
登录界面返回信息的接收函数： getLoginMessage
    func：
        1.接收所有用户信息
        2.计算用户画像
        3.设置个性化广告
    args：
        username：用户名
        mylog：用户有效票据数组
        prelogs：用户失效票据数据
        myticketnum：用户有效票据数量
        mypreticketnum：用户失效票据数量
        home：用户家所在城市
        probability：home对应的概率
        common：用户常去地
        pco：common对应的概率
        time_money，time_time，time_straight：分别是费用最少，时间最短，直飞搜索算法的用户权重
        citytimesfrom：用户全部始发城市的搜索权重数组
        citytimesto：用户全部目的城市的搜索权重数组
        cost：用户累计消费
        mileage：用户累计里程
*/
void MainWindow::getLoginMessage(QString username,Log* mylog,Log * prelogs,int myticketnum,int mypreticketnum,int home,double probability,int common,double pco,float time_money,float time_time,float time_straight,float *citytimesfrom,float *citytimesto,int cost,int mileage){
    if(username!=""){
        this->username=username;
        this->userLogs=mylog;
        this->prelogs=prelogs;
        this->myticketnum=myticketnum;
        this->mypreticketnum=mypreticketnum;
        ui->pushButton_5->setText("你好！ "+username);
        login=true;
        this->home=home;
        this->probability=probability;
        this->common=common;
        this->pco=pco;
        this->time_money=time_money;
        this->time_time=time_time;
        this->time_straight=time_straight;
        this->citytimesfrom=citytimesfrom;
        this->citytimesto=citytimesto;
        this->cost=cost;
        this->mileage=mileage;
        if(ui->pushButton_2->isChecked()) on_pushButton_2_clicked();
        else if(ui->pushButton_3->isChecked()) on_pushButton_3_clicked();
        bool bus=false;
        float probus=0;
        userImageAnalyse(userLogs,&bus,&probus);
        userSearchAnalyse(&commonfrom,&commonto,&profrom,&proto);
        setAD(bus);
    }
    loginW=NULL;
}
//用户展示界面返回的 退出登录信息的接收函数
void MainWindow::getuserinfoMessage()
{
    this->login=false;
    this->username="";
    this->myticketnum=0;
    ui->pushButton_5->setText("登录");
}
//搜索方式下拉栏变化槽函数，用于设置深度搜索按钮的可用性（智能搜索与直飞禁用）
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index==0 || index==3) ui->checkBox->setDisabled(true);
    else ui->checkBox->setDisabled(false);
}

//退改签界面初始化函数
void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->isChecked()){
        //由于与其他界面有公用控件，所以才需要以下语句设置控件
        layoutCleaner(2);
        layoutCleaner(7);
        widget0->show();
        resetChecked();
        ui->pushButton_2->setChecked(true);
        ui->pushButton_6->setVisible(true);
        ui->pushButton_7->setVisible(true);
        ui->label_3->setVisible(false);
        ui->label_12->setVisible(false);
        ui->label_13->setVisible(false);
        ui->label_14->setVisible(false);
        ui->lineEditari->setVisible(false);
        ui->lineEditdep->setVisible(false);
        ui->easystay->setVisible(false);
        ui->backgroundsky->setVisible(false);
        ui->checkBox->setVisible(false);
        ui->home_background->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->layoutbutton->setVisible(false);
        ui->layoutbutton_2->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->widget_2->setVisible(false);
        //修改位置
        ui->pushButton_9->setVisible(true);
        ui->comboBox_2->setVisible(true);
        ui->pushButton_12->setVisible(false);
        ui->scrollArea->setVisible(false);
        ui->comboBox_2->setGeometry(180,65,201,22);
        //由于退改签界面的排序规则比搜索界面更多，因此加入新的规则
        if(ui->comboBox_2->count()==10){
            ui->comboBox_2->addItems({"PID-升序","PID-降序","出发日期-升序","出发日期-降序"});
        }
        ui->pushButton_9->setGeometry(390,65,31,22);
        ui->label_4->setVisible(false);
        ui->label_7->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->label_8->setVisible(false);
        ui->dateEdit->setVisible(false);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        button_swap->setVisible(false);
        ui->verticalScrollBar_2->setVisible(false);
        ui->verticalScrollBar_3->setVisible(true);
        ui->widget->setVisible(false);
        QDateTime time= QDateTime::currentDateTime();//获取系统当前的时间
        ui->dateEdit_2->setDateTime(time);
        ui->dateEdit_2->setGeometry(460,65,140,22);
        ui->dateEdit_2->setVisible(true);
        ui->checkBox_2->move(620,68);
        ui->checkBox_2->setVisible(true);
        ui->checkBox_3->setVisible(true);
        ui->checkBox_3->move(750,68);
        copymode=0;
        premode=0;
        ticket_now=0;
        //清空系统无法自动回收的界面
        lastWindowCleaner();
        int i;
        if(myticketnum==0){
            Log* logno=new Log();
            if(username=="") logno->setLog("您还没有登录","登录后即可查看信息","没登录","快登录","00:00","24:00",2,"登录后即可查看","");
            else logno->setLog("您还没有订票",username,"没有票","快订票","00:00","24:00",2,"查询后即可订票","");
            ticketInfo* ticket0=new ticketInfo(logno,2);
            verticalLayout_7->addWidget(ticket0);
        }
        else{
            if(myticketnum<5){
                for(i=0;i<myticketnum;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                    verticalLayout_7->addWidget(ticket0);
                }
                QSpacerItem* sp1=new QSpacerItem(20,125*(5-myticketnum),QSizePolicy::Minimum,QSizePolicy::Fixed);
                verticalLayout_7->addItem(sp1);
            }
            else{
                for(i=0;i<5;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                    verticalLayout_7->addWidget(ticket0);
                }
            }
        }
    }
}

//搜索界面初始化函数
void MainWindow::on_pushButton_1_clicked()
{
    if(ui->pushButton_1->isChecked()){
        //由于与其他界面有公用控件，所以才需要以下语句设置控件（后台界面不用了太复杂）
        widget0->hide();
        resetChecked();
        ui->pushButton_1->setChecked(true);
        ui->label_3->setVisible(true);
        ui->label_12->setVisible(true);
        ui->label_13->setVisible(true);
        ui->label_14->setVisible(false);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_7->setVisible(false);
        ui->lineEditari->setVisible(true);
        ui->lineEditdep->setVisible(true);
        ui->easystay->setVisible(true);
        ui->backgroundsky->setVisible(true);
        ui->checkBox->setVisible(true);
        ui->home_background->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->pushButton_4->setVisible(true);
        ui->layoutbutton->setVisible(true);
        ui->layoutbutton_2->setVisible(true);
        ui->widget_2->setVisible(true);
        ui->label_10->setVisible(true);
        ui->label_11->setVisible(true);
        ui->pushButton_9->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->pushButton_12->setVisible(false);
        ui->scrollArea->setVisible(false);
        ui->comboBox_2->setGeometry(280,324,201,22);
        ui->pushButton_9->setGeometry(490,324,31,22);
        ui->dateEdit_2->setVisible(false);
        ui->checkBox_2->setVisible(false);
        ui->checkBox_3->setVisible(false);
        if(ui->comboBox_2->count()==14){
            ui->comboBox_2->removeItem(10);
            ui->comboBox_2->removeItem(10);
            ui->comboBox_2->removeItem(10);
            ui->comboBox_2->removeItem(10);
        }
        ui->label_4->setVisible(true);
        ui->label_7->setVisible(true);
        ui->comboBox->setVisible(true);
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_8->setVisible(true);
        ui->dateEdit->setVisible(true);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        button_swap->setVisible(true);
        ui->verticalScrollBar_2->setVisible(true);
        ui->verticalScrollBar_3->setVisible(false);
        ui->widget->setVisible(false);
        //清空系统无法自动回收的界面
        lastWindowCleaner();
        layoutCleaner(7);
    }
    changemode=0;
}

//用户信息统计界面初始化函数
void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->isChecked()){
        //由于与其他界面有公用控件，所以才需要以下语句设置控件
        widget0->hide();
        resetChecked();
        ui->pushButton_3->setChecked(true);
        ui->pushButton_6->setVisible(true);
        ui->pushButton_7->setVisible(true);
        ui->label_3->setVisible(false);
        ui->label_12->setVisible(false);
        ui->label_13->setVisible(false);
        ui->label_14->setVisible(false);
        ui->lineEditari->setVisible(false);
        ui->lineEditdep->setVisible(false);
        ui->easystay->setVisible(false);
        ui->backgroundsky->setVisible(false);
        ui->checkBox->setVisible(false);
        ui->home_background->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->layoutbutton->setVisible(false);
        ui->layoutbutton_2->setVisible(false);
        ui->label_10->setVisible(false);
        ui->widget_2->setVisible(false);
        ui->label_11->setVisible(false);
        ui->pushButton_9->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->pushButton_12->setVisible(false);
        ui->scrollArea->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->dateEdit->setVisible(false);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        button_swap->setVisible(false);
        ui->verticalScrollBar_2->setVisible(false);
        ui->verticalScrollBar_3->setVisible(false);
        ui->widget->setVisible(true);
        ui->dateEdit_2->setVisible(false);
        ui->checkBox_2->setVisible(false);
        ui->checkBox_3->setVisible(false);
        //清空滚动区域内控件
        layoutCleaner(2);
        //清空系统不会自动回收的界面
        lastWindowCleaner();
        //新建地图窗口
        m=new Map(userLogs,myticketnum);
        WId proc1Window_HWND = WId(this->winId()); //记下进程1的窗口句柄
        //TODO: 创建一个进程1的窗口代理
        QWindow* proc1Widow = QWindow::fromWinId(proc1Window_HWND);
        //TODO: 告诉w它的本地父窗口是proc1Window_HWND,这步务必要做不然m上的一些控件会出问题，比如qcombobox的下拉框可能会错位
        m->setProperty("_q_embedded_native_parent_handle",QVariant(proc1Window_HWND));
        //TODO: 将进程1的窗口设置为w的父窗口（w嵌入到proc1的窗口中）
        m->winId();
        m->windowHandle()->setParent(proc1Widow);
        m->setMinimumSize(780, 600);
        m->setMaximumSize(QSize(780, 600));
        m->resize(780, 600);
        m->move(150,70);
        m->show();
        //设置用户信息
        if(username!=""){
            ui->label_22->setText(username);
            if(home!=-1){
                ui->label_18->setText("用户住所："+citys[home]);
                ui->label_17->setText("概率："+QString::number(probability*100,'f',1)+'%');
            }
            if(common!=-1){
                ui->label_21->setText("用户常去："+citys[common]);
                ui->label_20->setText("概率："+QString::number(pco*100,'f',1)+'%');
            }
            if(time_money>=time_time && time_money>=time_straight){
                ui->label_19->setText("常用搜索方式：费用最少");
            }
            else if(time_time>=time_straight && time_time>time_money){
                ui->label_19->setText("常用搜索方式：时间最短");
            }
            else{
                ui->label_19->setText("常用搜索方式：直飞");
            }
            userSearchAnalyse(&commonfrom,&commonto,&profrom,&proto);
            if(commonfrom!=-1){
                ui->label_25->setText("常搜始发地："+citys[commonfrom]);
                ui->label_26->setText("概率："+QString::number(profrom*100,'f',1)+'%');
            }
            if(commonto!=-1){
                ui->label_27->setText("常搜目的地："+citys[commonto]);
                ui->label_28->setText("概率："+QString::number(proto*100,'f',1)+'%');
            }
        }
        float probus=0;
        userImageAnalyse(userLogs,&business,&probus);
        if(business) ui->label_23->setText("用户画像：商业人士");
        else ui->label_23->setText("用户画像：游客");
        ui->label_24->setText("概率："+QString::number(probus*100,'f',1)+'%');
    }
    changemode=0;
}

//退改签界面滚动条，滚动功能函数（更换显示的票据）注：对应票数>5时才管用
void MainWindow::on_verticalScrollBar_3_valueChanged(int value)
{
    //如果是改签模式
    if(changemode==1){
        if(ticketnum>4){
            int i=0;
            int j=5;
            j=(ticketnum-5)*((double)value/(double)999)+5;
            if(j<5)j=5;
            if(j>ticketnum) j=ticketnum;
            layoutCleaner(7);
            //ticket_now=j-5;
            for(i=j-5;i<j;i++){
                ticketInfo* ticket0=new ticketInfo(&logs[i],clog,4);
                verticalLayout_7->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
        }
    }
    //一般模式
    else{
        //如果开启了过往票据查询
        if(copymode==0 && premode==1 && myticketnum+mypreticketnum>5){
            int i=0;
            int j=5;
            j=(myticketnum+mypreticketnum-5)*((double)value/(double)999)+5;
            if(j<5)j=5;
            if(j>myticketnum+mypreticketnum) j=myticketnum+mypreticketnum;
            layoutCleaner(7);
            //ticket_now=j-5;
            for(i=j-5;i<j;i++){
                ticketInfo* ticket0;
                if(i>=myticketnum) ticket0=new ticketInfo(&prelogs[i-myticketnum],3);
                else ticket0=new ticketInfo(&userLogs[i],3);
                verticalLayout_7->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
        }
        //如果没有开启筛选功能
        else if(myticketnum>5 && copymode==0){
            int i=0;
            int j=5;
            j=(myticketnum-5)*((double)value/(double)999)+5;
            if(j<5)j=5;
            if(j>myticketnum) j=myticketnum;
            layoutCleaner(7);
            //ticket_now=j-5;
            for(i=j-5;i<j;i++){
                ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                verticalLayout_7->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
        }
        //如果开启了筛选功能
        else if(copymode==1 && copynum>5){
            int i=0;
            int j=5;
            j=(copynum-5)*((double)value/(double)999)+5;
            if(j<5)j=5;
            if(j>copynum) j=copynum;
            layoutCleaner(7);
            for(i=j-5;i<j;i++){
                ticketInfo* ticket0=new ticketInfo(copylogs[i],3);
                verticalLayout_7->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
        }
    }
}
/*
 排序按钮槽函数：
    func：实现票据的排序（搜索，退改签界面公用）
    sortmode 1：飞行时间 2：价格 3：起飞时间 4：降落时间 5：准点率 6：PID 7：日期（升序）
        7以上为降序对应排序规则为sortnum mod7
    关于排序：对于逆序排序采用了调换的方式优化
    注：由于采用了共用的设计，因此逻辑极为复杂
 */
void MainWindow::on_pushButton_9_clicked(bool checked)
{
    int index=ui->comboBox_2->currentIndex();
    int i,k;
    if(ui->pushButton_2->isChecked() && changemode==0 && myticketnum!=0){
        switch(index){
        case 0:if(mysortmode==9) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,2,0); mysortmode=2;break;
        case 1:if(mysortmode==2) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,9,0); mysortmode=9;break;
        case 2:if(mysortmode==8) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,1,0); mysortmode=1;break;
        case 3:if(mysortmode==1) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,8,0); mysortmode=8;break;
        case 4:if(mysortmode==10) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,3,0); mysortmode=3;break;
        case 5:if(mysortmode==3) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,10,0); mysortmode=10;break;
        case 6:if(mysortmode==11) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,4,0); mysortmode=4;break;
        case 7:if(mysortmode==4) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,11,0); mysortmode=11;break;
        case 8:if(mysortmode==5) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,12,0); mysortmode=12;break;
        case 9:if(mysortmode==12) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,5,0); mysortmode=5;break;
        case 10:if(mysortmode==13) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,6,0); mysortmode=6;break;
        case 11:if(mysortmode==6) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,13,0); mysortmode=13;break;
        case 12:if(mysortmode==14) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,7,0); mysortmode=7;break;
        case 13:if(mysortmode==7) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,14,0); mysortmode=14;break;
        }
    }
    else if(ticketnum!=0){
        switch(index){
        case 0:if(sortmode==9) invert(logs,ticketnum); else QuickSort(logs,ticketnum,2,0); sortmode=2;break;
        case 1:if(sortmode==2) invert(logs,ticketnum); else QuickSort(logs,ticketnum,9,0); sortmode=9;break;
        case 2:if(sortmode==8) invert(logs,ticketnum); else QuickSort(logs,ticketnum,1,0); sortmode=1;break;
        case 3:if(sortmode==1) invert(logs,ticketnum); else QuickSort(logs,ticketnum,8,0); sortmode=8;break;
        case 4:if(sortmode==10) invert(logs,ticketnum); else QuickSort(logs,ticketnum,3,0); sortmode=3;break;
        case 5:if(sortmode==3) invert(logs,ticketnum); else QuickSort(logs,ticketnum,10,0); sortmode=10;break;
        case 6:if(sortmode==11) invert(logs,ticketnum); else QuickSort(logs,ticketnum,4,0); sortmode=4;break;
        case 7:if(sortmode==4) invert(logs,ticketnum); else QuickSort(logs,ticketnum,11,0); sortmode=11;break;
        case 8:if(sortmode==5) invert(logs,ticketnum); else QuickSort(logs,ticketnum,12,0); sortmode=12;break;
        case 9:if(sortmode==12) invert(logs,ticketnum); else QuickSort(logs,ticketnum,5,0); sortmode=5;break;
        }
    }
    //如果是搜索界面并且没有开启筛选功能
    if(ui->pushButton_1->isChecked() && copymode==0){
        layoutCleaner(2);
        k=3;
        for(i=2;i>=0;i--){
            if(logs[i].ID=="" || logs[i].des=="不可达"){
                k=i;
            }
        }
        if(k==0) {
            Log* logno=new Log();
            logno->setLog("没有航空公司","123456","不可达","不可达","00:00","25:00",0,"0%","");
            ticketInfo* ticket0=new ticketInfo(logno,0);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            ui->verticalLayout_2->addWidget(ticket0);
        }
        else{
            for(i=0;i<k;i++){
                ticketInfo* ticket0=new ticketInfo(&logs[i],0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                ui->verticalLayout_2->addWidget(ticket0);
            }
        }
    }
    //如果是搜索界面并且开启筛选功能
    else if(ui->pushButton_1->isChecked() && copymode==1){
        getScrollBarMessage();
    }
    //如果是退改签界面并且开启改签功能
    else if(ui->pushButton_2->isChecked() && changemode==1){
        k=5;
        layoutCleaner(7);
        for(i=4;i>=0;i--){
            if(logs[i].ID=="" || logs[i].des=="不可达"){
                k=i;
            }
        }
        if(k==0) {
            Log* logno=new Log();
            logno->setLog("没有航空公司","123456","不可改签","不可改签","00:00","25:00",0,"0%","");
            ticketInfo* ticket0=new ticketInfo(logno,0);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            verticalLayout_7->addWidget(ticket0);
        }
        else{
            for(i=0;i<k;i++){
                ticketInfo* ticket0=new ticketInfo(&logs[i],clog,4);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                verticalLayout_7->addWidget(ticket0);
            }
        }
    }
    //如果是退改签界面并且开启筛选功能
    else if(ui->pushButton_2->isChecked() && copymode==1) on_checkBox_2_stateChanged(ui->checkBox_2->isChecked());
    //如果是退改签界面并且没有开启改签功能
    else if(ui->pushButton_2->isChecked() && changemode==0){
        layoutCleaner(7);
        if(myticketnum==0) {
            Log* logno=new Log();
            if(username=="") logno->setLog("您还没有登录","登录后即可查看信息","没登录","快登录","00:00","24:00",2,"登录后即可查看","");
            else logno->setLog("您还没有订票",username,"没有票","快订票","00:00","24:00",2,"查询后即可订票","");
            ticketInfo* ticket0=new ticketInfo(logno,2);
            verticalLayout_7->addWidget(ticket0);
        }
        else if(myticketnum<5){
            for(i=0;i<myticketnum;i++){
                ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                verticalLayout_7->addWidget(ticket0);
            }
            QSpacerItem* sp1=new QSpacerItem(20,125*(5-myticketnum),QSizePolicy::Minimum,QSizePolicy::Fixed);
            verticalLayout_7->addItem(sp1);
        }
        else{
            for(i=0;i<5;i++){
                ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                verticalLayout_7->addWidget(ticket0);
            }
        }
    }
    ticket_now=0;
    ui->checkBox_3->setCheckState(Qt::Unchecked);
}
//覆写关闭事件，删除了一些系不会自动回收的界面，并向数据库写入用户信息
void MainWindow::closeEvent(QCloseEvent *event) {
    lastWindowCleaner();
    if(username!=""){
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE","read_connection");
        database.setDatabaseName(pathCreator("dbs/users.db"));
        database.setUserName("root");
        database.setPassword("123456");
        QString password;
        if (!database.open())
        {
            qDebug() << "Error: Failed to connect database." << database.lastError();
        }
        else
        {
            //获取数据
            QString update_sql = QString("UPDATE users SET timemoney='%1', timetime='%2', timestraight='%3' WHERE name='%4'").arg(time_money).arg(time_time).arg(time_straight).arg(username);
            QSqlQuery queryuser(database);
            if(!queryuser.exec(update_sql))
            {
                qDebug() << queryuser.lastError();
            }
            else
            {
                qDebug() << "updated!";
            }
            QString last_log = QString("select * from users where name = '%1'").arg(username);
            queryuser.exec(last_log);
            queryuser.next();
            password=queryuser.value(2).toString();
            database.close();
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            QSqlDatabase::removeDatabase("read_connection");
        }
        database = QSqlDatabase::addDatabase("SQLITECIPHER","read_connection");
        database.setDatabaseName(pathCreator("dbs/"+username+".db"));
        database.setUserName(username);
        database.setPassword(password);
        database.setConnectOptions("QSQLITE_USE_CIPHER=sqlcipher; SQLCIPHER_LEGACY=1; SQLCIPHER_LEGACY_PAGE_SIZE=4096");
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
            QSqlQuery query(database);
            QString update_sql = QString("UPDATE searchtimes SET 北京='%1', 上海='%2', 昆明='%3', 广州='%4', 台北='%5', 西安='%6', 乌鲁木齐='%7', 哈尔滨='%8', 拉萨='%9', 西宁='%10', 新加坡='%11', 马尼拉='%12', 曼谷='%13', 东京='%14', 首尔='%15', 新德里='%16' WHERE LABEL='%17'").arg(citytimesfrom[0]).arg(citytimesfrom[1]).arg(citytimesfrom[2]).arg(citytimesfrom[3]).arg(citytimesfrom[4]).arg(citytimesfrom[5]).arg(citytimesfrom[6]).arg(citytimesfrom[7]).arg(citytimesfrom[8]).arg(citytimesfrom[9]).arg(citytimesfrom[10]).arg(citytimesfrom[11]).arg(citytimesfrom[12]).arg(citytimesfrom[13]).arg(citytimesfrom[14]).arg(citytimesfrom[15]).arg(0);
            if(!query.exec(update_sql)) qDebug() << query.lastError();
            else qDebug() << "updated!";
            update_sql = QString("UPDATE searchtimes SET 北京='%1', 上海='%2', 昆明='%3', 广州='%4', 台北='%5', 西安='%6', 乌鲁木齐='%7', 哈尔滨='%8', 拉萨='%9', 西宁='%10', 新加坡='%11', 马尼拉='%12', 曼谷='%13', 东京='%14', 首尔='%15', 新德里='%16' WHERE LABEL='%17'").arg(citytimesto[0]).arg(citytimesto[1]).arg(citytimesto[2]).arg(citytimesto[3]).arg(citytimesto[4]).arg(citytimesto[5]).arg(citytimesto[6]).arg(citytimesto[7]).arg(citytimesto[8]).arg(citytimesto[9]).arg(citytimesto[10]).arg(citytimesto[11]).arg(citytimesto[12]).arg(citytimesto[13]).arg(citytimesto[14]).arg(citytimesto[15]).arg(1);
            if(!query.exec(update_sql)) qDebug() << query.lastError();
            else qDebug() << "updated!";
        }
    }
}
/*
用户画像分析算法：userImageAnalyse
args：
  userLogs为用户的票据数组
  bus为用户画像
  probus为用户画像预估概率
*/
void MainWindow::userImageAnalyse(Log* userLogs,bool *bus,float *probus){
    int Times[2]={0,0};
    *probus=0;
    int i,j,begin,end,max=0,pre=-1,premax=0;
    for(i=0;i<myticketnum;i++){
        if(userLogs[i].business) Times[1]++;
        else Times[0]++;
    }
    if(Times[1]>=Times[0] && Times[1]!=0) {
        *bus=true;
        *probus=Times[1]/(double)(Times[1]+Times[0]);
    }
    else if(Times[1]<Times[0] && Times[0]!=0) {
        *bus=false;
        *probus=Times[0]/(double)(Times[1]+Times[0]);
    }
    else *bus=false;
}
/*
用户票务始发地与目的地的分析算法：userSearchAnalyse
args：
  commonfrom为始发地
  commonto为目的地
  profrom为始发地的预估概率
  proto为目的地的预估概率
*/
void MainWindow::userSearchAnalyse(int *commonfrom,int * commonto,float *profrom,float *proto){
    *commonfrom=-1;
    *commonto=-1;
    *profrom=0;
    *proto=0;
    int pre=-1;
    float max=0,premax=0;
    for (int i = 0; i < 16; i++) {
        if(max<citytimesfrom[i]) {
            premax=max;
            pre=*commonfrom;
            max=citytimesfrom[i];
            *commonfrom=i;
        }
        if(premax<citytimesfrom[i] && citytimesfrom[i]<max){
            pre=i;
            premax=citytimesfrom[i];
        }
    }
    if(max!=0) *profrom=max/(double)(max+premax);
    max=0;
    pre=-1;
    premax=0;
    for (int i = 0; i < 16; i++) {
        if(max<citytimesto[i]) {
            premax=max;
            pre=*commonto;
            max=citytimesto[i];
            *commonto=i;
        }
        if(premax<citytimesto[i] && citytimesto[i]<max){
            pre=i;
            premax=citytimesto[i];
        }
    }
    if(*commonfrom==*commonto){
        *commonto=pre;
        if(max!=0) *proto=premax/(double)(max+premax);
    }
    else if(max!=0) *proto=max/(double)(max+premax);
}
//我的订单按钮按下跳转至退改签界面
void MainWindow::on_pushButton_8_clicked()
{
    ui->pushButton_2->setChecked(true);
    on_pushButton_2_clicked();
}

//退出按钮
void MainWindow::on_pushButton_10_clicked()
{
    this->close();
}
//当退改签界面的滚动条停止滚动时设置当前滚动区域顶部的票号
void MainWindow::on_verticalScrollBar_3_sliderReleased()
{
    int value=ui->verticalScrollBar_3->value();
    ticket_now=(myticketnum-5)*((double)value/(double)999);
}
//将迪杰斯特拉算法输出的字符串翻译为人能看懂的格式
QString MainWindow::routeTranslate(QString qs){
    QStringList qsl=qs.split(' ');
    QRegularExpression numbers( "0|[1-9]\\d{0,1}" );
    QRegularExpressionMatch matchnum;
    QString coc="",ari="",beg="",las="";
    QStringList mid;
    Log *p,*q;
    int i=0,j=0,k=0,price_max=0;;
    foreach (QString item, qsl) {
        matchnum = numbers.match(item);
        if(item=="不可达") return "";
        if(matchnum.hasMatch()){
            if(item.toInt()<20){
                if(coc=="") coc=citys[item.toInt()];
                else {
                    mid.append(citys[item.toInt()]);
                    i++;
                }
                ari=citys[item.toInt()];
            }
            else if(price_max<item.toInt()) price_max=item.toInt();
        }
    }
    QString route;
    if(mid.count()==1) route="起："+coc+"| ";
    else route="起："+coc+"| 经：";
    for(i=0;i<mid.count()-1;i++){
        route=route+mid[i]+"| ";
    }
    route=route+"降："+ari+" ￥"+QString::number(price_max);
    return route;
}
//筛选滚动区域的槽函数，用于及时更新筛选结果
void MainWindow::getScrollBarMessage(){
    //如果筛选滚动区域内发生变化，则重新筛选票据
    int i;
    QStringList st;
    QWidget* wid=ui->scrollArea->widget();
    //查找所有选中筛选项
    foreach(QCheckBox* child,wid->findChildren<QCheckBox*>()){
        if(child->isChecked()) st.append(child->objectName());
    }
    //空则关闭筛选模式
    if(st.empty()){
        copymode=0;
        ui->verticalScrollBar_2->setSliderPosition(0);
        on_verticalScrollBar_2_valueChanged(0);
        return;
    }
    copynum=0;
    copymode=1;
    //筛选每一张票，并把符合条件的票的地址放入筛选指针数组
    for(i=0;i<ticketnum;i++){
        foreach(QString item,st){
            //如果是航线筛选
            if(item.left(1)=="起"){
                if(routeTranslate(logs[i].route)==item){
                    copylogs[copynum]=&logs[i];
                    copynum++;
                    break;
                }
            }
            //如果是航空公司筛选
            else{
                if(item.mid(0,logs[i].company.length()).contains(logs[i].company)){
                    copylogs[copynum]=&logs[i];
                    copynum++;
                    break;
                }
            }
        }
    }
    //清空票据滚动区域内控件
    layoutCleaner(2);
    ticket_now=0;
    if(copynum==0){
            Log* logno=new Log();
            logno->setLog("没有航空公司","123456","不可达","不可达","00:00","25:00",0,"0%","");
            ticketInfo* ticket0=new ticketInfo(logno,0);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            ui->verticalLayout_2->addWidget(ticket0);
    }
    else if(copynum<3){
        for(i=0;i<copynum;i++){
            ticketInfo* ticket0=new ticketInfo(copylogs[i],0);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            ui->verticalLayout_2->addWidget(ticket0);
        }
    }
    else{
        for(i=0;i<3;i++){
            ticketInfo* ticket0=new ticketInfo(copylogs[i],0);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            ui->verticalLayout_2->addWidget(ticket0);
        }
    }
    ui->verticalScrollBar_2->setSliderPosition(0);
}
//搜索界面筛选按钮槽函数，用于控制筛选滚动区域的显示情况
void MainWindow::on_pushButton_12_clicked()
{
    //如果按下搜索界面筛选按钮，将滚动区域显示出来，否则隐藏
    if(ui->scrollArea->isVisible()) ui->scrollArea->setVisible(false);
    else ui->scrollArea->setVisible(true);
}

//日期筛选按钮槽函数，用于开启和关闭删选功能
void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    //如果选中，并且票数大于0，开启筛选模式
    if(arg1 && myticketnum>0) {
        //重置筛选票数
        copynum=0;
        //开启筛选模式
        copymode=1;
        int i;
        //将符合条件的票的指针存入筛选指针数组
        for(i=0;i<myticketnum;i++){
            if(userLogs[i].curdate==ui->dateEdit_2->date().toString()){
                copylogs[copynum]=&userLogs[i];
                copynum++;
            }
        }
        //清除滚动区域内控件
        layoutCleaner(7);
        //设置当前滚动区域的第一张票为0号
        ticket_now=0;
        //如果没有符合条件的票
        if(copynum==0){
            Log* logno=new Log();
            logno->setLog("没有该日机票","123456","不可达","不可达","00:00","24:00",2,"0%","");
            ticketInfo* ticket0=new ticketInfo(logno,2);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            verticalLayout_7->addWidget(ticket0);
        }
        else if(copynum<5){
            for(i=0;i<copynum;i++){
                ticketInfo* ticket0=new ticketInfo(copylogs[i],3);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                verticalLayout_7->addWidget(ticket0);
            }
            QSpacerItem* sp1=new QSpacerItem(20,125*(5-copynum),QSizePolicy::Minimum,QSizePolicy::Fixed);
            verticalLayout_7->addItem(sp1);
        }
        else{
            for(i=0;i<5;i++){
                ticketInfo* ticket0=new ticketInfo(copylogs[i],3);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                verticalLayout_7->addWidget(ticket0);
            }
        }
        ui->verticalScrollBar_3->setSliderPosition(0);
    }
    //如果取消选中
    else {
        //关闭筛选模式
        //清空筛选票数
        copynum=0;
        copymode=0;
        //设置当前滚动区域的第一张票为0号
        ticket_now=0;
        //清除滚动区域内控件
        layoutCleaner(7);
        //如果没有票
        if(myticketnum==0){
            Log* logno=new Log();
            if(username=="") logno->setLog("您还没有登录","登录后即可查看信息","没登录","快登录","00:00","24:00",2,"登录后即可查看","");
            else logno->setLog("您还没有订票",username,"没有票","快订票","00:00","24:00",2,"查询后即可订票","");
            ticketInfo* ticket0=new ticketInfo(logno,2);
            verticalLayout_7->addWidget(ticket0);
        }
        else{
            if(myticketnum<5){
                for(int i=0;i<myticketnum;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                    verticalLayout_7->addWidget(ticket0);
                }
                QSpacerItem* sp1=new QSpacerItem(20,125*(5-myticketnum),QSizePolicy::Minimum,QSizePolicy::Fixed);
                verticalLayout_7->addItem(sp1);
            }
            else{
                for(int i=0;i<5;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                    verticalLayout_7->addWidget(ticket0);
                }
            }
        }
    }
}

//日期栏槽函数，用于在日期改变时及时更新筛选结果
void MainWindow::on_dateEdit_2_userDateChanged(const QDate &date)
{
    //如果日期筛选功能开启
    if(ui->checkBox_2->isChecked() && copymode==1){
        copynum=0;
        int i;
        //将符合筛选条件的机票的地址放入筛选指针数组中
        for(i=0;i<myticketnum;i++){
            if(userLogs[i].curdate==ui->dateEdit_2->date().toString()){
                copylogs[copynum]=&userLogs[i];
                copynum++;
            }
        }
        layoutCleaner(7);
        ticket_now=0;
        if(copynum==0){
            Log* logno=new Log();
            logno->setLog("没有该日机票","123456","不可达","不可达","00:00","24:00",2,"0%","");
            ticketInfo* ticket0=new ticketInfo(logno,2);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            verticalLayout_7->addWidget(ticket0);
        }
        else if(copynum<5){
            for(i=0;i<copynum;i++){
                ticketInfo* ticket0=new ticketInfo(copylogs[i],3);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                verticalLayout_7->addWidget(ticket0);
            }
            QSpacerItem* sp1=new QSpacerItem(20,125*(5-copynum),QSizePolicy::Minimum,QSizePolicy::Fixed);
            verticalLayout_7->addItem(sp1);
        }
        else{
            for(i=0;i<5;i++){
                ticketInfo* ticket0=new ticketInfo(copylogs[i],3);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                verticalLayout_7->addWidget(ticket0);
            }
        }
        ui->verticalScrollBar_3->setSliderPosition(0);
    }
}
//过往票据按钮槽函数，用于开关过往票据功能
void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    //如果选中
    if(arg1) {
        //过往票据状态开启
        premode=true;
        ui->checkBox_2->setEnabled(false);
        //清除滚动栏控件
        layoutCleaner(7);
        //如果没有票
        if(myticketnum+mypreticketnum==0){
            Log* logno=new Log();
            if(username=="") logno->setLog("您还没有登录","登录后即可查看信息","没登录","快登录","00:00","24:00",2,"登录后即可查看","");
            else logno->setLog("您还没有订票",username,"没有票","快订票","00:00","24:00",2,"查询后即可订票","");
            ticketInfo* ticket0=new ticketInfo(logno,2);
            verticalLayout_7->addWidget(ticket0);
        }
        else{
            //如果票数少于5
            if(myticketnum+mypreticketnum<5){
                for(int i=0;i<myticketnum+mypreticketnum;i++){
                    ticketInfo* ticket0;
                    if(i>=myticketnum) ticket0=new ticketInfo(&prelogs[i-myticketnum],3);
                    else ticket0=new ticketInfo(&userLogs[i],3);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                    verticalLayout_7->addWidget(ticket0);
                }
                QSpacerItem* sp1=new QSpacerItem(20,125*(5-myticketnum-mypreticketnum),QSizePolicy::Minimum,QSizePolicy::Fixed);
                verticalLayout_7->addItem(sp1);
            }
            //如果票数多于5
            else{
                for(int i=0;i<5;i++){
                    ticketInfo* ticket0;
                    if(i>=myticketnum) ticket0=new ticketInfo(&prelogs[i-myticketnum],3);
                    else ticket0=new ticketInfo(&userLogs[i],3);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                    verticalLayout_7->addWidget(ticket0);
                }
            }
        }
    }
    else {
        //过往票据状态关闭
        premode=false;
        ui->checkBox_2->setEnabled(true);
        //清除滚动栏控件
        layoutCleaner(7);
        if(myticketnum==0){
            Log* logno=new Log();
            if(username=="") logno->setLog("您还没有登录","登录后即可查看信息","没登录","快登录","00:00","24:00",2,"登录后即可查看","");
            else logno->setLog("您还没有订票",username,"没有票","快订票","00:00","24:00",2,"查询后即可订票","");
            ticketInfo* ticket0=new ticketInfo(logno,2);
            verticalLayout_7->addWidget(ticket0);
        }
        else{
            if(myticketnum<5){
                for(int i=0;i<myticketnum;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                    verticalLayout_7->addWidget(ticket0);
                }
                QSpacerItem* sp1=new QSpacerItem(20,125*(5-myticketnum),QSizePolicy::Minimum,QSizePolicy::Fixed);
                verticalLayout_7->addItem(sp1);
            }
            else{
                for(int i=0;i<5;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                    verticalLayout_7->addWidget(ticket0);
                }
            }
        }
    }
}

//后台按钮槽函数
void MainWindow::on_pushButton_back_clicked()
{
    if(ui->pushButton_back->isChecked()){
        //将其他界面的控件隐藏（后台页面使用了全新的开发方式，在切换到其他界面后会自动销毁）
        widget0->hide();
        resetChecked();
        ui->pushButton_back->setChecked(true);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_7->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_12->setVisible(false);
        ui->label_13->setVisible(false);
        ui->label_14->setVisible(false);
        ui->lineEditari->setVisible(false);
        ui->lineEditdep->setVisible(false);
        ui->easystay->setVisible(false);
        ui->backgroundsky->setVisible(false);
        ui->checkBox->setVisible(false);
        ui->home_background->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->layoutbutton->setVisible(false);
        ui->layoutbutton_2->setVisible(false);
        ui->label_10->setVisible(false);
        ui->widget_2->setVisible(false);
        ui->label_11->setVisible(false);
        ui->pushButton_9->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->pushButton_12->setVisible(false);
        ui->scrollArea->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->dateEdit->setVisible(false);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        button_swap->setVisible(false);
        ui->verticalScrollBar_2->setVisible(false);
        ui->verticalScrollBar_3->setVisible(false);
        ui->widget->setVisible(false);
        ui->dateEdit_2->setVisible(false);
        ui->checkBox_2->setVisible(false);
        ui->checkBox_3->setVisible(false);
        layoutCleaner(2);
        //清空系统无法自动回收的界面
        lastWindowCleaner();
        m4=new MainWindow4();
        WId proc1Window_HWND = WId(this->winId()); //记下进程1的窗口句柄
        //TODO: 创建一个进程1的窗口代理
        QWindow* proc1Widow = QWindow::fromWinId(proc1Window_HWND);
        //TODO: 告诉w它的本地父窗口是proc1Window_HWND,这步务必要做不然m上的一些控件会出问题，比如qcombobox的下拉框可能会错位
        m4->setProperty("_q_embedded_native_parent_handle",QVariant(proc1Window_HWND));
        //TODO: 将进程1的窗口设置为w的父窗口（w嵌入到proc1的窗口中）
        m4->winId();
        m4->windowHandle()->setParent(proc1Widow);
        m4->setMinimumSize(1100, 610);
        m4->setMaximumSize(QSize(1100, 610));
        m4->resize(1100, 610);
        m4->move(160,60);
        m4->show();
    }
}
//重置工具栏按钮的check状态
void MainWindow::resetChecked(){
    ui->pushButton_1->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_back->setChecked(false);
}
//设置广告函数
void MainWindow::setAD(int bus){

    QImage imgGg;
    //如果是游客且常去地存在
    if(!bus && common!=-1){
        QString ts=pathCreator("")+citys[this->common]+"旅.jpg";
        imgGg.load(ts);
        ui->label_10->setPixmap(changeImage(QPixmap::fromImage(imgGg),imgGg.height()/30));
    }
    //如果游客的家可以分析
    else if(home!=-1){
        if(this->home==0 ||this->home==1 || this->home==3){
            imgGg.load(pathCreator("")+citys[this->home]+"商.jpg");
        }
        else imgGg.load(pathCreator("")+"通用商.jpg");
        ui->label_10->setPixmap(changeImage(QPixmap::fromImage(imgGg),imgGg.height()/30));
    }
    //如果游客常出发地存在
    else if(commonfrom!=-1){
        if(this->commonfrom==0 ||this->commonfrom==1 || this->commonfrom==3){
            imgGg.load(pathCreator("")+citys[this->commonfrom]+"商.jpg");
        }
        else imgGg.load(pathCreator("")+"通用商.jpg");
        ui->label_10->setPixmap(changeImage(QPixmap::fromImage(imgGg),imgGg.height()/30));
    }
}
//用于清除系统无法自动回收的界面
void MainWindow::lastWindowCleaner(){
    if(m!=NULL){
        m->setAttribute(Qt::WA_DeleteOnClose, true);
        m->close();
        m=NULL;
    }
    //重新点击后台按钮重建页面
    if(m4!=NULL){
        m4->setAttribute(Qt::WA_DeleteOnClose, true);
        m4->close();
        m4=NULL;
    }
}
//用于清除layout中的控件
void MainWindow::layoutCleaner(int num){
    if(num==2) {
        QString layoutName = QString("verticalLayout_%1").arg(num);
        QVBoxLayout *layout = findChild<QVBoxLayout*>(layoutName);
        if (layout) {
            while (QLayoutItem* item = layout->takeAt(0))
            {
                if (QWidget* widget = item->widget()){
                    widget->disconnect();
                    widget->deleteLater();
                }

                if (QSpacerItem* spaerItem = item->spacerItem())
                    layout->removeItem(spaerItem);

                delete item;
            }
        }
    }
    else{
        while (QLayoutItem* item = verticalLayout_7->takeAt(0))
        {
            if (QWidget* widget = item->widget()){
                widget->disconnect();
                widget->deleteLater();
            }

            if (QSpacerItem* spaerItem = item->spacerItem())
                verticalLayout_7->removeItem(spaerItem);

            delete item;
        }
    }
}

