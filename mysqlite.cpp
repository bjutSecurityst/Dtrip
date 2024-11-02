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
