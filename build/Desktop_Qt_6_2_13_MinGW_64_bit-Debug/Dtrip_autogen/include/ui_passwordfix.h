/********************************************************************************
** Form generated from reading UI file 'passwordfix.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDFIX_H
#define UI_PASSWORDFIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Passwordfix
{
public:
    QPushButton *pushButton_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QSpacerItem *verticalSpacer_8;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;

    void setupUi(QWidget *Passwordfix)
    {
        if (Passwordfix->objectName().isEmpty())
            Passwordfix->setObjectName(QString::fromUtf8("Passwordfix"));
        Passwordfix->resize(331, 421);
        pushButton_4 = new QPushButton(Passwordfix);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(0, 0, 331, 421));
        pushButton_4->setCheckable(false);
        verticalLayoutWidget = new QWidget(Passwordfix);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 291, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));
        label->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 45); font: 15pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_6->addWidget(label);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 290 10pt \"Microsoft YaHei UI Light\";"));
        pushButton_5->setFlat(true);

        horizontalLayout_6->addWidget(pushButton_5);

        horizontalLayout_6->setStretch(0, 8);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_6 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer_4 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 30));
        lineEdit_2->setMaximumSize(QSize(16777215, 30));
        lineEdit_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(0, 30));
        lineEdit_3->setMaximumSize(QSize(16777215, 30));
        lineEdit_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        lineEdit_3->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(lineEdit_3);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setWordWrap(true);

        verticalLayout->addWidget(label_5);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(0, 30));
        lineEdit_4->setMaximumSize(QSize(16777215, 30));
        lineEdit_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        lineEdit_4->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(lineEdit_4);

        verticalSpacer_8 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";\n"
"selection-background-color: rgb(255, 170, 0);"));
        pushButton_2->setAutoExclusive(false);
        pushButton_2->setAutoDefault(false);
        pushButton_2->setFlat(false);

        verticalLayout->addWidget(pushButton_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(15, 3);
        label_4 = new QLabel(Passwordfix);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 390, 291, 20));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(Passwordfix);

        pushButton_2->setDefault(false);


        QMetaObject::connectSlotsByName(Passwordfix);
    } // setupUi

    void retranslateUi(QWidget *Passwordfix)
    {
        Passwordfix->setWindowTitle(QCoreApplication::translate("Passwordfix", "Form", nullptr));
        pushButton_4->setText(QString());
        label->setText(QCoreApplication::translate("Passwordfix", "\345\277\230\350\256\260/\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Passwordfix", "\350\277\224\345\233\236\343\200\213", nullptr));
        label_8->setText(QCoreApplication::translate("Passwordfix", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\350\264\246\345\217\267\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Passwordfix", "\350\264\246\345\217\267 (\350\213\261\346\226\207\346\225\260\345\255\227)", nullptr));
        label_7->setText(QCoreApplication::translate("Passwordfix", "\344\273\245\344\270\213\344\270\272\345\257\206\344\277\235\351\227\256\351\242\230\357\274\214\350\257\267\345\233\236\347\255\224\346\211\200\345\234\250\345\237\216\345\270\202\357\274\232", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Passwordfix", "\347\231\273\351\231\206\345\257\206\347\240\201 (\351\225\277\345\272\246>=6)", nullptr));
        label_2->setText(QCoreApplication::translate("Passwordfix", "\350\257\267\350\276\223\345\205\245\346\202\250\346\233\264\346\224\271\345\220\216\347\232\204\345\257\206\347\240\201\357\274\232", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("Passwordfix", "\346\226\260\347\231\273\351\231\206\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("Passwordfix", "\350\257\267\347\241\256\350\256\244\346\202\250\347\232\204\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("Passwordfix", "\347\241\256\350\256\244\346\226\260\347\231\273\351\231\206\345\257\206\347\240\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Passwordfix", "\344\277\256\346\224\271", nullptr));
        label_3->setText(QCoreApplication::translate("Passwordfix", "\345\216\237\345\257\206\347\240\201\351\224\231\350\257\257\357\274\214\350\257\267\346\243\200\346\237\245", nullptr));
        label_4->setText(QCoreApplication::translate("Passwordfix", "Dtrip \302\251 2024 bjutSecurityst  |   \344\272\254ICP\345\244\207114514\345\217\267  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Passwordfix: public Ui_Passwordfix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDFIX_H
