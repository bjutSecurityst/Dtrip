/********************************************************************************
** Form generated from reading UI file 'cityweight.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CITYWEIGHT_H
#define UI_CITYWEIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cityweight
{
public:
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QWidget *cityweight)
    {
        if (cityweight->objectName().isEmpty())
            cityweight->setObjectName(QString::fromUtf8("cityweight"));
        cityweight->resize(70, 61);
        label = new QLabel(cityweight);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 16));
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        doubleSpinBox = new QDoubleSpinBox(cityweight);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(10, 30, 51, 22));
        doubleSpinBox->setMaximum(16.000000000000000);
        doubleSpinBox->setValue(0.500000000000000);

        retranslateUi(cityweight);

        QMetaObject::connectSlotsByName(cityweight);
    } // setupUi

    void retranslateUi(QWidget *cityweight)
    {
        cityweight->setWindowTitle(QCoreApplication::translate("cityweight", "Form", nullptr));
        label->setText(QCoreApplication::translate("cityweight", "\345\214\227\344\272\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cityweight: public Ui_cityweight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CITYWEIGHT_H
