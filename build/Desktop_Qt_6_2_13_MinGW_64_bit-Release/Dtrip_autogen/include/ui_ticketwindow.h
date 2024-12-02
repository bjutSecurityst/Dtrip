/********************************************************************************
** Form generated from reading UI file 'ticketwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETWINDOW_H
#define UI_TICKETWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ticketWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *label_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ticketWindow)
    {
        if (ticketWindow->objectName().isEmpty())
            ticketWindow->setObjectName(QString::fromUtf8("ticketWindow"));
        ticketWindow->resize(1280, 720);
        ticketWindow->setMinimumSize(QSize(1280, 720));
        ticketWindow->setMaximumSize(QSize(1280, 720));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ApplicationIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ticketWindow->setWindowIcon(icon);
        centralwidget = new QWidget(ticketWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 420, 831, 251));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(true);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 430, 171, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 430, 101, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(29, 9, 1221, 411));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(410, 680, 381, 21));
        label_9->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(20, 420, 1241, 251));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1160, 440, 71, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1160, 500, 71, 41));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1160, 560, 71, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1150, 620, 101, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1080, 625, 51, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Microsoft YaHei UI\";"));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(1100, 510, 42, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1069, 510, 31, 20));
        ticketWindow->setCentralWidget(centralwidget);
        pushButton->raise();
        label->raise();
        verticalLayoutWidget->raise();
        label_2->raise();
        verticalLayoutWidget_2->raise();
        label_9->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        label_3->raise();
        label_4->raise();
        spinBox->raise();
        label_5->raise();
        statusbar = new QStatusBar(ticketWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ticketWindow->setStatusBar(statusbar);

        retranslateUi(ticketWindow);

        QMetaObject::connectSlotsByName(ticketWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ticketWindow)
    {
        ticketWindow->setWindowTitle(QCoreApplication::translate("ticketWindow", "\350\256\242\350\264\255\346\234\272\347\245\250", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("ticketWindow", "\346\211\247\351\243\236\351\243\236\346\234\272\344\277\241\346\201\257", nullptr));
        label_9->setText(QCoreApplication::translate("ticketWindow", "\302\251 2024 bjutSecurityst  |   \344\272\254ICP\345\244\2071145141919\345\217\267   |    \344\275\277\347\224\250\346\235\241\346\254\276", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("ticketWindow", "\347\241\256\345\256\232\350\264\255\344\271\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ticketWindow", "\346\224\276\345\274\203\350\264\255\347\245\250", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ticketWindow", "\350\277\224\345\233\236", nullptr));
        label_3->setText(QCoreApplication::translate("ticketWindow", "\346\263\250\357\274\232\345\225\206\345\212\241=\347\273\217\346\265\216*2", nullptr));
        label_4->setText(QCoreApplication::translate("ticketWindow", "\347\273\217\346\265\216\344\273\223", nullptr));
        label_5->setText(QCoreApplication::translate("ticketWindow", "\347\245\250\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ticketWindow: public Ui_ticketWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETWINDOW_H
