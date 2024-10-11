#define _CRT_SECURE_NO_WARNINGS 1
#include "mainwindow.h"
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
    ui->pushButton->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px; background-color: #88CDF6;");
    ui->pushButton_4->setIcon(QIcon("E:/Qtproject/Dtrip/search.png"));
    ui->pushButton_4->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px; background-color: #88CDF6;");
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
    widget0->resize(700,600);
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
        ticketWindow *t=new ticketWindow(tlog,mode);
        connect(t,&ticketWindow::sendToMainWindow,this,&MainWindow::getticketwindowMessage);
        connect(t,&ticketWindow::Exit,this,&MainWindow::show);
        t->show();
    }
}
void MainWindow::getticketwindowMessage(Log* tlog){
    if(userLogs==NULL) userLogs=tlog;
    else userLogs[myticketnum]=*tlog;
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
        sql_query2.exec("SELECT uid FROM ticket ORDER BY uid DESC LIMIT 1");
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
            QString insert_sql = QString("insert into ticket(uid, name, id , sou, des, time0, time1, price, chi, next, date) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11') ").arg(max_number+1).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(2).arg(p->curdate);
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
            while(p!=NULL){
                QString insert_sql;
                if(head) {
                    insert_sql = QString("insert into ticket(uid, name, id , sou, des, time0, time1, price, chi, next, date) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11') ").arg(max_number+1).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(1).arg(p->curdate);
                    head=false;
                }
                else insert_sql = QString("insert into ticket(uid, name, id , sou, des, time0, time1, price, chi, next, date) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11') ").arg(max_number+1).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(0).arg(p->curdate);
                if(!sql_query2.exec(insert_sql))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "inserted SUCCESS!";
                }
                max_number++;
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
}


void MainWindow::on_verticalScrollBar_2_sliderMoved(int position)
{
    if(ticketnum>2){
        int i=0;
        int j=3;
        j=(ticketnum+1)*((double)position/(double)100);
        if(j<3)j=3;
        if(j>ticketnum) j=ticketnum;
        while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();

            delete item;
        }
        ticket_now=j-3;
        ticketInfo* ticket0=new ticketInfo(&logs[j-3],0);
        ticketInfo* ticket1=new ticketInfo(&logs[j-2],0);
        ticketInfo* ticket2=new ticketInfo(&logs[j-1],0);
        ui->verticalLayout_2->addWidget(ticket0);
        ui->verticalLayout_2->addWidget(ticket1);
        ui->verticalLayout_2->addWidget(ticket2);
        connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
        connect(ticket1,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
        connect(ticket2,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
    }
}


void MainWindow::on_verticalScrollBar_2_valueChanged(int value)
{
    if(ticketnum>2){
        int i=0;
        int j=3;
        j=(ticketnum-3)*((double)ui->verticalScrollBar_2->sliderPosition()/(double)99)+3;
        if(j<3)j=3;
        if(j>ticketnum) j=ticketnum;
        while (QLayoutItem* item = ui->verticalLayout_2->takeAt(0))
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();

            if (QSpacerItem* spaerItem = item->spacerItem())
                ui->verticalLayout_2->removeItem(spaerItem);

            delete item;
        }
        ticket_now=j-3;
        ticketInfo* ticket0=new ticketInfo(&logs[j-3],0);
        ticketInfo* ticket1=new ticketInfo(&logs[j-2],0);
        ticketInfo* ticket2=new ticketInfo(&logs[j-1],0);
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
    year= QString::number(curDate.year());
    month= QString::number(curDate.month());
    day= QString::number(curDate.day());
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
                        j++;
                    }
                    //QuickSort4(logs,j);
                    for(i=ticket_checkednum;i<j;i++){
                        qDebug() << "首" <<logs[i].company<<logs[i].ID<<logs[i].sou<<logs[i].des<<logs[i].time0<<logs[i].time1<<logs[i].price<<logs[i].chi<< "\n";
                    }
                    ui->label_10->setVisible(false);
                    ui->label_11->setVisible(false);
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
                                    log2->setLog(logs0[k].company,logs0[k].ID,logs0[k].sou,logs0[k].des,logs0[k].time0,logs0[k].time1,logs0[k].price,logs0[k].chi,curdate.toString());
                                    logs[i].des=logs0[k].des;
                                    logs[i].price=logs[i].price+logs0[k].price;
                                    logs[i].time1=logs0[k].time1;
                                    repeat=true;
                                }
                                else{
                                    int price1=0;
                                    l++;
                                    p=&logs[i];
                                    q=&logs[l];
                                    while(p->next->next!=NULL){
                                        p=p->next;
                                        price1=price1+p->price;
                                        Log* log1=new Log();
                                        log1->setLog(p->company,p->ID,p->sou,p->des,p->time0,p->time1,p->price,p->chi,curdate.toString());
                                        q->next=log1;
                                        q=q->next;
                                    }
                                    logs[l].setLog(logs[i].company,logs[i].ID,logs[i].sou,logs0[k].des,logs[i].time0,logs0[k].time1,logs0[k].price+price1,logs[i].chi,curdate.toString());
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
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
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
    Login* login=new Login();
    login->show();
    connect(login,&Login::sendToMainWindow,this,&MainWindow::getLoginMessage);
}


void MainWindow::on_lineEditdep_textChanged(const QString &arg1)
{
    int i,j,k;
    bool label,labeldep=false,labelari=false;
    if(ui->lineEditdep->text()!=""){
        for(i=0;i<16;i++){
            if(citys[i].contains(ui->lineEditdep->text())) {
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
            if(citys[i].contains(ui->lineEditari->text())) {
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
            ui->verticalScrollBar_2->setValue(ticket_now/(double)(ticketnum-3)*100);
        }
    }
    else if(ui->pushButton_2->isChecked()){
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
            ui->verticalScrollBar_3->setValue(ticket_now/(double)(myticketnum-5)*100);
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
            ui->verticalScrollBar_2->setValue(ticket_now/(double)(ticketnum-3)*100);
        }
    }
    else if(ui->pushButton_2->isChecked()){
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
            ui->verticalScrollBar_3->setValue(ticket_now/(double)(myticketnum-5)*100);
        }
    }
}
void MainWindow::getLoginMessage(QString username,Log* mylog,int myticketnum){
    this->username=username;
    this->myticketnum=myticketnum;
    userLogs=mylog;
    ui->pushButton_5->setText("你好！ "+username);
    login=true;
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
        ui->label_4->setVisible(false);
        ui->label_7->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->dateEdit->setVisible(false);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        button_swap->setVisible(false);
        ui->verticalScrollBar_2->setVisible(false);
        ui->verticalScrollBar_3->setVisible(true);
        int i;
        if(myticketnum==0){
            Log* logno=new Log();
            if(username=="") logno->setLog("您还没有登录","登录后即可查看信息","没登录","快登录","00:00","24:00",2,"登录后即可查看","");
            else logno->setLog("您还没有订票",username,"没有票","快订票","00:00","24:00",2,"查询后即可订票","");
            ticketInfo* ticket0=new ticketInfo(logno,0);
            verticalLayout_7->addWidget(ticket0);
        }
        else{
            if(myticketnum<=5){
                for(i=0;i<myticketnum;i++){
                    ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
                    connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
                    verticalLayout_7->addWidget(ticket0);
                }
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
    ui->pushButton_2->setChecked(true);
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
        ui->label_10->setVisible(true);
        ui->label_11->setVisible(true);
        ui->label_4->setVisible(true);
        ui->label_7->setVisible(true);
        ui->comboBox->setVisible(true);
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->dateEdit->setVisible(true);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        button_swap->setVisible(true);
        ui->verticalScrollBar_2->setVisible(true);
        ui->verticalScrollBar_3->setVisible(false);
    }
    ui->pushButton_1->setChecked(true);
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->isChecked()){
        widget0->hide();
        ui->pushButton_1->setChecked(false);
        ui->pushButton_2->setChecked(false);
        ui->pushButton_3->setChecked(true);
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
    }
    ui->pushButton_3->setChecked(true);
}


void MainWindow::on_verticalScrollBar_3_valueChanged(int value)
{
    if(myticketnum>4){
        int i=0;
        int j=5;
        j=(myticketnum-5)*((double)value/(double)99)+5;
        if(j<5)j=5;
        if(j>myticketnum) j=myticketnum;
        while (QLayoutItem* item = verticalLayout_7->takeAt(0))
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();

            delete item;
        }
        ticket_now=j-5;
        for(i=j-5;i<j;i++){
            ticketInfo* ticket0=new ticketInfo(&userLogs[i],3);
            verticalLayout_7->addWidget(ticket0);
            connect(ticket0,&ticketInfo::sendToMainWindow,this,&MainWindow::getticketInfoMessage);
        }
    }
}

