#include "cityweight.h"
#include "ui_cityweight.h"

cityweight::cityweight(QString city,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cityweight)
{
    ui->setupUi(this);
    ui->label->setText(city+":");
}

cityweight::~cityweight()
{
    delete ui;
}

float cityweight::getweight()
{
    return ui->doubleSpinBox->value();
}
