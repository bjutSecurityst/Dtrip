#ifndef CITYWEIGHT_H
#define CITYWEIGHT_H

#include <QWidget>

namespace Ui {
class cityweight;
}

class cityweight : public QWidget
{
    Q_OBJECT

public:
    explicit cityweight(QString city,QWidget *parent = nullptr);
    ~cityweight();
    float getweight();

private:
    Ui::cityweight *ui;
};

#endif // CITYWEIGHT_H
