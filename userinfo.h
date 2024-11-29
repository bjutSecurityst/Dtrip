#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>

namespace Ui {
class userinfo;
}

class userinfo : public QWidget
{
    Q_OBJECT

public:
    explicit userinfo(QString username,int cost,int mileage,QWidget *parent = nullptr);
    ~userinfo();

private slots:
    void on_pushButton_3_clicked();

    void leaveEvent(QEvent *event) override {
        close(); // 退出窗口
        QWidget::leaveEvent(event); // 保留父类的默认处理
    }

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void sendToMainWindow();

private:
    Ui::userinfo *ui;
};

#endif // USERINFO_H
