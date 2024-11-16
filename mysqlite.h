#ifndef MYSQLITE_H
#define MYSQLITE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
bool openDatabasegetPassword(QString *password,QString username);
bool updateUserCostandMileage(int cost,int mileage,QString username);
#endif // MYSQLITE_H
