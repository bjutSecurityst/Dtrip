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
    int PID=-1,num=1;
    bool business=false;
    Log* next=NULL;
    QString route="";
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
    void setlogL(Log* tlog){
        this->company=tlog->company;
        this->ID=tlog->ID;
        this->sou=tlog->sou;
        this->des=tlog->des;
        this->time0=tlog->time0;
        this->time1=tlog->time1;
        this->price=tlog->price;
        this->chi=tlog->chi;
        this->curdate=tlog->curdate;
        this->PID=tlog->PID;
        this->business=tlog->business;
        this->route=tlog->route;
        this->num=tlog->num;
    }
    void setPID(int PID){
        this->PID=PID;
    }
    void setBus(bool business){
        this->business=business;
    }
    void setRoute(QString route){
        this->route=route;
    }
    void setnum(int num){
        this->num=num;
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
        this->PID=-1;
        this->business=false;
        this->route="";
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
