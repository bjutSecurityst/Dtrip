#include "mysqlite.h"
#include "QuickSort.h"

bool openDatabasegetPassword(QString *password,QString username){
    QSqlDatabase database2;
    database2 = QSqlDatabase::addDatabase("QSQLITE","read_connection_2");
    database2.setDatabaseName(pathCreator("dbs/users.db"));
    database2.setUserName("root");
    database2.setPassword("123456");
    if (!database2.open())
    {
        qDebug() << "Error: Failed to connect database." << database2.lastError();
        return false;
    }
    else
    {
        //获取数据
        QString last_log = QString("select * from users where name = '%1'").arg(username);
        QSqlQuery query(database2);
        query.exec(last_log);
        while(query.next()){
            *password = query.value("password").toString();
        }
        qDebug() << "success!";
        qDebug() << *password;
        database2.close();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        return true;
    }
}

bool updateUserCostandMileage(int cost,int mileage,QString username){
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE","read_connection");
    database.setDatabaseName(pathCreator("dbs/users.db"));
    database.setUserName("root");
    database.setPassword("123456");
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        QSqlDatabase::removeDatabase("read_connection");
        return false;
    }
    else
    {
        //获取数据
        QString update_sql = QString("UPDATE users SET cost='%1', mileage='%2' WHERE name='%3'").arg(cost).arg(mileage).arg(username);
        QSqlQuery queryuser(database);
        if(!queryuser.exec(update_sql))
        {
            qDebug() << queryuser.lastError();
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            QSqlDatabase::removeDatabase("read_connection");
            return false;
        }
        else
        {
            qDebug() << "updated!";
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            QSqlDatabase::removeDatabase("read_connection");
            return true;
        }
    }
}
bool getuserinfocost(QStringList *names,int *costs,QString username,int &mycost,int &myrank){
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE","read_connection");
    database.setDatabaseName(pathCreator("dbs/users.db"));
    database.setUserName("root");
    database.setPassword("123456");
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        QSqlDatabase::removeDatabase("read_connection");
        return false;
    }
    else
    {
        QString count_sqllogs="SELECT name,DENSE_RANK() OVER (ORDER BY cost DESC),cost AS ranking FROM users";
        QSqlQuery queryuser(database);
        if(!queryuser.exec(count_sqllogs)){
            qDebug() << queryuser.lastError();
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            QSqlDatabase::removeDatabase("read_connection");
            return false;
        }
        else
        {
            qDebug() << "selected!";
            int i=0;
            myrank=0;
            while(queryuser.next())
            {
                if(i<10){
                    if(queryuser.value(0).toString()==username){
                        myrank=queryuser.value(1).toInt();
                        mycost=queryuser.value(2).toInt();
                    }
                    names->append(queryuser.value(0).toString());
                    costs[i] = queryuser.value(2).toInt();
                    i++;
                }
                else if(myrank==0){
                    if(queryuser.value(0).toString()==username){
                        myrank=queryuser.value(1).toInt();
                        mycost=queryuser.value(2).toInt();
                        break;
                    }
                }
                else break;
            }
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            QSqlDatabase::removeDatabase("read_connection");
            return true;
        }
    }
}
bool getuserinfokilo(QStringList *names,int *kilos,QString username,int &mykilos,int &myrank){
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE","read_connection");
    database.setDatabaseName(pathCreator("dbs/users.db"));
    database.setUserName("root");
    database.setPassword("123456");
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        QSqlDatabase::removeDatabase("read_connection");
        return false;
    }
    else
    {
        QString count_sqllogs="SELECT name,DENSE_RANK() OVER (ORDER BY mileage DESC),mileage AS ranking FROM users";
        QSqlQuery queryuser(database);
        if(!queryuser.exec(count_sqllogs)){
            qDebug() << queryuser.lastError();
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            QSqlDatabase::removeDatabase("read_connection");
            return false;
        }
        else
        {
            qDebug() << "selected!";
            int i=0;
            myrank=0;
            while(queryuser.next())
            {
                if(i<10){
                    if(queryuser.value(0).toString()==username){
                        myrank=queryuser.value(1).toInt();
                        mykilos=queryuser.value(2).toInt();
                    }
                    names->append(queryuser.value(0).toString());
                    kilos[i] = queryuser.value(2).toInt();
                    i++;
                }
                else if(myrank==0){
                    if(queryuser.value(0).toString()==username){
                        myrank=queryuser.value(1).toInt();
                        mykilos=queryuser.value(2).toInt();
                        break;
                    }
                }
            }
            QString name0 = QSqlDatabase::database().connectionName();
            QSqlDatabase::removeDatabase(name0);
            QSqlDatabase::removeDatabase("read_connection");
            return true;
        }
    }
}
bool openDatabasegetuid(QString *uid,QString username){
    QSqlDatabase database2;
    database2 = QSqlDatabase::addDatabase("QSQLITE","read_connection_2");
    database2.setDatabaseName(pathCreator("dbs/users.db"));
    database2.setUserName("root");
    database2.setPassword("123456");
    if (!database2.open())
    {
        qDebug() << "Error: Failed to connect database." << database2.lastError();
        return false;
    }
    else
    {
        //获取数据
        QString last_log = QString("select * from users where name = '%1'").arg(username);
        QSqlQuery query(database2);
        query.exec(last_log);
        while(query.next()){
            *uid = QString::number(query.value("uid").toInt());
        }
        qDebug() << "success!";
        qDebug() << *uid;
        database2.close();
        QString name0 = QSqlDatabase::database().connectionName();
        QSqlDatabase::removeDatabase(name0);
        return true;
    }
}
