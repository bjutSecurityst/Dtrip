/********************************************************************************
** Form generated from reading UI file 'ranking.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKING_H
#define UI_RANKING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ranking
{
public:
    QWidget *widget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QProgressBar *progressBar_2;
    QLabel *label_13;
    QLabel *label_14;
    QSpacerItem *verticalSpacer_5;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ranking)
    {
        if (ranking->objectName().isEmpty())
            ranking->setObjectName(QString::fromUtf8("ranking"));
        ranking->resize(692, 490);
        widget = new QWidget(ranking);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-10, 0, 711, 491));
        verticalLayoutWidget_2 = new QWidget(widget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(-380, -10, 1091, 501));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(ranking);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(380, 0, 301, 481));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_7);

        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 12pt \"Mistral\";"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label_11);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(34, 30));
        label_12->setMaximumSize(QSize(34, 30));
        label_12->setScaledContents(true);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(label_12);

        progressBar_2 = new QProgressBar(verticalLayoutWidget_3);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setValue(24);

        horizontalLayout_6->addWidget(progressBar_2);

        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(34, 30));
        label_13->setMaximumSize(QSize(34, 30));
        label_13->setScaledContents(true);
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(label_13);


        verticalLayout_3->addLayout(horizontalLayout_6);

        label_14 = new QLabel(verticalLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_14);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_5);

        scrollArea_2 = new QScrollArea(verticalLayoutWidget_3);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy);
        scrollArea_2->setMinimumSize(QSize(0, 0));
        scrollArea_2->setFrameShape(QFrame::Shape::StyledPanel);
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea_2->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 297, 198));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_3->addWidget(scrollArea_2);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        pushButton_2 = new QPushButton(verticalLayoutWidget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/build/Desktop_Qt_6_2_13_MinGW_64_bit-Debug/to.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(10, 10));

        verticalLayout_3->addWidget(pushButton_2);


        retranslateUi(ranking);

        QMetaObject::connectSlotsByName(ranking);
    } // setupUi

    void retranslateUi(QWidget *ranking)
    {
        ranking->setWindowTitle(QCoreApplication::translate("ranking", "Form", nullptr));
        label_9->setText(QCoreApplication::translate("ranking", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_10->setText(QCoreApplication::translate("ranking", "\346\210\221\347\232\204\346\216\222\345\220\215\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("ranking", "\351\207\214\347\250\213\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("ranking", "\347\254\2545", nullptr));
        label_13->setText(QCoreApplication::translate("ranking", "\347\254\2544", nullptr));
        label_14->setText(QCoreApplication::translate("ranking", "\345\275\223\345\211\215\347\247\257\345\210\2068000\357\274\214\350\267\235\347\246\273\347\254\254\345\233\233\345\220\215 \350\277\230\351\234\200\350\246\20116000", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ranking", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ranking: public Ui_ranking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKING_H
