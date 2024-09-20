#ifndef LOG_H
#define LOG_H
#include <QString>
class Log {
public:
    QString company;
    QString ID;
    QString sou;
    QString des;
    QString time0;
    QString time1;
    int price;
    QString chi;
    Log() {}
    void setLog(QString company,QString ID,QString sou,QString des,QString time0,QString time1,int price,QString chi){
        this->company=company;
        this->ID=ID;
        this->sou=sou;
        this->des=des;
        this->time0=time0;
        this->time1=time1;
        this->price=price;
        this->chi=chi;
    }
private:

};
#endif // LOG_H
