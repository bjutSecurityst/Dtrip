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
        verticalLayoutWidget_2->setGeometry(QRect(19, 9, 1241, 411));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(410, 680, 381, 21));
        label_9->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(20, 420, 1241, 251));
        ticketWindow->setCentralWidget(centralwidget);
        pushButton->raise();
        label->raise();
        verticalLayoutWidget->raise();
        label_2->raise();
        verticalLayoutWidget_2->raise();
        label_9->raise();
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
    } // retranslateUi

};

namespace Ui {
    class ticketWindow: public Ui_ticketWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETWINDOW_H
