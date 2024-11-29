#ifndef MYSQLITE_H
#define MYSQLITE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
bool openDatabasegetPassword(QString *password,QString username);
bool updateUserCostandMileage(int cost,int mileage,QString username);
bool getuserinfocost(QStringList *names,int *costs,QString username,int &mycost,int &myrank);
bool getuserinfokilo(QStringList *names,int *kilos,QString username,int &mykilos,int &myrank);
bool openDatabasegetuid(QString *uid,QString username);
#endif // MYSQLITE_H
