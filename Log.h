#ifndef LOG_H
#define LOG_H
#include <QString>
class Log {
public:
    QString company;//航空公司
    QString PID;//票唯一ID
    QString ID="";//航班号
    QString sou;//始发地
    QString des;//目的地
    QString time0;//起飞时间
    QString time1;//到达时间
    int price;//价格
    QString chi;//晚点率
    QString curdate;//日期
    int num=1;//票数
    bool business=false;//true为商务
    Log* next=NULL;//子票指针
    QString route="",status="";//路径和票状态
    Log() {}
    ~Log(){}
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
    //深复制函数
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
    void setPID(QString PID){
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
    void setstatus(QString status){
        this->status=status;
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
        this->PID="-1";
        this->business=false;
        this->route="";
        this->status="";
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
