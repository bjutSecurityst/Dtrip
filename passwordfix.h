#ifndef PASSWORDFIX_H
#define PASSWORDFIX_H

#include <QWidget>

namespace Ui {
class Passwordfix;
}

class Passwordfix : public QWidget
{
    Q_OBJECT

public:
    explicit Passwordfix(QString name,QString password,int mode,QWidget *parent = nullptr);
    ~Passwordfix();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Passwordfix *ui;
    int mode;
};

#endif // PASSWORDFIX_H
