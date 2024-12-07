#include "mainwindow4.h"
#include "ui_mainwindow4.h"
#include "cityweight.h"
#include <QMessageBox>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <random>
#include "des.h"
#include <ctime>
#include "QuickSort.h"
#include <algorithm>
#pragma comment(lib,"sqlcipher.LIB")
//后台界面的实现
MainWindow4::MainWindow4(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow4)
{
    ui->setupUi(this);
    //设置控件
    for(int i=0;i<16;i++){
        cityweight *cw=new cityweight(citys[i]);
        cw->setObjectName(citys[i]);
        ui->gridLayout->addWidget(cw,i/16,i%16);
    }
    for(int i=0;i<16;i++){
        cityweight *cw=new cityweight(citys[i]);
        cw->setObjectName(citys[i]);
        ui->gridLayout_2->addWidget(cw,i/16,i%16);
    }
    for(int i=0;i<16;i++){
        cityweight *cw=new cityweight(citys[i]);
        cw->setObjectName(citys[i]);
        ui->gridLayout_3->addWidget(cw,i/16,i%16);
    }
    for(int i=0;i<16;i++){
        ui->comboBox->addItem(citys[i]);
    }
    //设置输入正则表达式过滤器
    ui->lineEdit_4->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-9]+$")));
    ui->pushButton->setStyleSheet("border: 2px solid #009ef9;border-radius: 10px;background-color: white;");
}

MainWindow4::~MainWindow4()
{
    delete ui;
}
//判断用户组名是否符合要求
void MainWindow4::on_lineEdit_returnPressed()
{
    if(ui->lineEdit->text().length()<3){
        ui->lineEdit->setText("");
            ui->lineEdit->setPlaceholderText("不能少于3个字符");
    }
}

//判断密码长度是否符合要求
void MainWindow4::on_lineEdit_2_returnPressed()
{
    if(ui->lineEdit_2->text().length()<6){
        ui->lineEdit->setText("");
        ui->lineEdit->setPlaceholderText("不能少于6个字符");
    }
}

/*
生成用户按钮槽函数即生成用户功能的实现
func：
1.对输入进行判断：用户组名是否正确，用户密码是否正确，出行次数是否符合要求
2.开始逐用户创建数据库并搜索数据加入到数据库中
3.生成过程中用进度条提示用户进度
*/
void MainWindow4::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==""){
        QMessageBox msgBox;
        msgBox.setText("用户组名不能为空");
        msgBox.setInformativeText("用户组名至少为3位");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    else if(ui->lineEdit_2->text()==""){
        QMessageBox msgBox;
        msgBox.setText("用户密码不能为空");
        msgBox.setInformativeText("用户密码至少为6位");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    else if(ui->lineEdit_4->text()==""){
        QMessageBox msgBox;
        msgBox.setText("出行次数不能为空");
        msgBox.setInformativeText("出行次数不能为空");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    else if(ui->dateEdit->date().daysTo(ui->dateEdit_2->date())<0){
        QMessageBox msgBox;
        msgBox.setText("最近日期不能小于初始日期");
        msgBox.setInformativeText("请检查");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    else if(ui->dateEdit->date().daysTo(ui->dateEdit_2->date())/ui->lineEdit_4->text().toInt()<2){
        QMessageBox msgBox;
        msgBox.setText("出行过于频繁");
        msgBox.setInformativeText("出行次数不能大于天数区间的一半\n这边建议您前进四");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    else{
        //获取组内用户数
        int usernums=ui->spinBox->value();
        float souweight[16],desweight[16];
        //获取用户出发地权重
        for (int i = 0; i < 16; i++)
        {
            QLayoutItem* item = ui->gridLayout->itemAt(i);
            cityweight *child=(cityweight*)item->widget();
            souweight[i]=child->getweight();
        }
        //获取用户目的地权重
        for (int i = 0; i < 16; i++)
        {
            QLayoutItem* item = ui->gridLayout_3->itemAt(i);
            cityweight *child=(cityweight*)item->widget();
            desweight[i]=child->getweight();
        }
        //获取用户搜索方式
        int searchmode=ui->comboBox_3->currentIndex();
        //获取常乘航司信息
        QString company=ui->lineEdit_3->text();
        int sounum;
        //获取出行次数
        sounum=ui->lineEdit_4->text().toInt();
        //初始化进度条
        ui->lineEdit_5->clear();
        ui->label_14->setText("0%");
        //开始生成用户
        for(int usernum=0;usernum<usernums;usernum++){
            //首先创建用户数据库，并设置部分用户数据
            createUsers(usernum,souweight,desweight,searchmode);
            //接下来开始票据生成
            //先获取区间起始日期
            QDate curdate=ui->dateEdit->date();
            //sounum：出行次数 interval：区间天数长度
            int interval;
            int *days=new int[sounum];
            interval=ui->dateEdit->date().daysTo(ui->dateEdit_2->date());
            //生成一个0-区间天数的数组
            vector<int> temp;
            for (int i = 0; i <= interval; i++){
                temp.push_back(i);
            }
            //随机打乱该数组
            random_shuffle(temp.begin(), temp.end());
            //取该数组的前sounum个作为出行日期
            for(int i=0;i<sounum;i++){
                days[i]=temp[i];
            }
            //将出行日期升序排序
            QuickSortcommon(days,sounum,0,0);
            Log mylogs[1000];
            int myticketnum=0;
            //开始逐日期构建航线并获取机票数据
            for(int i=0;i<sounum;i++){
                //计算出发日期
                curdate=ui->dateEdit->date().addDays(days[i]);
                //period：这次出行的最长天数，daysstay：在此地的停留时间
                int period=14,daysstay=0;
                //flytimes：飞行权重（用于计算回家概率）
                float flytimes=0.5;
                //计算本次出行的最长天数
                if(i!=sounum-1) period=days[i+1]-days[i];
                //购买第一张票
                int end=0,modebase=0,home;
                //urgent：是否为紧急清况（来不及了）
                bool urgent=false;
                //获取用户住所作为始发地
                int begin=ui->comboBox->currentIndex();
                //第一张票的始发地为用户住所
                home=begin;
                //根据权重随机目的地（end）
                float desweightcopy[16];
                for(int j=0;j<16;j++){
                    if(j==home) desweightcopy[j]=0;
                    else desweightcopy[j]=desweight[j];
                }
                //加权随机
                weightedRandom(desweightcopy,16,end);
                //设置搜索方式权重 0：费用最少，1：时间最短 2：直飞
                float timesearchs[3];
                switch(searchmode){
                case(0): timesearchs[0]=8;timesearchs[1]=0.5;timesearchs[2]=0;break;
                case(1): timesearchs[0]=0.5;timesearchs[1]=8;timesearchs[2]=0;break;
                case(2): timesearchs[0]=0.5;timesearchs[1]=0.5;timesearchs[2]=8;break;
                }
                //mode：0智能搜索 3直飞 modeuser 0直飞 1：费用最少 2：时间最短
                int mode,modeuser;
                //如果距离下次旅行只有1天，进入紧急模式
                if(period==1) {
                    //急了
                    urgent=true;
                    mode=0;
                    modeuser=2;
                }
                else{
                    //否则根据权重随机搜索方式
                    weightedRandom(timesearchs,3,modebase);
                    if(modebase==2) {
                        mode=3;
                        modeuser=0;
                    }
                    else if(modebase==0){
                        mode=0;
                        modeuser=1;
                    }
                    else{
                        mode=0;
                        modeuser=2;
                    }
                }
                Log logs[3000];
                int ticketnum=0,ticket_checkednum=0;
                //查询票据，算法与搜索界面相同
                findticket(curdate,begin,end,logs,mode,modeuser,ticketnum,ticket_checkednum);
                int rand;
                bool find=false;
                //如果开启了常乘航司功能
                if(company!=""){
                    Log copylogs[1000];
                    int copynum=0;
                    //对常乘航司进行筛选，将符合要求的机票加入到复制数组中
                    companyFilter(logs,ticketnum,copylogs,copynum);
                    //如果存在符合要求的票
                    if(copynum>0){
                        //随机获取一张票，并将该票放入用户票据中
                        myRandom(copynum,rand);
                        Log *p=&copylogs[rand];
                        Log *q=&mylogs[myticketnum];
                        while(p->next!=nullptr){
                            p=p->next;
                            Log* log1=new Log();
                            log1->setlogL(p);
                            q->next=log1;
                            q=q->next;
                        }
                        mylogs[myticketnum].setlogL(&copylogs[rand]);
                        myticketnum++;
                        find=true;
                    }
                }
                //否则随机选票
                if(!find){
                    //随机选择票据，并将该票放入用户票据中
                    myRandom(ticketnum,rand);
                    Log *p=&logs[rand];
                    Log *q=&mylogs[myticketnum];
                    while(p->next!=nullptr){
                        p=p->next;
                        Log* log1=new Log();
                        log1->setlogL(p);
                        q->next=log1;
                        q=q->next;
                    }
                    mylogs[myticketnum].setlogL(&logs[rand]);
                    myticketnum++;
                }
                vector<int> precity;
                //继续后续选择，直到回家
                while(end!=home){
                    //根据上一张票更新当前日期
                    if(mylogs[myticketnum-1].time1!="" && mylogs[myticketnum-1].time1.last(2)=="+1"){
                        curdate=curdate.addDays(1);
                    }
                    else if(mylogs[myticketnum-1].time1!="" && mylogs[myticketnum-1].time1.last(2)=="+2"){
                        curdate=curdate.addDays(2);
                    }
                    //如果时间紧迫，且下一次可以推迟，就推迟下次出发的时间
                    if(curdate.daysTo(ui->dateEdit->date().addDays(days[i+1]))==0){
                        if((i+2)<sounum && days[i+2]-days[i+1]>3){
                            days[i+1]++;
                        }
                        else if(i==sounum-2){
                            days[i+1]++;
                        }
                        //进入紧急模式（你看又急）
                        urgent=true;
                    }
                    //将上一次的目的地作为此次的始发地
                    begin=end;
                    bool back=false;
                    //如果不急的话，利用正态分布，计算出发间隔
                    if(!urgent){
                        double aver=period/2;
                        double stddev=period/6;
                        if(period>14){
                            aver=7;
                            stddev=2;
                        }
                        while(1){
                            std::default_random_engine generator;
                            std::normal_distribution<double> distribution(aver, stddev);
                            daysstay = distribution(generator);
                            if(daysstay>=0 && daysstay<period) break;
                        }
                        int lastdays=curdate.daysTo(ui->dateEdit->date().addDays(days[i+1]));
                        //随机出了如果立即返回
                        if(daysstay==0){
                            //开启紧急模式
                            urgent=true;
                        }
                        //如果待的太久了，赶紧回家
                        else if(lastdays-daysstay<=1){
                            //设置立即回家为true
                            back=true;
                        }
                        //更新当前日期
                        curdate=curdate.addDays(daysstay);
                    }
                    //如果紧急立即回家
                    if(back){
                        mode=0;
                        modeuser=2;
                        //将目的地设为家
                        end=home;
                    }
                    //否则加权计算目的地
                    else{
                        weightedRandom(timesearchs,3,modebase);
                        if(modebase==2) {
                            mode=3;
                            modeuser=0;
                        }
                        else if(modebase==0){
                            mode=0;
                            modeuser=1;
                        }
                        else{
                            mode=0;
                            modeuser=2;
                        }
                        float sum=0;
                        //复制权重数组，将始发地的权重设为0
                        for(int j=0;j<16;j++){
                            if(j!=home) sum+=desweight[j];
                            if(j==begin) desweightcopy[j]=0;
                            else desweightcopy[j]=desweight[j];
                        }
                        //将去过的地方的权重减半（每去一次减一半）
                        if(precity.size()!=0){
                            for(int j=0;j<precity.size();j++){
                                if(desweightcopy[precity.at(j)]!=0) {
                                    desweightcopy[precity.at(j)]=desweightcopy[precity.at(j)]/2;
                                    sum-=desweightcopy[precity.at(j)];
                                }
                            }
                        }
                        //如果始发地不等于家，则根据飞行次数设置家的权重
                        if(begin!=home) desweightcopy[home]=sum*flytimes;
                        //按权重随机目的地
                        weightedRandom(desweightcopy,16,end);
                    }
                    //清空上次搜索结果
                    for(int j=0;j<ticketnum;j++){
                        logs[j].clear();
                    }
                    ticketnum=0;
                    ticket_checkednum=0;
                    //查找票据
                    findticket(curdate,begin,end,logs,mode,modeuser,ticketnum,ticket_checkednum);
                    //如果紧急，先查今天的再查明天的
                    if(urgent || back){
                        bool find=false;
                        int pretime=0;
                        if(mylogs[myticketnum-1].time1.right(2)=="+1") pretime=1440;
                        else if(mylogs[myticketnum-1].time1.right(2)=="+2") pretime=2880;
                        for(int j=0;j<ticketnum;j++){
                            if(timediffer(mylogs[myticketnum-1].time1,logs[j].time0)+pretime>=60){
                                Log *p=&logs[rand];
                                Log *q=&mylogs[myticketnum];
                                while(p->next!=nullptr){
                                    p=p->next;
                                    Log* log1=new Log();
                                    log1->setlogL(p);
                                    q->next=log1;
                                    q=q->next;
                                }
                                mylogs[myticketnum].setlogL(&logs[rand]);
                                myticketnum++;
                                find=true;
                                break;
                            }
                        }
                        if(!find){
                            for(int j=0;j<ticketnum;j++){
                                logs[j].clear();
                            }
                            ticketnum=0;
                            ticket_checkednum=0;
                            findticket(curdate.addDays(1),begin,end,logs,mode,modeuser,ticketnum,ticket_checkednum);
                            myRandom(ticketnum,rand);
                            Log *p=&logs[rand];
                            Log *q=&mylogs[myticketnum];
                            while(p->next!=nullptr){
                                p=p->next;
                                Log* log1=new Log();
                                log1->setlogL(p);
                                q->next=log1;
                                q=q->next;
                            }
                            mylogs[myticketnum].setlogL(&logs[rand]);
                            myticketnum++;
                        }
                    }
                    //如果不紧急，先查常乘航司，查不到再查全部
                    else{
                        bool find=false;
                        if(company!=""){
                            Log copylogs[1000];
                            int copynum=0;
                            companyFilter(logs,ticketnum,copylogs,copynum);
                            if(copynum>0){
                                myRandom(copynum,rand);
                                Log *p=&copylogs[rand];
                                Log *q=&mylogs[myticketnum];
                                while(p->next!=nullptr){
                                    p=p->next;
                                    Log* log1=new Log();
                                    log1->setlogL(p);
                                    q->next=log1;
                                    q=q->next;
                                }
                                mylogs[myticketnum].setlogL(&copylogs[rand]);
                                myticketnum++;
                                find=true;
                            }
                        }
                        //否则随机选票
                        if(!find){
                            myRandom(ticketnum,rand);
                            Log *p=&logs[rand];
                            Log *q=&mylogs[myticketnum];
                            while(p->next!=nullptr){
                                p=p->next;
                                Log* log1=new Log();
                                log1->setlogL(p);
                                q->next=log1;
                                q=q->next;
                            }
                            mylogs[myticketnum].setlogL(&logs[rand]);
                            myticketnum++;
                        }
                    }
                    //飞行次数上升
                    flytimes++;
                    //将这次去的城市加入已去数组
                    precity.push_back(end);
                }
                for(int i=0;i<ticketnum;i++){
                    logs[i].clear();
                }
            }
            //买完票后, 删除无效票据
            for(int i=myticketnum-1;i>=0;i--){
                if(mylogs[i].time1=="" || mylogs[i].time0==""){
                    mylogs[i].clear();
                    for(int j=i;j<myticketnum;j++){
                        mylogs[j]=mylogs[j+1];
                    }
                    //i--;
                    myticketnum--;
                }
            }
            // for(int i=0;i<myticketnum;i++){
            //     qDebug() <<mylogs[i].company<<mylogs[i].ID<<mylogs[i].sou<<mylogs[i].des<<mylogs[i].time0<<mylogs[i].time1<<mylogs[i].price<<mylogs[i].chi<<mylogs[i].curdate<< "\n";
            // }
            //将用户票据写入用户数据库
            setTicketsToDB(mylogs,myticketnum,usernum);
            //更新进度条
            updateMyProgressbar(usernum);
            //delete[] days;
            for(int i=0;i<myticketnum;i++){
                mylogs[i].clear();
            }
        }
    }
}
//用户数据库生成函数：createUsers 功能与登录界面的相似
bool MainWindow4::createUsers(int num,float *souweight,float *desweight,int searchmode){
    float timemoney, timetime, timestraight;
    switch(searchmode){
    case(0): timemoney=8;timetime=0.5;timestraight=0.5;break;
    case(1): timemoney=0.5;timetime=8;timestraight=0.5;break;
    case(2): timemoney=0.5;timetime=0.5;timestraight=8;break;
    }
    QString username=ui->lineEdit->text()+"_"+QString::number(num);
    bool dbExist = QFile::exists(pathCreator("dbs/"+username+".db"));
    if (dbExist){
        return false;
    }
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("SQLITECIPHER","read_connection");
    qDebug() << pathCreator("dbs/"+username+".db");
    database.setDatabaseName(pathCreator("dbs/"+username+".db"));
    database.setUserName(username);
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
        QString insert_sql = QString("insert into searchtimes (LABEL, 北京, 上海, 昆明, 广州, 台北, 西安, 乌鲁木齐, 哈尔滨, 拉萨, 西宁, 新加坡, 马尼拉, 曼谷, 东京, 首尔, 新德里) values('0',");
        for(int i=0;i<16;i++){
            if(i!=15) insert_sql+="'"+QString::number(souweight[i])+"',";
            else insert_sql+="'"+QString::number(souweight[i])+"')";
        }
        if(!sql_query.exec(insert_sql))
        {
            qDebug() << sql_query.lastError();
        }
        else
        {
            qDebug() << "inserted searchtime0!";
        }
        insert_sql = QString("insert into searchtimes (LABEL, 北京, 上海, 昆明, 广州, 台北, 西安, 乌鲁木齐, 哈尔滨, 拉萨, 西宁, 新加坡, 马尼拉, 曼谷, 东京, 首尔, 新德里) values('1',");
        for(int i=0;i<16;i++){
            if(i!=15) insert_sql+="'"+QString::number(desweight[i])+"',";
            else insert_sql+="'"+QString::number(desweight[i])+"')";
        }
        if(!sql_query.exec(insert_sql))
        {
            qDebug() << sql_query.lastError();
        }
        else
        {
            qDebug() << "inserted searchtime1!";
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
            QString insert_sql = QString("insert into users(uid, name, password, question, timemoney, timetime, timestraight, cost, mileage) values('%1','%2','%3','%4','%5','%6','%7','0','0') ").arg(max_number+1).arg(username).arg(ui->lineEdit_2->text()).arg(ui->comboBox->currentText()).arg(timemoney).arg(timetime).arg(timestraight);
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
    QString name0 = QSqlDatabase::database().connectionName();
    QSqlDatabase::removeDatabase(name0);
    return true;
}
//查找票据函数：findticket 功能与主页面on_pushbutton4_clicked差不多，都是查找票据
void MainWindow4::findticket(QDate curdate,int begin,int end,Log* logs,int mode,int modeuser,int &ticketnum,int &ticket_checkednum)
{
    int nodeNum=16, arcNum=241;
    int i=0,j,k;
    bool label,labeldep=false,labelari=false;
    ticketnum=0;
    ticket_checkednum=0;
    QDate curDate =ui->dateEdit->date();
    QString year,month,day;
    int price=0,price0=0,time_min,time_min0;
    year= QString::number(curDate.year());
    month= QString::number(curDate.month());
    day= QString::number(curDate.day());
    CMap* pMap = new CMap(nodeNum,arcNum);
    Dist* dist;
    if(mode!=0) CMapSet(curDate,citys,pMap,mode);
    else {
        CMapSet(curDate,citys,pMap,modeuser);
    }
    string s="< "+to_string(begin)+" : 999 "+to_string(end)+" >";
    setLog(s,mode,curdate,ticketnum,ticket_checkednum,logs);
    if(mode==0 && ticketnum<10){
        dist = pMap->Dijkstra(begin);
        //获取最低路径
        string s = pMap->visit_first(dist,begin,end);
        setLog(s,modeuser,curdate,ticketnum,ticket_checkednum,logs);
        if(ticketnum<10){
            string s1 = pMap->visit_second(dist,begin,end);
            setLog(s1,modeuser,curdate,ticketnum,ticket_checkednum,logs);
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
                //获取最低路径
                bool blist[16];
                for(i=0;i<16;i++) {
                    blist[i]=false;
                }
                QStringList list = pMap->visit_plus(dist,begin,end,end,0,blist);
                for(i=0;i<list.size();i++) {
                    qDebug() << list[i] << "\n";
                }
                while (!list.empty()) {
                    setLog(list[0].toStdString(),modeuser,curdate,ticketnum,ticket_checkednum,logs);
                    list.removeFirst();
                    if(ticketnum>400) break;
                }
            }
        }
        delete[] dist;
    }
    delete pMap;
}
/*加权随机计算函数：weightedRandom
input args：
    array：权重数组
    n：数组长度
    randnum：随机结果
*/
template <typename T>
void MainWindow4::weightedRandom(T *array,int n,int &randnum){
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=array[i];
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distrib(0,sum); // 指定范围
    float randu=distrib(gen);
    // float srand(time(NULL));
    // float randu = (double)rand() / (32767 + 1) * sum;
    sum=0;
    for(int i=0;i<n;i++){
        sum+=array[i];
        if(sum>=randu) {
            randnum=i;
            break;
        }
    }
}
//指定范围随机小数生成函数：myRandom n：范围（0-n） randnum：随机小数
void MainWindow4::myRandom(int n,int &randnum){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distrib(0,n); // 指定范围
    randnum=distrib(gen);
}
//向数据库中写入用户票据数组 功能与主界面getticketWindowMessage差不多
void MainWindow4::setTicketsToDB(Log* mylogs,int myticketnum,int num){
    QString username=ui->lineEdit->text()+"_"+QString::number(num);
    bool business=ui->comboBox_2->currentIndex();
    QString uid;
    openDatabasegetuid(&uid,username);
    if(uid.length()>4) uid=uid.mid(0,4);
    for(int i=0;i<myticketnum;i++){
        if(business) mylogs[i].setBus(true);
        else mylogs[i].setBus(false);
        std::time_t t = std::time(0);
        string timeString=std::to_string(t);
        std::random_device rd;
        std::mt19937_64 g2 (rd());
        uint32_t u32Random = g2();
        DES *mydes=new DES();
        string time_H=mydes->longToA((long)t,36);
        string s=mydes->uint_32ToA(u32Random,36).substr(1,4);
        string sPID=time_H+uid.toStdString()+s;
        sPID=mydes->des_encrypt_ECB(sPID,"security");
        sPID=mydes->des_H(sPID);
        sPID=mydes->des_2To32(sPID);
        mydes->deleteLater();
        mylogs[i].setPID(QString::fromStdString(sPID));
    }
    QString password;
    int cost=0,mileage=0;
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

        for(int i=0;i<myticketnum;i++){
            Log *p=&mylogs[i];
            QString PID=p->PID;
            if(p->next==nullptr){
                QString insert_sql = QString("insert into ticket(PID, name, id , sou, des, time0, time1, price, chi, next, date, business, num) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13') ").arg(p->PID).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(-1).arg(p->curdate).arg(p->business).arg(p->num);
                if(!sql_query2.exec(insert_sql))
                {
                    qDebug() << sql_query2.lastError();
                }
                else
                {
                    qDebug() << "inserted Wang!";
                    cost+=p->price*(p->business+1);
                    int begin,end;
                    findCityNum(*p,begin,end);
                    mileage+=calDistance(cityp[begin],cityp[end]);
                }
            }
            else{
                bool head=true;
                int j=0,subnum=0;
                while(p->next!=nullptr){
                    p=p->next;
                    subnum++;
                }
                p=&mylogs[i];
                while(p!=nullptr){
                    QString insert_sql;
                    if(head) {
                        insert_sql = QString("insert into ticket(PID, name, id , sou, des, time0, time1, price, chi, next, date, business, num) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13') ").arg(PID).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(subnum).arg(p->curdate).arg(p->business).arg(p->num);
                        head=false;
                        cost+=p->price*(p->business+1);
                    }
                    else insert_sql = QString("insert into subticket(PID, name, id , sou, des, time0, time1, price, chi, next, date) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11') ").arg(PID).arg(p->company).arg(p->ID).arg(p->sou).arg(p->des).arg(p->time0).arg(p->time1).arg(p->price).arg(p->chi).arg(j).arg(p->curdate);
                    if(!sql_query2.exec(insert_sql))
                    {
                        qDebug() << sql_query2.lastError();
                    }
                    else
                    {
                        qDebug() << "inserted SUCCESS!";
                        if(!head){
                            int begin,end;
                            findCityNum(*p,begin,end);
                            mileage+=calDistance(cityp[begin],cityp[end]);
                        }
                    }
                    j++;
                    p=p->next;
                }
            }
        }
        database.close();
    }
    QString name0 = QSqlDatabase::database().connectionName();
    QSqlDatabase::removeDatabase(name0);
    QSqlDatabase::removeDatabase("read_connection");
    QSqlDatabase::removeDatabase("read_connection_2");
    updateUserCostandMileage(cost,mileage,username);
}
//进度条更新函数：updateMyProgressbar usernum：用户生成进度
void MainWindow4::updateMyProgressbar(int usernum){
    int a=(usernum+1)/(float)ui->spinBox->value()*100;
    int n=a/7;
    ui->lineEdit_5->clear();
    for(int i=0;i<n;i++){
        ui->lineEdit_5->insert("█");
    }
    ui->label_14->setText(QString::number(a)+"%");
    qApp->processEvents(QEventLoop::ExcludeUserInputEvents); // 它可以忽略用户的输入（鼠标和键盘事件）。
    this->show();
    update();
}
//常乘航司票据筛选函数：companyFilter
void MainWindow4::companyFilter(Log *mylogs,int myticketnum,Log *copylogs,int &copynum){
    int i;
    QString st=ui->lineEdit_3->text();
    copynum=0;
    for(i=0;i<myticketnum;i++){
        if(st.mid(0,mylogs[i].company.length()).contains(mylogs[i].company)){
            copylogs[copynum]=mylogs[i];
            copynum++;
        }
    }
}
