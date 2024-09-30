/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "MyGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_Map
{
public:
    QWidget *centralwidget;
    MyGraphicsView *graphicsView;
    QSlider *horizontalSlider;
    QLabel *label;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QDateEdit *dateEdit;
    QPushButton *pushButton_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Map)
    {
        if (Map->objectName().isEmpty())
            Map->setObjectName(QString::fromUtf8("Map"));
        Map->resize(1280, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ApplicationIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Map->setWindowIcon(icon);
        centralwidget = new QWidget(Map);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new MyGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, -1, 1280, 721));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        graphicsView->setInteractive(false);
        graphicsView->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
        graphicsView->setCacheMode(QGraphicsView::CacheModeFlag::CacheBackground);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(860, 10, 291, 31));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::TickPosition::TicksAbove);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(810, 10, 41, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(850, 560, 61, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\256\213\344\275\223\";"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(690, 630, 561, 68));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label_3);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 18pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label_5);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label_4);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 31));

        horizontalLayout->addWidget(pushButton);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 31));

        horizontalLayout->addWidget(pushButton_2);

        horizontalLayout->setStretch(0, 29);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 32);
        horizontalLayout->setStretch(3, 10);
        horizontalLayout->setStretch(5, 10);
        pushButton->raise();
        pushButton_2->raise();
        label_5->raise();
        label_6->raise();
        label_3->raise();
        label_4->raise();
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(685, 650, 381, 31));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(590, 650, 71, 31));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(20, 10, 110, 31));
        dateEdit->setDateTime(QDateTime(QDate(2024, 9, 20), QTime(8, 0, 0)));
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(2024, 9, 20));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(160, 10, 65, 31));
        pushButton_5->setMinimumSize(QSize(0, 31));
        Map->setCentralWidget(centralwidget);
        graphicsView->raise();
        pushButton_3->raise();
        horizontalSlider->raise();
        label->raise();
        label_2->raise();
        horizontalLayoutWidget->raise();
        pushButton_4->raise();
        dateEdit->raise();
        pushButton_5->raise();
        statusbar = new QStatusBar(Map);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Map->setStatusBar(statusbar);

        retranslateUi(Map);

        QMetaObject::connectSlotsByName(Map);
    } // setupUi

    void retranslateUi(QMainWindow *Map)
    {
        Map->setWindowTitle(QCoreApplication::translate("Map", "\345\234\260\345\233\276\351\200\211\346\213\251", nullptr));
        label->setText(QCoreApplication::translate("Map", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Map", "\344\270\255\345\233\275", nullptr));
        label_3->setText(QCoreApplication::translate("Map", "\345\247\213\345\217\221\345\234\260\357\274\232\350\257\267\347\202\271\345\207\273\345\247\213\345\217\221\345\234\260", nullptr));
        label_5->setText(QCoreApplication::translate("Map", "|", nullptr));
        label_4->setText(QCoreApplication::translate("Map", "\347\233\256\347\232\204\345\234\260\357\274\232\350\257\267\347\202\271\345\207\273\347\233\256\347\232\204\345\234\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Map", "\351\207\215\346\226\260\351\200\211\346\213\251", nullptr));
        label_6->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("Map", "\347\241\256\345\256\232", nullptr));
        pushButton_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Map", "\346\270\205\351\231\244\350\210\252\347\272\277", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Map", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Map: public Ui_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
