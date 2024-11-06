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
#include "ticketwindow.h"
//#include "mysqlite.h"
#include <QMessageBox>
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"MSIMG32.LIB")
#define TIMEOUT 4000
#define WindowWidth 1280
#define WindowHeight 720
QPixmap changeImage(QPixmap img_in,int radius);
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
    ui->pushButton_0->setStyleSheet("border:none;");
    ui->pushButton_0->setMaximumSize(100,30);
    ui->pushButton_0->setIcon(QIcon("E:/Qtproject/Dtrip/菜单栏2.png"));
    QFile file_search(pathCreator("qss/选择.qss"));
    file_search.open(QFile::ReadOnly);
    QString styleSheet_se = tr(file_search.readAll());
    ui->pushButton->setStyleSheet(styleSheet_se);
    ui->pushButton_4->setIcon(QIcon("E:/Qtproject/Dtrip/search.png"));
    ui->pushButton_4->setStyleSheet(styleSheet_se);
    //设置应用图标
    QPixmap icon0("E:/Qtproject/Dtrip/trip.png");
    ui->labelicon0->setPixmap(icon0);
    //设置查询窗口中内容
    ui->easystay->setStyleSheet("border: none; border-image: url(E:/Qtproject/Dtrip/easy_stay.png);");
    ui->backgroundsky->setMinimumSize(200,100);
    ui->backgroundsky->setStyleSheet("border: 2px solid lightblue; border-radius: 10px; border-image: url(E:/Qtproject/Dtrip/渐变背景.png);");
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
    ui->home_background->setStyleSheet("border: none; border-image: url(E:/Qtproject/Dtrip/homepage-background.png);");
    ui->comboBox->setCurrentIndex(-1);
    ui->verticalScrollBar_3->setVisible(false);

    button_swap = new QPushButton();
    button_swap->setParent(this);
    button_swap->setObjectName("交换");
    button_swap->setIcon(QIcon("E:/Qtproject/Dtrip/change.png"));
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
    imgGg.load("E:/Qtproject/Dtrip/广告位招租.jpg");
    ui->label_10->setPixmap(changeImage(QPixmap::fromImage(imgGg),40));
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
    widget0->resize(955,610);
    //游离layout需要加到widget上
    ui->widget->setVisible(false);
    ui->pushButton_12->setVisible(false);
    ui->scrollArea->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Timerout(){
    //定时的图片更新函数
    QString path("E:/Qtproject/Dtrip/scene");
    path+=QString::number(picId);
    path+=".jpg";
    QImage img;
    img.load(path);
    ui->label_8->setPixmap(changeImage(QPixmap::fromImage(img),30));
    picId++;
    picId=picId % 4;
}

QPixmap changeImage(QPixmap img_in,int radius){
    //图片圆角化
    QSize size = QSize(img_in.size());
    QBitmap mask = QBitmap(size);
    QPainter painter = QPainter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(mask.rect(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(mask.rect(), radius, radius);
    painter.end();
    img_in.setMask(mask);
    return img_in;
}

void MainWindow::on_pushButton_clicked()
{
    //转至地图选择页
    this->hide();
    Map *m=new Map(ui->dateEdit->date());
    m->show();
    connect(m,&Map::sendToMainWindow,this,&MainWindow::getMapMessage);
}


void MainWindow::on_verticalScrollBar_sliderMoved(int position)
{
    int y1=30,y2=65,y3=100;
    ui->pushButton_1->move(QPoint(5,y1+ui->verticalScrollBar->sliderPosition()));
    ui->pushButton_2->move(QPoint(5,y2+ui->verticalScrollBar->sliderPosition()));
    ui->pushButton_3->move(QPoint(5,y3+ui->verticalScrollBar->sliderPosition()));
}

void MainWindow::getMapMessage(QString a,QString b,QDate curdate){
    this->show();
    a.remove(0,4);
    b.remove(0,4);
    ui->lineEditdep->setText(a);
    ui->lineEditari->setText(b);
    ui->dateEdit->setDate(curdate);
}
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
void MainWindow::getticketwindowMessage(Log* tlog){
    if(userLogs[0].PID==-1) {
        tlog->setPID(1);
        Log *p=tlog;
        Log *q=&userLogs[0];
        while(p->next!=NULL){
            p=p->next;
            Log* log1=new Log();
            log1->setlogL(p);
            q->next=log1;
            q=q->next;
        }
        userLogs[0].setlogL(tlog);
        Log pp=userLogs[0];
    }
    else {
        if(mysortmode==13) invert(userLogs,myticketnum);
        else {
            QuickSort(userLogs,myticketnum,6);
            mysortmode=6;
        }
        tlog->setPID(userLogs[myticketnum-1].PID+1);
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
        Log pp=userLogs[0];
        Log qq=userLogs[1];
    }
    Log *p=tlog;
    QString password;
    bool open=openDatabasegetPassword(&password,username);
    if(!open) return;
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
        sql_query2.exec("SELECT PID FROM ticket ORDER BY PID DESC LIMIT 1");
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
        if(p->next==NULL){
            QString insert_sql = QString("insert into ticket(PID, name, id , sou, des, time0, time1, price, chi, next, date, business) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12') ").arg(max_number+1).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(-1).arg(p->curdate).arg(p->business);
            if(!sql_query2.exec(insert_sql))
            {
                qDebug() << sql_query2.lastError();
            }
            else
            {
                qDebug() << "inserted Wang!";
            }
        }
        else{
            bool head=true;
            int i=0,subnum=0;
            while(p->next!=NULL){
                p=p->next;
                subnum++;
            }
            p=tlog;
            while(p!=NULL){
                QString insert_sql;
                if(head) {
                    insert_sql = QString("insert into ticket(PID, name, id , sou, des, time0, time1, price, chi, next, date, business) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12') ").arg(max_number+1).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(subnum).arg(p->curdate).arg(p->business);
                    head=false;
                }
                else insert_sql = QString("insert into subticket(PID, name, id , sou, des, time0, time1, price, chi, next, date) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11') ").arg(max_number+1).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(i).arg(p->curdate);
                if(!sql_query2.exec(insert_sql))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "inserted SUCCESS!";
                }
                i++;
                p=p->next;
            }
        }
        database.close();
    }
    QString name0 = QSqlDatabase::database().connectionName();
    QSqlDatabase::removeDatabase(name0);
    QSqlDatabase::removeDatabase("read_connection");
    QSqlDatabase::removeDatabase("read_connection_2");
    QMessageBox msgBox;
    msgBox.setText("订票成功");
    msgBox.setInformativeText("点击OK返回主界面");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    myticketnum++;
    this->show();
}
void MainWindow::changeTicketMain(Log* tlog){
    Log *q,*t;
    int i=0,PID;
    Log *p=tlog;
    QString password;
    bool open=openDatabasegetPassword(&password,username);
    if(!open) return;
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
        QSqlQuery sql_query2(database);
        QString PID_log = QString("select * from ticket where PID = '%1'").arg(clog->PID);
        sql_query2.exec(PID_log);
        int next;
        if(!sql_query2.next()){
            qDebug() << "Error: Fail to read." << sql_query2.lastError();
        }
        else
        {
            qDebug() << "success!";
            PID= sql_query2.value(0).toInt();
            next = sql_query2.value(9).toInt();
        }
        QString update_sql=QString("UPDATE ticket SET name='%1', id='%2', sou='%3', des='%4', time0='%5', time1='%6', price='%7', chi='%8' WHERE PID='%9'").arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(clog->PID);
        if(!sql_query2.exec(update_sql))
        {
            qDebug() << sql_query2.lastError();
        }
        else
        {
            qDebug() << "updated!";
        }
        if(next!=-1){
            i=1;
            while(p->next!=NULL){
                p=p->next;
                QString update_sql=QString("UPDATE subticket SET name='%1', id='%2', sou='%3', des='%4', time0='%5', time1='%6', price='%7', chi='%8' WHERE PID='%9' AND next='%10'").arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(PID).arg(i);
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
        database.close();
    }
    QString name0 = QSqlDatabase::database().connectionName();
    QSqlDatabase::removeDatabase(name0);
    QSqlDatabase::removeDatabase("read_connection");
    QMessageBox msgBox;
    msgBox.setText("改签成功");
    msgBox.setInformativeText("点击OK返回主界面");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    tlog->setPID(clog->PID);
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
            Log* pp=&userLogs[i];
            pp=&userLogs[i];
            break;
        }
    }
    this->show();
    changemode=0;
    on_pushButton_2_clicked();
}
void MainWindow::changeTicketSearch(Log* tlog){
    Log *p=tlog;
    clog=tlog;
    int begin,end,k=5,i;
    string s="";
    this->show();
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
    if(p->next!=NULL) p=p->next;
    while(p!=NULL){
        if(p->next!=NULL){
            for(begin=0;begin<16;begin++){
                if(p->sou.mid(0,citys[begin].length()).contains(citys[begin])) break;
            }
            if(s=="") s="< "+to_string(begin);
            else s=s+" , "+to_string(begin);
        }
        else{
            for(begin=0;begin<16;begin++){
                if(p->sou.mid(0,citys[begin].length()).contains(citys[begin])) break;
            }
            for(end=0;end<16;end++){
                if(p->des.mid(0,citys[end].length()).contains(citys[end])) break;
            }
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
    setLog(s,2);
    if(clog->business){
        for(i=0;i<ticketnum;i++){
            logs[i].setBus(true);
        }
    }
    sortmode=1;
    qDebug() << QString::fromStdString(s) <<"\n";
    for(i=4;i>=0;i--){
        if(logs[i].ID=="" || logs[i].des=="不可达"){
            k=i;
        }
    }
    if(k==0) {
        k=0;
        Log* logno=new Log();
        logno->setLog("没有航空公司","123456","不可改签","不可改签","00:00","25:00",0,"0%","");
        ticketInfo* ticket0=new ticketInfo(logno,0);
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
    changemode=1;
    ui->pushButton_9->setVisible(true);
    ui->comboBox_2->setVisible(true);
}
void MainWindow::refundTicketMain(Log* tlog){
    Log *q,*t;
    int i=0,j,PID;
    Log *p=tlog;
    QString password;
    bool open=openDatabasegetPassword(&password,username);
    if(!open) return;
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
        QSqlQuery sql_query2(database);
        QString PID_log = QString("select * from ticket where PID = '%1'").arg(tlog->PID);
        sql_query2.exec(PID_log);
        int next;
        if(!sql_query2.next()){
            qDebug() << "Error: Fail to read." << sql_query2.lastError();
        }
        else
        {
            qDebug() << "success!";
            PID= sql_query2.value(0).toInt();
            next = sql_query2.value(9).toInt();
        }
        QString delete_sql=QString("DELETE FROM ticket WHERE PID = '%1'").arg(tlog->PID);
        if(!sql_query2.exec(delete_sql))
        {
            qDebug() << sql_query2.lastError();
        }
        else
        {
            qDebug() << "deleted!";
        }
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
        database.close();
    }
    QString name0 = QSqlDatabase::database().connectionName();
    QSqlDatabase::removeDatabase(name0);
    QSqlDatabase::removeDatabase("read_connection");
    QMessageBox msgBox;
    msgBox.setText("退票成功");
    msgBox.setInformativeText("点击OK返回主界面");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    for(i=0;i<myticketnum;i++){
        if(&userLogs[i]==tlog) {
            for(j=i;j<myticketnum-1;j++){
                userLogs[j]=userLogs[j+1];
            }
            userLogs[j].clear();
            myticketnum--;
            break;
        }
    }
    this->show();
    on_pushButton_2_clicked();
}
void MainWindow::on_button_swap_clicked()
{
    QString dep=ui->lineEditdep->text();
    QString ari=ui->lineEditari->text();
    ui->lineEditdep->setText(ari);
    ui->lineEditari->setText(dep);
}

void MainWindow::on_pushButton_0_clicked()
{
    if(btvisible==true){
        ui->pushButton_1->setVisible(0);
        ui->pushButton_2->setVisible(0);
        ui->pushButton_3->setVisible(0);
        btvisible=false;
    }
    else{
        ui->pushButton_1->setVisible(1);
        ui->pushButton_2->setVisible(1);
        ui->pushButton_3->setVisible(1);
        btvisible=true;
    }
}


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
    while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
    {
        if (QWidget* widget = item->widget())
            widget->deleteLater();

        delete item;
    }
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
    //根据下拉条目设置检索模式
    if(ui->comboBox->currentIndex()<4 && ui->comboBox->currentIndex()>=0) mode=ui->comboBox->currentIndex();
    else return;
    bool deepmode=ui->checkBox->checkState();
    clock_t c_start, c_end;
    c_start = clock();
    if(time_money!=0) time_money-=time_money/10;
    if(time_time!=0) time_time-=time_time/10;
    if(time_straight!=0) time_straight-=time_straight/10;
    if(mode==1) time_money++;
    else if(mode==2) time_time++;
    else if(mode==3) time_straight++;
    if(mode==2) sortmode=1;
    else sortmode=2;
    if(deepmode && mode!=3 && mode!=0){
        mode=mode+4;
        CMap* pMap = new CMap(nodeNum,10000);
        CMapSet(curDate,citys,pMap,mode-4);
        for(begin=0;begin<17;begin++){
            if(citys[begin]==ui->lineEditdep->text()) break;
        }
        for(end=0;end<17;end++){
            if(citys[end]==ui->lineEditari->text()) break;
        }
        Dist* dist,*dist0;
        dist = pMap->DijkstraPlus(begin);
        for(i=0;i<16;i++) {
            qDebug() << dist[i].m_vertex;
            for(j=0;j<6;j++){
                qDebug() << dist[i].m_pre_vertex_list[j];
                qDebug() << dist[i].m_length_list[j];
            }
            qDebug() << "\n";
        }
        //获取最低路径
        bool blist[16];
        for(i=0;i<16;i++) {
            blist[i]=false;
        }
        QStringList list = pMap->visit_plus(dist,begin,end,end,blist);
        for(i=0;i<list.size();i++) {
            qDebug() << list[i] << "\n";
        }
        while (!list.empty()) {
            setLog(list[0].toStdString(),mode);
            list.removeFirst();
        }
    }
    else{
        CMap* pMap = new CMap(nodeNum,arcNum);
        CMapSet(curDate,citys,pMap,mode);
        for(begin=0;begin<17;begin++){
            if(citys[begin]==ui->lineEditdep->text()) break;
        }
        for(end=0;end<17;end++){
            if(citys[end]==ui->lineEditari->text()) break;
        }
        //ui->label_11->setText(QString::number(end));
        if(mode==3 || mode==0) {
            string s="< "+to_string(begin)+" : 999 "+to_string(end)+" >";
            setLog(s,mode);
            if(mode==0 && ticketnum<10){
                dist = pMap->Dijkstra(begin);
                //获取最低路径
                string s = pMap->visit_first(dist,begin,end);
                setLog(s,1);
                if(ticketnum<10){
                    string s1 = pMap->visit_second(dist,begin,end);
                    setLog(s1,1);
                    if(ticketnum<3){
                        while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
                        {
                            if (QWidget* widget = item->widget())
                                widget->deleteLater();

                            delete item;
                        }
                        for(i=0;i<=ticketnum;i++){
                            logs[i].clear();
                        }
                        ticketnum=0;
                        ticket_checkednum=0;
                        pMap = new CMap(nodeNum,10000);
                        CMapSet(curDate,citys,pMap,1);
                        dist = pMap->DijkstraPlus(begin);
                        for(i=0;i<16;i++) {
                            qDebug() << dist[i].m_vertex;
                            for(j=0;j<6;j++){
                                qDebug() << dist[i].m_pre_vertex_list[j];
                            }
                            qDebug() << "\n";
                        }
                        //获取最低路径
                        bool blist[16];
                        for(i=0;i<16;i++) {
                            blist[i]=false;
                        }
                        QStringList list = pMap->visit_plus(dist,begin,end,end,blist);
                        for(i=0;i<list.size();i++) {
                            qDebug() << list[i] << "\n";
                        }
                        while (!list.empty()) {
                            setLog(list[0].toStdString(),1);
                            list.removeFirst();
                        }
                    }
                }
            }
        }
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
    ui->label_10->setVisible(false);
    ui->label_11->setVisible(false);
    ui->label_14->setVisible(true);
    ui->pushButton_6->setVisible(true);
    ui->pushButton_7->setVisible(true);
    ui->pushButton_9->setVisible(true);
    ui->comboBox_2->setVisible(true);
    QStringList st,sroute;
    int pricemin[200];
    for(i=0;i<200;i++){
        pricemin[i]=INT_MAX;
    }
    if(ticketnum!=0){
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
        for(i=0;i<sroute.count();i++){
            sroute[i]=routeTranslate(sroute[i]);
        }
        for(i=0;i<st.count();i++){
            st[i]=st[i]+" ￥"+QString::number(pricemin[i]);
        }
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
    if(logs[2].ID=="" || logs[2].des=="不可达"){
        k=2;
        if(logs[1].ID=="" || logs[1].des=="不可达") k=1;
        if(logs[0].ID=="" || logs[0].des=="不可达") {
            k=0;
            Log* logno=new Log();
            logno->setLog("没有航空公司","123456","不可达","不可达","00:00","25:00",0,"0%","");
            ticketInfo* ticket0=new ticketInfo(logno,0);
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
    c_end = clock();
    ui->label_14->setText("查询用时："+QString::number((double)(c_end - c_start) / CLOCKS_PER_SEC)+"s");
    printf("time=%f\n", (double)(c_end - c_start) / CLOCKS_PER_SEC);
    copymode=0;
}

void MainWindow::on_verticalScrollBar_2_valueChanged(int value)
{
    Log* scrollLogs;
    int scrollTicketnum;
    int position=ui->verticalScrollBar_2->sliderPosition();
    if(copymode==0){
        scrollLogs=logs;
        scrollTicketnum=ticketnum;
        if(scrollTicketnum>2){
            int i=0;
            int j=3;
            j=(scrollTicketnum+1)*((double)position/(double)999);
            if(j<3)j=3;
            if(j>scrollTicketnum) j=scrollTicketnum;
            while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
            {
                if (QWidget* widget = item->widget())
                    widget->deleteLater();

                delete item;
            }
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
    else if(copymode==1 && copynum>2){
        scrollTicketnum=copynum;
        int i=0;
        int j=3;
        j=(scrollTicketnum+1)*((double)position/(double)999);
        if(j<3)j=3;
        if(j>scrollTicketnum) j=scrollTicketnum;
        while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();

            delete item;
        }
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
    foreach (QString item, qsl) {
        matchnum = numbers.match(item);
        if(item=="不可达") return;
        if(matchnum.hasMatch()){
            if(item.toInt()<20){
                if(coc=="") coc=citys[item.toInt()];
                else {
                    mid->append(citys[item.toInt()]);
                    i++;
                }
                ari=citys[item.toInt()];
            }
            else if(price_max<item.toInt()) price_max=item.toInt();
        }
    }
    mid->removeLast();
    beg=coc;
    i=0;
    j=ticket_checkednum;
    if(mid->empty()){
        fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+ coc + "-" + ari + ".txt";
        QFile fs(fname);
        if(fs.open(QIODeviceBase::ReadOnly)){
            QTextStream in(&fs);
            in.setEncoding(QStringConverter::System);
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
                logs[j].setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                logs[j].setRoute(QString::fromStdString(s));
                logs[j].next=NULL;
                j++;
            }
            //QuickSort2(logs,j);
            for(i=ticket_checkednum;i<j;i++){
                qDebug() <<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
            }
        }
        ticketnum=j;
        ticket_checkednum=ticketnum;
        fs.close();
        QuickSort(logs,ticketnum,2);
    }
    else{
        las=mid->first();
        while(1){
            if(beg==coc){
                fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+ coc + "-" + las + ".txt";
                QFile fs(fname);
                if(fs.open(QIODeviceBase::ReadOnly)){
                    QTextStream in(&fs);
                    in.setEncoding(QStringConverter::System);
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
                        Log* log0=new Log();
                        log0->setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                        logs[j].next=log0;
                        logs[j].setLog(company,ID,sou,des,time0,time1,price,chi,curdate.toString());
                        logs[j].setRoute(QString::fromStdString(s));
                        j++;
                    }
                    //QuickSort4(logs,j);
                    for(i=ticket_checkednum;i<j;i++){
                        qDebug() << "首" <<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
                    }
                }
                ticketnum=j;
                fs.close();
                beg=mid->first();
                mid->removeFirst();
                if(mid->empty()) las=ari;
                else las=mid->first();
            }
            else{
                j=0;
                Log logs0[1000];
                fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+ beg + "-" + las + ".txt";
                QFile fs(fname);
                if(fs.open(QIODeviceBase::ReadOnly)){
                    QTextStream in(&fs);
                    in.setEncoding(QStringConverter::System);
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
                    if(mode==1 || mode==5) QuickSort(logs0,j,2);
                    for(i=0;i<j;i++){
                        qDebug() <<"中"<<logs0[i].company<<logs0[i].ID<<logs0[i].sou<<logs0[i].des<<logs0[i].time0<<logs0[i].time1<<logs0[i].price<<logs0[i].chi<< "\n";
                    }
                    int log_number=0,l=ticketnum-1;
                    bool repeat=false;
                    for(i=ticket_checkednum;i<ticketnum;i++){
                        if(mode==2 || mode==6) QuickSort_Turn(logs[i],logs0,j);
                        if(logs[i].time1.right(2)=="+1"){
                            logs[i].des="不可达";
                            continue;
                        }
                        if(logs[i].des=="不可达") continue;
                        repeat=false;
                        log_number=0;
                        if(mode==1 || mode==5) k=modSearch(logs0,logs[i].time1,0,j+1);
                        else k=0;
                        if(k==0 && timediffer(logs[i].time1,logs0[j-1].time0)<0 && (mode==1 || mode==5)) {
                            logs[i].des="不可达";
                            continue;
                        }
                        QString time_preserve=logs[i].time1;
                        for(; k<=j;k++){
                            if(timediffer(time_preserve,logs0[k].time0)>60 && timediffer(time_preserve,logs0[k].time0)<600){
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
                                if(log_number>=3 && mode<4) break;//&&mode<4
                            }
                        }
                        if(log_number==0) logs[i].des="不可达";
                    }
                    ticketnum=l+1;
                    for(i=0;i<ticketnum;i++){
                        qDebug() <<"过"<<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
                    }
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
            // else if(logs[i].price>(price_max+1000) && mode==5){
            //     for(j=i;j<=ticketnum;j++){
            //         logs[j]=logs[j+1];
            //     }
            //     i--;
            //     ticketnum--;
            // }
            else{
                qDebug() <<"结"<<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
            }
        }
        if(ticketnum<0) ticketnum=0;
        if(mode==1 || mode==5) QuickSort(logs,ticketnum,2);
        else if(mode==2 || mode==6) QuickSort(logs,ticketnum,1);
        ticket_checkednum=ticketnum;
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(loginW==NULL){
        loginW=new Login();
        loginW->show();
        connect(loginW,&Login::sendToMainWindow,this,&MainWindow::getLoginMessage);
    }
    else loginW->raise();
}


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

void CMapSet(QDate curDate,QString* citys,CMap* pMap,int mode){
    int nodeNum=16, arcNum=241;
    int i,j;
    bool label;
    QString year,month,day;
    QString times0,times1;
    int price=0,price0=0,time,time0;
    year= QString::number(curDate.year());
    month= QString::number(curDate.month());
    day= QString::number(curDate.day());
    QString fname,info0;
    QRegularExpression rxlen( "^(.*)/(.*)/(.*)/(.*)/(.*)/(.*)/(.*)/(.*)$" );
    QRegularExpressionMatch match;
    for (i = 0; i < nodeNum;i++) {
        Node* pNode0 = new Node(i);
        pMap->addNode(pNode0);
    }
    for (i = 0; i < nodeNum;i++) {
        for(j = i+1; j < nodeNum;j++) {
            price=0;
            time=0;
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[i] + "-" + citys[j] + ".txt";
            QFile fs(fname);
            if(fs.open(QIODeviceBase::ReadOnly)){
                QTextStream in(&fs);
                in.setEncoding(QStringConverter::System);
                if(mode==1){
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        match = rxlen.match(info0);
                        price0=match.captured(7).toInt();
                        if(price==0) price=price0;
                        else if(price0<price) price=price0;
                    }
                    label=pMap->setValueToMatrixForDirectedGraph(i, j, price);
                }
                else if(mode==2){
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        match = rxlen.match(info0);
                        times0 = match.captured(5);
                        times1 = match.captured(6);
                        time0 = timediffer(times0,times1);
                        if(time==0) time=time0;
                        else if(time0<time) time=time0;
                    }
                    label=pMap->setValueToMatrixForDirectedGraph(i, j, time);
                }
                else if(mode==5){
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        match = rxlen.match(info0);
                        price=match.captured(7).toInt();
                        label=pMap->setValueToMatrixForDirectedGraph(i, j, price);
                    }
                }
                else if(mode==6){
                    while (in.atEnd()==false){
                        info0=in.readLine();
                        match = rxlen.match(info0);
                        times0 = match.captured(5);
                        times1 = match.captured(6);
                        time = timediffer(times0,times1);
                        label=pMap->setValueToMatrixForDirectedGraph(i, j, time);
                    }
                }
            }
            fs.close();
            price=0;
            time=0;
            fname="E:/Qtproject/Dtrip/"+year+"."+month+"."+day+"/"+citys[j] + "-" + citys[i] + ".txt";
            QFile fs1(fname);
            if(fs1.open(QIODeviceBase::ReadOnly)){
                QTextStream in1(&fs1);
                in1.setEncoding(QStringConverter::System);
                if(mode==1){
                    while (in1.atEnd()==false){
                        info0=in1.readLine();
                        match = rxlen.match(info0);
                        price0=match.captured(7).toInt();
                        if(price==0) price=price0;
                        else if(price0<price) price=price0;
                    }
                    label=pMap->setValueToMatrixForDirectedGraph(j, i, price);
                }
                else if(mode==2){
                    while (in1.atEnd()==false){
                        info0=in1.readLine();
                        match = rxlen.match(info0);
                        times0 = match.captured(5);
                        times1 = match.captured(6);
                        time0 = timediffer(times0,times1);
                        if(time==0) time=time0;
                        else if(time0<time) time=time0;
                    }
                    label=pMap->setValueToMatrixForDirectedGraph(j, i, time);
                }
                else if(mode==5){
                    while (in1.atEnd()==false){
                        info0=in1.readLine();
                        match = rxlen.match(info0);
                        price=match.captured(7).toInt();
                        label=pMap->setValueToMatrixForDirectedGraph(j, i, price);
                    }
                }
                else if(mode==6){
                    while (in1.atEnd()==false){
                        info0=in1.readLine();
                        match = rxlen.match(info0);
                        times0 = match.captured(5);
                        times1 = match.captured(6);
                        time = timediffer(times0,times1);
                        label=pMap->setValueToMatrixForDirectedGraph(j, i, time);
                    }
                }
            }
            fs.close();
        }
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    if(ui->pushButton_1->isChecked()){
        if(ticketnum>3 && ticket_now<ticketnum-3){
            int i=0,j;
            while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
            {
                if (QWidget* widget = item->widget()){
                    widget->disconnect();
                    widget->deleteLater();
                }

                if (QSpacerItem* spaerItem = item->spacerItem()){
                    ui->verticalLayout_2->removeItem(spaerItem);
                }

                delete item;
            }
            ticket_now=ticket_now+1;
            j=ticket_now+3;
            ticketInfo* ticket0=new ticketInfo(&logs[j-3],0);
            ticketInfo* ticket1=new ticketInfo(&logs[j-2],0);
            ticketInfo* ticket2=new ticketInfo(&logs[j-1],0);
            ui->verticalLayout_2->addWidget(ticket0);
            ui->verticalLayout_2->addWidget(ticket1);
            ui->verticalLayout_2->addWidget(ticket2);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            connect(ticket1,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            connect(ticket2,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            ui->verticalScrollBar_2->setValue(ticket_now/(double)(ticketnum-3)*999);
        }
    }
    else if(ui->pushButton_2->isChecked()){
        if(changemode==1){
            if(ticketnum>5 && ticket_now<ticketnum-5){
                int i=0,j;
                while (QLayoutItem* item = verticalLayout_7->takeAt(0))
                {
                    if (QWidget* widget = item->widget()){
                        widget->disconnect();
                        widget->deleteLater();
                    }

                    if (QSpacerItem* spaerItem = item->spacerItem()){
                        verticalLayout_7->removeItem(spaerItem);
                    }

                    delete item;
                }
                ticket_now=ticket_now+1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(&logs[i],clog,4);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
                ui->verticalScrollBar_3->setValue(ticket_now/(double)(ticketnum-5)*999);
            }
        }
        else{
            if(myticketnum>5 && ticket_now<myticketnum-5){
                int i=0,j;
                while (QLayoutItem* item = verticalLayout_7->takeAt(0))
                {
                    if (QWidget* widget = item->widget()){
                        widget->disconnect();
                        widget->deleteLater();
                    }

                    if (QSpacerItem* spaerItem = item->spacerItem()){
                        verticalLayout_7->removeItem(spaerItem);
                    }

                    delete item;
                }
                ticket_now=ticket_now+1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
                ui->verticalScrollBar_3->setValue(ticket_now/(double)(myticketnum-5)*999);
            }
        }
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_1->isChecked()){
        if(ticketnum>3 && ticket_now>0){
            int i=0,j;
            while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
            {
                if (QWidget* widget = item->widget()){
                    widget->disconnect();
                    widget->deleteLater();
                }

                if (QSpacerItem* spaerItem = item->spacerItem())
                    ui->verticalLayout_2->removeItem(spaerItem);

                delete item;
            }
            ticket_now=ticket_now-1;
            j=ticket_now+3;
            ticketInfo* ticket0=new ticketInfo(&logs[j-3],0);
            ticketInfo* ticket1=new ticketInfo(&logs[j-2],0);
            ticketInfo* ticket2=new ticketInfo(&logs[j-1],0);
            ui->verticalLayout_2->addWidget(ticket0);
            ui->verticalLayout_2->addWidget(ticket1);
            ui->verticalLayout_2->addWidget(ticket2);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            connect(ticket1,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            connect(ticket2,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            ui->verticalScrollBar_2->setValue(ticket_now/(double)(ticketnum-3)*999);
        }
    }
    else if(ui->pushButton_2->isChecked()){
        if(changemode==1){
            if(ticketnum>5 && ticket_now>0){
                int i=0,j;
                while (QLayoutItem* item = verticalLayout_7->takeAt(0))
                {
                    if (QWidget* widget = item->widget()){
                        widget->disconnect();
                        widget->deleteLater();
                    }

                    if (QSpacerItem* spaerItem = item->spacerItem()){
                        verticalLayout_7->removeItem(spaerItem);
                    }

                    delete item;
                }
                ticket_now=ticket_now-1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(&logs[i],clog,4);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
                ui->verticalScrollBar_3->setValue(ticket_now/(double)(ticketnum-5)*999);
            }
        }
        else{
            if(myticketnum>5 && ticket_now>0){
                int i=0,j;
                while (QLayoutItem* item = verticalLayout_7->takeAt(0))
                {
                    if (QWidget* widget = item->widget()){
                        widget->disconnect();
                        widget->deleteLater();
                    }

                    if (QSpacerItem* spaerItem = item->spacerItem()){
                        verticalLayout_7->removeItem(spaerItem);
                    }

                    delete item;
                }
                ticket_now=ticket_now-1;
                j=ticket_now+5;
                for(i=j-5;i<j;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    verticalLayout_7->addWidget(ticket0);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                }
                ui->verticalScrollBar_3->setValue(ticket_now/(double)(myticketnum-5)*999);
            }
        }
    }
}
void MainWindow::getLoginMessage(QString username,Log* mylog,int myticketnum,int home,double probability,int common,double pco,float time_money,float time_time,float time_straight){
    if(username!=""){
        this->username=username;
        this->userLogs=mylog;
        this->myticketnum=myticketnum;
        ui->pushButton_5->setText("你好！ "+username);
        login=true;
        this->home=home;
        this->probability=probability;
        this->common=common;
        this->pco=pco;
        this->time_money=time_money;
        this->time_time=time_time;
        this->time_straight=time_straight;
        if(ui->pushButton_2->isChecked()) on_pushButton_2_clicked();
        else if(ui->pushButton_3->isChecked()) on_pushButton_3_clicked();
    }
    loginW=NULL;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index==0 || index==3) ui->checkBox->setDisabled(true);
    else ui->checkBox->setDisabled(false);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->isChecked()){
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
        while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
        {
            if (QWidget* widget = item->widget()){
                widget->disconnect();
                widget->deleteLater();
            }

            if (QSpacerItem* spaerItem = item->spacerItem())
                ui->verticalLayout_2->removeItem(spaerItem);

            delete item;
        }
        widget0->show();
        ui->pushButton_1->setChecked(false);
        ui->pushButton_2->setChecked(true);
        ui->pushButton_3->setChecked(false);
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
        if(m!=NULL){
            m->setAttribute(Qt::WA_DeleteOnClose, true);
            m->close();
            m=NULL;
        }
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


void MainWindow::on_pushButton_1_clicked()
{
    if(ui->pushButton_1->isChecked()){
        widget0->hide();
        ui->pushButton_1->setChecked(true);
        ui->pushButton_2->setChecked(false);
        ui->pushButton_3->setChecked(false);
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
        if(m!=NULL){
            m->setAttribute(Qt::WA_DeleteOnClose, true);
            m->close();
            m=NULL;
        }
    }
    changemode=0;
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->isChecked()){
        widget0->hide();
        ui->pushButton_1->setChecked(false);
        ui->pushButton_2->setChecked(false);
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
        while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
        {
            if (QWidget* widget = item->widget()){
                widget->disconnect();
                widget->deleteLater();
            }

            if (QSpacerItem* spaerItem = item->spacerItem())
                ui->verticalLayout_2->removeItem(spaerItem);

            delete item;
        }
        if(m!=NULL){
            m->setAttribute(Qt::WA_DeleteOnClose, true);
            m->close();
            m=NULL;
        }
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
                ui->label_19->setText("用户常用搜索方式：费用最少");
            }
            else if(time_time>=time_straight && time_time>time_money){
                ui->label_19->setText("用户常用搜索方式：时间最短");
            }
            else{
                ui->label_19->setText("用户常用搜索方式：直飞");
            }
        }
        bool bus=false;
        float probus=0;
        userImageAnalyse(userLogs,&bus,&probus);
        if(bus) ui->label_23->setText("用户画像：商业人士");
        else ui->label_23->setText("用户画像：游客");
        ui->label_24->setText("概率："+QString::number(pco*100,'f',1)+'%');
    }
    changemode=0;
}


void MainWindow::on_verticalScrollBar_3_valueChanged(int value)
{
    if(changemode==1){
        if(ticketnum>4){
            int i=0;
            int j=5;
            j=(ticketnum-5)*((double)value/(double)999)+5;
            if(j<5)j=5;
            if(j>ticketnum) j=ticketnum;
            while (QLayoutItem* item = verticalLayout_7->takeAt(0))
            {
                if (QWidget* widget = item->widget()) widget->deleteLater();
                delete item;
            }
            //ticket_now=j-5;
            for(i=j-5;i<j;i++){
                ticketInfo* ticket0=new ticketInfo(&logs[i],clog,4);
                verticalLayout_7->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
        }
    }
    else{
        if(myticketnum>4){
            int i=0;
            int j=5;
            j=(myticketnum-5)*((double)value/(double)999)+5;
            if(j<5)j=5;
            if(j>myticketnum) j=myticketnum;
            while (QLayoutItem* item = verticalLayout_7->takeAt(0))
            {
                if (QWidget* widget = item->widget()) widget->deleteLater();
                    delete item;
            }
            //ticket_now=j-5;
            for(i=j-5;i<j;i++){
                ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                verticalLayout_7->addWidget(ticket0);
                connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
            }
        }
    }
}

void MainWindow::on_pushButton_9_clicked(bool checked)
{
    int index=ui->comboBox_2->currentIndex();
    int i,k;
    if(ui->pushButton_2->isChecked() && changemode==0 && myticketnum!=0){
        switch(index){
        case 0:if(mysortmode==9) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,2); mysortmode=2;break;
        case 1:if(mysortmode==2) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,9); mysortmode=9;break;
        case 2:if(mysortmode==8) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,1); mysortmode=1;break;
        case 3:if(mysortmode==1) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,8); mysortmode=8;break;
        case 4:if(mysortmode==10) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,3); mysortmode=3;break;
        case 5:if(mysortmode==3) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,10); mysortmode=10;break;
        case 6:if(mysortmode==11) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,4); mysortmode=4;break;
        case 7:if(mysortmode==4) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,11); mysortmode=11;break;
        case 8:if(mysortmode==5) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,12); mysortmode=12;break;
        case 9:if(mysortmode==12) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,5); mysortmode=5;break;
        case 10:if(mysortmode==13) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,6); mysortmode=6;break;
        case 11:if(mysortmode==6) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,13); mysortmode=13;break;
        case 12:if(mysortmode==14) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,7); mysortmode=7;break;
        case 13:if(mysortmode==7) invert(userLogs,myticketnum); else QuickSort(userLogs,myticketnum,14); mysortmode=14;break;
        }
    }
    else if(ticketnum!=0){
        switch(index){
        case 0:if(sortmode==9) invert(logs,ticketnum); else QuickSort(logs,ticketnum,2); sortmode=2;break;
        case 1:if(sortmode==2) invert(logs,ticketnum); else QuickSort(logs,ticketnum,9); sortmode=9;break;
        case 2:if(sortmode==8) invert(logs,ticketnum); else QuickSort(logs,ticketnum,1); sortmode=1;break;
        case 3:if(sortmode==1) invert(logs,ticketnum); else QuickSort(logs,ticketnum,8); sortmode=8;break;
        case 4:if(sortmode==10) invert(logs,ticketnum); else QuickSort(logs,ticketnum,3); sortmode=3;break;
        case 5:if(sortmode==3) invert(logs,ticketnum); else QuickSort(logs,ticketnum,10); sortmode=10;break;
        case 6:if(sortmode==11) invert(logs,ticketnum); else QuickSort(logs,ticketnum,4); sortmode=4;break;
        case 7:if(sortmode==4) invert(logs,ticketnum); else QuickSort(logs,ticketnum,11); sortmode=11;break;
        case 8:if(sortmode==5) invert(logs,ticketnum); else QuickSort(logs,ticketnum,12); sortmode=12;break;
        case 9:if(sortmode==12) invert(logs,ticketnum); else QuickSort(logs,ticketnum,5); sortmode=5;break;
        }
    }
    if(ui->pushButton_1->isChecked() && copymode==0){
        while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
        {
            if (QWidget* widget = item->widget()){
                widget->disconnect();
                widget->deleteLater();
            }

            if (QSpacerItem* spaerItem = item->spacerItem())
                ui->verticalLayout_2->removeItem(spaerItem);

            delete item;
        }
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
    else if(ui->pushButton_1->isChecked() && copymode==1){
        getScrollBarMessage();
    }
    else if(ui->pushButton_2->isChecked() && changemode==1){
        k=5;
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
    else if((ui->pushButton_2->isChecked() && changemode==0)){
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
            QSpacerItem* sp1=new QSpacerItem(20,130*(5-myticketnum),QSizePolicy::Minimum,QSizePolicy::Fixed);
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
void MainWindow::closeEvent(QCloseEvent *event) {
    if(m!=NULL){
        m->setAttribute(Qt::WA_DeleteOnClose, true);
        m->close();
        m=NULL;
    }
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE","read_connection");
    database.setDatabaseName(pathCreator("dbs/users.db"));
    database.setUserName("root");
    database.setPassword("123456");
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
        database.close();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        QSqlDatabase::removeDatabase("read_connection");
    }
}

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

void MainWindow::on_pushButton_8_clicked()
{
    ui->pushButton_2->setChecked(true);
    on_pushButton_2_clicked();
}


void MainWindow::on_pushButton_10_clicked()
{
    this->close();
}

void MainWindow::on_verticalScrollBar_3_sliderReleased()
{
    int value=ui->verticalScrollBar_3->value();
    ticket_now=(myticketnum-5)*((double)value/(double)999);
}

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

void MainWindow::getScrollBarMessage(){
    int i;
    QStringList st;
    QWidget* wid=ui->scrollArea->widget();
    foreach(QCheckBox* child,wid->findChildren<QCheckBox*>()){
        if(child->isChecked()) st.append(child->objectName());
    }
    if(st.empty()){
        copymode=0;
        ui->verticalScrollBar_2->setSliderPosition(0);
        on_verticalScrollBar_2_valueChanged(0);
        return;
    }
    copynum=0;
    copymode=1;
    for(i=0;i<ticketnum;i++){
        foreach(QString item,st){
            if(item.left(1)=="起"){
                if(routeTranslate(logs[i].route)==item){
                    copylogs[copynum]=&logs[i];
                    copynum++;
                    break;
                }
            }
            else{
                if(item.mid(0,logs[i].company.length()).contains(logs[i].company)){
                    copylogs[copynum]=&logs[i];
                    copynum++;
                    break;
                }
            }
        }
    }
    while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
    {
        if (QWidget* widget = item->widget())
            widget->deleteLater();

        delete item;
    }
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

void MainWindow::on_pushButton_12_clicked()
{
    if(ui->scrollArea->isVisible()) ui->scrollArea->setVisible(false);
    else ui->scrollArea->setVisible(true);
}

