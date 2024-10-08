#ifndef MYSQLITE_H
#define MYSQLITE_H
#include "QuickSort.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
class MySQLite
{
public:
    MySQLite();
    QSqlDatabase* getdatabase();
    void setdatabase();
private:
    QSqlDatabase database;
    QSqlQuery sql_query;
};

#endif // MYSQLITE_H
