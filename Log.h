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
    QString curdate;
    Log* next=NULL;
    Log() {}
    void setLog(QString company,QString ID,QString sou,QString des,QString time0,QString time1,int price,QString chi,QString curdate){
        this->company=company;
        this->ID=ID;
        this->sou=sou;
        this->des=des;
        this->time0=time0;
        this->time1=time1;
        this->price=price;
        this->chi=chi;
        this->curdate=curdate;
    }
    void clear(){
        this->company="";
        this->ID="";
        this->sou="";
        this->des="";
        this->time0="";
        this->time1="";
        this->price=0;
        this->chi="";
        this->curdate="";
        Log *p,*q;
        if(this->next!=NULL){
            p=this->next;
            while(p->next!=NULL) {
                q=p->next;
                p->clear();
                p=q;
            }
            p->clear();
        }
        this->next=NULL;
    }
private:

};
#endif // LOG_H
