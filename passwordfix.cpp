#include "passwordfix.h"
#include "ui_passwordfix.h"
#include <QMessageBox>
#include <QUrl>
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include "QuickSort.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QRegularExpressionValidator>
Passwordfix::Passwordfix(QString name,QString password,int mode,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Passwordfix)
{
    ui->setupUi(this);
    ui->lineEdit->setText(name);
    if(mode==1) ui->lineEdit_2->setText(password);
    setAttribute(Qt::WA_QuitOnClose,false);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->pushButton_4->setStyleSheet("border: 2px solid #009ef9; border-radius: 10px; background-color: white;");
    ui->pushButton_2->setStyleSheet("border-radius: 5px; background-color: #FFCF4C; selection-background-color: #F0CF5C");
    ui->pushButton_5->setStyleSheet("text-align:right;");
    QFile file(pathCreator("qss/登录.qss"));
    //QFile file("登录.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    ui->pushButton_2->setStyleSheet(styleSheet);
    ui->label_3->setVisible(false);
    this->mode=mode;
    if(mode==0){
        ui->label->setText("忘记密码");
        ui->label_7->setText("以下为密保问题，请回答所在城市：");
        ui->lineEdit_2->setPlaceholderText("请输入答案");
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }
    else if(mode==1){
        ui->label->setText("修改密码");
        ui->label_7->setText("请输入原密码");
        ui->lineEdit_2->setPlaceholderText("登陆密码 (长度>=6)");
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" < > : / %]*$")));
    ui->lineEdit_2->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" < > : / %]*$")));
    ui->lineEdit_3->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" < > : / %]*$")));
    ui->lineEdit_4->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^? \\\\  * | \" < > : / %]*$")));
}

Passwordfix::~Passwordfix()
{
    delete ui;
}

void Passwordfix::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text()==""){
        ui->lineEdit->setPlaceholderText("用户名不能为空");
        ui->lineEdit->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
        return;
    }
    ui->lineEdit->setPlaceholderText("账号(英文数字)");
    ui->lineEdit->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
    bool dbExist = QFile::exists(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
    if (dbExist)
    {
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("SQLITECIPHER","read_connection");
        qDebug() << QSqlDatabase::drivers();
        if(ui->lineEdit_2->text()==""){
            if(mode==1) ui->lineEdit_2->setPlaceholderText("密码不能为空");
            else if(mode==0) ui->lineEdit_2->setPlaceholderText("密保答案不能为空");
            ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            return;
        }
        ui->lineEdit_2->setPlaceholderText("登陆密码 (长度>=6)");
        ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
        QSqlDatabase database2;
        database2 = QSqlDatabase::addDatabase("QSQLITE","read_connection_2");
        database2.setDatabaseName(pathCreator("dbs/users.db"));
        database2.setUserName("root");
        database2.setPassword("123456");
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
            QSqlQuery query(database2);
            query.exec(last_log);
            qDebug() << "success!";
            while(query.next()){
                password = query.value("password").toString();
                question = query.value("question").toString();
            }
            qDebug() << password << question;
            if(mode==1){
                if(ui->lineEdit_2->text()!=password) {
                    ui->lineEdit_2->setText("");
                    ui->lineEdit_2->setPlaceholderText("密码错误");
                    ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
                    QString name0 = QSqlDatabase::database().connectionName();
                    QSqlDatabase::removeDatabase(name0);
                    return;
                }
                if(ui->lineEdit_3->text()==password){
                    ui->lineEdit_3->setText("");
                    ui->lineEdit_3->setPlaceholderText("新密码不能与旧密码相同");
                    ui->lineEdit_3->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
                    QString name0 = QSqlDatabase::database().connectionName();
                    QSqlDatabase::removeDatabase(name0);
                    return;
                }
                ui->lineEdit_3->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
            }
            else if(mode==0){
                if(ui->lineEdit_2->text()!=question) {
                    ui->lineEdit_2->setText("");
                    ui->lineEdit_2->setPlaceholderText("密保错误");
                    ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
                    QString name0 = QSqlDatabase::database().connectionName();
                    QSqlDatabase::removeDatabase(name0);
                    return;
                }
            }
            if(ui->lineEdit_3->text()!=ui->lineEdit_4->text()){
                ui->label_5->setText("密码不一致，请再次确认您的密码");
                ui->label_5->setStyleSheet("color:rgb(255,0,0);");
                ui->lineEdit_4->setText("");
                QString name0 = QSqlDatabase::database().connectionName();
                QSqlDatabase::removeDatabase(name0);
                return;
            }
            ui->label_5->setText("请确认您的密码：");
            ui->label_5->setStyleSheet("color:rgb(0,0,0);");
            if(ui->lineEdit_3->text().length()<6){
                ui->label_2->setText("密码不安全，请确保密码长度>=6");
                ui->label_2->setStyleSheet("color:rgb(255,0,0);");
                ui->lineEdit_3->setText("");
                QString name0 = QSqlDatabase::database().connectionName();
                QSqlDatabase::removeDatabase(name0);
                return;
            }
            ui->lineEdit_2->setPlaceholderText("登陆密码 (长度>=6)");
            ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,0,0);");
            database.setDatabaseName(pathCreator("dbs/"+ui->lineEdit->text()+".db"));
            database.setUserName(ui->lineEdit->text());
            if(mode==0) database.setPassword(password);
            else database.setPassword(ui->lineEdit_2->text());
            QString a="QSQLITE_USE_CIPHER=sqlcipher; SQLCIPHER_LEGACY=1; SQLCIPHER_LEGACY_PAGE_SIZE=4096; QSQLITE_REMOVE_KEY";
            qDebug() <<a;
            database.setConnectOptions(a);
            if (!database.open())
            {
                qDebug() << "Error: Failed to connect database." << database.lastError();
                database.close();
                QSqlDatabase::removeDatabase("read_connection");
                QSqlDatabase::removeDatabase("read_connection_2");
                ui->lineEdit_2->setText("");
                ui->lineEdit_2->setPlaceholderText("删除失败");
                ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
                QString name0 = QSqlDatabase::database().connectionName();
                QSqlDatabase::removeDatabase(name0);
                return;
            }
            else
            {
                database.close();
            }
            database.setPassword(ui->lineEdit_3->text());
            a="QSQLITE_USE_CIPHER=sqlcipher; SQLCIPHER_LEGACY=1; SQLCIPHER_LEGACY_PAGE_SIZE=4096; QSQLITE_CREATE_KEY";
            qDebug() <<a;
            database.setConnectOptions(a);
            if (!database.open())
            {
                qDebug() << "Error: Failed to connect database." << database.lastError();
                database.close();
                QSqlDatabase::removeDatabase("read_connection");
                QSqlDatabase::removeDatabase("read_connection_2");
                ui->lineEdit_2->setText("");
                ui->lineEdit_2->setPlaceholderText("密码错误");
                ui->lineEdit_2->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
                QString name0 = QSqlDatabase::database().connectionName();
                QSqlDatabase::removeDatabase(name0);
                return;
            }
            else
            {
                database.close();
            }
            QString update_sql = "update users set password = :password where name = :name";
            query.prepare(update_sql);
            query.bindValue(":password", ui->lineEdit_3->text());
            query.bindValue(":name", ui->lineEdit->text());
            if(!query.exec())
            {
                qDebug() << query.lastError();
            }
            else
            {
                qDebug() << "updated!";
            }

        }
        database2.close();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        QSqlDatabase::removeDatabase("read_connection");
        QSqlDatabase::removeDatabase("read_connection_2");
        QMessageBox msgBox;
        msgBox.setText("新密码修改成功");
        msgBox.setInformativeText("点击OK返回登录界面");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        this->close();
        emit sendToLogin();
    }
    else{
        ui->lineEdit->setText("");
        ui->lineEdit->setPlaceholderText("该用户不存在");
        ui->lineEdit->setStyleSheet("font-size:12pt; color:rgb(0,160,230);");
        return;
    }
}


void Passwordfix::on_pushButton_5_clicked()
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    this->close();
    emit sendToLogin();
}

int Passwordfix::getMode(){
    return mode;
}

