#ifndef MYSQLITE_H
#define MYSQLITE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
//打开主数据库并获取用户密码函数：
bool openDatabasegetPassword(QString *password,QString username);
//更新主数据库中用户消费与里程函数：
bool updateUserCostandMileage(int cost,int mileage,QString username);
//从主数据库获取消费排行榜信息函数：
bool getuserinfocost(QStringList *names,int *costs,QString username,int &mycost,int &myrank);
//从主数据库获取里程排行榜信息函数：
bool getuserinfokilo(QStringList *names,int *kilos,QString username,int &mykilos,int &myrank);
//从主数据库获取用户UID函数：
bool openDatabasegetuid(QString *uid,QString username);
#endif // MYSQLITE_H
