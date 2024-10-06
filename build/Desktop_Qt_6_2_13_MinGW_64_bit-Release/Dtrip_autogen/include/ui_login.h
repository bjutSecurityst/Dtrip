/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_4;
    QLabel *label_4;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(557, 350);
        verticalLayoutWidget = new QWidget(Login);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 281, 301));
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

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer_4 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 30));
        lineEdit_2->setMaximumSize(QSize(16777215, 30));
        lineEdit_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(lineEdit_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setFlat(true);

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

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

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setMaximumSize(QSize(270, 16777215));

        horizontalLayout_5->addWidget(radioButton);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setScaledContents(true);

        horizontalLayout_5->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 20);

        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 20));
        pushButton_3->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 20));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(7, 3);
        verticalLayout->setStretch(10, 2);
        pushButton_4 = new QPushButton(Login);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(0, 0, 321, 351));
        pushButton_4->setCheckable(false);
        label_4 = new QLabel(Login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 320, 291, 20));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_4->raise();
        verticalLayoutWidget->raise();
        label_4->raise();

        retranslateUi(Login);

        pushButton_2->setDefault(false);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        label->setText(QCoreApplication::translate("Login", "\350\264\246\345\217\267\345\257\206\347\240\201\347\231\273\345\275\225", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Login", "\350\277\224\345\233\236\343\200\213", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Login", "\350\264\246\345\217\267(\350\213\261\346\226\207\346\225\260\345\255\227)", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Login", "\347\231\273\351\231\206\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Login", "\347\231\273 \345\275\225", nullptr));
        radioButton->setText(QString());
        label_5->setText(QCoreApplication::translate("Login", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("Login", "\345\222\214\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Login", "\346\233\264\346\224\271\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "\350\207\252\345\212\250\346\263\250\345\206\214", nullptr));
        label_2->setText(QString());
        pushButton_4->setText(QString());
        label_4->setText(QCoreApplication::translate("Login", "Dtrip \302\251 2024 bjutSecurityst  |   \344\272\254ICP\345\244\207114514\345\217\267  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
